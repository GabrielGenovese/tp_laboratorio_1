#include <stdio.h>
#include <string.h>
#include <ctype.h>



int validacionNumeroEntero(int* entero, char mensaje[]) // agregar variable mensaje
{
	int auxiliar;
	int retorno = -1;

	if(entero != NULL && mensaje != NULL)
	{
		printf("%s",mensaje);

		while(!(scanf("%d", &auxiliar)))
		{
			fflush(stdin);
			printf("ERROR, Ingrese un número entero porfavor: ");

		}
		retorno = 0;
		*entero = auxiliar;
	}

	return retorno;
}


int validacionNumeroEnteroConMinMax(int* entero, int minimo, int maximo, char mensaje[])
{
	int retorno = -1;

	if(entero != NULL && minimo < maximo && mensaje != NULL)
	{
		printf("%s",mensaje);

		while(!(scanf("%d", entero)) || (*entero < minimo || *entero > maximo) )
		{
			fflush(stdin);
			printf("ERROR, Vuelva a ingresar un número entero porfavor: ");

		}

		retorno = 0;
	}

	return retorno;
}

int validacionNumeroFloatConMinMax(float* entero, int minimo, int maximo, char mensaje[])
{
	int retorno = -1;

	if(entero != NULL && minimo < maximo && mensaje != NULL)
	{
		printf("%s",mensaje);

		while(!(scanf("%f", entero)) || (*entero < minimo || *entero > maximo) )
		{
			fflush(stdin);
			printf("ERROR, Vuelva a ingresar un número entero porfavor: ");

		}

		retorno = 0;
	}

	return retorno;
}

int validacionCaracter(char* caracter, char mensaje[])
{
	char auxiliar;
	int retorno = -1;

	if(caracter != NULL && mensaje != NULL)
	{
		printf("%s",mensaje);

		fflush(stdin);
		while(!(scanf("%c", &auxiliar)))
		{
			fflush(stdin);
			printf("ERROR, Ingrese un caracter porfavor: ");

		}
		retorno = 0;
		*caracter = auxiliar;
	}

	return retorno;
}


int validacionCaracterFijos(char* caracter, char mensaje[],char opcion1, char opcion2)
{
	int retorno = -1;
	char auxiliar;

	if(caracter != NULL && mensaje != NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c",&auxiliar);
		auxiliar = tolower(auxiliar);
		while(auxiliar != opcion1 && auxiliar != opcion2)
		{
			fflush(stdin);
			printf("ERROR, Elija entre %c / %c: ", opcion1, opcion2);
			scanf("%c",&auxiliar);
			auxiliar = tolower(auxiliar);
		}

		retorno = 0;
		*caracter = auxiliar;
	}

	return retorno;
}


int validacionStringAlpha(char string[], char mensaje[],int cantidadArray, char error[])
{
	char auxiliar[cantidadArray];
	int retorno = -1;
	int longitud;
	int contadorNumeros = 0;

	if(string != NULL && mensaje != NULL && cantidadArray > 0)
	{

		do
		{
			contadorNumeros = 0;
			printf("%s",mensaje);
			fflush(stdin);
			gets(auxiliar);
			longitud = strlen(auxiliar);

			if(longitud > cantidadArray-1)
			{
				printf("No debe sobrepasar los %d caracteres.",cantidadArray);
			}
			else
			{
				for(int i = 0; i < longitud; i++ )
				{
					if(!isalpha(auxiliar[i]) || auxiliar[i] == ' ')
					{
						contadorNumeros++;
					}
				}
				if(contadorNumeros)
				{
					printf("%s\n",error);
				}
			}

		}while(longitud > cantidadArray-1 || contadorNumeros > 0);

		strcpy(string,auxiliar);
		retorno = 0;
	}

	return retorno;
}


int validacionStringFijo3opc(char string[],char mensaje[],char opcion1[], char opcion2[], char opcion3[])
{
	int retorno = -1;
	char auxiliar[100];

	if(string != NULL && mensaje != NULL && opcion1 != NULL && opcion2 != NULL && opcion3 != NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		gets(auxiliar);
		strupr(auxiliar);
		strupr(opcion1);
		strupr(opcion2);
		strupr(opcion3);
		while(strcmp(auxiliar,opcion1) && strcmp(auxiliar,opcion2) && strcmp(auxiliar,opcion3))
		{
			printf("Error, Opcion Invalida\n");
			printf("%s",mensaje);
			fflush(stdin);
			gets(auxiliar);
			strupr(auxiliar);
		}
		retorno = 0;
	}

	return retorno;
}
