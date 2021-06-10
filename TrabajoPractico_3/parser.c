#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char buffer[4][128];
	int dataReadedAmount;
	Employee* readedEmployee;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

		while(!feof(pFile))
		{
			dataReadedAmount = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

			if(dataReadedAmount == 4)
			{
				readedEmployee = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
				ll_add(pArrayListEmployee,readedEmployee);
				retorno = 0;
			}
			else
			{
				printf("No Se han podido leer todos los Datos del Archivo");
				break;
			}

		}


	}

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char buffer[4][128];
	int dataReadedAmount;
	Employee* readedEmployee;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

		while(!feof(pFile))
		{
			dataReadedAmount = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

			if(dataReadedAmount == 4)
			{
				readedEmployee = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
				ll_add(pArrayListEmployee,readedEmployee);
				retorno = 0;
			}
			else
			{
				printf("No Se han podido leer todos los Datos del Archivo");
				break;
			}

		}


	}

    return retorno;
}