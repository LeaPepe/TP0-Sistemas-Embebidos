#include "pointClass.h"

// Constructors
Point::Point(){ 
	// Empty
	x = 0;
	y= 0;
}

Point::Point(const int x_,const int y_){ 
	// Empty
	x = x_;
	y = y_;
}

Point::Point(const Point p){ 
	// Empty
	x = p.x;
	y = p.y;
}

// Destructor
Point::~Point(){ 
	
}

// Functions
void Point::set(const int x_, const int y_){
	x = x_;
	y = y_;
}

void Point::set(const Point p){
	x = p.x;
	y = p.y;
}
void Point::setX(const int x_){
	x = x_;
	
}
void Point::setY(const int y_){
	y = y_;
}

void add(const int dx_, const int dx_){
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