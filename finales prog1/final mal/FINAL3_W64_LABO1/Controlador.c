#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Cliente.h"
#include "Venta.h"
#include "Vista.h"
#include "DataManager.h"

static ArrayList* nominaClientes;
static int proximoIdCliente=0;
static int getNewIdCliente();
static int setNewIdCliente(int id);

void cont_init(void)
{
    // Creacion del modelo de datos
    nominaClientes = al_newArrayList();
    setNewIdCliente(dm_readAllClientes(nominaClientes) + 1);
    //______________________________

    vista_init();

    vista_mostrarMenu(); // bloqueante, nunca sale de esta funcion. no poner nada debajo de esta linea
}

int cont_altaCliente (char* nombre,char* apellido,char* dni)
{
    Cliente* auxSocio;
    auxSocio = soc_new(nombre,apellido,dni,getNewIdCliente(),CLIENTE_ESTADO_ACTIVO);
    if(auxSocio!=NULL)
    {
        al_add(nominaClientes,auxSocio);
        dm_saveAllClientes(nominaClientes);
        return 0;
    }
    return -1;
}

int cont_bajaCliente (int id)
{
    Cliente* auxSocio;
    auxSocio=soc_findById(nominaClientes,id);
    if(auxSocio!=NULL)
    {
        soc_setEstado(auxSocio,CLIENTE_ESTADO_INACTIVO);
        dm_saveAllClientes(nominaClientes);
    }

    return 0;
}


int cont_modificarCliente (char* nombre,char* apellido,char* dni, int id)
{
    Cliente* auxSocio;

    auxSocio=soc_findById(nominaClientes,id);

    if(auxSocio!=NULL)
    {
        soc_setNombre(auxSocio,nombre);
        soc_setApellido(auxSocio,apellido);
        soc_setDni(auxSocio,dni);
        dm_saveAllClientes(nominaClientes);
    }

    return 0;
}

int cont_listarClientes (void)
{
    vista_mostrarSocios(nominaClientes);
    return 0;
}


static int getNewIdCliente()
{
    return proximoIdCliente++;
}

static int setNewIdCliente(int id)
{
    proximoIdCliente = id;
    return 0;
}
