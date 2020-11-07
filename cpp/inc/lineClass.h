#ifndef __LINE_CLASS_H__
#define __LINE_CLASS_H__

#include "shapeClass.h"
#include <math.h>

// 2D Line
class Line : public Shape
{
public:
	Line(const int,const int,const int,const int);
	~Line(); 
	void move(const int, const int);
	void scale(const float);
	float getLength(void) const;
	
private:
	Point start,end;
};

float lerp(int a,int b,float t);
#endif