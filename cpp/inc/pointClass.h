#ifndef __POINT_CLASS_H__
#define __POINT_CLASS_H__

#include <cstdlib>


// 2D point
class Point
{
public:
	Point();
	Point(const int, const int); 
	Point(const Point&); 
	~Point(); 
	
	void set(const int, const int);
	void set(const Point&);
	void setX(const int);
	void setY(const int);
	void add(const int, const int);
	
	int getX() const;
	int getY() const;
	
	
	Point& operator+(const Point&);
	Point& operator=(const Point&);

private:
	int x,y;
};

#endif