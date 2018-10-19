#ifndef LUISTONCIC_H_INCLUDED
#define LUISTONCIC_H_INCLUDED
#include "Datos.h"
#include "Parser.h"
#include "Examen.h"

#define ESC 27
#define CR 13


/*
typedef struct
{
    char nombre[62];
    int id; //if 0 == NULL
    int estado;
    long int dni;
}Struct1;   //Struct1 pers [CANT]; //en main va.
*/





//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \brief imprime por pantalla las opciones del menu, y te deja seleccionar una.
 *
 * \param cadenas, se pasa el array como parametro.
 * \return retorna un entero con la opcion seleccionada.
 *
 *  Ejemplo: lt_menu("Menu: \n1.-Agregar \n2.-Borrar \n3.-Salir\n\n");
 *
 */
int lt_menu(char cadenas_del_menu[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief realiza un switch (menu de opciones) .
 *
 * \param cadenas, se pasa el array con el texto a mostrar como parametro.
 * \return void no retorna datos.
 *
 */
void lt_miMenu(char cadenas_del_menu[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Funciones capsula.
 *
 * \return void no retornan datos
 *
 */
void lt_opcion1();
void lt_opcion2();
void lt_opcion3();
void lt_opcion4();
void lt_opcion5();
void lt_opcion6();
void lt_opcion7();
void lt_opcion8();
void lt_opcion9();
void lt_opcion10();
void lt_opcion1720();

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief pregunta al usuario si desea continuar o cancelar.
 *
 * \param cadena, es el msj a ser mostrado.
 * \return devuelve 1 si desea continuar, o 0 si cancelo.
 *
 *
 *  Ejemplo:  int choice;
 *            choice = lt_enterOrEsc(" ");
 *
 */
int lt_enterOrEsc(char cadena_a_mostrar[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief imprime por consola un marco de titulo y/o bienvenida.
 *
 * \return void
 *
 */
void lt_begin();

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief imprime por consola un marco de despedida.
 *
 * \return void
 *
 */
void lt_end();

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 *
 */
char lt_getNumeroAleatorio(int desde, int hasta, int iniciar);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief limpia pantalla usando secuencias ANSI escape.
 *
 * \param void
 * \return void
 *
 */
void lt_clear(void);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief realiza un retraso. (ms = cantidad de milisegundos.)
 *
 * \param msc int los milisegundos son pasados como parametro.
 * \return void
 *
 */
void lt_sleep(int msc);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief realiza un fflush.
 *
 * \param void
 * \return void
 *
 */
void lt_flush(void);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief muestra la hora y dia actual.
 *
 * \param void
 * \return void
 *
 */
void lt_showDate(void);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------















//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// /** \brief recibe el array pasado como parametro, y realiza un ordenamiento aleatorio.
//  *
//  * \param vec el array se pasa como parametro
//  *
//  * \note
//  *     Para determinar si se modifica la posicion de un elemento, se usa una funcion aleatoria
//  *     y luego con la operacion modulo (%) nos da el resto de dividir rand() entre 2.
//  *     este resto puede ir de 0 a 1. de la misma forma, el modulo de rand().
//  *     entre N+1 va de 0 a N.
//  *
//  */
// void lt_mezclaRandom (Struct1 vec[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// /** \brief inicializa el vector con el valor deseado indicando que su estado es disponible.
//  *
//  * \param vec[] Struct1 se pasa el array como parametro.
//  * \param cant_elementos int la extension del array.
//  * \param valor_a_ingresar int es el valor que se desea ingresar. EJEMPLO: (-1)
//  * \return void no retorna datos.
//  *
//  */
// void lt_inicializarArrayEstado(Struct1 vec[], int cant_elementos, int valor_a_ingresar);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// /** \brief busca la primer ocurrencia en el array.
//  *
//  * \param vec[] Struct1 el array se pasa como parametro.
//  * \param cant_elementos int indica la longitud del array.
//  * \param valor_a_buscar int es el valor que se busca. EJEMPLO (-1)
//  * \return int si no hay ocurrencia (-1) y si la hay, retorna la posicion de la misma (i).
//  *
//  */
// int lt_obtenerPrimerOcurrencia(Struct1 vec[], int cant_elementos, int valor_a_buscar);








#endif // LUISTONCIC_H_INCLUDED
