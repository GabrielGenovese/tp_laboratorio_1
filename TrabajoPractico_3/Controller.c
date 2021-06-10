#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "menus.h"
#include "validaciones_utn.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
    	pFile = fopen(path,"r");
    	if(pFile != NULL)
    	{
    		if(!parser_EmployeeFromBinary(pFile,pArrayListEmployee))
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
    return retorno;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
    	pFile = fopen(path,"rb");
    	if(pFile != NULL)
    	{
    		if(!parser_EmployeeFromBinary(pFile,pArrayListEmployee))
    		{
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
			index = (*pArrayListEmployee).size - 1;
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
    			if(searchEmployeeByID(employee,id) != NULL)
    			{
    				employeeToModify = searchEmployeeByID(employee,id);
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
				if(searchEmployeeByID(employee,id) != NULL)
				{
					employeeToRemove = searchEmployeeByID(employee,id);
					index = i;
					break;
				}
			}
			if(employeeToRemove != NULL)
			{
				printEmployee(employeeToRemove);
				validacionStringAlpha(YesNo,"�Esta seguro que desea eliminarlo? si/no: ",3);
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
    return 1;
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
    return 1;
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
    return 1;
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
    return 1;
}


