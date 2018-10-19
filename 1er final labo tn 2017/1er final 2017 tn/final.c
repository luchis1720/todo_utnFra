#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>
#include <conio.h>
#include "luistoncic.h"
#include "ArrayList.h"
#include "final.h"


int final_loadClientFile(ArrayList* lista)
{
    int ans=-1;
    char nombreA[31];
    char apellidoA[31];
    char nameAUX[62];
    char idclien[6];
    char dniclien[10];
    int idA; //if 0 == NULL
    long int dniA;
    S_client* cliente;

    FILE* archivo;

    if(lista!=NULL)
    {
        archivo = fopen("clientes.txt","r");
        if(archivo == NULL)
        {
            printf("NO SE PUDO ABRIR EL ARCHIVO\n");
            fclose(archivo);
        }
        else
        {
            while(!feof(archivo))
            {
                fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",idclien,nombreA,apellidoA,dniclien);

                idA = atoi(idclien);
                dniA = atol(dniclien);

                strlwr(nombreA);
                strlwr(apellidoA);
                nombreA[0]= toupper(nombreA[0]);
                apellidoA[0]= toupper(apellidoA[0]);
                strcpy(nameAUX,apellidoA);
                strcat(nameAUX, ", ");
                strcat(nameAUX, nombreA);

                if((cliente=final_clienteNew())!= NULL)
                {
                    final_setIdCliente(cliente,idA);
                    final_setNameCliente(cliente,nameAUX);
                    final_setCodeCliente(cliente,dniA);

                    final_setCantVentaCliente(cliente,0);
                    final_setIdVentaCliente(cliente,0);
                    final_setPriceVentaCliente(cliente,0.0);
                    final_setProdVentaCliente(cliente,0);

                    lista->add(lista,cliente);
                    ans = 0;
                }
            }
            fclose(archivo);
        }
    }
    return ans;
}

int final_loadSaleFile(ArrayList* lista)
{
    int ans=-1, a;
    char idventaA[6];
    char idclienteA[6];
    char cantA[7];
    char precioA[20];
    char codprodA[6];
    int id_ventaAUX;
    int id_clienteAUX;
    int cod_productoAUX;
    float precioUnitAUX;
    int cant_ProdAUX;
    S_client* cliente;
    S_client* aux;

    FILE* archivo;

    if(lista!=NULL)
    {
        archivo = fopen("ventas.txt","r");
        if(archivo == NULL)
        {
            printf("NO SE PUDO ABRIR EL ARCHIVO\n");
            fclose(archivo);
        }
        else
        {
            while(!feof(archivo))
            {
                fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idventaA,idclienteA,codprodA,cantA,precioA);

                id_clienteAUX = atoi(idclienteA);
                id_ventaAUX = atoi(idventaA);
                cod_productoAUX= atoi(codprodA);
                cant_ProdAUX= atoi(cantA);
                precioUnitAUX= atoi(precioA);

                for(a=0; a<al_len(lista); a++)
                {
                    if((cliente=final_clienteNew())!= NULL)
                    {
                        cliente=al_get(lista,a);
                        if(final_cliente_getIdCliente(cliente)==id_clienteAUX)
                        {
                            if(final_cliente_getIdVenta(cliente)!=0)
                            {
                                if((aux=final_clienteNew())!=NULL)
                                {
                                    aux=cliente;
                                    final_setCantVentaCliente(aux,cant_ProdAUX);
                                    final_setIdVentaCliente(aux,id_ventaAUX);
                                    final_setPriceVentaCliente(aux,precioUnitAUX);
                                    final_setProdVentaCliente(aux,cod_productoAUX);

                                    lista->add(lista,aux);
                                    ans=0;
                                }
                            }
                            else
                            {
                                if((aux=final_clienteNew())!=NULL)
                                {
                                    aux=cliente;
                                    final_setCantVentaCliente(aux,cant_ProdAUX);
                                    final_setIdVentaCliente(aux,id_ventaAUX);
                                    final_setPriceVentaCliente(aux,precioUnitAUX);
                                    final_setProdVentaCliente(aux,cod_productoAUX);

                                    al_set(lista,a,aux); //reescribo...
                                    ans=0;
                                }
                            }
                        }
                    }
                }
            }
            fclose(archivo);
        }
    }
    return ans;
}

