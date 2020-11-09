
#include <stdio.h>
#include <math.h>
#include "image.h"
#include "shape.h"
#include "line.h"
#include "rectangle.h"


#define MAX_IMG_NAME	20

#define N_ROWS			200 	// Cantidad de filas
#define N_COLS			200		// Cantidad de columnas

#define PI 3.1415926

/* Ejemplo de uso de las funciones de la clase "imagen" */

int main(void){
	image_t img;
	int img_count=0;
	line_t line;
	rectangle_t rect;
	char img_name[MAX_IMG_NAME];
	
	// Line
	if(!line_ctor(&line,20,10,40,40)){
		printf("cant build shape");
		return 1;
	}
	// Rect
	if(!rectangle_ctor(&rect,40,120,40,40)){
		printf("cant build shape");
		return 1;
	}
	
	for(int i=0; i<72; i++){
		// image
		image_ctor(&img,N_ROWS,N_COLS); 

		// plot
		line_plot(&line,&img);
		rectangle_plot(&rect,&img);
		
		// move
		line_move(&line,3,2);
		rectangle_move(&rect,1,2);
		
		// rotate
		line_rotate(&line,PI/8);
		rectangle_rotate(&rect,-PI/8);
		// save
		sprintf(img_name,"./images/img%.3d.pbm",img_count); 
		image_to_file(&img,img_name); 
		
		// mem
		image_dtor(&img); 

		++img_count;
	}
	printf("bye\r\n");
	// mem
	line_dtor(&line);
	rectangle_dtor(&rect);
	
	return 0;
}