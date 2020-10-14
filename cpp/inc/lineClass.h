// 2D Line
class Line : public Shape
{
public:
	Line(const int,const int,const int,const int);
	~Line(); 
	
	bool move(const int, const int);
	bool rotate(const float);
	bool scale(const float);
	uint32_t getLength(void) const;
	
private:
	Point start,end;
};