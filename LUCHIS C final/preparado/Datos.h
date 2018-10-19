#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED
#include "Validaciones.h"


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param cadena, es el mensaje a ser mostrado
 * \return el caracter ingresado por el usuario
 *
 *  Ejemplo: lt_getchar("Por favor ingrese un caracter: ");
 *
 */
char dat_getChar(char cadena_a_mostrar[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \brief  solicita un numero entero al usuario y devuelve el resultado.
 * \param cadena, es el mensaje a ser mostrado.
 * \return el numero ingresado por el usuario.
 *
 *  Ejemplo: lt_getInt("Por favor, Ingrese un numero: ");
 *
 */
int dat_getInt (char cadena_a_mostrar[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \brief  solicita un numero entero largo al usuario y devuelve el resultado.
 * \param cadena, es el mensaje a ser mostrado.
 * \param enteroL_len, es la longitud de digitos que se desea en el entero largo (MAX 10).
 * \return el numero ingresado por el usuario.
 *
 *  Ejemplo: lt_getLongInt ("por favor, ingrese DNI: ",8); // EnteroL_len == 8 para D.N.I.
 *
 */
long int dat_getLongInt (char cadena[], int enteroL_len);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \brief  solicita un numero flotante al usuario y devuelve el resultado.
 * \param cadena, es el mensaje a ser mostrado.
 * \return el numero ingresado por el usuario.
 *
 *  Ejemplo: lt_getFloat("Ingreseun numero real: ");
 *
 */
float dat_getFloat(char cadena[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \brief Solicita un texto al usuario y lo guarda.
 * \param cadena, es el mensaje a ser mostrado.
 * \param save, array donde se guarda el texto.
 * \param texto_len, longitud dek texti que desea ser guardado.
 * \return no devuelve datos.
 *
 *  Ejemplo:  char palabra[41];
 *          lt_getTexto("por favor ingrese el texto", palabra, 41); // quiero que la palabra o texto solo tenga 40 caracteres
 *
 */
void dat_getTexto(char cadena[],char save[],int texto_len);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \brief Solicita un nombre y apellido al usuario y lo guarda.
 * \param save, array donde se guarda el nombre y apellido.
 * \return no devuelve datos.
 *
 *  Ejemplo: lt_getName(usuario);
 *
 */
void dat_getName(char save[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




#endif // DATOS_H_INCLUDED
