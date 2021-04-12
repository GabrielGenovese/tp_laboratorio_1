#include <stdio.h>

int validacionNumeroEntero(int* entero,int* bandera)
{
	int comparador;

	printf("Ingrese un número entero: ");
	fflush(stdin);
	comparador = scanf("%d", entero);
	*bandera = 1;

	if(comparador == 0)
	{
		*bandera = 0;
		printf("ERROR, Vuelva a ingresar un número porfavor");
		*entero = 0;
		return 1;
	}
	return 0;
}


