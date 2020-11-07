#include "pointClass.h"

// Constructors
Point::Point():x(0),y(0){ 
	// Empty
}

Point::Point(const int x_,const int y_):x(x_),y(y_){ 
	//x,y params
}

Point::Point(const Point& p):x(p.x),y(p.y){ 
	// point param
}

// Destructor
Point::~Point(){ 
	
}

// Functions
void Point::set(const int x_, const int y_){
	x = x_;
	y = y_;
}

void Point::set(const Point& p){
	x = p.x;
	y = p.y;
}
void Point::setX(const int x_){
	x = x_;
	
}
void Point::setY(const int y_){
	y = y_;
}

void Point::add(const int dx, const int dy){
	x += dx;
	y += dy;
}
int Point::getX() const{
	return x;
}
int Point::getY() const{
	return y;
}

Point& Point::operator=(const Point& p){
	x = p.x;
	y = p.y;
	return *this;
}

Point& Point::operator+(const Point& p){
	x += p.x;
	y += p.y;
	return *this;
}