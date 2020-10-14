#include <stdbool.h>

// 2D Shape
class Shape
{
public:
	Shape();
	Shape(const Shape);
	~Shape(); 
	
	bool move(const int, const int);
	int distanceFrom(const Shape) const;

	bool rotate(const float);
	void setPos(const int, const int);
	bool plot(Img) const;
	
private:
	Point* points_;
	size_t nPoints_;
	Point pos_;
	
	bool append(const Shape);
};
