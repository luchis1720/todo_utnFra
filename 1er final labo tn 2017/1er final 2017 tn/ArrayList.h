/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
//luis toncic

#ifndef __ARRAYLIST
#define __ARRAYLIST
struct ArrayList
{
    int size;
    void **pElements;
    int reservedSize;

    int     (*add)();
    int     (*len)();
    int     (*contains)();
    int     (*set)();
    int     (*remove)();
    int     (*clear)();
    int     (*push)();
    int     (*indexOf)();
    int     (*isEmpty)();
    void*   (*get)();
    void*   (*pop)();
    int     (*containsAll)();
    int     (*sort)();
    struct ArrayList* (* clone)();
    struct ArrayList* (*subList)();
    int     (*deleteArrayList)();

} typedef ArrayList;
#endif


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief asigna una nueva arrayList con AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Retorna (NULL) si hay error [no asigna memoria] o retorna el puntero  al nuevo arraylist si esta bien
 */
ArrayList* al_newArrayList(void);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Agrega un elemento al final de ArrayList. Verifica que tanto el puntero this como pElement
 *         sean distintos de NULL
 *
 * \param this ArrayList* el arraylist se pasa como parametro.
 * \param pElement void* la lista de elementos se pasa como parametro.
 * \return int  Si falla la función retorna (-1) y si tiene éxito (0).
 *
 */
int al_add(ArrayList* this,void* pElement);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Elimina el ArrayList . Verificando que el puntero this sea distinto de NULL.
 *
 * \param this ArrayList* el arraylist se pasa como parametro.
 * \return int Si la verificación falla la función retorna (-1), si esta vacío (0).
 *
 */
int al_deleteArrayList(ArrayList* this);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief obtiene la cantidad de elementos del arraylist y lo retorna.
 *
 * \param this ArrayList* el array list se pasa como parametro.
 * \return int retorna el tamaño del arraylist.
 *
 */
int al_len(ArrayList* this);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Retorna un puntero al elemento que se encuentra en el índice especificado. Verificando que el
 *         puntero this sea distinto de NULL y que num sea positivo e inferior al tamaño del array.
 *
 * \param this ArrayList* el arraylist se pasa como parametro
 * \param num int el indice ingresado se pasa como parametro.
 * \return Si falla, la función retorna (NULL) y si tiene éxito retorna el elemento.
 *
 */
void* al_get(ArrayList* this, int index);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Comprueba si existe el elemento que se le pasa como parámetro. Verificando que tanto el
 *         puntero this como pElement sean distintos de NULL. (es un buscador).
 *
 * \param this ArrayList* el arraylist se pasa como parametro.
 * \param pElement void* la lista de elementos se pasa como parametro.
 * \return int Si falla, retorna (-1), si encuentra el elemento (1) y si no lo encuentra (0).
 *
 */
int al_contains(ArrayList* this, void* pElement);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Inserta un elemento en el ArrayList, en el índice especificado. Verificando que tanto el puntero
 *         this como pElement sean distintos de NULL y que index sea positivo e inferior al tamaño del array. reescribe si es necesario.
 *
 * \param this ArrayList* el array list se pasa como parametro
 * \param index int el indice se pasa com parametro
 * \param pElement void* la lista de elementos se pasa como parametro.
 * \return int Si falla, retorna (-1) y si tiene éxito (0).
 *
 */
int al_set(ArrayList* this, int index,void* pElement);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Elimina un elemento del ArrayList, en el índice especificado. Verificando que el puntero this
 *         sea distinto de NULL y que index sea positivo e inferior al tamaño del array.
 *
 * \param this ArrayList* el array list se pasa como parametro.
 * \param index int el indice se pasa como parametro
 * \return int Si falla, la función retorna (-1) y si tiene éxito (0).
 *
 */
int al_remove(ArrayList* this,int index);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Borra todos los elementos de ArrayList. Verificando que el puntero this sea distinto de NULL. (solo la informacion, no como el delete que borra todo)
 *
 * \param this ArrayList* el arraylist se pasa como parametro.
 * \return int Si la verificación falla la función retorna (-1) y si tiene éxito (0).
 *
 */
int al_clear(ArrayList* this);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Retorna un nuevo ArrayList copia del ArrayList original. Verificando que el puntero this sea distinto de NULL.
 *
 * \param this ArrayList* el array list se pasa como parametro.
 * \return ArrayList* Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el nuevo array.
 *
 */
ArrayList* al_clone(ArrayList* this);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Desplaza los elementos e inserta en la posición index. Verificando que tanto el puntero this como pElement sean distintos de NULL
 *         y que index sea positivo e inferior al tamaño del array.
 *
 * \param this ArrayList* el arraylist se pasa como parametro.
 * \param index int el indice se pasa como parametro
 * \param pElement void* la lista de elementos se pasa como parametro.
 * \return int Si la verificación falla la función retorna (-1) y si tiene éxito (0).
 *
 */
