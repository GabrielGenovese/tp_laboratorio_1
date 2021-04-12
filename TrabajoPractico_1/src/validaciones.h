/*
 * validaciones.h
 *
 *  Created on: 11 abr. 2021
 *      Author: gabri
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/*brief valida numeros enteros, si se ingresa otra cosa pide que vuelvas a ingresar.
 * param1 el numero a validar, y al que se le asignara lo ingresado al final.
 * param2 activa una bandera confirmando que la variable no esta vacia.
 * return retorna 0 si funciono sin problemas y 1 si no se ingresa un número, dejando el parametro en 0
 * */

int validacionNumeroEntero(int* entero,int* bandera);


#endif /* VALIDACIONES_H_ */
