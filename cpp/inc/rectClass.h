// 2D Rectangle
class Rect : public Shape
{
public:
	Rect(const int,const int,const int,const int);
	~Rect(); 
	
	bool rotate(float angle);
	uint32_t getArea(void) const;
	
private:
	uint32_t height_,width_;
};