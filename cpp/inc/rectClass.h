#ifndef __RECT_CLASS_H__
#define __RECT_CLASS_H__

#include "shapeClass.h"
#include "lineClass.h"

class Rect : public Shape
{
public:
	Rect(const int,const int,const uint32_t,const uint32_t);
	~Rect();
	uint32_t getArea(void) const;
	
private:
	uint32_t height,width;
};

#endif