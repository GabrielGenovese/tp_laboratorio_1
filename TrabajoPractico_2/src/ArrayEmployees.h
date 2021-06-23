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


/** \brief To indicate that all position in the array are empty,this function put the flag (isEmpty)
* in TRUE in all position of the array.
* \param1 list Employee* Pointer to array of employees.
* \param2 len int Array length.
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
* */
int initEmployees(eEmployees employees[], int size);


/*\brief Search for an empty position (isEmpty == 1), When it is found return the index for references
 * \param1  list Employee* Pointer to array of employees.
 * \param2 len int Array length.
 * \return int Return (-1) if Error - (0) if Ok.
 * */
int searchFree(eEmployees employees[], int size, int* index);


/*\brief Make the validation of data entry, All parameters go for reference.
 * \param1 char name[].
 * \param2 char lastName[].
 * \param3 float* salary.
 * \param4 int* Sector.
 * \return int Return (-1) if Error - (0) if Ok.
 * */
int dataEntry(char name[],char lastName[], float* salary, int* sector);


/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param1 list employee*
* \param2 len int
* \param3 freeIndex int
* \param4 id int
* \param5 name[] char
* \param6 lastName[] char
* \param7 salary float
* \param8 sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or withoutfree space] - (0) if Ok
*/
int addEmployee(eEmployees list[], int size, int freeIndex, int *id, char name[], char lastName[], float salary, int sector);


/** \brief find an Employee by Id en returns the index position in array.
*
* \param1 list Employee*
* \param2 len int
* \param3 id int
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*/
int findEmployeeById(eEmployees list[],int size, int id);


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param index int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*/
int removeEmployee(eEmployees list[],int size, int index);


/**\brief Sort the elements in the array employees upward by lastName and Sector.
* \param1 list Employee*
* \param2 len int
*  \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
* */
int upwardOrdering(eEmployees list[], int size);


/**\brief Sort the elements in the array employees downward by lastName and Sector.
* \param1 list Employee*
* \param2 len int
*  \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
* */
int descendingOrdering(eEmployees list[],int size);


/**\brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
* \param1 list Employee*
* \param2 len int
* \param3 order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortEmployees(eEmployees list[],int size, int order);


/**\brief Print titles of values (ID,Name,LastName,Salary,Sector) orderly manner.
 * */
void headLine();


/**\brief List one employee from the employees array.
 * \param1 list[] eEmployees
 * \param2 index int. Where is the Employee to list.
 * \return int Return (-1) if Error [Invalid index or NULL pointer] - (0) if Ok.
 * */
int listOne(eEmployees list[], int index);


/**\brief List all the employees from the employees array.
 * \param1 list[] eEmployees
 * \param2 len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
 * */
int listAll(eEmployees list[], int size);


/**\brief Calculate and print how many employees are upon average salary.
 * \param1 list[] eEmployees
 * \param2 len int
 * \param3 averageSalary int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
 * */
int uponAverageSalary(eEmployees list[], int size, int averageSalary);


/**\brief Calculate and print the total and Average Salary.
 * \param1 list[] eEmployees
 * \param2 len int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok.
 * */
int totalAndAverageSalary(eEmployees list[],int size);


#endif /* ARRAYEMPLOYEES_H_ */
