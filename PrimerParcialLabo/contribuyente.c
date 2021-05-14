#include <stdio.h>
#include <stdlib.h>
#include "contribuyente.h"

int initContribuyente(eContribuyente arrayContribuyente[], int tamArray)
{
    int i;
    int resultado=-1;


       if (tamArray !=0)
        {
            for (i=0;i<tamArray;i++)
            {
            	arrayContribuyente[i].isEmpty=1;
                resultado=0;
            }
        }

        return resultado;
}
int agregarContribuyente(eContribuyente arrayContribuyente[], int tamArray, int contador)
{
    int resultado=0;
    int espacioLibre=-1;
    int i;
    /////
    if (tamArray >0)
    {
        for (i=0;i<tamArray;i++)
        {
            if (arrayContribuyente[i].isEmpty==1)
            {

                espacioLibre=i;

                break;
            }
        }
    }

    if(espacioLibre>=0)
    {


    	    utn_getNombre("\nIngrese el nombre: ","\nIngrese un nombre correcto: ",arrayContribuyente[espacioLibre].nombre,2,25);

    	    utn_getNombre("\nIngrese el apellido: ","\nIngrese un apellido correcto: ",arrayContribuyente[espacioLibre].apellido,2,25);

            utn_getInt("\nIngrese el cuil: ","\nIngresa un valor correcto 0-99999: ",&arrayContribuyente[espacioLibre].cuil,2,99999,0);


            arrayContribuyente[espacioLibre].idContribuyente=contador+1;
            arrayContribuyente[espacioLibre].isEmpty=0;


            resultado=1;
    }



    return resultado;
}
int mostrarContribuyentes(eContribuyente arrayContribuyente[] ,int tamArray)
{

    int i;
    int resultado=-1;
    if(arrayContribuyente != NULL && tamArray>=0)
    {
        for(i=0;i<tamArray;i++)
        {
            if(arrayContribuyente[i].isEmpty==0)
            {
            	mostrarContribuyente(arrayContribuyente,i);
            }

       }
       resultado=1;
    }

    return resultado;
}
int mostrarContribuyente(eContribuyente arrayContribuyente[] ,int i)
{
   printf("\nNOMBRE:%s---APELLIDO:%s---CUIL:%d---ID:%d\n",arrayContribuyente[i].nombre,
                                                          arrayContribuyente[i].apellido,
                                                          arrayContribuyente[i].cuil,
                                                          arrayContribuyente[i].idContribuyente);



    return 1;
}
int modificacionContribuyente(eContribuyente arrayContribuyente[], int tamArray)
{

    int retorno=-2;
    int opcionMod;
    int i;
    int aux;
    char auxChar;

    mostrarContribuyentes(arrayContribuyente,tamArray);

    utn_getInt("\nIngrese el ID  del usuario que quiera modificar: ","\nIngresa un valor correcto 0-1999: ",&aux,2,1999,0);


    if(tamArray > 0 && arrayContribuyente != NULL)
    {
        for(i=0;i<tamArray;i++)
        {
            if(aux==arrayContribuyente[i].idContribuyente && arrayContribuyente[i].isEmpty==0)
            {
            	mostrarContribuyente(arrayContribuyente,i);
                utn_getChar("\nDesea modificar este usuario(s--O--n): ","\nIngrese la opcion correcta entre(s--O--n): ",&auxChar,2);

                if(auxChar=='s')
                {
                    opcionMod=modificar();

                    switch(opcionMod)
                    {
                            case 1:
                        	    utn_getNombre("\nIngrese el nombre: ","\nIngrese un nombre correcto: ",arrayContribuyente[i].nombre,2,25);
                                break;
                            case 2:
                        	    utn_getNombre("\nIngrese el apellido: ","\nIngrese un apellido correcto: ",arrayContribuyente[i].apellido,2,25);
                                break;
                            case 3:
                                utn_getInt("\nIngrese el CUIL: ","\nIngresa un valor correcto 0-99999: ",&arrayContribuyente[i].cuil,2,99999,0);
                                break;

                    }
                    retorno=1;
                    break;
                }
            }
        }

    }


    return retorno;
}

int bajaContribuyente(eContribuyente arrayContribuyente[], int tamArray)
{
    int aux;
    char auxChar;
    int i;
    int resultado = 0;

    mostrarContribuyentes(arrayContribuyente,tamArray);

    utn_getInt("\nIngrese el legajo  del usuario que quiere dar de baja: ","\nIngresa un valor correcto 0-1999: ",&aux,2,1999,0);

    for(i=0;i<tamArray;i++)
    {
        if(aux==arrayContribuyente[i].idContribuyente && arrayContribuyente[i].isEmpty==0)
        {
        	mostrarContribuyente(arrayContribuyente,i);
            utn_getChar("\nDesea elimnar este usuario(s--O--n): ","\nIngrese la opcion correcta entre(s--O--n): ",&auxChar,2);

            if(auxChar=='s')
            {
            	arrayContribuyente[i].isEmpty=1;
                resultado=1;
                break;
            }
        }
    }
    return resultado;
}

int mostrarContribuyentePorId(eContribuyente arrayContribuyente[], int tamArray,int id)
{
     int i;
    if(arrayContribuyente != NULL && tamArray>=0)
    {
        for(i=0;i<tamArray;i++)
        {
            if(arrayContribuyente[i].isEmpty==0 && arrayContribuyente[i].idContribuyente==i)
            {
            	mostrarContribuyente(arrayContribuyente,i);

            }

       }

    }
    return 1;
}
