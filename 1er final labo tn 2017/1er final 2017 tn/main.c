#include <stdio.h>
#include <stdlib.h>
#include "luistoncic.h"
#include "ArrayList.h"
#include "final.h"
#include "manejodatoslt.h"

int main()
{
    ArrayList* clientes=al_newArrayList();

    if(clientes!=NULL)
    {
        lt_opciones("1.-ALTA DE CLIENTE\n2.-MODIFICAR CLIENTE\n3.-BAJA DE CLIENTE\n4.-LISTAR CLIENTES\n5.-REALIZAR UNA VENTA\n6.-ANULAR VENTA\n7.-INFORMAR VENTAS\n8.-INFORMAR VENTAS POR PRODUCTOS\n9.-GENERAR INFORME DE VENTAS\n10.-INFORMAR CANTIDAD DE VENTAS POR CLIENTE\n0.-SALIR\n",clientes);
        lt_end();
        //lt_showDate();
    }

    return 0;
}
