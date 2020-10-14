#ifndef __IMAGE_CLASS_H__
#define __IMAGE_CLASS_H__


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

// binary state ON/OFF
typedef enum {LOW, HIGH} state_t;

// pmb image
class Image
{
public:
	Image(const size_t,const size_t);
	Image(const Image);
	~Image(); 
	
	void write(const uint32_t, const uint32_t, const state_t);
	state_t read(const uint32_t x,const uint32_t y) const;
	
	friend std::ostream& operator<<(std::ostream&,const Image&);
	
private:
	state_t** data_;
	size_t nRows_,nCols_;
};