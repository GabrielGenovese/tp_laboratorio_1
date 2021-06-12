#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/*brief Crea una estructura Employee inicializado en '0' o ' ' en memoria dinamica y devuelve un puntero a ella.
 * return Employee*.
 * */
Employee* employee_new();


/*brief crea una estructura Employee en memoria dinamica y le asigna los valores pasados por parametro y devuelve un
puntero a ella.
 * param1 idStr char*.
 * param2 nombreStr char*.
 * param3 horasTrabajadas char*.
 * param4 sueldoStr char*.
 * return Employee*.
 * */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();


/*brief Le asigna el id pasado por parametros a una estructura Employee* pasada por referencia
 * param1 this Employee*
 * param2 id int
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int employee_setId(Employee* this,int id);


/*brief Devuelve por referencia el id de la estructura Employee pasado por parametros
 * param1 this Employee*
 * param2 id int*
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int employee_getId(Employee* this,int* id);


/*brief Le asigna el Nombre pasado por parametros a una estructura Employee* pasada por referencia
 * param1 this Employee*
 * param2 nombre char*
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int employee_setNombre(Employee* this,char* nombre);


/*brief Devuelve por referencia el Nombre de la estructura Employee pasado por parametros
 * param1 this Employee*
 * param2 nombre char*
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int employee_getNombre(Employee* this,char* nombre);


/*brief Le asigna Las horas trabajadas pasadas por parametros a una estructura Employee* pasada por referencia
 * param1 this Employee*
 * param2 horasTrabajadas int
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);


/*brief Devuelve por referencia las horas trabajadas de la estructura Employee pasado por parametros
 * param1 this Employee*
 * param2 horasTrabajadas int*
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);


/*brief Le asigna el sueldo por parametros a una estructura Employee* pasada por referencia
 * param1 this Employee*
 * param2 sueldo int
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int employee_setSueldo(Employee* this,int sueldo);


/*brief Devuelve por referencia el sueldo de la estructura Employee pasado por parametros
 * param1 this Employee*
 * param2 sueldo int*
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int employee_getSueldo(Employee* this,int* sueldo);


/*brief Hace la validacion de datos para el alta de un nuevo empleado.
 * param1 nombre char*.
 * param2 horasTrabajadas char*.
 * param3 sueldo char*.
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int employee_dataRequest(char *nombre, char *horasTrabajadas, char *sueldo);


/*brief Imprime Todos los datos de la estructura Employee pasada por parametros
 * param1 empleado Employee*
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
int printEmployee(Employee *empleado);


/*brief Compara el id de la estructura Employee pasada por parametros con el parametro id y si son iguales devuelve un
puntero a esa estructura.
 * param1 employee Employee*
 * param2 id int
 * return retorna 0 si funciono correctamente o -1 si hubo algun problema.
 * */
Employee* compareEmployeeByID(Employee *employee, int id);


/*brief imprime la cabecera de los datos de un empleado
 * */
void printHeader();

/*brief decide cual de los 2 empleados pasados por parametros es mayor o menor dependiendo del ID
 * param1 employee1 void*
 * param2 employee2 void*
 * return retorna 1 si employee1 > employee2, retorna -1 si employee1 < employee2 y retorna 0 si son iguales
 * */
int sortByID(void* employee1,void* employee2);


/*brief decide cual de los 2 empleados pasados por parametros es mayor o menor dependiendo del Sueldo
 * param1 employee1 void*
 * param2 employee2 void*
 * return retorna 1 si employee1 > employee2, retorna -1 si employee1 < employee2 y retorna 0 si son iguales
 * */
int sortBySueldo(void* employee1,void* employee2);


/*brief decide cual de los 2 empleados pasados por parametros es mayor o menor dependiendo de las horas trabajadas
 * param1 employee1 void*
 * param2 employee2 void*
 * return retorna 1 si employee1 > employee2, retorna -1 si employee1 < employee2 y retorna 0 si son iguales
 * */
int sortByHorasTrabajadas(void* employee1,void* employee2);


/*brief decide cual de los 2 empleados pasados por parametros es mayor o menor dependiendo del nombre
 * param1 employee1 void*
 * param2 employee2 void*
 * return retorna 1 si employee1 > employee2, retorna -1 si employee1 < employee2 y retorna 0 si son iguales
 * */
int sortByNombre(void* employee1,void* employee2);

#endif // employee_H_INCLUDED
