#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED


/** \brief valida si una cadena de texto solo tiene caracteres y no numeros.
 *
 * \param cadena, el array se pasa como parametro.
 * \return devuelve 0 si es solo letras o 1 si tiene numeros.
 *
 */

int val_validarTexto(char cadena[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief valida si una de texto solo tiene numeros y no letras ni signos.
 *
 * \param cadena, el array se pasa como parametro.
 * \return devuelve 0 si es solo numeros o 1 si tiene letras y/o signos.
 *
 */
int val_validarEnteros(char cadena[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief valida si una cadena de texto solo tiene numeros y no letras ni signos, a excepcion del punto (coma).
 *
 * \param cadena, el array se pasa como parametro.
 * \return devuelve 0 si es solo numeros o 1 si tiene letras y/o signos.
 *
 */
int val_validarFlotantes(char cadena[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief cuenta simbolos en una cadena de texto.
 *
 * \param cadena, el array se pasa como parametro.
 * \return devuelve 1 si hay un solo simbolo, o 0 si tiene mas de uno.
 *
 */

int val_contadorCadena(char cadena[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief cuenta simbolos negativos en una cadena de texto
 *
 * \param cadena[] char, el array se pasa como parametro.
 * \return int devuelve 1 si hay un solo simbolo negativo al inicio, o 0 si tiene mas de uno y fuera del inicio.
 *
 */
int val_allowNeg(char cadena[]);




#endif // VALIDACIONES_H_INCLUDED

