// Constructors
Shape::Shape(const Shape s){
		
	// position
	pos.set(s.pos);

	// alloc mem for coordinates array (maybe proper constructor?)
	if ( !(points = (Point*)malloc(sizeof(Point)*s.nPoints)) ){
		return false;
	}
	nPoints = s.nPoints;
	
	// copy array
	for(size_t i=0; i<nPoints; i++){
		points[i] = s.points[i];
	}
	return true;
}

Shape::Shape(const Point* p, const size_t n, const int x, const int y){
		
	// position
	pos.set(x,y);

	// alloc mem for points
	if ( !(points = (Point*)malloc(sizeof(Point)*n)) ){
		return false;
	}
	nPoints = n;
	
	// copy array
	for(size_t i=0; i<nPoints; i++){
		points[i] = p[i];
	}
	return true;
}

// Destructor
Shape::~Shape(){
	if (points != NULL){
		free(points);
	}
}


// Functions
bool Shape::move(const int dx, const int dy){
	// alloc mem for moved points
	Point* newPoints;
	if ( !(newPoints = (Point*)malloc(sizeof(Point)*nPoints)) ){
		return false;
	}

	// move each point
	for(size_t i=0; i<nPoints; i++){
		Points[i].add(dx,dy);
	}
	
	//move position
	pos.add(dx,dy)
	
	//destroy and replace
	free(points);
	points = newPoints;
	return true;
}


float Shape::distanceFrom(const Shape s) const{
	return sqrt((pos.x - s.pos.x)^2 + (pos.y - s.pos.y)^2);
}


bool Shape::rotate(const float){
	// Completar
	return true;
}

void Shape::setPos(const int x, const int x){
	pos.setPos(x,y);
}

void Shape::plot(Image* img)const{
	// for each coordinate, draw the pixel
	for(size_t i=0; i<nPoints; i++){

		//if pixel inside image, draw pixel
		if((points[i].x >= 0 || points[i].x < img->nCols) && (points[i].y >= 0 || points[i].y < img->nRows)){
			img->write(points[i].x,points[i].y,HIGH);  // draw pixel
		}
	}
}

bool Shape::append(const Shape s){
	Point* newPoints;
	
	// alloc mem for appended array(size1 + size2)
	if ( !(newPoints = (Point*)malloc(sizeof(Point)*(s.nPoints + nPoints)) )){
		return false;
	}
	
	// copy arrays
	for(size_t i=0; i<nPoints; i++){
		newPoints[i] = points[i];
	}
	for(size_t i=0; i<s.nPoints; i++){
		newPoints[i+nPoints] = s.points[i];
	}
	nPoints += s.nPoints

	// destroy old array
	if(points != NULL){ // empty array exception
		free(points);
	}
	points = newPoints; // set new array
	return true;
}