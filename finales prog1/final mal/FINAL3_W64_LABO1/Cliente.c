#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Cliente.h"


Cliente* soc_new(char* nombre, char* apellido, char* dni, int id, int estado)
{
    Cliente* nuevoSocio = malloc(sizeof(Cliente));
    soc_setNombre(nuevoSocio,nombre);
    soc_setApellido(nuevoSocio,apellido);
    soc_setDni(nuevoSocio,dni);
    soc_setId(nuevoSocio,id);
    soc_setEstado(nuevoSocio,estado);

    return nuevoSocio;
}


int soc_delete(Cliente* this)
{
    free(this);
    return 0;
}


int soc_setNombre(Cliente* this,char* nombre)
{
    strcpy(this->nombre,nombre);
    return 0;
}


char* soc_getNombre(Cliente* this)
{
    return this->nombre;
}


int soc_setApellido(Cliente* this,char* apellido)
{
    strcpy(this->apellido,apellido);
    return 0;
}


char* soc_getApellido(Cliente* this)
{
    return this->apellido;
}


int soc_setDni(Cliente* this,char* dni)
{
    strcpy(this->dni,dni);
    return 0;
}


char* soc_getDni(Cliente* this)
{
    return this->dni;
}


int soc_setId(Cliente* this,int id)
{

    this->id = id;
    return 0;
}

int soc_getId(Cliente* this)
{
    return this->id;
}

int soc_setEstado(Cliente* this,int estado)
{

    this->estado = estado;
    return 0;
}

int soc_getEstado(Cliente* this)
{
    return this->estado;
}


Cliente* soc_findById(ArrayList* pArraySocio, int id)
{
    int i;
    Cliente *auxSocio;
    void* retorno=NULL;

    for(i=0;i<al_len(pArraySocio);i++)
    {
        auxSocio = al_get(pArraySocio,i);
        if(id == auxSocio->id)
        {
            retorno = auxSocio;
        }
    }

    return retorno;
}




