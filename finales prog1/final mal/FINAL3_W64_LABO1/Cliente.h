#include "ArrayList.h"

#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED
typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    char dni[51];
    int estado;
}Cliente;
#endif // SOCIO_H_INCLUDED

#define CLIENTE_ESTADO_ACTIVO 0
#define CLIENTE_ESTADO_INACTIVO 1

Cliente* soc_new(char* nombre, char* apellido, char* dni, int id, int estado);
int soc_delete(Cliente*);
int soc_setNombre(Cliente*,char* nombre);
char* soc_getNombre(Cliente*);
int soc_setApellido(Cliente* this,char* apellido);
char* soc_getApellido(Cliente* this);
int soc_setDni(Cliente* this,char* dni);
char* soc_getDni(Cliente* this);
int soc_setId(Cliente* this,int id);
int soc_getId(Cliente* this);
int soc_setEstado(Cliente* this,int estado);
int soc_getEstado(Cliente* this);




Cliente* soc_findById(ArrayList*, int);




