
#include <stdio.h>
#include "image.h"
#include "shape.h"
#include "line.h"
#include "rectangle.h"


#define MAX_IMG_NAME	20

#define N_ROWS			200 	// Cantidad de filas
#define N_COLS			200		// Cantidad de columnas


/* Ejemplo de uso de las funciones de la clase "imagen" */

int main(void){
	
	image_t img;
	int img_count=0;
	line_t shape;
	char img_name[MAX_IMG_NAME];
	
	printf("\n");
	printf("Main\n");
	// Construyo una linea
	if(!line_ctor(&shape,0,0,5,0)){
		printf("cant build shape");
		return 1;
	}
	
	for(int i=0; i<10; i++){
		// Construyo el objeto "imagen"
		image_ctor(&img,N_ROWS,N_COLS); 

		// la imprimo en la imagen
		line_plot(&shape,&img);
		
		// muevo la linea
		line_move(&shape,1,1);
		
		
		// Lo guardo en un archivo
		sprintf(img_name,"./images/img%.3d.pbm",img_count); 
		image_to_file(&img,img_name); 
		
		// Libero memoria
		image_dtor(&img); 

		++img_count;
	}

	return 0;
}