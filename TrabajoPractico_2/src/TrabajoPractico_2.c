#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "validaciones_UTN.h"
#include "menus.h"

#define MAX_EMPLOYEES 1000


int main(void) {
	setbuf(stdout, NULL);

	int opcionPrincipal;
	eEmployees employeesList[MAX_EMPLOYEES];

	int freeSlot;
	int opcionSecundaria;
	int index;
	int flagEmployeeEntry = 0;

	int id = 1;
	char name[LENNAME];
	char lastName[LENNAME];
	float salary;
	int sector;
	int ordering;

	initEmployees(employeesList,MAX_EMPLOYEES);

	do
	{
		menu(&opcionPrincipal,"Elija una opcion: ");

		switch(opcionPrincipal)
		{
		case 1:
			if(!searchFree(employeesList,MAX_EMPLOYEES,&freeSlot))
			{
				dataEntry(name,lastName,&salary,&sector);
				if(!addEmployee(employeesList,MAX_EMPLOYEES,freeSlot,&id,name,lastName,salary,sector))
				{
					listOne(employeesList,freeSlot);
					printf("Empleado Agregado Correctamente\n");
				}
				flagEmployeeEntry = 1;
			}
			else
			{
				printf("No hay ningun espacio Libre\n");
			}
			break;
		case 2:
			if(flagEmployeeEntry == 1)
			{
				validacionNumeroEntero(&id,"Ingrese el ID del empleado a modificar: ");
				index = findEmployeeById(employeesList,MAX_EMPLOYEES,id);
				if(index != -1 )
				{
					listOne(employeesList,index);
					do
					{
						menuModificar(&opcionSecundaria,"Elija que quiere modificar: ");
						switch(opcionSecundaria)
						{
						case 1:
							validacionStringAlpha(employeesList[index].name,"Ingrese el nuevo nombre: ",51,"Nombre Incorrecto");
							break;
						case 2:
							validacionStringAlpha(employeesList[index].lastname,"Ingrese el nuevo apellido: ",51,"Apellido Incorrecto");
							break;
						case 3:
							validacionNumeroFloatConMinMax(&employeesList[index].salary,0,1000000,"Ingrese el nuevo sueldo: ");
							break;
						case 4:
							validacionNumeroEntero(&employeesList[index].sector, "Ingrese el nuevo sector: ");
							break;
						case 5:
							break;
						default:
							printf("Opcion Incorrecta\n");
							break;
						}
						printf("Empleado modificado\n");
						listOne(employeesList,index);
					}while(opcionSecundaria != 5);
				}
				else
				{
					printf("Ingrese un numero de ID valido.\n");
				}
			}
			else
			{
				printf("No se ha Ingresado Ningun Empleado \n");
			}

			break;
		case 3:
			if (flagEmployeeEntry == 1)
			{
				validacionNumeroEntero(&id,"Ingrese el ID del empleado a eliminar: ");
				index = findEmployeeById(employeesList,MAX_EMPLOYEES,id);
				if(index != -1 )
				{
					listOne(employeesList,index);
					if(!removeEmployee(employeesList,MAX_EMPLOYEES,index))
					{
						printf("Empleado eliminado\n");
					}
				}
				else
				{
					printf("Numero de ID invalido.\n");
				}
			}
			else
			{
				printf("No se ha Ingresado Ningun Empleado\n");
			}
			break;
		case 4:
			if(flagEmployeeEntry == 1)
			{
				do
				{
					menuInformar(&opcionSecundaria, "Opcion: ");
					switch(opcionSecundaria)
					{
					case 1:
						validacionNumeroEnteroConMinMax(&ordering,0,1,"Ingrese 1 para que se Ordene de manera ascendente o 0 para que se ordene de manera descendente: ");
						sortEmployees(employeesList,MAX_EMPLOYEES,ordering);
						listAll(employeesList,MAX_EMPLOYEES);
						break;
					case 2:
						totalAndAverageSalary(employeesList,MAX_EMPLOYEES);
						break;
					case 3:
						break;
					default:
						printf("Opcion Incorrecta\n");
						break;
					}
				}while(opcionSecundaria != 3);
			}
			else
			{
				printf("No se ha Ingresado Ningun Empleado ");
			}
			break;
		case 5:
			break;
		default:
			printf("Opcion Incorrecta\n");
			break;
		}

	}while(opcionPrincipal != 5);


	return EXIT_SUCCESS;
}
