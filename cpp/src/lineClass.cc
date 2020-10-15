#include "lineClass.h"

Line::Line(const int x1,const int y1, const int x2, const int y2){

	//line parameters
	setPos(x1,y1);
	start.set(x1,y1);
	end.set(x2,y2);
	
	//parameters used
	int dx = x2-x1;
	int dy = y2-y1;
	size_t n = fmax(dx,dy);
	float step = 1./n;
	
	// mem alloc for line coordinates
	if ( !(points = (Point*)malloc(sizeof(Point)*n)) ){
		return; //false;
	}
	nPoints = n;
	
	//coordinates
	for(size_t i = 0; i<nPoints; i++){
		points[i].setX((int)round(lerp(x1,x2,i*step)));
		points[i].setY((int)round(lerp(y1,y2,i*step)));
	}
	return; //true;
}

Line::~Line(){
	// parent takes care
}

bool Line::move(const int dx, const int dy){
	// move shape
	if(!Shape::move(dx,dy)){
		return false;
	}
	
	//move line points
	start.add(dx,dy);
	end.add(dx,dy);
	return true;
}

bool Line::rotate(const float){
	// completar
	return true;
}
bool Line::scale(const float){
	// completar
	return true;
}
float Line::getLength() const{
	return sqrt(((start.getX() - end.getX())^2) + ((start.getY() - end.getY())^2));
}

float Line::lerp(int a,int b,float t){
	if(a == b){
		return a;
	}
	return (1 - t) * a + t * b;
}