#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED
#include "ArrayList.h"

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    char dni[51];
    int estado;
}Ent1;


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


/** \brief constructor de la entidad.
 *
 * \param nombre char* el nombre se pasa como parametro
 * \param apellido char* el apellido se pasa como parametro
 * \param dni char* el dni se pasa como parametro
 * \param id int el ID se pasa como parametro
 * \param estado int el estado se pasa como parametro
 * \return Ent1* retorna una Entidad cargada con los parametros
 *
 */
Ent1* enty1_new(char* nombre, char* apellido, char* dni, int id, int estado);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief elimina de memoria una entidad.
 *
 * \param this Ent1* la entidad se pasa como parametro.
 * \return int retorna 0 si es exito; -1 si es error.
 *
 */
int enty1_delete(Ent1* this);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief adjudica el nombre en la entidad
 *
 * \param this Ent1* la entidad se pasa como parametro
 * \param nombre char* el nombre se pasa como parametro
 * \return int retorna -1 si la entidad es NULL, 1 si el parametro es NULL, o 0 si es un exito
 *
 */
int enty1_setNombre(Ent1* this,char* nombre);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief obtiene el parametro nombre de la entidad.
 *
 * \param this Ent1* la entidad se pasa como parametro.
 * \return char* retorna el parametro: nombre, de la entidad
 *
 */
char* enty1_getNombre(Ent1* this);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief adjudica el apellido en la entidad
 *
 * \param this Ent1* la entidad se pasa como parametro
 * \param apellido char* el apellido se pasa como parametro
 * \return int retorna -1 si la entidad es NULL, 1 si el parametro es NULL, o 0 si es un exito
 *
 */
int enty1_setApellido(Ent1* this,char* apellido);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief obtiene el parametro apellido de la entidad.
 *
 * \param this Ent1* la entidad se pasa como parametro.
 * \return char* retorna el parametro: apellido, de la entidad
 *
 */
char* enty1_getApellido(Ent1* this);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief adjudica el DNI en la entidad
 *
 * \param this Ent1* la entidad se pasa como parametro.
 * \param dni char* el dni se pasa como parametro.
 * \return int retorna -1 si la entidad es NULL, 1 si el parametro es NULL, o 0 si es un exito
 *
 */
int enty1_setDni(Ent1* this,char* dni);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief obtiene el parametro DNI de la entidad.
 *
 * \param this Ent1* la entidad se pasa como parametro.
 * \return char* retorna el parametro: DNI, de la entidad
 *
 */
char* enty1_getDni(Ent1* this);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief adjudica el ID en la entidad
 *
 * \param this Ent1* la entidad se pasa como parametro.
 * \param id int el ID se pasa como parametro
 * \return int retorna -1 si la entidad es NULL, 1 si el parametro es NULL, o 0 si es un exito
 *
 */
int enty1_setId(Ent1* this,int id);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief obtiene el parametro ID de la entidad.
 *
 * \param this Ent1* la entidad se pasa como parametro.
 * \return int retorna el parametro: ID, de la entidad
 *
 */
int enty1_getId(Ent1* this);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief adjudica el estado en la entidad
 *
 * \param this Ent1* la entidad se pasa como parametro.
 * \param estado int el estado se pasa como parametro
 * \return int retorna -1 si la entidad es NULL, 1 si el parametro es NULL, o 0 si es un exito
 *
 */
int enty1_setEstado(Ent1* this,int estado);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief obtiene el parametro Estado de la entidad.
 *
 * \param this Ent1* la entidad se pasa como parametro.
 * \return int retorna el parametro: estado, de la entidad
 *
 */
int enty1_getEstado(Ent1* this);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief busca en la lista, la entidad con el id pasado como parametro para devolverla.
 *
 * \param lista1 ArrayList* la lista se pasa como parametro
 * \param id int el ID a buscar se pasa como parametro
 * \return Ent1* retorna una entidad con el id seleccionado
 *
 */
Ent1* enty1_findById(ArrayList* lista1, int id);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief imprime por pantalla todo el contenido de la lista.
 *
 * \param lista1 ArrayList* la lista se pasa como parametro.
 * \return void
 *
 */
void enty1_mapAll(ArrayList* lista1);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief imprime por pantalla el contenido de una entidad
 *
 * \param entidad Ent1* la entidad se pasa por parametro.
 * \return void
 *
 */
void enty1_print(Ent1* entidad);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------





#endif // ENTIDADES_H_INCLUDED