void final_firstClient(ArrayList* lista)
{
    S_client* cliente;
    if (lista!=NULL && (cliente=final_clienteNew())!=NULL)
    {
        cliente->dni=33655967;
        cliente->id=0;
        strcpy(cliente->nombre,"Luis, Toncic");

        lista->add(lista,cliente);
    }
}

int final_getLastId(ArrayList* lista)
{
    int ans, lastId, aux;
    S_client* cliente;
    if(lista!=NULL && (cliente=final_clienteNew())!=NULL)
    {
        if(al_len(lista)==0)
            lastId=0;
        else
        {
            aux=al_len(lista);
            cliente=al_get(lista,(aux-1));
            lastId=final_cliente_getIdCliente(cliente);
        }
        //printf("hy %d\n",lastId);
    }
    ans=lastId;

    return ans;
}

int final_altaCliente(ArrayList* lista)
{
    int ans=-1, lastId, checkId, checkName, checkCode, checkIdVenta, checkPrice, checkCant, checkProd;
    char nombre[62];
    long int dni;
    S_client* cliente;

    if((cliente=final_clienteNew()) !=NULL && lista!=NULL)
    {
        lastId= final_getLastId(lista);
        lt_getName(nombre);
        dni=lt_getLongInt("Por favor, ingrese D.N.I.: ",8);

        checkName=final_setNameCliente(cliente,nombre);
        checkCode=final_setCodeCliente(cliente,dni);
        checkId=final_setIdCliente(cliente,(lastId+1));

        checkIdVenta=final_setIdVentaCliente(cliente,0);
        checkPrice=final_setPriceVentaCliente(cliente,0.0);
        checkCant=final_setCantVentaCliente(cliente,0);
        checkProd=final_setProdVentaCliente(cliente,0);

        if(checkCode==0 && checkId==0 && checkName==0 && checkIdVenta==0 && checkPrice==0 && checkCant==0 && checkProd==0)
        {
            lista->add(lista,cliente);
            ans=0;
            //free(cliente);
        }
    }
    return ans;
}

void final_printCliente(ArrayList* lista)
{
    int i;
    S_client* cliente;

    if(lista!=NULL)
    {

        for(i=0; i<al_len(lista); i++)
        {
            if((cliente=final_clienteNew())!=NULL)
            {
                cliente=al_get(lista,i);
                if(final_cliente_getIdVenta(cliente)!=0)
                {
                    printf("ID: %d\tNOMBRE: %s\tD.N.I.: %ld\tID VENTA: %d\tCOD. PROD: %d\tTOTAL: $%.2f\n",final_cliente_getIdCliente(cliente),final_cliente_getNombre(cliente),final_cliente_getDni(cliente),final_cliente_getIdVenta(cliente),final_cliente_getCodProd(cliente),final_cliente_getPrecio(cliente));
                }
                else
                {
                    printf("ID: %d\t NOMBRE: %s\t D.N.I.: %ld\t  SIN VENTAS!! \n",final_cliente_getIdCliente(cliente),final_cliente_getNombre(cliente),final_cliente_getDni(cliente));
                }

                //free(cliente);
            }
        }
    }
}

void final_modificarCliente(ArrayList* lista, int index)
{
    S_client* cliente;
    int confirm,checkName=-1,checkCode=-1, a ;
    char nombre[62];
    long int dni;


    if(lista!=NULL)
    {
        for (a=0; a<al_len(lista); a++)
        {
            if((cliente=final_clienteNew())!=NULL)
            {
                cliente=al_get(lista, a);
                if(final_cliente_getIdCliente(cliente)==index)
                {
                    printf("se modificaran los datos de: NOMBRE %s ; D.N.I.: %ld \n",final_cliente_getNombre(cliente),final_cliente_getDni(cliente));
                    if((confirm=lt_enterOrEsc(" "))==1)
                    {
                        lt_getName(nombre);
                        dni=lt_getLongInt("Por favor, ingrese D.N.I.: ",8);

                        checkName=final_setNameCliente(cliente,nombre);
                        checkCode=final_setCodeCliente(cliente,dni);

                        if(checkCode==0 && checkName==0)
                        {
                            al_set(lista,a,cliente); //reescribo
                            printf("Cliente modificado con exito\n");
                        }
                    }
                }
            }
        }
    }
}

