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
	~Image(); 
	
	void write(const uint32_t, const uint32_t, const state_t);
	state_t read(const uint32_t,const uint32_t) const;
	
	friend std::ostream& operator<<(std::ostream&,const Image&);
	
private:
	state_t** data;
	size_t nRows,nCols;
};

#endif