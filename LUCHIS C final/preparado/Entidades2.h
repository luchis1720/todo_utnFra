#ifndef ENTIDADES2_H_INCLUDED
#define ENTIDADES2_H_INCLUDED
#include "ArrayList.h"

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    char dni[51];
    int estado;
}Ent2;


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief constructor de la entidad.
 *
 * \param nombre char* el nombre se pasa como parametro
 * \param apellido char* el apellido se pasa como parametro
 * \param dni char* el dni se pasa como parametro
 * \param id int el ID se pasa como parametro
 * \param estado int el estado se pasa como parametro
 * \return Ent2* retorna una Entidad cargada con los parametros
 *
 */
Ent2* enty2_new(char* nombre, char* apellido, char* dni, int id, int estado);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief elimina de memoria una entidad.
 *
 * \param this Ent2* la entidad se pasa como parametro.
 * \return int retorna 0 si es exito; -1 si es error.
 *
 */
int enty2_delete(Ent2* this);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief adjudica el nombre en la entidad
 *
 * \param this Ent2* la entidad se pasa como parametro
 * \param nombre char* el nombre se pasa como parametro
 * \return int retorna -1 si la entidad es NULL, 1 si el parametro es NULL, o 0 si es un exito
 *
 */
int enty2_setNombre(Ent2* this,char* nombre);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief obtiene el parametro nombre de la entidad.
 *
 * \param this Ent2* la entidad se pasa como parametro.
 * \return char* retorna el parametro: nombre, de la entidad
 *
 */
char* enty2_getNombre(Ent2* this);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief adjudica el apellido en la entidad
 *
 * \param this Ent2* la entidad se pasa como parametro
 * \param apellido char* el apellido se pasa como parametro
 * \return int retorna -1 si la entidad es NULL, 1 si el parametro es NULL, o 0 si es un exito
 *
 */
int enty2_setApellido(Ent2* this,char* apellido);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief obtiene el parametro apellido de la entidad.
 *
 * \param this Ent2* la entidad se pasa como parametro.
 * \return char* retorna el parametro: apellido, de la entidad
 *
 */
char* enty2_getApellido(Ent2* this);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief adjudica el DNI en la entidad
 *
 * \param this Ent2* la entidad se pasa como parametro.
 * \param dni char* el dni se pasa como parametro.
 * \return int retorna -1 si la entidad es NULL, 1 si el parametro es NULL, o 0 si es un exito
 *
 */
int enty2_setDni(Ent2* this,char* dni);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief obtiene el parametro DNI de la entidad.
 *
 * \param this Ent2* la entidad se pasa como parametro.
 * \return char* retorna el parametro: DNI, de la entidad
 *
 */
char* enty2_getDni(Ent2* this);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief adjudica el ID en la entidad
 *
 * \param this Ent2* la entidad se pasa como parametro.
 * \param id int el ID se pasa como parametro
 * \return int retorna -1 si la entidad es NULL, 1 si el parametro es NULL, o 0 si es un exito
 *
 */
int enty2_setId(Ent2* this,int id);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief obtiene el parametro ID de la entidad.
 *
 * \param this Ent2* la entidad se pasa como parametro.
 * \return int retorna el parametro: ID, de la entidad
 *
 */
int enty2_getId(Ent2* this);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief adjudica el estado en la entidad
 *
 * \param this Ent2* la entidad se pasa como parametro.
 * \param estado int el estado se pasa como parametro
 * \return int retorna -1 si la entidad es NULL, 1 si el parametro es NULL, o 0 si es un exito
 *
 */
int enty2_setEstado(Ent2* this,int estado);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief obtiene el parametro Estado de la entidad.
 *
 * \param this Ent2* la entidad se pasa como parametro.
 * \return int retorna el parametro: estado, de la entidad
 *
 */
int enty2_getEstado(Ent2* this);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief busca en la lista, la entidad con el id pasado como parametro para devolverla.
 *
 * \param lista2 ArrayList* la lista se pasa como parametro
 * \param id int el ID a buscar se pasa como parametro
 * \return Ent2* retorna una entidad con el id seleccionado
 *
 */
Ent2* enty2_findById(ArrayList* lista2, int id);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief imprime por consola todo el contenido de la lista.
 *
 * \param lista2 ArrayList* la lista se pasa como parametro
 * \return void
 *
 */
void enty2_mapAll(ArrayList* lista2);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief imprime por pantalla el contenido de una entidad
 *
 * \param entidad Ent2* la entidad se pasa por parametro.
 * \return void
 *
 */
void enty2_print(Ent2* entidad);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


#endif // ENTIDADES2_H_INCLUDED
