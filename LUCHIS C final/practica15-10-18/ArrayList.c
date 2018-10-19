#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

//luis toncic

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10


/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement)
{
    int ans = -1;
    if (this != NULL && pElement != NULL)
    {
        ans = 0;
        *( (this->pElements) + (this->size) ) = pElement;  //a un puntero le sumo un entero para desplazarme a otro puntero

        this->size++;  // porque acabo de agregar un elemento

        if (this->size == this->reservedSize) // aca redimensiono si es necesario
        {
            if(resizeUp(this) == -1)
            {
                ans = -1;
            }
        }
    }

    return ans;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int ans = -1;

    if(this != NULL)
    {
        free(this->pElements);
        ans = 0;
    }

    return ans;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int ans = -1;

    if(this != NULL)
    {
        ans = this->size;
    }

    return ans;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* ans = NULL;

    if(this != NULL && index >= 0 && index < this->len(this))
    {
        ans = *(this->pElements + index) ;
    }

    return ans;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int ans = -1;
    int i;

    if(this != NULL && pElement != NULL)
    {
        for(i=0; i < this->len(this); i++)
        {
            if(pElement == al_get(this,i))
            {
                ans = 1;
                break;
            }
            else
            {
                ans = 0;
            }
        }
    }

    return ans;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int ans = -1;
    if(this != NULL && pElement != NULL && index >= 0 && index < this->len(this))
    {
        *(this->pElements + index) = pElement;
        ans = 0;
    }

    return ans;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int ans = -1;
    if(this != NULL && index >= 0 && index < this->len(this))
    {
        contract(this, index);
        ans = 0;
    }
    return ans;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int ans = -1;
    if(this != NULL)
    {
        this->size = 0;
        resizeDown(this);
        ans=0;
    }

    return ans;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* ans = NULL;
    int i;
    if(this != NULL)
    {
        ans = al_newArrayList();
        for(i=0; i<this->len(this); i++)
        {
            al_add(ans,al_get(this,i));
        }
    }
    return ans;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int ans = -1;

    if(this != NULL && pElement != NULL && index >= 0 && index <= this->len(this))
    {
        expand(this,index);
        al_set(this,index,pElement);
        ans=0;
    }

    return ans;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement) //es un buscador
{
    int ans = -1;
    int i;
    if (this != NULL && pElement != NULL )
    {
        for(i=0; i<this->len(this); i++)
        {
            if(pElement == al_get(this,i))
            {
                ans = i;
                break;
            }
        }

    }
    return ans;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int ans = -1;
    if (this != NULL)
    {
        if(this->len(this) == 0)
        {
            ans = 1;
        }
        else
        {
            ans = 0;
        }
    }

    return ans;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* ans = NULL;
    if(this != NULL && index >= 0 && index < this->len(this) )
    {
        ans = al_get(this,index);
        al_remove(this,index);
    }
    return ans;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    void* ans = NULL;
    int i;
    if(this != NULL && from >= 0 && from < this->len(this) && to >= from && to <= this->len(this))
    {
        ans = al_newArrayList();
        for(i=from; i<to; i++)
        {
            al_add(ans,al_get(this,i));
        }
    }

    return ans ;
}


/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)  //compara si listas son iguales.
{
    int ans = -1;
    int i, cont=0;

    if(this != NULL && this2 != NULL)
    {
        if (al_len(this) == al_len(this2))
        {
            for(i=0; i < this->len(this); i++)
            {
                if(al_contains(this,al_get(this2,i))== 0)
                {
                    cont++;
                }
                else
                {
                    ans = 1;
                }
            }
        }
    }
    if (cont==al_len(this) && cont == al_len(this2))
        ans= 0;

    return ans;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void*,void*), int order)
{
    int ans = -1;
    if(this!=NULL && (order == 0 || order == 1) && (*pFunc) !=NULL)
    {
        ans = 0;
        int i, j;
        int orden;
        void* aux;

        for(i=0; i<this->size-1; i++)
        {
            for(j=i+1; j<this->size; j++)
            {
                orden = pFunc(al_get(this,i),al_get(this,j));
                if(orden == 1)
                {
                    if(order == 1)
                    {
                        aux = *(this->pElements+i);
                        *(this->pElements+i) = *(this->pElements+j);
                        *(this->pElements+j) = aux;
                    }
                }
                else
                {
                    if(order == 0)
                    {
                        aux = *(this->pElements+i);
                        *(this->pElements+i) = *(this->pElements+j);
                        *(this->pElements+j) = aux;
                    }
                }
            }
        }
    }

    return ans;
}

/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int ans = -1;
    void* auxiliar;

    if(this != NULL)
    {
        auxiliar =  realloc (this->pElements, sizeof(void*) * (this->reservedSize + AL_INCREMENT) ); // el tamaño del tipo de dato lo multiplico por el tamaño resevado + el espacio que agrego que es 10
        if (auxiliar != NULL)
        {
            this->pElements = auxiliar;
            this->reservedSize = this->reservedSize + AL_INCREMENT;
            ans = 0;
        }
    }

    return ans;

}

/** \brief Decrement the number of elements in pList to AL_INITIAL_VALUE.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                     (0) if ok
 */
int resizeDown(ArrayList* this)
{
    int ans = -1;
    void* auxiliar;
    if(this != NULL)
    {
        auxiliar = realloc(this->pElements,sizeof(void*)*AL_INITIAL_VALUE);
        if(auxiliar != NULL)
        {
            this->pElements = auxiliar;
            this->reservedSize = AL_INITIAL_VALUE;
            ans = 0;
        }
    }
    return ans;
}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int ans = -1;
    int i;

    if(this != NULL && index >= 0 && index <= this->size)
    {
        for( i=this->size; i >index; i--)
        {
            *(this->pElements + i) = *(this->pElements + (i-1));
        }
        this->size++;
        ans = 0;
    }
    return ans;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int ans = -1;
    int i;

    if(this != NULL && index >= 0 && index < this->size)
    {
        for( i=index; i<((this->size)-1); i++)
        {
            *(this->pElements + i) = *(this->pElements + (i+1)) ;
        }
        this->size--;

        ans = 0;
    }
    return ans;
}

/*
ArrayList* al_filter (ArrayList* listIn, int(*functionFilter)(void*))
{
    void* returnAux = NULL;
    int i;
    void* auxElement;

    if(listIn != NULL && functionFilter!= NULL)
    {
        returnAux = al_newArrayList();
        for(i=0; i<al_len(listIn); i++)
        {
            auxElement = al_get(listIn,i);
            if (functionFilter(auxElement) == 1)
            {
                al_add(returnAux,auxElement);
            }
        }
    }
    return returnAux;
}
*/


