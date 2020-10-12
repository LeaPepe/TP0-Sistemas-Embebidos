#include "rectangle.h"
#include <stdint.h>
#include <math.h>


bool rectangle_ctor(rectangle_t *me, uint32_t position_x, uint32_t position_y, 
					uint32_t height, uint32_t width){
	// define rect params
	me->super.position.x = position_x;
	me->super.position.y = position_y;
	me->height = height;
	me->width = width;
	
	// create 4 lines
	line_t l1,l2,l3,l4;
	
	//horizontal
	if(!line_ctor(&l1,position_x,position_y,position_x+width,position_y)){
		return false;
	}
	if(!line_ctor(&l2,position_x,position_y+height-1,position_x+width,position_y+height-1)){
		return false;
	}
	//vertical minus the extreme points
	if(!line_ctor(&l3,position_x,position_y,position_x,position_y+height)){
		return false;
	}

	if(!line_ctor(&l4,position_x+width-1,position_y,position_x+width-1,position_y+height)){
		return false;
	}
	
	
	coordinates_array_t* coords = &(me->super.array);
	coords->n_array = 0;
	coords->coordinates = NULL;
	
	// append lines array to rectangle shape
	if(!coordinates_append(coords,&l1.super.array)){
		return false;
	}
	
	if(!coordinates_append(coords,&l2.super.array)){
		return false;
	}
	if(!coordinates_append(coords,&l3.super.array)){
		return false;
	}
	if(!coordinates_append(coords,&l4.super.array)){
		return false;
	}
	
	// destroy lines
	line_dtor(&l1);
	line_dtor(&l2);
	line_dtor(&l3);
	line_dtor(&l4);
	return true;
}

// destructor
void rectangle_dtor(rectangle_t *me){
	shape_dtor(&(me->super));
	return;
}

bool rectangle_move(rectangle_t *me, uint32_t dx, uint32_t dy){
	
	// move coordinates
	if(!shape_move(&me->super,dx,dy)){
		return false;
	}
	
	return true;
}
bool rectangle_rotate(rectangle_t *me, float angle){
	// Completar
}


uint32_t rectangle_get_area(rectangle_t *me){
	// Completar
}

bool rectangle_plot(rectangle_t *me, image_t *image){
	return shape_plot(&me->super,image);
}
