#include <stdio.h>
#include <stdlib.h>
#include "Examen.h"

static ArrayList* lista1;
static ArrayList* lista2;

void examen_init()
{
    lista1=al_newArrayList();
    lista2=al_newArrayList();
    lt_miMenu(MENU);
    lt_end();
    //lt_showDate();
}

void examen_rename1() //CARGAR DEPOSITOS
{
    par_loader(lista1,lista2,"dep0","dep1");
}

void examen_rename2() //LISTAR PRODUCTOS DE DEPOSITO
{
    int conf, depot = dat_getInt("por favor ingrese el numero de deposito a listar: ");
    while (!(depot ==1 && depot ==2 ))
    {
        printf("ERROR los depositos existentes son el 1 o el 2.\n");
        depot= dat_getInt("Ingrese uno por favor: ");
    }
    printf("usted a ingresado: %d", depot);
    if ((conf=lt_enterOrEsc("\n")))
    {
        if (depot==1 )
            enty1_mapAll(lista1);
        if (depot==2)
            enty2_mapAll(lista2);
    }
}

void examen_rename3() // MOVER PRODUCTOS A DEPOSITO
{
    int origen, destino, otro, codigoProd, conf, i;
    Ent1* aux1;
    //Ent2* aux2; //no se termina usando pero esta ok

    origen= dat_getInt("por favor ingrese el numero de deposito origen: ");

    otro = origen;
    while (!(origen ==1 && origen ==2 ))
    {
        printf("ERROR los depositos existentes son el 1 o el 2.\n");
        origen= dat_getInt("Ingrese uno por favor: ");
        otro=origen;
    }

    printf("usted a ingresado: %d", origen);
    if ((conf=lt_enterOrEsc("\n")))
    {
        destino= dat_getInt("por favor ingrese el numero de deposito destino: ");
        while (!(destino ==1 && destino ==2 && destino==otro))
        {
            if (destino==otro)
                printf("El deposito destino no puede ser igual al deposito origen");
            else
                printf("ERROR los depositos existentes son el 1 o el 2.\n");

            destino= dat_getInt("Ingrese uno por favor: ");
        }
        printf("usted a ingresado: %d", destino);
        if ((conf=lt_enterOrEsc("\n")))
        {
            if (origen==1)
            {
                enty1_mapAll(lista1);
            }
            else
            {
                enty2_mapAll(lista2);
            }
            codigoProd = dat_getInt("\nPor favor ingrese el codigo de producto a mover: ");

            for(i=0;i<al_len(lista1);i++)
            {
                aux1 = al_get(lista1,i);
                if (codigoProd==aux1->id)
                {
                    printf("producto encontrado, Seguro que desea Moverlo al otro deposito?");
                    if((conf=lt_enterOrEsc("\n")))
                    {
                        al_remove(lista1,i);
                        al_add(lista2,aux1);
                        break;
                    }
                }
            }
            while (i==al_len(lista1))
            {
                printf("El codigo de producto no existe en inventario");
                codigoProd = dat_getInt("\nReintente por favor: ");
                for(i=0;i<al_len(lista1);i++)
                {
                    aux1 = al_get(lista1,i);
                    if (codigoProd==aux1->id)
                    {
                        printf("producto encontrado, Seguro que desea Moverlo al otro deposito?");
                        if((conf=lt_enterOrEsc("\n")))
                        {
                            al_remove(lista1,i);
                            al_add(lista2,aux1);
                            break;
                        }
                    }
                }
            }
        }
    }
    //archivo
    par_saveFile1(lista1,"dep0");
    par_saveFile2(lista2,"dep1");
}

