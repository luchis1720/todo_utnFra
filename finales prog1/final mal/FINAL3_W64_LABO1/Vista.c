#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "Cliente.h"
#include "Venta.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"


static void opcionAlta();
static void opcionBaja();
static void opcionModificacion();
static void opcionListado();


int vista_init (void)
{
    return 0;
}

int vista_mostrarMenu(void)
{
    char buffer[10];
    int option=0;

    while(option != 10)
    {
        val_getInt(buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,5);
        option = atoi(buffer);

        switch(option)
        {
            case 1:
                opcionListado();
                break;
            case 2:
                opcionAlta();
                break;
            case 3:
                opcionBaja();
                break;
            case 4:
                opcionModificacion();
                break;
            // HACER
            case 5:
            {
                // opcionImportarClientes();
                break;
            }
            case 6:
            {
                //opcionRealizarVenta();
                break;
            }
            case 7:
            {
                //opcionGenerarInformeVentasPorPorducto();
                break;
            }
            case 8:
            {
                //opcionGenerarInformeVentasDeFecha();
                break;
            }
            case 9:
            {
                //opcionInformar();
                break;
            }
            //_______
        }
    }

    return 0;
}

void vista_mostrarSocios(ArrayList* pListaSocios)
{
    int i;
    Cliente* auxSocio;
    for(i=0;i<al_len(pListaSocios);i++)
        {
            auxSocio=al_get(pListaSocios,i);
            if(auxSocio->estado==CLIENTE_ESTADO_ACTIVO)
            {
            auxSocio = al_get(pListaSocios,i);
            printf("NOMBRE: %s - APELLIDO: %s- ID: %d - DNI: %s\n",soc_getNombre(auxSocio),
                            soc_getApellido(auxSocio),soc_getId(auxSocio),soc_getDni(auxSocio));
            }
        }

}


void mostrarError(char *);

static void opcionAlta()
{
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];
    val_getString(auxNombre, "Nombre? ", "Error",2,50);
    val_getString(auxApellido, "Apellido? ", "Error",2,50);
    val_getInt(auxDni, "DNI? ", "Error",2,50);
    cont_altaCliente(auxNombre,auxApellido,auxDni);

}

static void opcionBaja()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaCliente(id);
    }

}

static void opcionModificacion()
{
    char auxId[10];
    int id;
    char auxNombre[50];
    char auxApellido[50];
    char auxDni[50];

    if((val_getUnsignedInt(auxId,"Id a modificar" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(val_getString(auxNombre, "Nombre? ", "Error",2,50)==0)
        {
            if(val_getString(auxApellido, "Apellido? ", "Error",2,50)==0)
            {
                if(val_getInt(auxDni, "DNI? ", "Error",2,50)==0)
                {
                    cont_modificarCliente(auxNombre,auxApellido,auxDni,id);
                }
            }
        }
    }
}

static void opcionListado()
{
    cont_listarClientes();
}
