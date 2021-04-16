/*
Nombre: Genovese Gabriel Alejandro
Division: E
TRABAJO PRACTICO 1
*/

#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "validaciones.h"
#include "calculos.h"

int main(void) {
	setbuf(stdout,NULL);

	int primerOperando;
	int banderaPrimerOperando = 0;
	int segundoOperando;
	int banderaSegundoOperando = 0;
	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	float resultadoDivision;
	long int factorialPrimerOperando;
	long int factorialSegundoOperando;
	int banderaCalculoEcho = 0;
	int opcion;
	int retornoSuma;
	int retornoResta;
	int retornoMultiplicacion;
	int retornoDivision;
	int retornoFactorialA;
	int retornoFactorialB;



	do
	{
		menuCuatroOpciones(&opcion,primerOperando,segundoOperando,banderaPrimerOperando,banderaSegundoOperando);
		switch(opcion)
			{
			case 1:
				if(!banderaPrimerOperando)
				{
					validacionNumeroEntero(&primerOperando,&banderaPrimerOperando);
				}
				else
				{
					printf("ERROR, Ya tiene un valor ingresado");
				}
				break;
			case 2:
				if(!banderaSegundoOperando)
				{
					validacionNumeroEntero(&segundoOperando,&banderaSegundoOperando);
				}
				else
				{
					printf("ERROR, Ya tiene un valor ingresado");
				}
				break;
			case 3:
				if(banderaPrimerOperando && banderaSegundoOperando)
				{
					retornoSuma = suma(primerOperando,segundoOperando,&resultadoSuma);
					retornoResta = resta(primerOperando,segundoOperando,&resultadoResta);
					retornoMultiplicacion= multiplicacion(primerOperando,segundoOperando,&resultadoMultiplicacion);
					retornoDivision = division(primerOperando,segundoOperando,&resultadoDivision);
					retornoFactorialA = factorial(primerOperando,&factorialPrimerOperando);
					retornoFactorialB = factorial(segundoOperando,&factorialSegundoOperando);

					banderaCalculoEcho = 1;
				}
				else
				{
					printf("ERROR,Falta ingresar uno de los números (o ambos)\n");
				}
				break;
			case 4:
				if(banderaCalculoEcho)
				{
					if(!retornoSuma)
					{
						printf("El resultado de la suma es (A + B): %d\n",resultadoSuma);
					}
					else
					{
						printf("No hay resultado de suma porque no habia nada que Sumar\n");
					}


					if(!retornoResta)
					{
						printf("El resultado de la resta es (A - B): %d\n",resultadoResta);
					}
					else
					{
						printf("No hay resultado de resta porque no habia nada que restar\n");
					}


					if(!retornoMultiplicacion)
					{
						printf("El resultado de la multiplicacion es (A * B): %d\n",resultadoMultiplicacion);
					}
					else
					{
						printf("No hay resultado de multiplicacion porque no habia nada que multiplicar\n");
					}


					if(retornoDivision)
					{
						printf("No se puede dividir por cero\n");
					}
					else
					{
						printf("El resultado de la division es (A / B): %.2f\n",resultadoDivision);
					}


					if(!retornoFactorialA)
					{
						printf("El resultado del factorial de A es: %ld\n",factorialPrimerOperando);
					}
					else
					{
						if(retornoFactorialA == -1){
							printf("No se puede hacer el factorial de 0 o de un numero negativo\n");
						}
						else
						{
							if(retornoFactorialA == 1)
							{
								printf("Disculpe, Esta operacion No soporta un numero mayor a 12\n");
							}
						}
					}


					if(!retornoFactorialB)
					{
						printf("El resultado del factorial de B es: %ld\n",factorialSegundoOperando);
					}
					else
					{
						if(retornoFactorialB == -1){
							printf("No se puede hacer el factorial de 0 o de un numero negativo\n");
						}
						else
						{
							if(retornoFactorialB == 1)
							{
								printf("Disculpe, Esta operacion No soporta un numero mayor a 12\n");
							}
						}
					}

					system("pause");

					banderaPrimerOperando = 0;
					banderaSegundoOperando = 0;
					banderaCalculoEcho = 0;
				}
				else
				{
					printf("ERROR,Todavia no se ha realizado ningun calculo ");
				}

				break;
			case 5:
				break;
			default:
				printf("Opcion Invalida\n");
				system("pause");
				break;
			}
	}while(opcion != 5);



	return EXIT_SUCCESS;
}