int al_push(ArrayList* this, int index, void* pElement);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Retorna el índice de la primera aparición de un elemento (element) en el ArrayList. Verificando
 *         que tanto el puntero this como pElement sean distintos de NULL.
 *
 * \param this ArrayList* el arraylist se pasa como parametro.
 * \param pElement void* la lista de elementos se pasa como parametro.
 * \return int Si la verificación falla o no encuentra el elemento la función retorna (-1) y si encuentra el elemento retorna su índice.
 *
 */
int al_indexOf(ArrayList* this, void* pElement);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Retorna cero si contiene elementos y uno si no los tiene. Verificando que el puntero this sea distinto de NULL.
 *
 * \param this ArrayList* el arraylist se pasa como parametro.
 * \return int Si la verificación falla la función retorna (-1), si esta vacío (1) y si contiene elementos (0).
 *
 */
int al_isEmpty(ArrayList* this);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Retorna un puntero al elemento que se encuentra en el índice especificado y luego lo elimina de la lista.
 *         Verificando que el puntero this sea distinto de NULL y que index sea positivo e inferior al tamaño del array.
 *
 * \param this ArrayList* el arraylist se pasa como parametro.
 * \param index int el indice se pasa como parametro.
 * \return void* Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el elemento.
 *
 */
void* al_pop(ArrayList* this,int index);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Retorna un nuevo ArrayList con el subconjunto de elementos. Verificando que el puntero this sea distinto
 *         de NULL y que tanto el indice 'from' como 'to' sean positivos e inferiores al tamaño del array.
 *
 * \param this ArrayList* el arraylist se pasa como parametro.
 * \param from int el valor del indice "desde" donde se empieza a copiar se pasa como parametro.
 * \param to int el valor del indice "hasta" donde se termina de copiar se pasa como parametro.
 * \return ArrayList*  Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el nuevo arraylist.
 *
 */
ArrayList* al_subList(ArrayList* this,int from,int to);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Comprueba si los elementos pasados son contenidos por el ArrayList. Verificando que tanto el
 *         puntero this como this2 sean distintos de NULL.
 *
 * \param this ArrayList* el arraylist se pasa como parametro.
 * \param this2 ArrayList* el segundo arraylist se pasa como parametro.
 * \return int Si la verificación falla o no encuentra el elemento la función retorna (-1), si las listas difieren (0) y si ambas listas son iguales retorna (1).
 *
 */
int al_containsAll(ArrayList* this,ArrayList* this2);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Ordena los elementos del array recibiendo como parámetro la función que sera la encargada de determinar que elemento es mas grande que otro
 *         y si se debe ordenar de manera ascendente o descendente. Verificando que tanto el puntero this como el puntero a la funcion pFunc sean distintos de NULL.
 *
 * \param this arraylist* el arraylist se pasa como parametro.
  * \param pFunc (*pFunc) puntero a la funcion para comparar elementos del arraylist.
 * \param order int  [1] indica ASCENDENTE - [0] indica DESCENDENTE
 * \return int  Si la verificación falla (-1) caso contrario retorna (0).
 *
 */
int al_sort(ArrayList* this, int (*pFunc)(void*,void*), int order);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief incrementa elementos (espacio vacios) en AL_INCREMENT elementos. Verificando que el arrayList sea distinto de NULL.
 *
 * \param this ArrayList* el arraylist se pasa como parametro.
 * \return int Si la verificación falla, retorna (-1), caso contrario retorna (0).
 *
 */
int resizeUp(ArrayList* this);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief expande array de elementos(agranda).  Verificando que el arrayList sea distinto de NULL.
 *
 * \param this arrayList* el arraylist se pasa como parametro.
 * \param index int el indice del elemento
 * \return int Si la verificación falla, retorna (-1), caso contrario retorna (0).
 *
 */
int expand(ArrayList* this,int index);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief contrae el array de elementos (minimiza) mueve. Verificando que el arrayList sea distinto de NULL.
 *
 * \param this ArrayList* el arraylist se pasa como parametro.
 * \param index int el indice del elemento
 * \return int Si la verificación falla, retorna (-1), caso contrario retorna (0).
 *
 */
int contract(ArrayList* this,int index);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief disminuye los numeros de elementor en el arraylist a AL_INITIAL_VALUE.
 * \param this ArrayList* el arraylist se pasa como parametro.
 * \return int retorna (-1) si hay error [this es un puntero NULL o no puede asignar memoria] o (0) si tiene exito.
 */
int resizeDown(ArrayList* this);


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



/** \brief filtra un array list
 * \param listIn ArrayList* la arraylist se pasa como parametro.
 * \param functionFilter (*functionFilter) funcion pasada como argumento que decide si los elementos de la lista se copian o no.
 * \return ArrayList* retorna un nuevo ArrayList con ciertos elementos de la lista pasada como parametro.
 *
 */
ArrayList* al_filter (ArrayList* listIn, int(*functionFilter)(void*));

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
