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
	int indice;
	int banderaIngresado = 0;

	int id;
	char nombre[LENNAME];
	char apellido[LENNAME];
	float sueldo;
	int sector;
	int ordenamiento;

	initEmployees(employeesList,MAX_EMPLOYEES);

	do
	{
		menu(&opcionPrincipal,"Elija una opcion: ");

		switch(opcionPrincipal)
		{
		case 1:
			if(!buscarLibre(employeesList,MAX_EMPLOYEES,&freeSlot))
			{
				ingresoDatos(&id,nombre,apellido,&sueldo,&sector);
				addEmployee(employeesList,MAX_EMPLOYEES,freeSlot,id,nombre,apellido,sueldo,sector);
				banderaIngresado = 1;
			}
			else
			{
				printf("No hay ningun espacio Libre");
			}
			break;
		case 2:
			if(banderaIngresado == 1)
			{
				validacionNumeroEntero(&id,"Ingrese el ID del empleado a modificar: ");
				indice = findEmployeeById(employeesList,MAX_EMPLOYEES,id);
				if(indice != -1 )
				{
					do
					{
						menuModificar(&opcionSecundaria,"Elija que quiere modificar: ");
						switch(opcionSecundaria)
						{
						case 1:
							validacionString51C(employeesList[indice].name,"Ingrese el nuevo nombre: ");
							break;
						case 2:
							validacionString51C(employeesList[indice].lastname,"Ingrese el nuevo apellido: ");
							break;
						case 3:
							validacionNumeroFloatConMinMax(&employeesList[indice].salary,0,1000000,"Ingrese el nuevo sueldo: ");
							break;
						case 4:
							validacionNumeroEntero(&employeesList[indice].sector, "Ingrese el nuevo sector: ");
							break;
						case 5:
							break;
						default:
							printf("Opcion Incorrecta");
							break;
						}
					}while(opcionSecundaria != 5);
				}
				else
				{
					printf("Ingrese un numero de ID valido.");
				}
			}
			else
			{
				printf("No se ha Ingresado Ningun Empleado ");
			}

			break;
		case 3:
			if (banderaIngresado == 1)
			{
				validacionNumeroEntero(&id,"Ingrese el ID del empleado a eliminar: ");
				indice = findEmployeeById(employeesList,MAX_EMPLOYEES,id);
				if(indice != -1 )
				{
					removeEmployee(employeesList,MAX_EMPLOYEES,indice);
				}
				else
				{
					printf("Numero de ID invalido.");
				}
			}
			else
			{
				printf("No se ha Ingresado Ningun Empleado ");
			}
			break;
		case 4:
			if(banderaIngresado == 1)
			{
				do
				{
					menuInformar(&opcionSecundaria, "Opcion: ");
					switch(opcionSecundaria)
					{
					case 1:
						validacionNumeroEnteroConMinMax(&ordenamiento,0,1,"Ingrese 1 para que se Ordene de manera ascendente o 0 para que se ordene de manera descendente: ");
						sortEmployees(employeesList,MAX_EMPLOYEES,ordenamiento);
						listAll(employeesList,MAX_EMPLOYEES);
						break;
					case 2:
						totalAndAverageSalary(employeesList,MAX_EMPLOYEES);
						break;
					case 3:
						break;
					default:
						printf("Opcion Incorrecta");
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
			printf("Opcion Incorrecta");
			break;
		}

	}while(opcionPrincipal != 5);


	return EXIT_SUCCESS;
}
