#include "shape.h"
#include "line.h"
#include <stdint.h>
#include <math.h>

float lerp(uint32_t a,uint32_t b,float t){
	if(a == b){
		return a;
	}
	return (1 - t) * a + t * b;
}

// Constructor
bool line_ctor(line_t *me, uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2){
	
	// validation: ToDo
	
	//line parameters
	me->start.x = x1;
	me->start.y = y1;
	me->end.x = x2;
	me->end.y = y2;
	
	// shape position

	//parameters used
	uint32_t dx = x2-x1;
	uint32_t dy = y2-y1;
	uint32_t nPoints = fmax(dx,dy);
	float step = 1./nPoints;
	
	printf("dx=%i,dy=%i,npoints=%i,step=%f\n",dx,dy,nPoints,step);
	// mem alloc for line coordinates
	if ( !(me->super.array.coordinates = (coordinate_t*)malloc(sizeof(coordinate_t)*nPoints)) ){
		return false;
	}
	me->super.array.n_array = nPoints;
	
	for(uint32_t i = 0; i<nPoints; i++){
		me->super.array.coordinates[i].x = (int)round(lerp(x1,x2,i*step));
		me->super.array.coordinates[i].y = (int)round(lerp(y1,y2,i*step));
		printf("Punto(%i,%i)\n",me->super.array.coordinates[i].x,me->super.array.coordinates[i].y);
	}
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
	// move position
	me->super.position.x += dx;
	me->super.position.y += dy;
	
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
