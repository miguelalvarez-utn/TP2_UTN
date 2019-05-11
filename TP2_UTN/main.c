#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "utn.h"
#define CANTIDAD_ESPACIOS 5
int main()
{
    int opcion;
    int contadorIdempleados = 0;
    Empleados arrayEmpleados[CANTIDAD_ESPACIOS];                   //cambiar
    empleados_Inicializar(arrayEmpleados,CANTIDAD_ESPACIOS);                   //cambiar
    empleados_mock(arrayEmpleados, CANTIDAD_ESPACIOS,&contadorIdempleados) ;

    do
    {
        MenuEmpleados();
        utn_getUnsignedInt("",                   //cambiar
        "\nError",1,sizeof(int),1,6,1,&opcion);
        switch(opcion)
        {
            case 1:
                empleados_alta(arrayEmpleados,CANTIDAD_ESPACIOS,&contadorIdempleados);
                break;
            case 2:
                if(!emp_verificacion(arrayEmpleados,CANTIDAD_ESPACIOS))
                {
                    printf("no hay empleados cargados");
                    break;
                }
                empleados_listar2(arrayEmpleados,CANTIDAD_ESPACIOS);
                empleados_baja(arrayEmpleados,CANTIDAD_ESPACIOS);
                break;
            case 3:
                if(!emp_verificacion(arrayEmpleados,CANTIDAD_ESPACIOS))
                {
                    printf("no hay empleados cargados");
                    break;
                }
                empleados_listar2(arrayEmpleados,CANTIDAD_ESPACIOS);
                empleados_modificar(arrayEmpleados,CANTIDAD_ESPACIOS);
            case 4:
                if(!emp_verificacion(arrayEmpleados,CANTIDAD_ESPACIOS))
                {
                    printf("no hay empleados cargados");
                    break;
                }
                InformeEmpleado(arrayEmpleados,CANTIDAD_ESPACIOS);
                break;
            case 5:
                if(!emp_verificacion(arrayEmpleados,CANTIDAD_ESPACIOS))
                {
                    printf("no hay empleados cargados");
                    break;
                }
                empleados_listar2(arrayEmpleados,CANTIDAD_ESPACIOS);
                break;


        }
    }while(opcion != 6);
    return 0;
}
