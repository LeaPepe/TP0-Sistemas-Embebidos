#include "shape.h"
#include "line.h"
#include <stdint.h>
#include <math.h>

// a==b?a,(1 - t) * a + t * b;
static float lerp(int a,int b,float t){
	if(a == b){
		return a;
	}
	return (1 - t) * a + t * b;
}

// Constructor
bool line_ctor(line_t *me, int x1, int y1, int x2, int y2){
	
	//line parameters
	me->start.x = x1;
	me->start.y = y1;
	me->end.x = x2;
	me->end.y = y2;
	
	// shape position
	me->super.position.x = x1;
	me->super.position.y = y1;
	

	//parameters used
	int dx = x2-x1;
	int dy = y2-y1;
	size_t n = fmax(dx,dy);
	float step = 1./n;
	
	// mem alloc for line coordinates
	if ( !(me->super.array.coordinates = (coordinate_t*)malloc(sizeof(coordinate_t)*n)) ){
		return false;
	}
	me->super.array.n_array = n;
	
	//coordinates
	for(uint32_t i = 0; i<me->super.array.n_array; i++){
		me->super.array.coordinates[i].x = (int)round(lerp(x1,x2,i*step));
		me->super.array.coordinates[i].y = (int)round(lerp(y1,y2,i*step));
	}
	
	return true;
}



// Destructor
void line_dtor(line_t *me){
	shape_dtor(&(me->super));
	return;
}
	
bool line_rotate(line_t *me, float angle){
	
	
	//rotate shape
	shape_rotate(&me->super,angle);
  
	//rotate end. Start is pivot
	float cosA = cos(angle);
	float sinA = sin(angle);
	int pivot_x = me->super.position.x;
	int pivot_y = me->super.position.y;
	int px = me->end.x;
	int py = me->end.y;
	me->end.x = (int)round(cosA * (px - pivot_x) - sinA * (py - pivot_y) + pivot_x);
	me->end.y = (int)round(sinA * (px - pivot_x) + cosA * (py - pivot_y) + pivot_y);	
	return true;
}


bool line_scale(line_t *me, float factor){
	//completar
	return true;
}


float line_get_lenght(line_t *me){
	return sqrt(((me->start.x - me->end.x)^2) + ((me->start.y - me->end.y)^2));
}

bool line_move(line_t *me, int dx, int dy){
	
	// move shape
	shape_move(&me->super,dx,dy);
	
	//move line points
	me->start.x += dx;
	me->end.x += dx;
	me->start.y += dy;
	me->end.y += dy;
	return true;
}

bool line_plot(line_t *me, image_t *image){
	//plot shape
	return shape_plot(&me->super,image);
}
