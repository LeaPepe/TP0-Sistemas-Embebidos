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
	
	bool move(const int, const int);
	bool rotate(const float);
	bool scale(const float);
	float getLength(void) const;
	
private:
	float lerp(int,int,float);
	Point start,end;
};

#endif