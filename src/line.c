#include "shape.h"
#include "line.h"
#include <stdint.h>
#include <math.h>



// Constructor
bool line_ctor(line_t *me, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2){
	
	// validation: ToDo
	
	//line parameters
	me->start.x = x1;
	me->start.y = y1;
	me->end.x = x2;
	me->end.x = y2;
	
	// shape position

	//parameters used
	uint32_t dx = x2-x1;
	uint32_t dy = y2-y1;
	me->m = dy/dx;
	me->b = -(me->m*x1) + y1;
	//build coordinates
	
	if(dx>dy){ // x is grater
		// mem alloc for line coordinates
		if ( !(me->super.array.coordinates = (coordinate_t*)malloc(sizeof(coordinate_t)*dx)) ){
			return false;
		}
		me->super.array.n_array = 0;
		//coordinates
		for(uint32_t i; i<dx; i++){
			me->super.array.coordinates[i].x = me->start.x + i;
			me->super.array.coordinates[i].y = round(me->m*me->super.array.coordinates[i].x + me->b);
			//printf("Punto(%i,%i)\n",me->super.array.coordinates[i].x,me->super.array.coordinates[i].y);
			me->super.array.n_array++;
		}
	} else {
		// mem alloc for line coordinates
		if ( !(me->super.array.coordinates = (coordinate_t*)malloc(sizeof(coordinate_t)*dy)) ){
			return false;
		}
		me->super.array.n_array = 0;
		//coordinates
		for(uint32_t i = 0; i<dy; i++){
			me->super.array.coordinates[i].y = me->start.y + i;
			me->super.array.coordinates[i].x = round((me->super.array.coordinates[i].y-me->b)/me->m);
			printf("Punto(%i,%i)\n",me->super.array.coordinates[i].x,me->super.array.coordinates[i].y);
			me->super.array.n_array++;
		}
	}
	//printf("Line %i\n",me->super.array.n_array);

	return true;
}

// Destructor
void line_dtor(line_t *me){
	shape_dtor(&(me->super));
	return;
}
	
bool line_rotate(line_t *me, float angle){
  // Completar
}


bool line_scale(line_t *me, float factor){
  // Completar
}


float line_get_lenght(line_t *me){
  // Completar
}

bool line_move(line_t *me, uint32_t dx, uint32_t dy){
	
	// move coordinates
	if(!shape_move(&me->super,dx,dy)){
		return false;
	}
	
	//move line points
	me->start.x += dx;
	me->end.x += dx;
	me->start.y += dy;
	me->end.y += dy;
	return true;
}

bool line_plot(line_t *me, image_t *image){
	//printf("Plot line");
	return shape_plot(&me->super,image);
}
