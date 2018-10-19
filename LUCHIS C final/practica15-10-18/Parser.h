#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "ArrayList.h"
#include "luistoncic.h"
#include "Entidades.h"
#include "Entidades2.h"

/** \brief carga los archivos en las listas.
 *
 * \param lista1 ArrayList* la lista se pasa como parametro.
 * \param lista2 ArrayList* la lista se pasa como parametro.
 * \param archivo1 char* el nombre del archivo se pasa como parametro.
 * \param archivo2 char* el nombre del archivo se pasa como parametro.
 * \return void
 *
 */
void par_loader(ArrayList* lista1, ArrayList* lista2, char* archivo1, char* archivo2);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief carga los datos de la lista en el archivo.
 *
 * \param lista ArrayList* la lista se pasa como parametro
 * \param archivo char* el nombre del archivo se pasa como parametro
 * \return int retorna -1 si no puede crear el archivo 0  si la carga fue un exito
 *
 */
int par_saveFile1(ArrayList* lista, char* archivo);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief carga los datos de la lista en el archivo.
 *
 * \param lista ArrayList* la lista se pasa como parametro
 * \param archivo char* el nombre del archivo se pasa como parametro
 * \return int retorna -1 si no puede crear el archivo 0  si la carga fue un exito
 *
 */
int par_saveFile2(ArrayList* lista, char* archivo);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief carga los datos de la lista en el archivo
 *
 * \param lista ArrayList* la lista se pasa como parametro.
 * \param archivo char* el nombre del archivo se pasa como parametro.
 * \return int retorna -1 si no puede crear el archivo 0  si la carga fue un exito
 *
 */
int par_saveFile1(ArrayList* lista, char* archivo);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief realiza la lectura del archivo, y el volcado del mismo en la lista.
 *
 * \param lista ArrayList* la lista se pasa como parametro
 * \param archivo char* el nombre del archivo se pasa como parametro
 * \return int retorna -1 si el archivo no existe, 1 si existe pero hubo error de lectura o 0 si esta OK.
 *
 */
int par_loadFile1(ArrayList* lista, char* archivo);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief realiza la lectura del archivo, y el volcado del mismo en la lista.
 *
 * \param lista ArrayList* la lista se pasa como parametro
 * \param archivo char* el nombre del archivo se pasa como parametro
 * \return int retorna -1 si el archivo no existe, 1 si existe pero hubo error de lectura o 0 si esta OK.
 *
 */
int par_loadFile2(ArrayList* lista, char* archivo);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#endif // PARSER_H_INCLUDED
