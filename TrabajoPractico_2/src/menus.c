#include <stdio.h>
#include "validaciones_UTN.h"

int menu(int* opcElegida, char mensaje[])
{
	int retorno = -1;

	if(opcElegida != NULL)
	{
		printf("\n1. ALTAS\n");
		printf("2. MODIFICAR\n");
		printf("3. BAJA\n");
		printf("4. INFORMAR\n");
		printf("5. SALIR\n");
		validacionNumeroEntero(opcElegida,mensaje);

		retorno = 0;
	}

	return retorno;
}


int menuModificar(int* opcElegida, char mensaje[])
{
	int retorno = -1;

	if(opcElegida != NULL && mensaje != NULL)
	{
		printf("\n1. Modificar Nombre\n");
		printf("2. Modificar Apellido\n");
		printf("3. Modificar Salario\n");
		printf("4. Modificar Sector\n");
		printf("5. Salir\n");
		validacionNumeroEntero(opcElegida,mensaje);

		retorno = 0;
	}

	return retorno;
}


int menuInformar(int* opcElegida, char mensaje[])
{
	int retorno = -1;

	if(opcElegida != NULL && mensaje != NULL)
	{
		printf("\n1. Listado de los Empleados ordenados Alfabeticamente por apellido y sector\n");
		printf("2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio\n");
		printf("3. Salir\n");
		validacionNumeroEntero(opcElegida,mensaje);

		retorno = 0;
	}

	return retorno;
}
