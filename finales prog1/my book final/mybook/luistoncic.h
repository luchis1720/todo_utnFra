#ifndef LUISTONCIC_H_INCLUDED
#define LUISTONCIC_H_INCLUDED

#define ESC 27
#define CR 13

typedef struct
{
    char nombre[62];
    int edad;
    int estado;
    long int dni;
}Struct1;   //Struct1 pers [CANT]; //en main va.





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

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param cadena, es el mensaje a ser mostrado
 * \return el caracter ingresado por el usuario
 *
 *  Ejemplo: lt_getchar("Por favor ingrese un caracter: ");
 *
 */
char lt_getChar(char cadena_a_mostrar[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \brief  solicita un numero entero al usuario y devuelve el resultado.
 * \param cadena, es el mensaje a ser mostrado.
 * \return el numero ingresado por el usuario.
 *
 *  Ejemplo: lt_getInt("Por favor, Ingrese un numero: ");
 *
 */
int lt_getInt (char cadena_a_mostrar[]);

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
long int getenterolargo (char cadena[], int enteroL_len);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \brief  solicita un numero flotante al usuario y devuelve el resultado.
 * \param cadena, es el mensaje a ser mostrado.
 * \return el numero ingresado por el usuario.
 *
 *  Ejemplo: lt_getFloat("Ingreseun numero real: ");
 *
 */
float lt_getFloat(char cadena[]);

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
void lt_getTexto(char cadena[],char save[],int texto_len);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * \brief Solicita un nombre y apellido al usuario y lo guarda.
 * \param save, array donde se guarda el nombre y apellido.
 * \return no devuelve datos.
 *
 *  Ejemplo: lt_getName(usuario);
 *
 */
void lt_getName(char save[]);

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

/** \brief inicializa el vector con el valor deseado indicando que su estado es disponible.
 *
 * \param vec[] Struct1 se pasa el array como parametro.
 * \param cant_elementos int la extension del array.
 * \param valor_a_ingresar int es el valor que se desea ingresar. EJEMPLO: (-1)
 * \return void no retorna datos.
 *
 */
void lt_inicializarArrayEstado(Struct1 vec[], int cant_elementos, int valor_a_ingresar);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief busca la primer ocurrencia en el array.
 *
 * \param vec[] Struct1 el array se pasa como parametro.
 * \param cant_elementos int indica la longitud del array.
 * \param valor_a_buscar int es el valor que se busca. EJEMPLO (-1)
 * \return int si no hay ocurrencia (-1) y si la hay, retorna la posicion de la misma (i).
 *
 */
int lt_obtenerPrimerOcurrencia(Struct1 vec[], int cant_elementos, int valor_a_buscar);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------









//VALIDACIONES

/** \brief valida si una cadena de texto solo tiene caracteres y no numeros.
 *
 * \param cadena, el array se pasa como parametro.
 * \return devuelve 0 si es solo letras o 1 si tiene numeros.
 *
 */

int lt_validarTexto(char cadena[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief valida si una de texto solo tiene numeros y no letras ni signos.
 *
 * \param cadena, el array se pasa como parametro.
 * \return devuelve 0 si es solo numeros o 1 si tiene letras y/o signos.
 *
 */
int lt_validarEnteros(char cadena[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief valida si una cadena de texto solo tiene numeros y no letras ni signos, a excepcion del punto (coma).
 *
 * \param cadena, el array se pasa como parametro.
 * \return devuelve 0 si es solo numeros o 1 si tiene letras y/o signos.
 *
 */
int lt_validarFlotantes(char cadena[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief cuenta simbolos en una cadena de texto.
 *
 * \param cadena, el array se pasa como parametro.
 * \return devuelve 1 si hay un solo simbolo, o 0 si tiene mas de uno.
 *
 */

int lt_contadorCadena(char cadena[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief cuenta simbolos negativos en una cadena de texto
 *
 * \param cadena[] char, el array se pasa como parametro.
 * \return int devuelve 1 si hay un solo simbolo negativo al inicio, o 0 si tiene mas de uno y fuera del inicio.
 *
 */
int lt_allowNeg(char cadena[]);

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

/** \brief recibe el array pasado como parametro, y realiza un ordenamiento aleatorio.
 *
 * \param vec el array se pasa como parametro
 *
 * \note
 *     Para determinar si se modifica la posicion de un elemento, se usa una funcion aleatoria
 *     y luego con la operacion modulo (%) nos da el resto de dividir rand() entre 2.
 *     este resto puede ir de 0 a 1. de la misma forma, el modulo de rand().
 *     entre N+1 va de 0 a N.
 *
 */
void lt_mezclaRandom (Struct1 vec[]);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void lt_begin();

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void lt_end();

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void lt_clear(void);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void lt_sleep(int msc);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void lt_flush(void);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void lt_showDate(void);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



#endif // LUISTONCIC_H_INCLUDED
