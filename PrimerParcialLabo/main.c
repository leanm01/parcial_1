/*

MERINO LEANDRO


Desarrollar en ANSI C:
Se necesita administrar la recaudacion de impuestos de los contribuyentes, y para ello
se deber� realizar un programa de acuerdo a lo siguiente:
Contar� con el siguiente men�:

1) Alta de Contribuyente: Se da de alta un contribuyente con nombre, apellido, y c.u.i.l. Se
generar� un ID �nico (comenzando en 1000) para este contribuyente que se imprimir� por
pantalla si el alta es correcta.

2) Modificar datos del contribuyente: Se ingresa el ID del contribuyente y se permitir�
cambiar el nombre, el apellido y el c.u.i.l.

3) Baja de contribuyente: Se ingresa el ID del contribuyente y se listar�n todas las
recaudaciones de dicho contribuyente. Luego se preguntar� si se quiere confirmar la
eliminaci�n, la cual implicar� la eliminaci�n de todos las recaudaciones y del contribuyente.

4) Recaudaci�n: Permitir� crear una nueva recaudaci�n. Se pedir�n los siguientes datos: ID
de contribuyente, mes, tipo (1-ARBA, 2-IIBB, 3-GANANCIAS) e importe. Se generar�
autom�ticamente un identificador num�rico (comenzando en 100) para la recaudaci�n y se
imprimir� en pantalla.

5) Refinanciar Recaudaci�n: Se pedir� el ID de la recaudaci�n y se imprimir� la informaci�n
del contribuyente al que pertenece, luego se pedir� confirmaci�n para cambiarse de estado y
se cambiar� al estado "refinanciar".

6) Saldar Recaudaci�n: Se pedir� el ID de la recaudaci�n y se imprimir� la informaci�n del
contribuyente al que pertenece, luego se pedir� confirmaci�n para cambiarse de estado y se
cambiar� al estado "saldado".

7) Imprimir Contribuyentes: Se imprimir� una lista de los contribuyentes con todos sus datos
junto con las Recaudaciones que posee.

8) Imprimir Recaudaci�n: Se imprimir� una lista de las Recaudaciones con estado
�saldadas� con todos sus datos junto con el c.u.i.l. y nombre del contribuyente
correspondiente.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "contribuyente.h"
#include "recaudacion.h"
#include "UTN.h"

#define TAM_CONTRI 2
#define TAM_RECAUD 2
int main()
{

	eContribuyente lista[TAM_CONTRI];
	initContribuyente(lista, TAM_CONTRI);

	eRecaudacion listaRecaudacion[TAM_RECAUD];
	initRecaudacion(listaRecaudacion, TAM_RECAUD);



    int opcion;
    int contadorId=999;
    int contadorIdRecaudacion=99;
    int estadoAlta=0;
    int estadoBaja;
    int hayContribuyente=0;
    int hayRecaudacion=0;

    do
    {
        opcion = menu();
        switch(opcion)
        {



            case 1:


            	estadoAlta = agregarContribuyente(lista, TAM_CONTRI, contadorId);

            	 if (estadoAlta==-1)
                 {
            	      printf("\nAlta Contribuyente erronea!!\n\n");
            	 }
            	 else
            	 {
            	       printf("\nAlta Contribuyente exitosa!!\n\n");
            	       contadorId++;
            	       hayContribuyente=1;

                 }
               break;

            case 2:
            	if (hayContribuyente==0)
                {
            	    printf("\nNo hay contribuyentes que modificar!!\n\n");
            	}
            	else
            	{
            	    estadoBaja=modificacionContribuyente(lista, TAM_CONTRI);

            	    if (estadoBaja==-1)
            	    {
            	          printf("\nOperacion erronea!!\n\n");
                    }
            	    else
            	    {
            	          printf("\nOperacion exitosa!!\n\n");
            	    }
            	}
                break;


            case 3:



            	if (hayContribuyente==0)
                {
            	      printf("\nNo hay contribuyentes que dar de baja!!\n\n");
                }
            	else
            	{
            	    estadoBaja=bajaContribuyente(lista, TAM_CONTRI);

            	       if (estadoBaja==-1)
            	       {
            	            printf("\nOperacion erronea!!\n\n");

            	       }
            	       else
            	       {
            	            printf("\nOperacion exitosa!!\n\n");
            	       }
            	}


            break;
            case 4:


                estadoAlta = agregarRecaudacion(listaRecaudacion, TAM_RECAUD,lista, TAM_CONTRI, contadorIdRecaudacion);

            	 if (estadoAlta==-1)
                 {
            	      printf("\nAlta recaudacion erronea!!\n\n");
            	 }
            	 else
            	 {
            	       printf("\nAlta recaudacion exitosa!!\n\n");
            	       contadorId++;
            	       hayRecaudacion=1;

                 }
                 mostrarRecaudaciones(listaRecaudacion, TAM_RECAUD);
               break;
           case 5:

                if (hayRecaudacion==0)
                {
            	    printf("\nNo hay recaudacion que modificar!!\n\n");
            	}
            	else
            	{
            	    estadoBaja=modificacionRecaudacion(listaRecaudacion, TAM_RECAUD);

            	    if (estadoBaja==-1)
            	    {
            	          printf("\nOperacion erronea!!\n\n");
                    }
            	    else
            	    {
            	          printf("\nOperacion exitosa!!\n\n");
            	    }
            	}
                break;
            case 6:
            	mostrarRecaudaciones(listaRecaudacion, TAM_RECAUD);
            break;

            case 7:
                mostrarContribuyentes(lista, TAM_CONTRI);
            break;

            case 8:

            break;
            case 9:
            	printf("\nGracias por usar el programa...\n");
            break;
        }


    }while(opcion!=9);

    return 0;
}
