#include <stdio.h>

int validacionNumeroEntero(int* entero,int* bandera)
{


	printf("Ingrese un n�mero entero: ");


	while(!(scanf("%d", entero)))
	{
		fflush(stdin);
		printf("ERROR, Vuelva a ingresar un n�mero entero porfavor: ");

	}

	*bandera = 1;

	return 0;
}


