/*
 * calculos.h
 *
 *  Created on: 11 abr. 2021
 *      Author: gabri
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/* brief obtiene 2 parametros por valor, los suma y devuelve el resultado por referencia.
 * param1 primer numero a sumar
 * param2 segundo numero a sumar
 * param3 resultado pasado por referencia
 * return retorna 0 si funciono correctamente
 * */
int suma(int numero1,int numero2,int* resultado);



/* brief obtiene 2 parametros por valor, los resta y devuelve el resultado por referencia.
 * param1 primer numero a restar
 * param2 segundo numero a restar
 * param3 resultado pasado por referencia
 * return retorna 0 si funciono correctamente
 * */
int resta(int numero1,int numero2,int* resultado);



/* brief obtiene 2 parametros por valor, los multiplica y devuelve el resultado por referencia.
 * param1 primer numero a multiplicar
 * param2 segundo numero a multiplicar
 * param3 resultado pasado por referencia
 * return retorna 0 si funciono correctamente
 * */
int multiplicacion(int numero1,int numero2,int* resultado);



/* brief obtiene el dividendo y el divisor por valor, confirma que el divisor sea diferente de 0,en caso de
 * serlo activa la bandera de divisor y termina la funsion sin dividir, en caso de no serlo divide y devuelve
 * el resultado por referencia.
 * param1 es el dividendo
 * param2 es el divisor
 * param3 bandera de divisor igual a 0
 * param4 resultado de la division pasado por referencia
 * return retorna 0 si funciono correctamente
 * */
int division (int numero1,int numero2,int *bandera,float* resultado);



/*brief obtiene un numero y calcula su factorial devolviendolo por referencia.
 * param1 numero al cual hacer el factorial.
 * param2 resultado del factorial pasado por referencia.
 * return retorna 0 si funciono correctamente
 * */
int factorial(int numero,int* resultado);

#endif /* CALCULOS_H_ */
