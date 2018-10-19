#ifndef VALIDAR_H_INCLUDED
#define VALIDAR_H_INCLUDED



/** \brief verifica si el valor recibido es solomente num�rico.
 *
 * \param cadena[] char el array se pasa como parametro.
 * \return int retorna 1 si es n�merico o 0 si no lo es.
 *
 */
int val_soloNumeros(char cadena[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief verifica si el valor recibido contiene solo letras.
 *
 * \param cadena[] char el array a ser analizado se pasa como parametro.
 * \return int 1 si contiene solo ' ' o letras y 0 si no lo es.
 *
 */
int val_soloLetras(char cadena[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief verifica si el valor recibido contiene solo letras y n�meros.
 *
 * \param cadena[] char el array a ser analizado se pasa como parametro.
 * \return int 1 si contiene solo ' ' y/o letras y/o n�meros, y 0 si no lo es.
 *
 */
int val_alfaNumerico(char cadena[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



void myFgets(char* buffer, int limite,FILE* archivo);

int val_getNombre(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarNombre(char* buffer);

int val_getUnsignedInt(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarUnsignedInt(char* buffer);

int val_getFloat(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_esNumericoFlotante(char* buffer);

int val_getDireccion(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_esAlfaNumerico(char str[]);

int val_validarTipoPantalla(char* buffer);
int val_getTipoPantalla(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);

int val_getNombreVideo(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_validarNombreVideo(char str[]);

int val_getCuit(char* destino, char* mensaje,char* mensajeError,int intentos,int limite);
int val_esCuit(char* buffer);


#endif // VALIDAR_H_INCLUDED
