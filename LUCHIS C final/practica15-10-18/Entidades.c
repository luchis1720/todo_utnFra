#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "Entidades.h"



Ent1* enty1_new(char* nombre, char* apellido, char* dni, int id, int estado)
{
    Ent1* nuevoEnty = malloc(sizeof(Ent1));
    enty1_setNombre(nuevoEnty,nombre);
    enty1_setApellido(nuevoEnty,apellido);
    enty1_setDni(nuevoEnty,dni);
    enty1_setId(nuevoEnty,id);
    enty1_setEstado(nuevoEnty,estado);

    return nuevoEnty;
}

int enty1_delete(Ent1* this)
{
    int ans=-1;
    if (this!= NULL)
    {
        free(this);
        ans=0;
    }
    return ans;
}

int enty1_setNombre(Ent1* this,char* nombre)
{
    int ans=-1;
    if (this!= NULL)
    {
        ans=1;
        if (nombre != NULL)
        {
            strcpy(this->nombre,nombre);
            ans=0;
        }
    }
    return ans;
}

char* enty1_getNombre(Ent1* this)
{
    if (this!= NULL)
        return this->nombre;
}

int enty1_setApellido(Ent1* this,char* apellido)
{
    int ans=-1;
    if (this!= NULL)
    {
        ans=1;
        if (apellido != NULL)
        {
            strcpy(this->apellido,apellido);
            ans=0;
        }

    }
    return ans;
}

char* enty1_getApellido(Ent1* this)
{
    if (this!= NULL)
        return this->apellido;
}

int enty1_setDni(Ent1* this,char* dni)
{
    int ans=-1;
    if (this!= NULL)
    {
        ans=1;
        if (dni!= NULL)
        {
            strcpy(this->dni,dni);
            ans=0;
        }
    }
    return ans;
}

char* enty1_getDni(Ent1* this)
{
    if (this!= NULL)
        return this->dni;
}

int enty1_setId(Ent1* this,int id)
{
    int ans=-1;
    if (this!= NULL)
    {
        this->id = id;
        ans=0;
    }
    return ans;
}

int enty1_getId(Ent1* this)
{
    if (this!= NULL)
        return this->id;
}

int enty1_setEstado(Ent1* this,int estado)
{
    int ans=-1;
    if (this!= NULL)
    {
        this->estado = estado;
        ans=0;
    }
    return ans;
}

int enty1_getEstado(Ent1* this)
{
    if (this!= NULL)
        return this->estado;
}

Ent1* enty1_findById(ArrayList* lista1, int id)
{
    int i;
    Ent1 *aux;
    void* ans=NULL;

    for(i=0;i<al_len(lista1);i++)
    {
        aux = al_get(lista1,i);

        if(id == aux->id)
            ans = aux;
    }

    return ans;
}

void enty1_mapAll(ArrayList* lista1)
{
    int i;
    Ent1 *aux;

    for(i=0;i<al_len(lista1);i++)
    {
        aux = al_get(lista1,i);
        enty1_print(aux);
    }
}

void enty1_print(Ent1* entidad)
{
    printf("\n");
    printf("ID: %d\n",entidad->id);
    printf("Apellido: %s\n",entidad->apellido);
    printf("Nombre: %s\n",entidad->nombre);
    printf("DNI: %s\n",entidad->dni);
    printf("Estado: %d\n",entidad->estado);
    printf("--------------------------------------------------\n");
}