void final_bajaCliente(ArrayList* lista, int index)
{
    S_client* cliente;
    int confirm, checkId, a;


    if(lista!=NULL)
    {
        for (a=0; a<al_len(lista); a++)
        {
            if((cliente=final_clienteNew())!=NULL)
            {
                cliente=al_get(lista, a);
                if(final_cliente_getIdCliente(cliente)==index)
                {
                    printf("se dara de baja a: NOMBRE %s ; D.N.I.: %ld \n",final_cliente_getNombre(cliente),final_cliente_getDni(cliente));
                    if((confirm=lt_enterOrEsc(" "))==1)
                    {
                        if(final_cliente_getIdVenta(cliente)!=0)
                        {
                            printf("Primero elimine la venta asociada, para dar de baja al cliente\n");
                        }
                        else
                        {
                            checkId=final_setIdCliente(cliente,0);
                            if(checkId==0)
                            {
                                al_set(lista,a,cliente); //reescribo
                                printf("Cliente dado de baja con exito\n");
                            }
                        }
                    }
                }
            }
        }
    }
}

int final_checkList(ArrayList* lista) //revisa si la lista esta con bajas logicas totales
{
    S_client* cliente;
    int cont=0, ans=-1, i;

    if(lista!=NULL && (cliente=final_clienteNew())!=NULL)
    {
        for(i=0; i<al_len(lista); i++)
        {
            cliente=al_get(lista,i);
            if(final_cliente_getIdCliente(cliente)!=0)
                cont++;
        }
        if(cont>0)
            ans=0;
    }
    return ans;
}

void final_surnameSort(ArrayList* lista)
{
    int check;
    check= al_sort(lista,final_compByName,1);
    if(check==0)
        printf("\nDatos ordenados por Apellido\n");
    else
    {
        printf("\nNo se pudo ordenar\n");
    }
}

int final_compByName(S_client* nombre1, S_client* nombre2)
{
    int ans;
    ans = strcmp(nombre1->nombre,nombre2->nombre);
    return ans;
}

int final_compByNumber(S_client* num1, S_client* num2)
{
    int ans = 0;

    if(num1->id > num2->id)
    {
        ans = 1;
    }
    else if(num1->id < num2->id)
    {
        ans = -1;
    }
    return ans;
}

