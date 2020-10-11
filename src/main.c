
#include <stdio.h>
#include "image.h"
#include "line.h"


#define MAX_IMG_NAME	20

#define N_ROWS			200 	// Cantidad de filas
#define N_COLS			200		// Cantidad de columnas


/* Ejemplo de uso de las funciones de la clase "imagen" */

int main(void){
	
	image_t img;
	int img_count=0;
	line_t line;
	char img_name[MAX_IMG_NAME];
	
	//printf("Main");
	// Construyo una linea
	line_ctor(&line,0,0,10,100);
	
	for(int i=0; i<10; i++){
		//printf("For");
		// Construyo el objeto "imagen"
		image_ctor(&img,N_ROWS,N_COLS); 

		// muevo la linea
		line_move(&line,3,1);
		
		// la imprimo en la imagen
		line_plot(&line,&img);
		
		// Lo guardo en un archivo
		sprintf(img_name,"./images/img%.3d.pbm",img_count); 
		image_to_file(&img,img_name); 
		
		// Libero memoria
		image_dtor(&img); 

		++img_count;
	}

	return 0;
}