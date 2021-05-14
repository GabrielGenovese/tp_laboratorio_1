#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones_UTN.h"
#include "ArrayEmployees.h"


int initEmployees(eEmployees employees[], int size)
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


int searchFree(eEmployees employees[], int size, int* index)
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


int dataEntry(int* id,char name[],char lastName[], float* salary, int* sector)
{
	int retorno = -1;

	if(id != NULL && name != NULL && lastName != NULL && salary != NULL && sector != NULL)
	{
		validacionNumeroEntero(id,"Ingrese el ID del empleado: ");
		validacionString51C(name,"Ingrese el nombre del empleado: ");
		validacionString51C(lastName,"Ingrese el apellido del empleado: ");
		validacionNumeroFloatConMinMax(salary,0,1000000,"Ingrese el sueldo del empleado: ");
		validacionNumeroEntero(sector, "Ingrese el sector del empleado: ");

		retorno = 0;
	}
	return retorno;
}


int addEmployee(eEmployees list[], int size, int freeIndex, int id, char name[], char lastName[], float salary, int sector)
{
	int retorno = -1;

	if(list != NULL && size > 0 && freeIndex > -1 && freeIndex < 1001 && id > -1 && name != NULL && lastName != NULL && salary > 0 && sector >-1)
	{
		list[freeIndex].id = id;
		strcpy(list[freeIndex].name,name);
		strcpy(list[freeIndex].lastname,lastName);
		list[freeIndex].salary = salary;
		list[freeIndex].sector = sector;

		list[freeIndex].isEmpty = 0;
		retorno = 0;
	}

	return retorno;
}


int findEmployeeById(eEmployees list[],int size, int id)
{
	int retorno = -1;

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


int upwardOrdering(eEmployees list[], int size)
{
	int retorno = -1;
	eEmployees auxiliar;

	if(list != NULL && size > 0)
	{
		for(int i = 0; i < size -1; i++)
		{
			for(int j = i +1; j < size; j++)
			{
				if(strcmp(list[i].lastname,list[j].lastname) > 0)
				{
					auxiliar = list[i];
					list[i] = list[j];
					list[j] = auxiliar;
					retorno = 0;
				}
				else
				{
					if(strcmp(list[i].lastname,list[j].lastname) == 0)
					{
						if(list[i].sector > list[j].sector )
						{
							auxiliar = list[i];
							list[i] = list[j];
							list[j] = auxiliar;
							retorno = 0;
						}
					}
				}
			}
		}
	}
	return retorno;
}


int descendingOrdering(eEmployees list[],int size)
{
	int retorno = -1;
	eEmployees auxiliar;

	if(list != NULL && size > 0)
	{
		for(int i = 0; i < size -1; i++)
		{
			for(int j = i +1; j < size; j++)
			{
				if(strcmp(list[i].lastname,list[j].lastname) < 0)
				{
					auxiliar = list[i];
					list[i] = list[j];
					list[j] = auxiliar;
				}
				else
				{
					if(strcmp(list[i].lastname,list[j].lastname) == 0)
					{
						if(list[i].sector < list[j].sector )
						{
							auxiliar = list[i];
							list[i] = list[j];
							list[j] = auxiliar;
						}
					}
				}
			}
		}
	}
	return retorno;
}


int sortEmployees(eEmployees list[],int size, int order)
{
	int retorno = -1;

	if(list != NULL && size > 0 && (order != 1 || order != 0))
	{
		if(order)
		{
			upwardOrdering(list,size);
		}
		else
		{
			descendingOrdering(list,size);
		}

		retorno =0;
	}
	return retorno;
}


void headLine()
{
	printf("\n%10s","ID |");
	printf("%20s","Nombre |");
	printf("%20s","Apellido |");
	printf("%10s","Sueldo |");
	printf("%10s","Sector |\n");
}


int listOne(eEmployees list[], int index)
{
	int retorno = -1;
	if(list != NULL && index > -1)
	{

		printf("\n%10d |",list[index].id);
		printf("%20s |",list[index].name);
		printf("%20s |",list[index].lastname);
		printf("%10.2f |",list[index].salary);
		printf("%10d |\n",list[index].sector);
		retorno = 0;
	}
	return retorno;
}


int listAll(eEmployees list[], int size)
{
	int retorno = -1;

	if(list != NULL && size > 0)
	{
		headLine();
		for(int i = 0; i < size ; i++)
		{
			if(list[i].isEmpty == 0)
			{
				listOne(list,i);
			}
		}
		retorno = 0;
	}

	return retorno;
}

int uponAverageSalary(eEmployees list[], int size, int averageSalary)
{
	int retorno = -1;
	int accountant = 0;

	if(list != NULL && size > 0 && averageSalary > 0)
	{
		for(int i = 0; i < size; i++)
		{
			if(!list[i].isEmpty && list[i].salary > averageSalary)
			{
				accountant++;
			}
		}
		printf("Hay %d empleado/s que superan el salario promedio\n",accountant);
		retorno = 0;
	}

	return retorno;
}


int totalAndAverageSalary(eEmployees list[],int size)
{
	int retorno = -1;
	float totalSalary = 0;
	float averageSalary = 0;
	float employeesAmount = 0;

	if(list != NULL && size > 0)
	{
		for(int i = 0; i < size; i++)
		{
			if(!list[i].isEmpty)
			{
				totalSalary += list[i].salary;
				employeesAmount++;
			}
		}
		retorno = 0;
		averageSalary = totalSalary / employeesAmount;
		printf("El Total de los salarios de los empleados es: %.2f\n",totalSalary);
		printf("Y el salario promedio es de: %.2f\n",averageSalary);
		uponAverageSalary(list,size,averageSalary);
	}

	return retorno;
}
