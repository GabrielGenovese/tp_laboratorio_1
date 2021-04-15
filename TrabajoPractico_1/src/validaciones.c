#include <stdio.h>

int validacionNumeroEntero(int* entero,int* bandera)
{


	printf("Ingrese un número entero: ");


	while(!(scanf("%d", entero)))
	{
		fflush(stdin);
		printf("ERROR, Vuelva a ingresar un número entero porfavor: ");

	}

	*bandera = 1;

	return 0;
}


