#ifndef VALIDACIONES_UTN_H_
#define VALIDACIONES_UTN_H_


/*brief valida numeros enteros, si se ingresa otra cosa pide que vuelvas a ingresar.
 * param1 el numero a validar, y al que se le asignara lo ingresado al final.
 * return retorna 0 si funciono sin problemas.
 * */

int validacionNumeroEntero(int* entero, char mensaje[]); // agregar variable mensaje


/*brief valida numeros enteros entre el minimo y el maximo, si se ingresa otra cosa pide que vuelvas
 * a ingresar.
 * param1 el numero a validar, y al que se le asignara lo ingresado al final.
 * param2 es el minimo numero que puede ingresar.
 * param3 es el maximo numero que puede ingresar.
 * return retorna 0 si funciono sin problemas.
 * */
int validacionNumeroEnteroConMinMax(int* entero, int minimo, int maximo, char mensaje[]);


/*brief valida que lo ingresado sea un caracter, si se ingresa otra cosa pide que vuelvas a ingresar.
 * param1 variable pasada por referencia donde se guardara el caracter despues de validarlo.
 * param2 mensaje con el cual se pide la entrada de datos especifica.
 * return retorna 0 si no hubo errores y -1 si no pudo validad.
 * */
int validacionCaracter(char* caracter, char mensaje[]);


/*brief valida que lo ingresado sea menor a 20 caracteres, si es mayor pide que vuelvas a ingresar.
 * param1 variable pasada por referencia donde se guardara el string despues de validarlo.
 * param2 mensaje con el cual se pide la entrada de datos especifica.
 * return retorna 0 si no hubo errores y -1 si no pudo validad.
 * */
int validacionString20C(char string[], char mensaje[]);


/*brief valida que lo ingresado sea un caracter igual a alguna de las opciones.
 * param1 variable pasada por referencia donde se guardara el caracter despues de validarlo.
 * param2 mensaje para pedir el caracter.
 * param3 primera opcion.
 * param4 segunda opcion.
 * return retorna 0 si funciono correctamente, si no, retorna -1.
 * */
int validacionCaracterFijos(char* caracter, char mensaje[],char opcion1, char opcion2);


/*brief valida que el string ingresado sea igual a alguna de las opciones pasadas por parametros.
 * param1 variable donde se guardara el string ingresado despues de ser validado.
 * param2 mensaje que se mostrara para saber que ingresar.
 * param3 Es la primera opcion para comparar con lo ingresado.
 * param4 Es la segunda opcion para comparar con lo ingresado.
 * param5 Es la tercera opcion para comparar con lo ingresado.
 * return retorna 0 si no hubo problemas, si no retorna -1.
 * */
int validacionStringFijo3opc(char string[],char mensaje[],char opcion1[], char opcion2[], char opcion3[]);

int validacionNumeroFloatConMinMax(float* entero, int minimo, int maximo, char mensaje[]);


#endif /* VALIDACIONES_UTN_H_ */
