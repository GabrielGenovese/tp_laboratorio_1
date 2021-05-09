#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "menus.h"

#define MAX_EMPLOYEES 1000


int main(void) {

	int opcion;
	eEmployees employeesList[MAX_EMPLOYEES];
	int freeSlot;
	int opcionModificar;
	int indice;

	int id;
	char nombre[LENNAME];
	char apellido[LENNAME];
	float sueldo;
	int sector;

	initEmployees(employeesList,MAX_EMPLOYEES);

	do
	{
		menu(&opcion,"Elija una opcion: ");

		switch(opcion)
		{
		case 1:
			if(!buscarLibre(employeesList,MAX_EMPLOYEES,&freeSlot))
			{
				ingresoDatos(&id,nombre,apellido,&sueldo,sector);
				addEmployee(employeesList,MAX_EMPLOYEES,freeSlot,id,nombre,apellido,sueldo,sector);
			}
			else
			{
				printf("No hay ningun espacio Libre");
			}
			break;
		case 2:
			validacionNumeroEntero(&id,"Ingrese el ID del empleado a modificar: ");
			indice = findEmployeeById(employeesList,MAX_EMPLOYEES,id);
			if(indice != -1 )
			{
				do
				{
					menuModificar(&opcionModificar,"Elija que quiere modificar: ");
					switch(opcionModificar)
					{
					case 1:
						validacionString51C(employeesList[indice].name,"Ingrese el nuevo nombre: ");
						break;
					case 2:
						validacionString51C(employeesList[indice].lastname,"Ingrese el nuevo apellido: ");
						break;
					case 3:
						validacionNumeroFloatConMinMax(employeesList[indice].salary,0,1000000,"Ingrese el nuevo sueldo: ");
						break;
					case 4:
						validacionNumeroEntero(employeesList[indice].sector, "Ingrese el nuevo sector: ");
						break;
					case 5:
						break;
					default:
						printf("Opcion Incorrecta");
						break;
					}
				}while(opcionModificar != 5);
			}
			else
			{
				printf("Ingrese un numero de ID valido.");
			}
			break;
		case 3:
			validacionNumeroEntero(&id,"Ingrese el ID del empleado a eliminar: ");
			indice = findEmployeeById(employeesList,MAX_EMPLOYEES,id);
			if(indice != -1 )
			{
				removeEmployee(employeesList,MAX_EMPLOYEES,indice);
			}
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			printf("Opcion Incorrecta");
			break;
		}

	}while(opcion != 5);


	return EXIT_SUCCESS;
}
