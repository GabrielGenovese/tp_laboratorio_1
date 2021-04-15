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
	int retornoDivision;


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
					suma(primerOperando,segundoOperando,&resultadoSuma);
					resta(primerOperando,segundoOperando,&resultadoResta);
					multiplicacion(primerOperando,segundoOperando,&resultadoMultiplicacion);
					retornoDivision =division(primerOperando,segundoOperando,&resultadoDivision);
					factorial(primerOperando,&factorialPrimerOperando);
					factorial(segundoOperando,&factorialSegundoOperando);

					banderaCalculoEcho = 1;
				}
				else
				{
					printf("ERROR,Falta ingresar uno de los números (o ambos)");
				}
				break;
			case 4:
				if(banderaCalculoEcho)
				{
					printf("El resultado de la suma es (A + B): %d\n",resultadoSuma);
					printf("El resultado de la resta es (A - B): %d\n",resultadoResta);
					printf("El resultado de la multiplicacion es (A * B): %d\n",resultadoMultiplicacion);
					if(retornoDivision)
					{
						printf("No se puede dividir por cero");
					}
					else
					{
						printf("El resultado de la division es (A / B): %.2f\n",resultadoDivision);
					}
					printf("El resultado del factorial de A es: %ld\n",factorialPrimerOperando);
					printf("El resultado del factorial de B es: %ld\n",factorialSegundoOperando);
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
