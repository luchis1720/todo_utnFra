#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "Entidades2.h"

Ent2* enty2_new(char* nombre, char* apellido, char* dni, int id, int estado)
{
    Ent2* nuevoEnty = malloc(sizeof(Ent2));
    enty2_setNombre(nuevoEnty,nombre);
    enty2_setApellido(nuevoEnty,apellido);
    enty2_setDni(nuevoEnty,dni);
    enty2_setId(nuevoEnty,id);
    enty2_setEstado(nuevoEnty,estado);

    return nuevoEnty;
}

int enty2_delete(Ent2* this)
{
    int ans=-1;
    if (this!= NULL)
    {
        free(this);
        ans=0;
    }
    return ans;
}

int enty2_setNombre(Ent2* this,char* nombre)
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

char* enty2_getNombre(Ent2* this)
{
    if (this!= NULL)
        return this->nombre;
}

int enty2_setApellido(Ent2* this,char* apellido)
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

char* enty2_getApellido(Ent2* this)
{
    if (this!= NULL)
        return this->apellido;
}

int enty2_setDni(Ent2* this,char* dni)
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

char* enty2_getDni(Ent2* this)
{
    if (this!= NULL)
        return this->dni;
}

int enty2_setId(Ent2* this,int id)
{
    int ans=-1;
    if (this!= NULL)
    {
        this->id = id;
        ans=0;
    }
    return ans;
}

int enty2_getId(Ent2* this)
{
    if (this!= NULL)
        return this->id;
}

int enty2_setEstado(Ent2* this,int estado)
{
    int ans=-1;
    if (this!= NULL)
    {
        this->estado = estado;
        ans=0;
    }
    return ans;
}

int enty2_getEstado(Ent2* this)
{
    if (this!= NULL)
        return this->estado;
}

Ent2* enty2_findById(ArrayList* lista2, int id)
{
    int i;
    Ent2* aux;
    void* ans=NULL;

    for(i=0;i<al_len(lista2);i++)
    {
        aux = al_get(lista2,i);

        if(id == aux->id)
            ans = aux;
    }

    return ans;
}

void enty2_mapAll(ArrayList* lista2)
{
    int i;
    Ent2* aux;

    for(i=0;i<al_len(lista2);i++)
    {
        aux = al_get(lista2,i);
        enty1_print(aux);
    }
}

void enty2_print(Ent2* entidad)
{
    printf("\n");
    printf("ID: %d\n",entidad->id);
    printf("Apellido: %s\n",entidad->apellido);
    printf("Nombre: %s\n",entidad->nombre);
    printf("DNI: %s\n",entidad->dni);
    printf("Estado: %d\n",entidad->estado);
    printf("--------------------------------------------------\n");
}

