
#include "rectClass.h"


Rect::Rect(const int x,const int y,const uint32_t w,const uint32_t h){
	// define rect params
	setPos(x,y);
	height = h;
	width = w;
	nPoints = 0;
	points = NULL;
	
	// create 4 lines
	Line l1(x,y,x+w,y);
	Line l2(x,y+h-1,x+w,y+h-1);
	Line l3(x,y,x,y+h);
	Line l4(x+w-1,y,x+w-1,y+h);
	
	// apend points of lines to rect
	if(!append(l1)){
		return;//false;
	}
	if(!append(l2)){
		return;// false;
	}
	if(!append(l3)){
		return;// false;
	}
	if(!append(l4)){
		return;// false;
	}
	return;// true;
}
Rect::~Rect(){
	// parent takes care
}

uint32_t Rect::getArea(void) const{
	return width*height;
}