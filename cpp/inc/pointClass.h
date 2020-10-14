#include <cstdlib>

// 2D point
class Point
{
public:
	Point();
	Point(const int x, const int y); 
	Point(const Point); 
	~Point(); 
	
	void set(const int, const int);
	void setX(const int);
	void setY(const int);
	
	int getX() const;
	int getY() const;
	
	
private:
	int x_,y_;
};
