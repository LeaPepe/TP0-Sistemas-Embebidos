#include "shapeClass.h"

// Constructors
Shape::Shape(){
	// empty
	pos.set(0,0);
	nPoints = 0;
	points = NULL;
}

Shape::Shape(const Shape& s){
		
	// position
	pos.set(s.pos);

	// alloc mem for coordinates array (maybe proper constructor?)
	if ( !(points = (Point*)malloc(sizeof(Point)*s.nPoints)) ){
		return; //false;
	}
	nPoints = s.nPoints;
	
	// copy array
	for(size_t i=0; i<nPoints; i++){
		points[i] = s.points[i];
	}
	return; //true;
}

Shape::Shape(const Point* p, const size_t n, const int x, const int y){
		
	// position
	pos.set(x,y);

	// alloc mem for points
	if ( !(points = (Point*)malloc(sizeof(Point)*n)) ){
		return; //false;
	}
	nPoints = n;
	
	// copy array
	for(size_t i=0; i<nPoints; i++){
		points[i] = p[i];
	}
	return; //true;
}

// Destructor
Shape::~Shape(){
	if (points != NULL){
		free(points);
	}
}


// Functions
void Shape::move(const int dx, const int dy){
	// move each point
	for(size_t i=0; i<nPoints; i++){
		points[i].add(dx,dy); // add delta
	}
	//move position also
	pos.add(dx,dy);
}


float Shape::distanceFrom(const Shape s) const{
	return sqrt(((pos.getX() - s.pos.getX())^2) + ((pos.getY() - s.pos.getY())^2));
}


void Shape::rotate(const float angle){
	float cosTheta = cos(angle);
    float sinTheta = sin(angle);
	Point pivot(pos);
	int xn,yn;
	for(size_t i=0; i<nPoints; i++){
		xn = (int)(cosTheta * (points[i].getX() - pivot.getX()) - sinTheta * (points[i].getY() - pivot.getY()) + pivot.getX());
		yn = (int)(sinTheta * (points[i].getX() - pivot.getX()) + cosTheta * (points[i].getY() - pivot.getY()) + pivot.getY());
		points[i].setX(round(xn));
		points[i].setY(round(yn));
	}
}

void Shape::setPos(const int x, const int y){
	pos.set(x,y);
}

void Shape::plot(Image* img)const{
	// for each point, draw the pixel
	for(size_t i=0; i<nPoints; i++){


		//if pixel inside image, draw pixel
		
		if((points[i].getX() >= 0 || (size_t)points[i].getX() < img->getCols()) && (points[i].getY() >= 0 || (size_t)points[i].getY() < img->getRows())){
			img->write(points[i].getX(),points[i].getY(),HIGH);  // draw pixel
		}
	}
}

bool Shape::append(const Shape& s){
	Point* newPoints;
	
	// alloc mem for appended array(size1 + size2)
	if ( !(newPoints = (Point*)malloc(sizeof(Point)*(s.nPoints + nPoints)) )){
		return false;
	}
	
	// copy arrays
	for(size_t i=0; i<nPoints; i++){
		newPoints[i] = points[i];
	}
	for(size_t i=0; i<s.nPoints; i++){
		newPoints[i+nPoints] = s.points[i];
	}
	nPoints += s.nPoints;

	// destroy old array
	if(points != NULL){ // empty array exception
		free(points);
	}
	points = newPoints; // set new array
	return true;
}