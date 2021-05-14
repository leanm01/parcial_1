#ifndef CONTRIBUYENTE_H_
#define CONTRIBUYENTE_H_

typedef struct
{

	int idContribuyente;
    char nombre[25];
    char apellido[25];
	int cuil;
	int isEmpty;

}eContribuyente;

int initContribuyente(eContribuyente arrayContribuyente[], int tamArray);

int agregarContribuyente(eContribuyente arrayContribuyente[], int tamArray, int contador);

int mostrarContribuyentes(eContribuyente arrayContribuyente[] ,int tamArray);

int mostrarContribuyente(eContribuyente arrayContribuyente[] ,int i);

int modificacionContribuyente(eContribuyente arrayContribuyente[], int tamArray);

int bajaContribuyente(eContribuyente arrayContribuyente[], int tamArray);

int mostrarContribuyentePorId(eContribuyente arrayContribuyente[], int tamArray,int id);


#endif
