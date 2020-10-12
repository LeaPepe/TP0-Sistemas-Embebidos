
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
	line_t shape1;
	rectangle_t shape2;
	char img_name[MAX_IMG_NAME];
	
	// Construyo una linea
	if(!line_ctor(&shape1,10,10,100,40)){
		printf("cant build shape");
		return 1;
	}
	//construyo un rectangulo
	if(!rectangle_ctor(&shape2,15,15,50,30)){
		printf("cant build shape");
		return 1;
	}
	
	for(int i=0; i<50; i++){
		// Construyo el objeto "imagen"
		image_ctor(&img,N_ROWS,N_COLS); 

		// las imprimo en la imagen
		line_plot(&shape1,&img);
		rectangle_plot(&shape2,&img);
		
		// muevo las formas
		line_move(&shape1,1,2);
		rectangle_move(&shape2,2,1);
		
		
		// Lo guardo en un archivo
		sprintf(img_name,"./images/img%.3d.pbm",img_count); 
		image_to_file(&img,img_name); 
		
		// Libero memoria
		image_dtor(&img); 

		++img_count;
	}

	return 0;
}