#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inicializacionEstructura(eEmployees employees[], int size)
{
	int retorno = -1;

	if(employees != NULL && size > 0)
	{
		for(int i = 0; i < size; i++)
		{
			retorno = 0;
			employees[i].isEmpty = 1;
		}
	}
	return retorno;
}


int buscarLibre(eEmployees employees[], int size, int* index)
{
	int retorno = -1;

	if(employees != NULL && size > 0 && index != NULL)
	{
		for(int i = 0; i < size; i++)
		{
			if(employees[i].isEmpty)
			{
				*index = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int ingresoDatos(int* id,char nombre[],char apellido[], float* sueldo, int* sector)
{
	int retorno = -1;

	if(id != NULL && nombre != NULL && apellido != NULL && sueldo != NULL && sector != NULL)
	{
		validacionNumeroEntero(id,"Ingrese el ID del empleado: ");
		validacionString51C(nombre,"Ingrese el nombre del empleado: ");
		validacionString51C(apellido,"Ingrese el apellido del empleado: ");
		validacionNumeroFloatConMinMax(sueldo,0,1000000,"Ingrese el sueldo del empleado: ");
		validacionNumeroEntero(sector, "Ingrese el sector del empleado: ");

		retorno = 0;
	}
	return retorno;
}

int addEmployee(eEmployees list[], int size, int freeIndex, int id, char nombre[], char apellido[], float sueldo, int sector)
{
	int retorno = -1;

	if(list != NULL && size > 0 && freeIndex > -1 && freeIndex < 1001 && id > -1 && nombre != NULL && apellido != NULL && sueldo > 0 && sector >-1)
	{
		list[freeIndex].id = id;
		strcpy(list[freeIndex].name,nombre);
		strcpy(list[freeIndex].lastname,apellido);
		list[freeIndex].salary = sueldo;
		list[freeIndex].sector = sector;

		list[freeIndex].isEmpty = 0;
		retorno = 0;
	}

	return retorno;
}


int findEmployeeById(eEmployees list[],int size, int id)
{
	int retorno = -1;
	int legajo;

	if(list != NULL && size > 0 && id > -1)
	{
		for(int i = 0; i < size; i++)
		{
			if( !list[i].isEmpty && list[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}


int removeEmployee(eEmployees list[],int size, int index)
{
	int retorno = -1;

	if(list != NULL && size > 0 && index > -1)
	{
		if(!list[index].isEmpty)
		{
			list[index].isEmpty = 1;
			retorno = 0;
		}
	}

	return retorno;
}
