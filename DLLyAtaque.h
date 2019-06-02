#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

typedef struct
{
	char nombre[30];
	int dano;
	unsigned int dado;
	int habilidad;
}Ataque;

typedef struct Node
{
	struct Node *next;
	struct Node *prev;
	Ataque guajolocombo;
}Node;

typedef struct
{
	Node *first;
	Node *last;
	Node *cursor;
    size_t len;
}DLL;



/*
* @brief Crea un Ataque y lo Almacena en una DLL
* @param Un apuntador a la DLL en donde se almacenara el ataque y el numero del ataque 
*/
void newAtaque( DLL*this, int type );

/*
* @brief Crea una DLL 
* @return Un apuntador a la DLL creada
*/
DLL* DLL_New();

/*
* @brief Apunta al nodo en el que se encuentra el cursor de la DLL de ataques
* @param Un apuntador a DLL 
* @return Devuelve el Ataque que es apuntado por el cursor de la DLL
*/
Ataque DLL_Peek( DLL* this );

/*
* @brief Coloca el cursor al inicio de la DLL 
* @param Un apuntador a DLL
*/
void DLL_CursorFirst( DLL *this );

/*
* @brief Mueve el cursor un nodo a la derecha
* @param Un apuntador a DLL
*/
void DLL_CursorNext( DLL *this );

/*
* @brief Mueve el cursor un nodo a la izquierda 
* @param Un apuntador a DLL
*/
void DLL_CursorPrev( DLL *this );

/*
* @brief Indica si la DLL esta vacia
* @param Un apuntador a DLL
* @return true o false dependendiendo si la DLL se encuentra vacia
*/
bool DLL_IsEmpty( DLL* this );

/*
* @brief Vacía la DLL 
* @param Un apuntador a DLL
*/
void DLL_MakeEmpty( DLL* this );

/*
* @brief Indica la cantidad de ataques en la DLL 
* @param Un apuntador a DLL
* @return La cantidad de Ataques en la DLL
*/
size_t DLL_Len( DLL* this );

/*
* @brief Muestra un menu en el cual el usuario indicara 
	que ataque desea utilizar 
* @param Un apuntador a DLL
* @return El ataque seleccionado por el usuario 
*/
Ataque Ataque_Menu( DLL* this );

/*
* @brief Busca un ataque al azar del enemigo 
* @param Un apuntador a DLL 
* @return Un ataque aleatorio del enemigo
*/
Ataque Ataque_Enemigo ( DLL* lista );

/*
* @brief Borra una DLL
* @param Un apuntador a la DLL que se desea borrar 
*/
void DLL_Delete( DLL* this );
