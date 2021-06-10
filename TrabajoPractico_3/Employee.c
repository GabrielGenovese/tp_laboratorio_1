#include "Employee.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "validaciones_UTN.h"

int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	if(this != NULL && id > -1)
	{
		(*this).id = id;
		retorno = 0;
	}
	return retorno;
}


int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = (*this).id;
		retorno = 0;
	}
	return retorno;
}


int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy((*this).nombre,nombre);
		retorno = 0;
	}
	return retorno;
}


int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,(*this).nombre);
		retorno = 0;
	}
	return retorno;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas > -1)
	{
		(*this).horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = (*this).horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}


int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo > -1)
	{
		(*this).sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = (*this).sueldo;
		retorno = 0;
	}
	return retorno;
}


Employee* employee_new()
{
	Employee* retorno = NULL;
	Employee* newEmployee = NULL;

	newEmployee = (Employee*)malloc(sizeof(Employee));

	if (newEmployee != NULL)
	{
		employee_setId(newEmployee,0);
		employee_setNombre(newEmployee," ");
		employee_setHorasTrabajadas(newEmployee,0);
		employee_setSueldo(newEmployee,0);

		retorno = newEmployee;
	}

	return retorno;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* retorno = NULL;
	Employee* newEmployeeWithParam = NULL;
	int id;
	int horasTrabajadas;
	int sueldo;


	newEmployeeWithParam = employee_new();

	if(newEmployeeWithParam != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		id = atoi(idStr);
		horasTrabajadas = atoi(horasTrabajadasStr);
		sueldo = atoi(sueldoStr);

		employee_setId(newEmployeeWithParam,id);
		employee_setNombre(newEmployeeWithParam,nombreStr);
		employee_setHorasTrabajadas(newEmployeeWithParam,horasTrabajadas);
		employee_setSueldo(newEmployeeWithParam,sueldo);

		retorno = newEmployeeWithParam;
	}
	return retorno;
}

int employee_dataRequest(char *nombre, char *horasTrabajadas, char *sueldo)
{
	int retorno = -1;
	char dataEmployee[3][128];
	int count = 0;

	if(nombre != NULL && horasTrabajadas != NULL && sueldo != NULL)
	{
		count +=validacionStringAlpha(*(dataEmployee+0),"Ingrese el nombre del empleado: ",128);
		count +=validacionStringNumerico(*(dataEmployee+1),"Ingrese las horas trabajadas del empleado: ",128);
		count +=validacionStringNumerico(*(dataEmployee+2),"Ingrese el sueldo del empleado: ",128);
		if(!count)
		{
			strcpy(nombre,*(dataEmployee));
			strcpy(horasTrabajadas,*(dataEmployee+1));
			strcpy(sueldo,*(dataEmployee+2));
		}
	}
	return retorno;
}

int printEmployee(Employee *empleado)
{
	int retorno = 1;

	if(empleado != NULL)
	{
		printf("%d \t",(*(empleado)).id);
		printf("%s \t",(*empleado).nombre);
		printf("%d \t",(*empleado).horasTrabajadas);
		printf("%d \n",(*empleado).sueldo);
		retorno = 0;
	}

	return retorno;
}


Employee* searchEmployeeByID(Employee *employee, int id)
{
	Employee* retorno = NULL;
	if(employee != NULL)
	{
		if((*employee).id == id)
		{
			retorno = employee;
		}
	}
	return retorno;
}
