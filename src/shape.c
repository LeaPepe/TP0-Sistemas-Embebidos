
#include "shape.h"


// constructor
bool shape_ctor(shape_t *me, coordinates_array_t *array, int position_x, int position_y){
	
	if ( !(me->array.coordinates = (coordinate_t*)malloc(sizeof(coordinate_t)*array->n_array)) ){
		printf("cant create coordinates");
		return false;
	}
	
	// position
	me->position.x = position_x;
	me->position.y = position_y;
	
	// number of points
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
	if (me->array.coordinates != NULL) free(me->array.coordinates);
}

// move shape
bool shape_move(shape_t *me, int dx, int dy){
	// move each point
	for(uint32_t i=0; i<me->array.n_array; i++){
		me->array.coordinates[i].x = me->array.coordinates[i].x + dx;
		me->array.coordinates[i].y = me->array.coordinates[i].y + dy;
	}
	//move position also
	me->position.x = me->position.x + dx;
	me->position.y = me->position.y + dy;
	return true;
}


bool shape_rotate(shape_t *me, float angle){
	float cosA = cos(angle);
    float sinA = sin(angle);
	int pivot_x = me->position.x;
	int pivot_y = me->position.y;
	int xn,yn;
	for(uint32_t i=0; i < me->array.n_array; i++){
		int px = me->array.coordinates[i].x;
		int py = me->array.coordinates[i].y;
		xn = (int)round(cosA * (px - pivot_x) - sinA * (py - pivot_y) + pivot_x);
		yn = (int)round(sinA * (px - pivot_x) + cosA * (py - pivot_y) + pivot_y);
		me->array.coordinates[i].x = xn;
		me->array.coordinates[i].y = yn;
		//printf("(%i,%i) at %i. n = %i \r\n",xn,yn,i,me->array.n_array);
	}
	return true;
}

float shape_distance_from(shape_t *me, shape_t *shape){
	// Completar
	return 0;
}

bool shape_plot(shape_t *me, image_t *image){
	
	// for each coordinate, draw the pixel
	for(uint32_t i=0; i<me->array.n_array; i++){
		
		coordinate_t* pixel = &(me->array.coordinates[i]); // pointer for tidyness
		//if pixel inside image, draw pixel
		if((pixel->x >= 0 && pixel->x < image->n_cols) && 
	       (pixel->y >= 0 && pixel->y < image->n_rows)){
			image_write(image,pixel->y,pixel->x,HIGH);  // draw pixel
		}
	}
	
	return true;
	//end plot
}

bool coordinates_append(coordinates_array_t* array1, coordinates_array_t* array2){
	
	coordinate_t* coords = NULL;
	
	// alloc mem for appended array(size1 + size2)
	if ( !(coords = (coordinate_t*)malloc(sizeof(coordinate_t)*(array1->n_array + array2->n_array)) )){
		return false;
	}
	
	// copy arrays
	for(uint32_t i=0; i<array1->n_array; i++){
		coords[i].x = array1->coordinates[i].x;
		coords[i].y = array1->coordinates[i].y;
	}
	for(uint32_t i=0; i<array2->n_array; i++){
		coords[i+array1->n_array].x = array2->coordinates[i].x;
		coords[i+array1->n_array].y = array2->coordinates[i].y;
	}
	array1->n_array = array1->n_array + array2->n_array;
	// free old array
	if(array1->coordinates != NULL){ // empty array exception
		free(array1->coordinates);
	}
	array1->coordinates = coords; // set new array
	return true;
}