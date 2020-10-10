
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "image.h"


// constructor
bool image_ctor(image_t *me, uint32_t n_rows, uint32_t n_cols){

	me->n_rows = n_rows;
	me->n_cols = n_cols;

	// alloc memory for cols (pointers)
	if ( !(me->data = (img_data_t **)malloc(sizeof(img_data_t *)*n_cols)) ){
		return false;
	}

	// alloc memory for rows (bits)
	for(uint32_t i=0; i<n_cols; i++){
		if ( !(me->data[i] = (img_data_t *)malloc(sizeof(img_data_t)*n_rows)) ){
			return false;
		}
		
		// zero initialize
		for(uint32_t j=0; j<n_rows; j++){
			image_write(me, i, j, LOW);
		}
	}

	return true;
}

// destructor
void image_dtor(image_t *me){

	// why?
	uint32_t n_cols = me->n_cols;
	
	// free data cols
	for(uint32_t i=0; i<n_cols; i++){
		free(me->data[i]);
	}

	// free row pointers
	free(me->data);
}

// value write in row i col j
void image_write(image_t *me, uint32_t i, uint32_t j, img_data_t value){
	me->data[i][j] = value;
}	

// value read in row i col j
img_data_t image_read(image_t *me, uint32_t i, uint32_t j){
	return me->data[i][j];
}


// translate image to a file
void image_to_file(image_t *me, const char *filename){

	uint32_t n_cols, n_rows;
	FILE *filename_ptr;

	n_rows = me->n_rows;
	n_cols = me->n_cols;

	filename_ptr = fopen(filename, "w+");

	fprintf(filename_ptr, "P1\n%d %d\n", n_cols, n_rows);
	for(uint32_t i=0; i<n_cols; i++){
		for(uint32_t j=0; j<n_rows; j++){
			fprintf(filename_ptr, "%d ", image_read(me, i, j) );
		}
		fprintf(filename_ptr, "\n");
	}

	fclose(filename_ptr);

}