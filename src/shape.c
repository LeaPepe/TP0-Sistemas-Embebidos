#include <stdlib.h>
#include "shape.h"
#include "image.h"


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


void shape_dtor(shape_t *me){
	// free the only array
	free(me->array.coordinates);
}

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
	// Completar
	return true;
}