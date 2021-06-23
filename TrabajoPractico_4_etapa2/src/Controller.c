#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "menus.h"
#include "validaciones_utn.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;
    int opcionesListaUsada;

    if(path != NULL && pArrayListEmployee != NULL)
    {
    	if(ll_isEmpty(pArrayListEmployee))
    	{
			pFile = fopen(path,"r");
			if(pFile != NULL)
			{
				if(!parser_EmployeeFromText(pFile,pArrayListEmployee))
				{
					printf("LOS DATOS SE CARGARON CORRECTAMENTE");
					retorno = 0;
				}
				else
				{
					printf("No se pudieron cargar los datos");
				}
				fclose(pFile);
			}
			else
			{
				printf("No se pudo abrir el archivo.");
			}
		}
    	else
    	{
    		menuListaUsada(&opcionesListaUsada,"Opcion: ");
    		do{
				switch(opcionesListaUsada)
				{
				case 1:
					ll_clear(pArrayListEmployee);
					break;
				case 2:
					controller_saveAsBinary("backup.bin",pArrayListEmployee);
					ll_clear(pArrayListEmployee);
					break;
				case 3:
					break;
				default:
					printf("opcion Invalida");
					break;
				}
    		}while(opcionesListaUsada > 3 || opcionesListaUsada < 1);
    	}
    }

    return retorno;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)//COMPLETAR
{
    int retorno = -1;
    FILE* pFile;
    int opcionesListaUsada;

    if(path != NULL && pArrayListEmployee != NULL)
    {
    	if(ll_isEmpty(pArrayListEmployee))
    	{
			pFile = fopen(path,"rb");
			if(pFile != NULL)
			{
				if(!parser_EmployeeFromBinary(pFile,pArrayListEmployee))
				{
					retorno = 0;
					printf("LOS DATOS SE CARGARON CORRECTAMENTE");
				}
				else
				{
					printf("No se pudieron cargar los datos");
				}
				fclose(pFile);
			}
			else
			{
				printf("No se pudo abrir el archivo.");
			}
    	}
    	else
    	{
    		menuListaUsada(&opcionesListaUsada,"Opcion: ");
				do{
					switch(opcionesListaUsada)
					{
					case 1:
						ll_clear(pArrayListEmployee);
						break;
					case 2:
						controller_saveAsBinary("backup.bin",pArrayListEmployee);
						ll_clear(pArrayListEmployee);
						break;
					case 3:
						break;
					default:
						printf("opcion Invalida");
						break;
					}
				}while(opcionesListaUsada > 3 || opcionesListaUsada < 1);
    	}


    }
    return retorno;
}


/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int lastEmployeeId;
	int index;
	Employee *lastEmployee;
	int retorno = -1;
	char id[128];
	char nombre[128];
	char horasTrabajadas[128];
	char sueldo[128];
	Employee *newEmployee;

	if(pArrayListEmployee != NULL)
	{
		if(!ll_isEmpty(pArrayListEmployee))
		{
			index = ll_len(pArrayListEmployee) - 1;
			lastEmployee = ll_get(pArrayListEmployee,index);
			employee_getId(lastEmployee,&lastEmployeeId);
			itoa(lastEmployeeId+1,id,10);
		}
		else
		{
			strcpy(id,"1");
		}
		employee_dataRequest(nombre,horasTrabajadas,sueldo);
		newEmployee = employee_newParametros(id,nombre,horasTrabajadas,sueldo);

		if(newEmployee != NULL)
		{
			printEmployee(newEmployee);
			ll_add(pArrayListEmployee,newEmployee);
			retorno = 0;
		}
		else
		{
			printf("No se ha podido aderir este empleado");
		}

	}

	return retorno;
}


