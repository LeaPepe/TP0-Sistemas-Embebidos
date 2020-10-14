#ifndef __RECT_CLASS_H__
#define __RECT_CLASS_H__

#define "shapeClass.h"

class Rect : public Shape
{
public:
	Rect(const int,const int,const uint32_t,const uint32_t);
	~Rect(); 
	
	bool rotate(float angle);
	uint32_t getArea(void) const;
	
private:
	uint32_t height_,width_;
};

#endif