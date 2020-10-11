#include <stdlib.h>
#include "shape.h"


// constructor
bool shape_ctor(shape_t *me, coordinates_array_t *array, uint32_t position_x, uint32_t position_y){
	
	// position
	me->position.x = position_x;
	me->position.y = position_y;
	
	
	// alloc mem for coordinates array (maybe proper constructor?)
	if ( !(me->array.coordinates = (coordinate_t*)malloc(sizeof(coordinate_t)*array->n_array)) ){
		return false;
	}
	me->array.n_array = array->n_array;
	
	// copy array
	for(uint32_t i=0; i<me->array.n_array; i++){
		me->array.coordinates[i].x = array->coordinates[i].x;
		me->array.coordinates[i].y = array->coordinates[i].y;
	}
	return true;
}

// destructor
void shape_dtor(shape_t *me){
	// free the only array
	free(me->array.coordinates);
}

// move shape
bool shape_move(shape_t *me, uint32_t dx, uint32_t dy){
	
	//make new array for moving 
	coordinate_t *moved_coordinates;
	if ( !(moved_coordinates = (coordinate_t*)malloc(sizeof(coordinate_t)*me->array.n_array)) ){
		return false;
	}
	
	// for each coordinate, move it
	for(uint32_t i=0; i<me->array.n_array; i++){
		// move coordinate, only positive so no troubles.
		moved_coordinates[i].x = me->array.coordinates[i].x + dx;
		moved_coordinates[i].y = me->array.coordinates[i].y + dy;
	}
	
	//move position
	me->position.x += dx;
	me->position.y += dy;
	
	//destroy and replace
	free(me->array.coordinates);
	me->array.coordinates = moved_coordinates;
	return true;
}


bool shape_rotate(shape_t *me, float angle){
	// Completar
	return true;
}

float shape_distance_from(shape_t *me, shape_t *shape){
	// Completar
	return 0;
}

bool shape_plot(shape_t *me, image_t *image){
	// for each coordinate, draw the pixel
	
	for(uint32_t i=0; i<me->array.n_array; i++){
		//printf("%i\n",i);
		//printf("%i\n",me->array.n_array);
		coordinate_t* pixel = &me->array.coordinates[i];
		
		//if pixel out of bounds, dont draw it
		if((pixel->x >= 0 || pixel->x < image->n_cols) && (pixel->y >= 0 || pixel->y < image->n_rows)){
			printf("pixel = %i,%i",pixel->x,pixel->y);
			image_write(image,pixel->y,pixel->x,HIGH); 
		}
	}
	return true;	
}

bool coordinates_append(coordinates_array_t* array1, coordinates_array_t* array2){
	
	coordinate_t* coords;
	
	// alloc mem for appended array
	size_t size = sizeof(coordinate_t)*(array1->n_array + array2->n_array);
	if ( !(coords = (coordinate_t*)malloc(size) )){
		return false;
	}

	// copy arrays
	for(uint32_t i=0; i<array1->n_array; i++){
		coords[i].x = array1->coordinates[i].x;
		coords[i].y = array1->coordinates[i].y;
	}
	for(uint32_t i=0; i<array2->n_array; i++){
		coords[i+array1->n_array].x = array1->coordinates[i].x;
		coords[i+array1->n_array].y = array1->coordinates[i].y;
	}
	
	// free old array and assign appended array
	free(array1->coordinates);
	array1->coordinates = coords;
	array1->n_array = size;
	return true;
}