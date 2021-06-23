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

void printHeader()
{
	printf("%10s|","ID");
	printf("%30s|","nombre");
	printf("%20s|","Horas Trabajadas");
	printf("%15s|\n","sueldo");
}

int printEmployee(Employee *empleado)
{
	int retorno = 1;
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;

	if(empleado != NULL)
	{
		employee_getId(empleado,&id);
		employee_getNombre(empleado,nombre);
		employee_getHorasTrabajadas(empleado,&horasTrabajadas);
		employee_getSueldo(empleado,&sueldo);

		printf("%10d|",id);
		printf("%30s|",nombre);
		printf("%20d|",horasTrabajadas);
		printf("%15d|\n",sueldo);
		retorno = 0;
	}

	return retorno;
}


Employee* compareEmployeeByID(Employee *employee, int id)
{
	Employee* retorno = NULL;
	int EmpleadoActual;
	if(employee != NULL)
	{
		employee_getId(employee,&EmpleadoActual);
		if(EmpleadoActual == id)
		{
			retorno = employee;
		}
	}
	return retorno;
}


int sortByID(void* employee1,void* employee2)
{
	int retorno = 0;
	Employee * empl1 = NULL;
	Employee * empl2 = NULL;
	int idEmp1;
	int idEmp2;



	if(employee1 != NULL && employee2 != NULL )
	{
		empl1 = employee1;
		empl2 = employee2;

		employee_getId(empl1,&idEmp1);
		employee_getId(empl2,&idEmp2);
		if(idEmp1 > idEmp2)
		{
			retorno = 1;
		}
		else
		{
			if(idEmp1 < idEmp2)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}


int sortBySueldo(void* employee1,void* employee2)
{
	int retorno = 0;
	int sueldoEmp1;
	int sueldoEmp2;
	Employee* empl1;
	Employee* empl2;

	if(employee1 != NULL && employee2 != NULL )
	{
		empl1 = employee1;
		empl2 = employee2;

		employee_getSueldo(empl1,&sueldoEmp1);
		employee_getSueldo(empl2,&sueldoEmp2);

		if(sueldoEmp1 > sueldoEmp2)
		{
			retorno = 1;
		}
		else
		{
			if(sueldoEmp1 < sueldoEmp2)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}


int sortByHorasTrabajadas(void* employee1,void* employee2)
{
	int retorno = 0;
	int horasEmp1;
	int horasEmp2;
	Employee* empl1;
	Employee* empl2;

	if(employee1 != NULL && employee2 != NULL )
	{
		empl1 = employee1;
		empl2 = employee2;

		employee_getHorasTrabajadas(empl1,&horasEmp1);
		employee_getHorasTrabajadas(empl2,&horasEmp2);

		if(horasEmp1 > horasEmp2)
		{
			retorno = 1;
		}
		else
		{
			if(horasEmp1 < horasEmp2)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}


int sortByNombre(void* employee1,void* employee2)
{
	int retorno = 0;
	char nombreEmp1[128];
	char nombreEmp2[128];
	Employee* empl1;
	Employee* empl2;

	if(employee1 != NULL && employee2 != NULL )
	{

		empl1 = employee1;
		empl2 = employee2;

		employee_getNombre(empl1,nombreEmp1);
		employee_getNombre(empl2,nombreEmp2);

		retorno = strcmp(nombreEmp1,nombreEmp2);
	}

	return retorno;
}
