#ifndef SHAPE_H
#define SHAPE_H

#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "image.h"


/* Coordenada de la imagen (punto en el espacio de 2D) */ 
typedef struct {
	int x; // Coordenada en x
	int y; // Coordenada en y
} coordinate_t;

/* Vector de coordenadas almacenado dinámicamente */
typedef	struct {
	coordinate_t *coordinates; 	// Array dinámico de coordenadas
	uint32_t n_array; 			// Largo del vector
} coordinates_array_t;

/* Estructura principal que representa a la clase "figura" */
typedef	struct {
	coordinates_array_t array; 	// Vector de coordenadas
	coordinate_t position; 		// Posición de la figura
} shape_t;



/** 	@brief: Contructor del objeto "figura"
*		@params: recibe el puntero al objeto, y la posición en el espacio (posición en x e y)
*		@return: Devuelve verdadero sii encontró memoria para guardar el objeto.
**/
bool shape_ctor(shape_t *me, coordinates_array_t *array, int position_x, int position_y);


/** 	@brief: Destructor del objeto "figura"
*		@params: Recibe el puntero al objeto.
*		@return: void
**/
void shape_dtor(shape_t *me);


/** 	@brief: Mueve al objeto diferencialmente
*		@params: Recibe el puntero al objeto y la cantidad de espacio que se quiere trasladar la figura.
*		@return: verdadero si la operación se realizó exitosamente
**/
bool shape_move(shape_t *me, int dx, int dy);


/** 	@brief: Calcula la distancia a la posición de otra figura
*		@params: Recibe el puntero al objeto y la cantidad de espacio que se quiere trasladar la figura.
*		@return: la distancia entre ambas figuras
**/
float shape_distance_from(shape_t *me, shape_t *shape);


/** 	@brief: Guarda la figura en una imagen
*		@params: Recibe el puntero al objeto y el puntero a la imagen donde se guarda.
*		@return: verdadero si la operación se realizó exitosamente
**/
bool shape_plot(shape_t *me, image_t *image);

/** 	@brief: concatena dos arrays de coordenadas en el primero
*		@params: Recibe el puntero ambos arreglos
*		@return: verdadero si la operación se realizó exitosamente
**/
bool coordinates_append(coordinates_array_t* array1, coordinates_array_t* array2);

bool shape_rotate(shape_t *me, float angle);
#endif
