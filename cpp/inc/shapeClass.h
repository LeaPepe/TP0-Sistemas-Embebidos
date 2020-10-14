#ifndef __SHAPE_CLASS_H__
#define __SHAPE_CLASS_H__

#include <stdbool.h>
#include "pointClass.h"
#include "imageClass.h"

// 2D Shape
class Shape
{
public:
	Shape(const Point*, const size_t, const int, const int);
	Shape(const Shape);
	~Shape(); 
	
	bool move(const int, const int);
	float distanceFrom(const Shape) const;

	bool rotate(const float);
	void setPos(const int, const int);
	void plot(Image) const;
	
private:
	Point* points;
	size_t nPoints;
	Point pos;
	
	bool append(const Shape);
};

#endif