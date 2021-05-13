#define LENNAME 51

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

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

int addEmployee(eEmployees list[], int size, int freeIndex, int id, char nombre[], char apellido[], float sueldo, int sector);

int findEmployeeById(eEmployees list[],int size, int id);

int removeEmployee(eEmployees list[],int size, int index);

int upwardOrdering(eEmployees list[], int size);

int descendingOrdering(eEmployees list[],int size);

int sortEmployees(eEmployees list[],int size, int order);

int headLine();

int listOne(eEmployees list[], int index);

int listAll(eEmployees list[], int size);

int uponAverageSalary(eEmployees list[], int size, int averageSalary);

int totalAndAverageSalary(eEmployees list[],int size);


#endif /* ARRAYEMPLOYEES_H_ */
