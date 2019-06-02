#ifndef  Personaje_INC
#define  Personaje_INC

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<time.h>

#include "DLLyAtaque.h"

typedef int Item;
typedef Item* ItemPtr;

typedef struct Personaje
{
	char* nombre;
	int vida;
	int vida_total;
	int fuerza;
	int inteligencia;
	int agilidad;
	DLL *ataques;
} Personaje;

/*
* @brief Crea un TDU Personaje 
* @return El apuntador al tipo de dato Personaje
*/
Personaje* Crear_Personaje( char* name );

/*
* @brief Crea un TDU Personaje que representa a un enemigo
* @return El apuntador al tipo de dato Personaje
*/
Personaje* Crear_Enemigo( );

/*
* @brief Crea un TDU Personaje que representa al jefe del juego
* @return El apuntador al tipo de dato Personaje
*/
Personaje* Crear_Boss( );

/*
* @brief Borra un TDU Personaje 
* @param El personaje, enemeigo o jefe a borrar
*/
void Borrar_Personaje( Personaje* this );

/*
* @brief Mejora las habilidades de un TDU Personaje 
* @param Los puntos que seran usados para la mejora y el personaje cuyas habilidades serán mejoradas
*/
void Mejora_Personaje( Item PM, Personaje* this );

/*
* @brief Indica el valor correspondiente al campo nombre del TDU personaje 
* @param El personaje del cual se quiere conocer su nombre
* @return El valor del campo nombre del TDU
*/
char* Personaje_Nombre( Personaje* this );

/*
* @brief Indica el valor correspondiente al campo vida del TDU personaje 
* @param El personaje del cual se quiere conocer sus puntos vida
* @return El valor del campo vida del TDU
*/
Item Personaje_Vida( Personaje* this );

/*
* @brief Indica el valor correspondiente al campo vida total del TDU personaje 
* @param El personaje del cual se quiere conocer sus puntos vida total
* @return El valor del campo vida total del TDU
*/
int Personaje_Vida_total( Personaje* this );

/*
* @brief Indica el valor correspondiente al campo fuerza del TDU personaje 
* @param El personaje del cual se quiere conocer su fuerza
* @return El valor del campo fuerza del TDU
*/
Item Personaje_Fuerza( Personaje* this );

/*
* @brief Indica el valor correspondiente al campo inteligencia del TDU personaje 
* @param El personaje del cual se quiere conocer su inteligencia
* @return El valor del campo inteligencia del TDU
*/
Item Personaje_Inteligencia( Personaje* this );

/*
* @brief Indica el valor correspondiente al campo agilidad del TDU personaje 
* @param El personaje del cual se quiere conocer agilidad
* @return El valor del campo agilidad del TDU
*/
Item Personaje_Agilidad( Personaje* this );

/*
* @brief Indica el valor correspondiente a la DLL de ataques del TDU personaje 
* @param El personaje del cual se quiere conocer la lista de ataques
* @return La DLL con los ataques del TDU
*/
DLL* Personaje_Ataques( Personaje* this );

/*
* @brief Emula una batalla entre el personaje y el enemigo correspondiente
* @param Los apuntadores al TDU personaje del personaje principal y el enemigo que se enfrentaran
* @return Un booleano indicando si el personaje ganó la batalla o no
*/
bool Batalla(Personaje *this, Personaje *that);




#endif