void examen_rename4() //DESCONTAR PRODUCTOS DE DEPOSITO
{
    int i, j, codProducto, cantidadDesc, cantidadFinal, conf;
    Ent1* aux1;
    Ent2* aux2;


    enty1_mapAll(lista1);
    enty2_mapAll(lista2);
    codProducto= dat_getInt("Por favor ingrese el codigo de producto que desea descontar una cantidad: ");

    for (i=0;i<al_len(lista1);i++)
    {
         aux1 = al_get(lista1,i);
         if (codProducto==aux1->id)
         {
             cantidadDesc= dat_getInt("\nIngrese la cantidad a descontar: ");
             while (cantidadDesc>aux1->estado) //es cualquiera pero no daba modificar la esturctura
             {
                 printf("\nla cantidad a descontar es mayor a la existente, por favor reingrese una cantidad:");
                 cantidadDesc = dat_getInt("");
             }
             printf("\nse descontaran %d productos al total de %d productos", cantidadDesc, aux1->estado);
             if ((conf=lt_enterOrEsc("\n")))
             {
                 cantidadFinal= aux1->estado - cantidadDesc;
                 if (cantidadFinal==0)
                 {
                     printf("\nse descontaran todos los productos, se eliminara el elemento del registro: ");
                     if ((conf=lt_enterOrEsc("\n")))
                     {
                         al_remove(lista1,i);
                         break;
                     }
                 }
                 else
                 {
                    aux1->estado= cantidadFinal;
                    al_set(lista1,i,aux1);
                    printf("\nse descontaron los productos");
                    break;
                 }
             }
         }
    }
    if(i==al_len(lista1))
    {
        for (j=0;i<al_len(lista2);j++)
        {
             aux2 = al_get(lista2,j);
             if (codProducto==aux2->id)
             {
                 cantidadDesc= dat_getInt("\nIngrese la cantidad a descontar: ");
                 while (cantidadDesc>aux2->estado) //es cualquiera pero no daba modificar la esturctura
                 {
                     printf("\nla cantidad a descontar es mayor a la existente, por favor reingrese una cantidad:");
                     cantidadDesc = dat_getInt("");
                 }
                 printf("\nse descontaran %d productos al total de %d productos", cantidadDesc, aux2->estado);
                 if ((conf=lt_enterOrEsc("\n")))
                 {
                     cantidadFinal= aux2->estado - cantidadDesc;
                     if (cantidadFinal==0)
                     {
                         printf("\nse descontaran todos los productos, se eliminara el elemento del registro: ");
                         if ((conf=lt_enterOrEsc("\n")))
                         {
                             al_remove(lista2,j);
                             break;
                         }
                     }
                     else
                     {
                        aux2->estado= cantidadFinal;
                        al_set(lista2,j,aux2);
                        printf("\nse descontaron los productos");
                        break;
                     }
                 }
             }
        }
    }
    if(i==al_len(lista1) && j==al_len(lista2))
    {
        printf("\nel codigo de producto no se encuentra en el registro\n");
    }
    //archivo
    par_saveFile1(lista1,"dep0");
    par_saveFile2(lista2,"dep1");
}

void examen_rename5() //AGREGAR PRODUCTOS A DEPOSITO
{
    int i, j, codProducto, cantidadSuma, cantidadFinal, conf, deposito, newCantidad, newId;
    char newProducto[242];
    Ent1* aux1;
    Ent2* aux2;

    enty1_mapAll(lista1);
    enty2_mapAll(lista2);
    codProducto= dat_getInt("Por favor ingrese el codigo de producto que desea descontar una cantidad: ");

    for (i=0;i<al_len(lista1);i++)
    {
         aux1 = al_get(lista1,i);
         if (codProducto==enty1_getId(aux1))
         {
             cantidadSuma= dat_getInt("\nIngrese la cantidad a sumar: ");
         }
         printf("\nse sumaran %d productos al total de %d productos", cantidadSuma, enty1_getEstado(aux1));
             if ((conf=lt_enterOrEsc("\n")))
             {
                 cantidadFinal = (enty1_getEstado(aux1)) + cantidadSuma;
                 enty1_setEstado(aux1,cantidadFinal);
                 al_set(lista1,i,aux1);
                 printf("\nSe sumaron los productos");
                 break;
             }
    }
    if(i==al_len(lista1))
    {
        for (j=0;i<al_len(lista2);j++)
        {
             aux2 = al_get(lista2,j);
             if (codProducto==enty2_getId(aux2))
             {
                 cantidadSuma= dat_getInt("\nIngrese la cantidad a sumar: ");
             }
             printf("\nse sumaran %d productos al total de %d productos", cantidadSuma, enty2_getEstado(aux2));
                 if ((conf=lt_enterOrEsc("\n")))
                 {
                     cantidadFinal = (enty2_getEstado(aux2)) + cantidadSuma;
                     enty2_setEstado(aux2,cantidadFinal);
                     al_set(lista2,j,aux2);
                     printf("\nSe sumaron los productos");
                     break;
                 }
        }
    }
    if(i==al_len(lista1) && j== al_len(lista2))
    {
        printf("\nEl codigo de producto no existe en el inventario, ");
        if ((conf=lt_enterOrEsc("desea crearlo?")))
        {
            deposito = dat_getInt("ingrese en que deposito guardara su producto:");
            while (!(deposito ==1 && deposito ==2 ))
            {
                printf("\nERROR los depositos existentes son el 1 o el 2.\n");
                deposito= dat_getInt("Ingrese uno por favor: ");
            }
            dat_getTexto("ingrese la descripcion del producto: ",newProducto,242);
            newCantidad = dat_getInt("ingrese la cantidad inicial de producto: ");
            newId= codProducto;

            if(deposito==1)
            {
                enty1_setId(aux1,newId);
                enty1_setNombre(aux1,newProducto);
                enty1_setEstado(aux1,newCantidad);
                al_add(lista1,aux1);
            }
            else
            {
                enty2_setId(aux2,newId);
                enty2_setNombre(aux2,newProducto);
                enty2_setEstado(aux2,newCantidad);
                al_add(lista2,aux2);
            }
        }
    }
    //archivo
    par_saveFile1(lista1,"dep0");
    par_saveFile2(lista2,"dep1");
}

void examen_rename6() //SALIR
{

}

void examen_rename7()
{

}

void examen_rename8()
{

}

void examen_rename9()
{

}

void examen_rename10()
{

}

void examen_rename1720() //SECRETO PARA CONTROL DE LISTAS Y ARCHIVOS
{

}