int final_ventaNuevaCliente(ArrayList* lista,int index)
{
    S_client* cliente;
    S_client* aux;
    int ans=1, a, confirm, confirm2, venta, conf1, conf2, conf3, checkIdVenta, checkPrice, checkCant, checkProd;
    int cant1, cant2, cant3, cod1, cod2, cod3, idVenta1, idVenta2, idVenta3;
    float precio1, precio2, precio3;

    if(lista!=NULL)
    {
        for (a=0; a<al_len(lista); a++)
        {
            if((cliente=final_clienteNew())!=NULL)
            {
                cliente=al_get(lista, a);
                if(final_cliente_getIdCliente(cliente)==index)
                {

                    printf("se vendera a: NOMBRE %s ; D.N.I.: %ld \n",final_cliente_getNombre(cliente),final_cliente_getDni(cliente));
                    if((confirm=lt_enterOrEsc(" "))==1)
                    {
                        if(final_cliente_getIdVenta(cliente)!=0)
                        {
                            if((confirm2=lt_enterOrEsc("El cliente ya tiene una venta asociada, desea realizar otra?"))==1)
                            {
                                aux=cliente;
                                //se puede funcionar...
                                printf("1.-TV LG 32 - $8999.99\n2.-PS4 - $12999.99\n3.-IPHONE7 - $19480.99");
                                venta=lt_getInt("ingrese el producto que desea vender: \n");
                                if(venta==1)
                                {
                                    conf1=lt_enterOrEsc("Usted ingreso TV LG 32 - $8999.99");
                                    if(conf1==1);
                                    {
                                        cant1=lt_getInt("ingrese la cantidad que desea vender: \n");
                                        precio1=8999.99*cant1;
                                        cod1=TVLG;
                                        if((idVenta1=final_getLastIdVenta(lista))==-1)
                                        {
                                            printf("ERROR, Generando codigo de venta");
                                        }
                                        else
                                        {
                                            checkIdVenta=final_setIdVentaCliente(aux,(idVenta1+1));
                                            checkPrice=final_setPriceVentaCliente(aux,precio1);
                                            checkCant=final_setCantVentaCliente(aux,cant1);
                                            checkProd=final_setProdVentaCliente(aux,cod1);

                                            if(checkIdVenta==0 && checkPrice==0 && checkCant==0 && checkProd==0)
                                            {
                                                lista->add(lista,aux);
                                                ans=0;
                                            }
                                        }
                                    }
                                }
                                if(venta==2)
                                {
                                    conf2=lt_enterOrEsc("Usted ingreso PS4 - $12999.99");
                                    if(conf2==1);
                                    {
                                        cant2=lt_getInt("ingrese la cantidad que desea vender: \n");
                                        precio2=12999.99*cant2;
                                        cod2=PLAY;
                                        if((idVenta2=final_getLastIdVenta(lista))==-1)
                                        {
                                            printf("ERROR, Generando codigo de venta");
                                        }
                                        else
                                        {
                                            checkIdVenta=final_setIdVentaCliente(aux,(idVenta2+1));
                                            checkPrice=final_setPriceVentaCliente(aux,precio2);
                                            checkCant=final_setCantVentaCliente(aux,cant2);
                                            checkProd=final_setProdVentaCliente(aux,cod2);

                                            if(checkIdVenta==0 && checkPrice==0 && checkCant==0 && checkProd==0)
                                            {
                                                lista->add(lista,aux);
                                                ans=0;
                                            }
                                        }
                                    }
                                }
                                if(venta==3)
                                {
                                    conf3=lt_enterOrEsc("Usted ingreso IPHONE7 - $19480.99");
                                    if(conf3==1);
                                    {
                                        cant3=lt_getInt("ingrese la cantidad que desea vender: \n");
                                        precio3=19480.99*cant3;
                                        cod3=CELU;
                                        if((idVenta3=final_getLastIdVenta(lista))==-1)
                                        {
                                            printf("ERROR, Generando codigo de venta");
                                        }
                                        else
                                        {
                                            checkIdVenta=final_setIdVentaCliente(aux,(idVenta3+1));
                                            checkPrice=final_setPriceVentaCliente(aux,precio3);
                                            checkCant=final_setCantVentaCliente(aux,cant3);
                                            checkProd=final_setProdVentaCliente(aux,cod3);

                                            if(checkIdVenta==0 && checkPrice==0 && checkCant==0 && checkProd==0)
                                            {
                                                lista->add(lista,aux);
                                                ans=0;
                                            }
                                        }
                                    }

                                }                //...Hasta aca.
                            }
                        }//Fin venta !=0
                        else
                        {
                            printf("1.-TV LG 32 - $8999.99\n2.-PS4 - $12999.99\n3.-IPHONE7 - $19480.99");
                            venta=lt_getInt("ingrese el producto que desea vender: \n");
                            if(venta==1)
                            {
                                conf1=lt_enterOrEsc("Usted ingreso TV LG 32 - $8999.99");
                                if(conf1==1);
                                {
                                    cant1=lt_getInt("ingrese la cantidad que desea vender: \n");
                                    precio1=8999.99*cant1;
                                    cod1=TVLG;
                                    if((idVenta1=final_getLastIdVenta(lista))==-1)
                                    {
                                        printf("ERROR, Generando codigo de venta");
                                    }
                                    else
                                    {
                                        checkIdVenta=final_setIdVentaCliente(cliente,(idVenta1+1));
                                        checkPrice=final_setPriceVentaCliente(cliente,precio1);
                                        checkCant=final_setCantVentaCliente(cliente,cant1);
                                        checkProd=final_setProdVentaCliente(cliente,cod1);

                                        if(checkIdVenta==0 && checkPrice==0 && checkCant==0 && checkProd==0)
                                        {
                                            al_set(lista,a,cliente);// Reescribo
                                            ans=0;
                                        }
                                    }
                                }
                            }
                            if(venta==2)
                            {
                                conf2=lt_enterOrEsc("Usted ingreso PS4 - $12999.99");
                                if(conf2==1);
                                {
                                    cant2=lt_getInt("ingrese la cantidad que desea vender: \n");
                                    precio2=12999.99*cant2;
                                    cod2=PLAY;
                                    if((idVenta2=final_getLastIdVenta(lista))==-1)
                                    {
                                        printf("ERROR, Generando codigo de venta");
                                    }
                                    else
                                    {
                                        checkIdVenta=final_setIdVentaCliente(cliente,(idVenta2+1));
                                        checkPrice=final_setPriceVentaCliente(cliente,precio2);
                                        checkCant=final_setCantVentaCliente(cliente,cant2);
                                        checkProd=final_setProdVentaCliente(cliente,cod2);

                                        if(checkIdVenta==0 && checkPrice==0 && checkCant==0 && checkProd==0)
                                        {
                                            al_set(lista,a,cliente);// Reescribo
                                            ans=0;
                                        }
                                    }
                                }
                            }
                            if(venta==3)
                            {
                                conf3=lt_enterOrEsc("Usted ingreso IPHONE7 - $19480.99");
                                if(conf3==1);
                                {
                                    cant3=lt_getInt("ingrese la cantidad que desea vender: \n");
                                    precio3=19480.99*cant3;
                                    cod3=CELU;
                                    if((idVenta3=final_getLastIdVenta(lista))==-1)
                                    {
                                        printf("ERROR, Generando codigo de venta");
                                    }
                                    else
                                    {
                                        checkIdVenta=final_setIdVentaCliente(cliente,(idVenta3+1));
                                        checkPrice=final_setPriceVentaCliente(cliente,precio3);
                                        checkCant=final_setCantVentaCliente(cliente,cant3);
                                        checkProd=final_setProdVentaCliente(cliente,cod3);

                                        if(checkIdVenta==0 && checkPrice==0 && checkCant==0 && checkProd==0)
                                        {
                                            al_set(lista,a,cliente);// Reescribo
                                            ans=0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

            }
        }
    }
    return ans;
}

int final_getLastIdVenta(ArrayList* lista)
{
    int ans=-1, lastId=1, aux, venta, venta2=0, i;
    S_client* cliente;
    if(lista!=NULL && (cliente=final_clienteNew())!=NULL)
    {
        if(al_len(lista)==0)
            lastId=0;
        else
        {
            aux=al_len(lista);
            for(i=0; i<aux; i++)
            {
                cliente=al_get(lista,i);
                if(final_cliente_getIdVenta(cliente)!=0)
                {
                    venta= final_cliente_getIdVenta(cliente);
                    if(venta>venta2)
                        venta2=venta;
                }
            }
            //lastId=cliente->id_venta;
        }
        //printf("hy %d\n",lastId);
    }
    if (lastId!=0)
        ans=venta2;
    //ans=lastId;

    return ans;
}

void final_anularVenta(ArrayList* lista, int index)
{
    S_client* cliente;
    int confirm, checkId, a;

    if(lista!=NULL)
    {
        for (a=0; a<al_len(lista); a++)
        {
            if((cliente=final_clienteNew())!=NULL)
            {
                cliente=al_get(lista, a);
                if(final_cliente_getIdCliente(cliente)==index)
                {
                    printf("se dara de baja a: NOMBRE: %s ;D.N.I.: %ld ;",final_cliente_getNombre(cliente),final_cliente_getDni(cliente));
                    if(final_cliente_getCodProd(cliente)==TVLG)
                        printf("PRODUCTO: TV LG 32 ;CANT: %d\n",final_cliente_getCantidad(cliente));
                    if(final_cliente_getCodProd(cliente)==PLAY)
                        printf("PRODUCTO: PS4 ;CANT: %d\n",final_cliente_getCantidad(cliente));
                    if(final_cliente_getCodProd(cliente)==CELU)
                        printf("PRODUCTO: IPHONE7 ;CANT: %d\n",final_cliente_getCantidad(cliente));
                    if((confirm=lt_enterOrEsc(" "))==1)
                    {
                        checkId=final_setIdVentaCliente(cliente,0);
                        if(checkId==0)
                        {
                            al_set(lista,a,cliente); //reescribo
                            printf("Venta dada de baja con %cxito\n",130);
                        }
                    }
                }
            }
        }
    }
}

void final_informeVentasProductos(ArrayList* lista, int codigo)
{
    S_client* cliente;
    int i,producto;
    if(codigo==1)
    {
        producto=TVLG;
        printf("TV LG 32\n\n");
    }
    else if (codigo==2)
    {
        producto=PLAY;
        printf("PS4\n\n");
    }
    else
    {
        producto=CELU;
        printf("IPHONE7\n\n");
    }

    if(lista!=NULL)
    {
        for(i=0; i<al_len(lista); i++)
        {
            if((cliente=final_clienteNew())!=NULL)
            {
                cliente=al_get(lista,i);
                if(final_cliente_getCodProd(cliente)==producto)
                {
                    printf("CLIENTE: %s\tD.N.I.: %ld\tCANTIDAD: %d\tTOTAL:$%.2f\n",final_cliente_getNombre(cliente),final_cliente_getDni(cliente),final_cliente_getCantidad(cliente),final_cliente_getPrecio(cliente));
                }
            }
        }
    }
}

int final_volcadoArchivos(ArrayList* lista)
{
    int ans=-1, i;
    FILE *pFile;
    S_client* cliente;

    if ((pFile=fopen("informe.txt","w"))==NULL)
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO\n");
    }
    else
    {
        fprintf(pFile,"id_venta,id_cliente,Nombre,D.N.I.,codProducto,cantidad,precio\n");

        for(i=0; i<al_len(lista); i++)
        {
            if((cliente=final_clienteNew())!=NULL)
            {
                cliente=al_get(lista,i);
                fprintf(pFile,"%d,%d,%s,%ld,%d,%d,%.2f\n", final_cliente_getIdVenta(cliente), final_cliente_getIdCliente(cliente), final_cliente_getNombre(cliente), final_cliente_getDni(cliente), final_cliente_getCodProd(cliente), final_cliente_getCantidad(cliente), final_cliente_getPrecio(cliente));
            }
        }
        ans = 0;
    }

    fclose(pFile);
    //free(cliente);

    return ans;
}

void final_ventasXcliente(ArrayList* lista)
{
    S_client* cliente;
    S_client* aux;
    int i, k, vendido, cont=0;
    float acumtotal=0, acumtv=0, acumcel=0, acumplay=0;

    if(lista!=NULL)
    {
        for(i=0; i<al_len(lista); i++)
        {
            if((cliente=final_clienteNew())!=NULL)
            {
                cliente=al_get(lista,i);
                if(final_cliente_getIdVenta(cliente)!=0)
                {
                    vendido=final_cliente_getIdCliente(cliente);
                    for(k=0; k<al_len(lista); k++)
                    {
                        if((aux=final_clienteNew())!=NULL)
                        {
                            aux=al_get(lista,k);
                            if(final_cliente_getIdCliente(aux)==vendido)
                            {
                                if(final_cliente_getCodProd(aux)==TVLG)
                                {
                                    acumtv=acumtv+(8999.99*final_cliente_getCantidad(aux));
                                    cont++;
                                }
                                else if(final_cliente_getCodProd(aux)==PLAY)
                                {
                                    acumplay=acumplay+(12999.99*final_cliente_getCantidad(aux));
                                    cont++;
                                }
                                else if(final_cliente_getCodProd(aux)==CELU)
                                {
                                    acumcel=acumcel+(19480.99*final_cliente_getCantidad(aux));
                                    cont++;
                                }
                            }
                        }
                    }
                    acumtotal= acumcel+acumplay+acumtv;
                    printf("CLIENTE: %s\tDNI: %ld\tREALIZO %d COMPRAS, POR UN MONTO TOTAL DE: $%.2f\n",final_cliente_getNombre(cliente),final_cliente_getDni(cliente),cont,acumtotal);
                }
            }
        }
    }
}






//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//--MANEJO DE DATOS-------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



S_client* final_clienteNew()
{
    S_client* newStruct;

    newStruct= (S_client*)malloc(sizeof(S_client));
    if(newStruct!=NULL)
        return newStruct;

    return NULL;
}

int final_setNameCliente(S_client* pointer, char name[])
{
    int ans=-1;
    if(pointer!=NULL && name!=NULL)
    {
        strcpy(pointer->nombre,name);
        ans=0;
    }
    return ans;
}

int final_setCodeCliente(S_client* pointer, long int code)
{
    int ans=-1;
    if(pointer!=NULL)
    {
        pointer->dni=code;
        ans=0;
    }
    return ans;
}

int final_setIdCliente(S_client* pointer,int num)
{
    int ans=-1;
    if(pointer!=NULL)
    {
        pointer->id=num;
        ans=0;
    }
    return ans;
}

int final_setIdVentaCliente(S_client* pointer, int num)
{
    int ans=-1;
    if(pointer!=NULL)
    {
        pointer->id_venta=num;
        ans=0;
    }

    return ans;
}

int final_setCantVentaCliente(S_client* pointer, int cant)
{
    int ans=-1;
    if(pointer!=NULL)
    {
        pointer->cant_Prod=cant;
        ans=0;
    }
    return ans;
}

int final_setProdVentaCliente(S_client* pointer, int code)
{
    int ans=-1;
    if(pointer!=NULL)
    {
        pointer->cod_producto =code;
        ans=0;
    }
    return ans;
}

int final_setPriceVentaCliente(S_client* pointer, float price)
{
    int ans=-1;
    if(pointer!=NULL)
    {
        pointer->precioUnit=price;
        ans=0;
    }
    return ans;
}

int final_cliente_getIdVenta(S_client* pointer)
{
    int ans=-1;

    if(pointer!=NULL)
    {
        ans=pointer->id_venta;
    }
    return ans;
}

int final_cliente_getIdCliente(S_client* pointer)
{
    int ans=-1;

    if(pointer!=NULL)
    {
        ans=pointer->id;
    }
    return ans;
}

char* final_cliente_getNombre(S_client* pointer)
{
    char* name;
    if (pointer!=NULL)
        name= pointer->nombre;
    return name;
}

long int final_cliente_getDni(S_client* pointer)
{
    long int ans=-1;

    if(pointer!=NULL)
    {
        ans=pointer->dni;
    }
    return ans;
}

int final_cliente_getCodProd(S_client* pointer)
{
    int ans=-1;

    if(pointer!=NULL)
    {
        ans=pointer->cod_producto;
    }
    return ans;
}

int final_cliente_getCantidad(S_client* pointer)
{
    int ans=-1;

    if(pointer!=NULL)
    {
        ans=pointer->cant_Prod;
    }
    return ans;
}

float final_cliente_getPrecio(S_client* pointer)
{
    float ans=-1;

    if(pointer!=NULL)
    {
        ans=pointer->precioUnit;
    }
    return ans;
}





int final_saveClientFile(ArrayList* lista)
{
    int ans=-1, i;
    FILE *pFile;
    S_client* cliente;

    if ((pFile=fopen("cliente.txt","w"))==NULL)
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO\n");
    }
    else
    {
        fprintf(pFile,"id_cliente,Nombre,D.N.I.\n");

        for(i=0; i<al_len(lista); i++)
        {
            if((cliente=final_clienteNew())!=NULL)
            {
                cliente=al_get(lista,i);
                fprintf(pFile,"%d,%s,%ld\n",  final_cliente_getIdCliente(cliente), final_cliente_getNombre(cliente), final_cliente_getDni(cliente));
            }
        }
        ans = 0;
    }

    fclose(pFile);
    //free(cliente);

    return ans;
}

int final_saveSaleFile(ArrayList* lista)
{
    int ans=-1, i;
    FILE *pFile;
    S_client* cliente;

    if ((pFile=fopen("venta.txt","w"))==NULL)
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO\n");
    }
    else
    {
        fprintf(pFile,"id_venta,id_cliente,codProducto,cantidad,precioUnitario\n");

        for(i=0; i<al_len(lista); i++)
        {
            if((cliente=final_clienteNew())!=NULL)
            {
                cliente=al_get(lista,i);
                if(final_cliente_getIdVenta(cliente)!=0)
                    fprintf(pFile,"%d,%d,%d,%d,%.2f\n", final_cliente_getIdVenta(cliente), final_cliente_getIdCliente(cliente), final_cliente_getCodProd(cliente), final_cliente_getCantidad(cliente), final_cliente_getPrecio(cliente));
            }
        }
        ans = 0;
    }

    fclose(pFile);
    //free(cliente);

    return ans;
}

