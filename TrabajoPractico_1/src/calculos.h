#ifndef CALCULOS_H_
#define CALCULOS_H_


/* brief obtiene 2 parametros por valor, los suma y devuelve el resultado por referencia siempre y
 * cuando aunquesea uno de los dos parametros sea diferente de 0.
 *
 * param1 primer numero a sumar
 * param2 segundo numero a sumar
 * param3 resultado pasado por referencia
 *
 * return retorna 0 si funciono correctamente, y retorna 1 si se pasaron  dos ceros por parametros.
 * */
int suma(int numero1,int numero2,int* resultado);



/* brief obtiene 2 parametros por valor, los resta y devuelve el resultado por referencia siempre y
 * cuando aunquesea uno de los dos parametros sea diferente de 0.
 *
 * param1 primer numero a restar
 * param2 segundo numero a restar
 * param3 resultado pasado por referencia
 *
 * return retorna 0 si funciono correctamente, y retorna 1 si se pasaron  dos ceros por parametros.
 * */
int resta(int numero1,int numero2,int* resultado);



/* brief obtiene 2 parametros por valor, los multiplica y devuelve el resultado por referencia siempre y
 * cuando aunquesea uno de los dos parametros sea diferente de 0.
 *
 * param1 primer numero a multiplicar
 * param2 segundo numero a multiplicar
 * param3 resultado pasado por referencia
 *
 * return retorna 0 si funciono correctamente y retorna 1 si se pasaron  dos ceros por parametros.
 * */
int multiplicacion(int numero1,int numero2,int* resultado);



/* brief obtiene el dividendo y el divisor por valor, confirma que los parametros sean diferentes de 0 y si
 * lo son, calcula la division entre ellos.
 *
 * param1 es el dividendo
 * param2 es el divisor
 * param3 resultado de la division pasado por referencia
 *
 * return retorna 0 si funciono correctamente  y retorna 1 si se paso un cero por alguno de los parametros.
 * */
int division (int numero1,int numero2,float* resultado);



/*brief obtiene un numero y calcula su factorial devolviendolo por referencia.
 *
 * param1 numero al cual hacer el factorial.
 * param2 resultado del factorial pasado por referencia.
 *
 * return retorna 0 si funciono correctamente, retorna 1 si el numero pasado por parametro  supera el
 * numero maximo al que el programa puede hacerle factorial y -1 si se pasa por parametro un 0.
 * */
int factorial(int numero,long int* resultado);

#endif /* CALCULOS_H_ */
