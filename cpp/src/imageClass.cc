#include "imageClass.h"

// Constructor
Image::Image(const size_t nCols_,const size_t nRows_){
	nCols = nCols_;
	nRows = nRows_;

	// alloc memory for cols (pointers)
	if ( !(data = (state_t **)malloc(sizeof(state_t*)*nCols)) ){
		return ;//false;
	}

	// alloc memory for rows (bits)
	for(size_t i=0; i<nCols; i++){
		if ( !(data[i] = (state_t *)malloc(sizeof(state_t)*nRows)) ){
			return; //false;
		}
		
		// zero initialize
		for(size_t j=0; j<nRows; j++){
			write(i, j, LOW);
		}
	}
	return; //true;
}

// Destructor
Image::~Image(){
	// free data cols
	for(size_t i=0; i<nCols; i++){
		if(data[i] != NULL) free(data[i]);
	}
	// free row pointers
	if(data != NULL)free(data);
}

void Image::write(const uint32_t x, const uint32_t y, const state_t value){
		data[x][y] = value;
}

state_t Image::read(const uint32_t x,const uint32_t y) const{
	return data[x][y];
}

void Image::toFile(const char* filename){
	
	std::ofstream file;
	file.open(filename);
	file << *this;

}

size_t Image::getRows(){
	return nRows;
}

size_t Image::getCols(){
	return nCols;
}

std::ostream& operator<<(std::ostream& os,const Image& img){
	//preamble
	os << "P1\n" << img.nCols << " " << img.nRows << "\n";
	// binary matrix
	for(uint32_t i=0; i<img.nCols; i++){
		for(uint32_t j=0; j<img.nRows; j++){
			os << img.read(i, j) << " ";
		}
		os << "\n";
	}
	return os;
}