#include <stdio.h>
#include <stdlib.h>

int menuCuatroOpciones(int* opcion,int A,int B,int banderaA,int banderaB)
{
	*opcion = 0;

	if(banderaA == 0)
	{
		printf("\n1. Ingresar primer operando (A = X)");
	}
	else
	{
		printf("\n1. Ingresar primer operando (A = %d)",A);
	}
	if(banderaB == 0)
	{
		printf("\n2. Ingresar segundo operando (B = Y)");
	}
	else
	{
		printf("\n2. Ingresar segundo operando (B = %d)",B);
	}

	printf("\n3. Calcular todas las operaciones");
	printf("\n4. Informar resultados");
	printf("\n5. Salir\n");
	fflush(stdin);
	scanf("%d",opcion);
	fflush(stdin);

	return 0;
}