/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int opcion = 0;
    int id;
    Employee* employeeToModify = NULL;
    Employee* employee = NULL;
    int lenList;
    int auxNum;
    char auxNombre[128];

    if(pArrayListEmployee != NULL)
    {
    	if(!ll_isEmpty(pArrayListEmployee))
    	{
    		validacionNumeroEntero(&id,"Ingrese el ID del empleado a modificar: ");
    		lenList = ll_len(pArrayListEmployee);

    		for(int i = 0; i < lenList; i++)
    		{
    			employee = ll_get(pArrayListEmployee,i);
    			if(compareEmployeeByID(employee,id) != NULL)
    			{
    				employeeToModify = compareEmployeeByID(employee,id);
    				break;
    			}
    		}
    		if(employeeToModify != NULL)
    		{
				do
				{
					printEmployee(employeeToModify);
					menuModificar(&opcion,"opcion: ");
					switch(opcion)
					{
					case 1:
						validacionStringAlpha(auxNombre,"Ingrese el nombre del empleado: ",128);
						employee_setNombre(employeeToModify,auxNombre);
						break;
					case 2:
						validacionNumeroEntero(&auxNum,"Ingrese las horas trabajadas del empleado: ");
						employee_setHorasTrabajadas(employeeToModify,auxNum);
						break;
					case 3:
						validacionNumeroEntero(&auxNum,"Ingrese el sueldo del empleado: ");
						employee_setSueldo(employeeToModify,auxNum);
						break;
					case 4:
						break;
					default:
						printf("opcion Invalida");
						break;
					}
				}while(opcion != 4);

    		}
    		else
    		{
    			printf("No se a encontrado un empleado con ese ID");
    		}

    	}
    	else
    	{
    		printf("No hay empleados que modificar");
    	}
    }
    return retorno;
}


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int id;
	int lenList;
	Employee* employee;
	Employee* employeeToRemove;
	char YesNo[2];
	int index;

	if(pArrayListEmployee != NULL)
	{
		if(!ll_isEmpty(pArrayListEmployee))
		{
			validacionNumeroEntero(&id,"Ingrese el ID del empleado a modificar: ");
			lenList = ll_len(pArrayListEmployee);

			for(int i = 0; i < lenList; i++)
			{
				employee = ll_get(pArrayListEmployee,i);
				if(compareEmployeeByID(employee,id) != NULL)
				{
					employeeToRemove = compareEmployeeByID(employee,id);
					index = i;
					break;
				}
			}
			if(employeeToRemove != NULL)
			{
				printEmployee(employeeToRemove);
				validacionStringAlpha(YesNo,"¿Esta seguro que desea eliminarlo? si/no: ",3);
				strlwr(YesNo);
				if(strcmp(YesNo,"si") == 0 || strcmp(YesNo,"no") == 0  )
				{
					if(strcmp(YesNo,"si") == 0)
					{
						ll_remove(pArrayListEmployee,index);
					}
				}
				else
				{
					printf("opcion Invalida");
				}
			}
			else
			{
				printf("No se a encontrado un empleado con ese ID");
			}
		}
		else
		{
			printf("No hay empleados que eliminar");
		}
	}
    return retorno;
}


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int lenList;
    Employee* employeeAux;

    if(pArrayListEmployee != NULL)
    {
    	if(!ll_isEmpty(pArrayListEmployee))
    	{
			lenList = ll_len(pArrayListEmployee);
			printHeader();
			for(int i = 0; i < lenList; i++)
			{
				employeeAux = ll_get(pArrayListEmployee,i);
				printEmployee(employeeAux);
			}
    	}
    	else
    	{
    		printf("No hay empleados que listar\n");
    	}

    	retorno = 0;
    }

    return retorno;
}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int res;
	int opcion;
	int upDown;

	if(pArrayListEmployee!= NULL)
	{
		if(!ll_isEmpty(pArrayListEmployee))
		{

			do
			{
			menuOrdenar(&opcion,"Opcion: ");
			if(opcion < 5 && opcion > 0)
			{
				do{
					menuAscendenteDescendente(&upDown,"Opcion: ");
					switch(upDown)
					{
					case 1:
						upDown = 1;
						break;
					case 2:
						upDown = 0;
						break;
					default:
						upDown = -1;
						printf("\nOpcion Invalida\n");
						break;
					}
				}while(upDown == -1);
			}
			printf("upDown: %d",upDown);
			switch(opcion)
			{
			case 1:
				res = ll_sort(pArrayListEmployee,sortByID,upDown); // 1 ascendente /-1 descendente
				if (!res)
				{
					printf("\nLista Ordenada Correctamente por ID.\n");
				}
				else
				{
					printf("\nError al ordenar\n");
				}
				break;
			case 2:
				res = ll_sort(pArrayListEmployee,sortByNombre,upDown); // 1 ascendente /-1 descendente
				if (!res)
				{
					printf("\nLista Ordenada Correctamente por Nombre.\n");
				}
				else
				{
					printf("\nError al ordenar\n");
				}
				break;
			case 3:
				res = ll_sort(pArrayListEmployee,sortByHorasTrabajadas,upDown); // 1 ascendente /-1 descendente
				if (!res)
				{
					printf("\nLista Ordenada Correctamente por Horas Trabajadas.\n");
				}
				else
				{
					printf("\nError al ordenar\n");
				}
				break;
			case 4:
				res = ll_sort(pArrayListEmployee,sortBySueldo,upDown); // 1 ascendente /-1 descendente
				if (!res)
				{
					printf("\nLista Ordenada Correctamente por Sueldo.\n");
				}
				else
				{
					printf("\nError al ordenar\n");
				}
				break;
			case 5:
				break;
			default:
				printf("\nOpcion Invalida\n");
				opcion = 0;
				break;
			}
			}while(!opcion);


		}
		else
		{
			printf("No hay empleados que Ordenar.");
		}
	}

	return retorno;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;
	int id;
	int horasTrabajadas;
	int sueldo;
	char nombre[128];
	Employee * actualEmployee;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		if(!ll_isEmpty(pArrayListEmployee))
		{
			pFile = fopen(path,"w");

			if(pFile != NULL)
			{
				fprintf(pFile,"ID,Nombre,HorasTrabajadas,Sueldo\n");

				for(int i = 0; i < ll_len(pArrayListEmployee); i++)
				{
					actualEmployee = ll_get(pArrayListEmployee,i);
					if(actualEmployee != NULL)
					{
						employee_getId(actualEmployee,&id);
						employee_getNombre(actualEmployee,nombre);
						employee_getHorasTrabajadas(actualEmployee,&horasTrabajadas);
						employee_getSueldo(actualEmployee,&sueldo);

						fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
					}
				}
				printf("Se guardaron los datos exitosamente en %s",path);
				fclose(pFile);
			}
			else
			{
				printf("No se pudo abrir %s",path);
			}
		}
		else
		{
			printf("No hay nada que imprimir");
		}
	}

    return retorno;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pFile;
	Employee * actualEmployee;
	int cantidadEscrita;
	int flagbreak = 0;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		if(!ll_isEmpty(pArrayListEmployee))
		{
			pFile = fopen(path,"wb");

			if(pFile != NULL)
			{
				for(int i = 0; i < ll_len(pArrayListEmployee); i++)
				{
					actualEmployee = ll_get(pArrayListEmployee,i);
					if(actualEmployee != NULL)
					{
						cantidadEscrita = fwrite(actualEmployee,sizeof(Employee),1,pFile);
						if(cantidadEscrita < 1)
						{
							printf("Error al guardar en %s",path);
							flagbreak = 1;
							break;
						}
					}
				}
				if(!flagbreak)
				{
					printf("Se guardaron los datos exitosamente en %s",path);
				}
				fclose(pFile);
			}
			else
			{
				printf("No se pudo abrir %s",path);
			}
		}
		else
		{
			printf("No hay nada que imprimir");
		}
	}

	return retorno;
}
