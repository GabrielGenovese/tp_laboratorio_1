#include <stdio.h>
#include "validaciones_UTN.h"

int menu(int* opcElegida, char mensaje[])
{
	int retorno = -1;

	if(opcElegida != NULL && mensaje != NULL)
	{
		printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
		printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
		printf("3. Alta de empleado.\n");
		printf("4. Modificar datos de empleado.\n");
		printf("5. Baja de empleado.\n");
		printf("6. Listar empleados.\n");
		printf("7. Ordenar empleados.\n");
		printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
		printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
		printf("10. Salir\n");
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
		printf("\n1. Modificar Nombre.\n");
		printf("2. Modificar Horas Trabajadas.\n");
		printf("3. Modificar Sueldo.\n");
		printf("4. Salir\n");
		validacionNumeroEntero(opcElegida,mensaje);

		retorno = 0;
	}

	return retorno;
}


int menuOrdenar(int* opcElegida, char mensaje[])
{
	int retorno = -1;

	if(opcElegida != NULL && mensaje != NULL)
	{
		printf("\n1. Ordenar por ID.\n");
		printf("2. Ordenar por nombre.\n");
		printf("3. Ordenar por horas trabajadas.\n");
		printf("4. Ordenar por sueldo.\n");
		printf("5. Salir\n");
		validacionNumeroEntero(opcElegida,mensaje);

		retorno = 0;
	}

	return retorno;
}

int menuAscendenteDescendente(int* opcElegida, char mensaje[])
{
	int retorno = -1;

	if(opcElegida != NULL && mensaje != NULL)
	{
		printf("\n1. Ascendente\n");
		printf("2. Descendente\n");
		validacionNumeroEntero(opcElegida,mensaje);

		retorno = 0;
	}

	return retorno;
}
