#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "utn.h"



 //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array empleados Array of empleados
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int empleados_Inicializar(Empleados array[], int size)                                    //cambiar empleados
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array empleados Array de empleados
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int empleados_buscarEmpty(Empleados array[], int size, int* posicion)                    //cambiar empleados
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array empleados Array de empleados
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int empleados_buscarID(Empleados array[], int size, int valorBuscado, int* posicion)                    //cambiar empleados
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array empleados Array de empleados
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int empleados_buscarInt(Empleados array[], int size, int valorBuscado, int* posicion)                    //cambiar empleados
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].sector==valorBuscado)                                                   //cambiar campo sector
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array empleados Array de empleados
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int empleados_buscarString(Empleados array[], int size, char* valorBuscado, int* indice)                    //cambiar empleados
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].nombre,valorBuscado)==0)                                        //cambiar campo nombre
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array empleados Array de empleados
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int empleados_alta(Empleados array[], int size, int* contadorID)                          //cambiar empleados
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(empleados_buscarEmpty(array,size,&posicion)==-1)                          //cambiar empleados
        {
            printf("\nNo hay lugares vacios\n");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\nSector: ","\nError",1,sizeof(int),1,10,1,&array[posicion].sector);           //mensaje + cambiar campo sector
            utn_getFloat("\nSueldo: ","\nError",1,sizeof(float),0,1,1,&array[posicion].sueldo);             //mensaje + cambiar campo sueldo
            utn_getName("\nNombre: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);                      //mensaje + cambiar campo nombre
            utn_getTexto("\nApellido: ","\nError",1,TEXT_SIZE,1,array[posicion].apellido);                 //mensaje + cambiar campo apellido
            printf("\n Posicion: %d\n ID: %d\n sector: %d\n sueldo: %f\n nombre: %s\n apellido: %s",
                   posicion, array[posicion].idUnico,array[posicion].sector,array[posicion].sueldo,array[posicion].nombre,array[posicion].apellido);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array empleados Array de empleados
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int empleados_baja(Empleados array[], int sizeArray)                                      //cambiar empleados
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(empleados_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            array[posicion].sector=0;                                                               //cambiar campo sector
            array[posicion].sueldo=0;                                                             //cambiar campo sueldo
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo nombre
            strcpy(array[posicion].apellido,"");                                               //cambiar campo apellido
            retorno=0;
        }
    }
    return retorno;
}
////////////////////////////////////////
int emp_verificacion(Empleados lista[], int size)
{
    int i;
    int retorno = 0;
    for(i = 0;i<size;i++)
    {
        if(lista[i].isEmpty != 1)
        {

            retorno = 1;
        }
    }
    return retorno;
}
//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array empleados Array de empleados
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int empleados_bajaValorRepetidoInt(Empleados array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;                                                                   //cambiar campo id
                array[i].sector=0;                                                               //cambiar campo sector
                array[i].sueldo=0;                                                             //cambiar campo sueldo
                strcpy(array[i].nombre,"");                                                   //cambiar campo nombre
                strcpy(array[i].apellido,"");                                               //cambiar campo apellido
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array empleados Array de empleados
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int empleados_modificar(Empleados array[], int sizeArray)                                //cambiar empleados
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    int opcion;
    if(array!=NULL && sizeArray>0)
    {

        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(empleados_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {    MenuMod();   //copiar printf de alta

                utn_getUnsignedInt("",                   //cambiar
                "\nError",1,sizeof(int),1,6,1,&opcion);
                switch(opcion)
                {
                    case 1:
                        utn_getName("Ingrese nuevo nombre : ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);          //mensaje + cambiar campo sector
                        break;
                    case 2:
                        utn_getName("Ingrese nuevo apellido: ","\nError",1,TEXT_SIZE,1,array[posicion].nombre);              //mensaje + cambiar campo sueldo
                        break;
                    case 3:
                           utn_getFloat("Ingrese nuevo sueldo: ","\nError",1,sizeof(float),0,1,1,&array[posicion].sueldo);                   //mensaje + cambiar campo nombre
                        break;
                    case 4:
                        utn_getUnsignedInt("\n: ","\nError",1,sizeof(int),1,1,1,&array[posicion].sector);             //mensaje + cambiar campo apellido
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!=5);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array empleados Array de empleados
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int empleados_ordenarPorDobleCriterio(Empleados array[],int size, int orderFirst, int orderSecond)                              //cambiar empleados
{
    int retorno=-1;
    int i;
    Empleados buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].nombre,array[i+1].nombre) < 0) && orderFirst) ||
                    ((strcmp(array[i].nombre,array[i+1].nombre) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }
                else if(strcmp(array[i].nombre,array[i+1].nombre) == 0)
                {
                    if( ((array[i].sueldo < array[i+1].sueldo) && orderSecond) ||
                        ((array[i].sueldo > array[i+1].sueldo) && !orderSecond) )
                    {
                        flagSwap=1;
                        buffer = array[i];
                        array[i] = array[i+1];
                        array[i+1] = buffer;
                    }
                }
            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array empleados Array de empleados
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int empleados_listar(Empleados array[], int size)                      //cambiar empleados
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n---------------------------------------\n");
                printf("\nsector: %d\napellido: %s\n\n",array[i].sector,array[i].apellido);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}
/////////////////////////////////////////////////////////////////////////////
/** \brief Lista los elementos de un array
* \param array empleados Array de empleados
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int empleados_listar2(Empleados array[], int size)                      //cambiar empleados
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n---------------------------------------\n");
                printf("\nNombre: %s\napellido: %s\nSueldo: %f\nSector: %d\nID: %d\n",array[i].nombre,
                       array[i].apellido,
                       array[i].sueldo,
                       array[i].sector,
                       array[i].idUnico);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}
/////////////////////////////////////////////////////////////////////////////
int InformeEmpleado(Empleados lista[],int size)
{
   int i,j;
   int retorno;
   Empleados buffer;

   for(i = 0;i < size-1;i++)
   {
       for(j =i+1;j < size-1;j++)
       {
           if(strcmp(lista[i].apellido,lista[j].apellido)> 0)
           {
               buffer = lista[i];
               lista[i] = lista[j];
               lista[j] = buffer;
               retorno = 0;
           }
       }
   }
   empleados_listar(lista,size);
   emp_totalPromedio(lista,size);
   return retorno;
}
/////////////////////////////////////////////////////////////////////////////
int emp_totalPromedio(Empleados array[] , int size)
{
    int i,j;
    int retorno = -1;
    float buffer = 0;
    float promedio;
    float total;
    for(i = 0;i<size;i++)
    {
        buffer += array[i].sueldo;
        retorno = 0;
    }
    total = buffer;
    promedio = buffer/size;
    for(j = 0;j<size;j++)
    {
        if(array[j].sueldo > promedio)
        {
                printf("\n------------Empleado que supera el promedio-------------\n");
                printf("\nNombre: %s\napellido: %s\nSueldo: %f\nSector: %d\nID: %d\n",array[j].nombre,
                array[j].apellido,
                array[j].sueldo,
                array[j].sector,
                array[j].idUnico);
        }
    }
    printf("\n------------Total y promedios de sueldos-------------\n");
    printf("\n\nTotal: %f\nPromedios: %f\n",total,promedio);
    return retorno;
}
void empleados_mock(Empleados arrayEmpleados[], int size,int *contadorId)                      //cambiar empleados
{
    //*******************************************************************
    int aux = 0;
    arrayEmpleados[0].idUnico=0;
    arrayEmpleados[0].isEmpty=0;
    arrayEmpleados[0].sector=20;
    arrayEmpleados[0].sueldo=10;
    strcpy(arrayEmpleados[0].apellido,"Barrios");
    strcpy(arrayEmpleados[0].nombre,"horacio");
    *contadorId =++ aux;

    arrayEmpleados[1].idUnico=1;
    arrayEmpleados[1].isEmpty=0;
    arrayEmpleados[1].sector=21;
    arrayEmpleados[1].sueldo=10;
    strcpy(arrayEmpleados[1].apellido,"Alvarez");
    strcpy(arrayEmpleados[1].nombre,"miguel");
    *contadorId =++ aux;

    arrayEmpleados[2].idUnico=2;
    arrayEmpleados[2].isEmpty=0;
    arrayEmpleados[2].sector=22;
    arrayEmpleados[2].sueldo=10;
    strcpy(arrayEmpleados[2].apellido,"Carles");
    strcpy(arrayEmpleados[2].nombre,"Luis");
    *contadorId =++ aux;

    arrayEmpleados[3].idUnico=3;
    arrayEmpleados[3].isEmpty=0;
    arrayEmpleados[3].sector=23;
    arrayEmpleados[3].sueldo=20;
    strcpy(arrayEmpleados[3].apellido,"Dorian");
    strcpy(arrayEmpleados[3].nombre,"Will");

}
//////////////////////////////////
void MenuEmpleados()
{
    printf("\n\nMENU EMPLEADOS\n");
    printf("--------------\n");
    printf("1 - Alta\n");
    printf("2 - Baja\n");
    printf("3 - Modificacion\n");
    printf("4 - Informes\n");
    printf("5 - Listar\n");
    printf("6 - SALIR\n");
    printf("Elija opcion: ");
}
///////////////////////////////////
void MenuMod()
{
    printf("MENU MODIFICACION\n");
    printf("--------------\n");
    printf("1 - NOMBRE\n");
    printf("2 - APELLIDO\n");
    printf("3 - SUELDO\n");
    printf("4 - SECTOR\n");
    printf("5 - SALIR\n");
    printf("Elija opcion: ");
}
