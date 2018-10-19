#ifndef MYBOOK_H_INCLUDED
#define MYBOOK_H_INCLUDED




typedef struct
{
    char mensaje[3048];
    int id_mensaje;
    int id_usuario;
    long int popularidadm;
} S_message;   //Struct1 pers [CANT]; //en main va.


typedef struct
{
    char nick[62];
    int id_usuario;
    long int popularidadu;
} S_user;


typedef struct
{
    int id_mensaje;
    char mensaje[3048];
    long int popularidadm;
    int id_usuario;
    char nick[62];
    long int popularidadu;
    int estado;

} S_feed;


/** \brief carga el arraylist con los datos del archivo mensajes.csv.
 *
 * \param lista ArrayList* el arraylist se pasa como parametro.
 * \return int retorna -1 si es NULL o 0 si es OK.
 *
 */
int mb_loadMensajes(ArrayList* lista);


/** \brief carga el arraylist con los datos del archivo usuarios.csv.
 *
 * \param lista ArrayList* el arraylist se pasa como parametro.
 * \return int retorna -1 si es NULL o 0 si es OK.
 *
 */
int mb_loadUsuarios(ArrayList* lista);


/** \brief carga el tercer arraylist con los datos de los dos primeros.
 *
 * \param lista1 ArrayList* el arraylist se pasa como parametro.
 * \param lista2 ArrayList* el arraylist se pasa como parametro.
 * \param lista3 ArrayList* el arraylist se pasa como parametro.
 * \return int retorna -1 si es NULL o 0 si es OK.
 *
 */
int mb_loadFeed(ArrayList* lista1,ArrayList* lista2,ArrayList* lista3);


/** \brief crea el archivo con los datos del arraylist proporcionado.
 *
 * \param lista ArrayList* el arraylist se pasa como parametro.
 * \param nombre_archivo char* el nombre de archivo se pasa como parametro
 * \return void no retorna datos.
 *
 */
void mb_saveFeed(ArrayList* lista,char* nombre_archivo);


/** \brief crea dinamicamente un espacio para almacenar a la estructura.
 *
 * \return S_message* puntero a la estructura creada si tiene exito. o NULL si falla.
 *
 */
S_message* mb_mensajeNew();


/** \brief crea dinamicamente un espacio para almacenar a la estructura.
 *
 * \return S_user* puntero a la estructura creada si tiene exito. o NULL si falla.
 *
 */
S_user* mb_usuarioNew();


/** \brief crea dinamicamente un espacio para almacenar a la estructura.
 *
 * \return S_feed* puntero a la estructura creada si tiene exito. o NULL si falla.
 *
 */
S_feed* mb_feedNew();




#endif // MYBOOK_H_INCLUDED


