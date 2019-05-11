#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
#define TEXT_SIZE 20
/*
1*  REEMPLAZAR LOS TRES TIPOS DE NOMBRES "EMPLEADOS X EL QUE QUIERAS(todo mayuscula)"
    "Empleados x el que Quieras(primer letra en mayuscula)""empleadoss x que quieras(todo minuscula)"
*/
typedef struct
{
    int idUnico;
    int isEmpty;
    //-----------------
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];
    float sueldo;
    int sector;




}Empleados;


#endif // EMPLEADOS_H_INCLUDED

int empleados_Inicializar(Empleados array[], int size);                                    //cambiar empleados
int empleados_buscarEmpty(Empleados array[], int size, int* posicion);                    //cambiar empleados
int empleados_buscarID(Empleados array[], int size, int valorBuscado, int* posicion);                    //cambiar empleados
int empleados_buscarInt(Empleados array[], int size, int valorBuscado, int* posicion);                    //cambiar empleados
int empleados_buscarString(Empleados array[], int size, char* valorBuscado, int* indice);                    //cambiar empleados
int empleados_alta(Empleados array[], int size, int* contadorID);                          //cambiar empleados
int empleados_baja(Empleados array[], int sizeArray);                                      //cambiar empleados
int empleados_bajaValorRepetidoInt(Empleados array[], int sizeArray, int valorBuscado);
int empleados_modificar(Empleados array[], int sizeArray);                                //cambiar empleados
int empleados_ordenarPorDobleCriterio(Empleados array[],int size, int orderFirst, int orderSecond);                                  //cambiar empleados
int empleados_listar(Empleados array[], int size);                      //cambiar empleados
void empleados_mock(Empleados arrayEmpleados[], int size,int *contadorId);                      //cambiar empleados
void MenuEmpleados();
void MenuMod();
int InformeEmpleado(Empleados lista[],int size);
int emp_totalPromedio(Empleados array[] , int size);
int empleados_listar2(Empleados array[], int size) ;
int emp_verificacion(Empleados lista[], int size);
