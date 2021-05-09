#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define LENNAME 51

typedef struct
{
	int id;
	char name[LENNAME];
	char lastname[LENNAME];
	float salary;
	int sector;
	int isEmpty;
}eEmployees;

int initEmployees(eEmployees employees[], int size);

int buscarLibre(eEmployees employees[], int size, int* index);

int ingresoDatos(int* id,char nombre[],char apellido[], float* sueldo, int* sector);

int findEmployeeById(eEmployees list[],int size, int id);

int removeEmployee(eEmployees list[],int size, int index);

#endif /* ARRAYEMPLOYEES_H_ */
