#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "personaje.h"

bool historia( Personaje* Player1, char* map_direction )
{
    system("clear");
    FILE* ptr_file;
    char _history1[30], _history2[30], _right[30], _left[30];
    int _enemy, _boss, _upgrade, _life, _weapon, _death;
    bool _pelea = true;

    ptr_file = fopen( map_direction, "r" );

    fscanf( ptr_file, "%[^\n]\n%[^\n]\n%[^\n]\n%[^\n]\n%d\t%d\t%d\t%d\t%d\t%d", _history1, _history2, _right, _left, &_enemy, &_boss, &_upgrade, &_weapon, &_life, &_death );

    fclose( ptr_file );

    if ( strlen(_history1) != 1 )
    {
        ptr_file = fopen( _history1, "r" );
        while(1) {
            char c;
            c = fgetc(ptr_file);
            if( feof(ptr_file) ) {
            break;
            }
            printf("%c", c);
        }
        fclose(ptr_file);
    }
    printf("\nPresiona enter para continuar\n");
    getchar();

    if ( _enemy != 0 )
    {
        Personaje* Enemigo = Crear_Enemigo( );
        _pelea = Batalla( Player1, Enemigo );
        Borrar_Personaje( Enemigo );
    }

    if ( _boss != 0 )
    {
        Personaje* Boss = Crear_Boss( );
        _pelea = Batalla( Player1, Boss );
        Borrar_Personaje( Boss );
    }

    if ( _weapon != 0 )
    {
        newAtaque( Personaje_Ataques( Player1 ), _weapon );
    }

    if ( _upgrade != 0 )
    {
        Mejora_Personaje( _upgrade, Player1 );
    }

    if ( _death != 0)
    {
        return false;
    }

    system("clear");

    if ( _pelea != false)
    {
        if ( strlen(_history2) != 1 )
        {
            ptr_file = fopen( _history2, "r" );
            while(1) {
                char c;
                c = fgetc(ptr_file);
                if( feof(ptr_file) ) {
                break;
                }
                printf("%c", c);
            }
            fclose(ptr_file);
        }
        printf("\nPresiona enter para continuar\n");
        getchar();

        if ( _life != 0 )
        {
            return true;
        }

        int eleccion;
        printf("Para donde te mueves: \n"
                "-1-\tIzquierda\n"
                "-2-\tDerecha\n"
                );
        do{
        printf( "Introduzca eleccion: ");
        scanf("%d", &eleccion);
    	while ( (getchar()) != '\n' );
        }while ( eleccion >= 3 || eleccion <= 0 );

        if (eleccion == 1){
            _pelea = historia( Player1, _right );}
        else{
            _pelea = historia( Player1, _left );}
    }


    return _pelea;
}

int main(){

    srand(time (0));

    char nombre[50];
    char Start[30] = {"map_guide_1.txt"};
    FILE* ptr_file;
    bool Prueba;
    system("clear");
    printf("Asistente: Bienvenido. ¿Cuál es tu nombre?\n ");
    scanf("%[^\n]", nombre);
    while ( (getchar()) != '\n' );

    Personaje* Player1 = Crear_Personaje( nombre );

    printf("Asistente: Pareces desorientado. Déjame ayudarte.\n");
    printf(" Vida: %d\n",Personaje_Vida( Player1 ) );
    printf(" Agilidad: %d\n",Personaje_Agilidad( Player1 ) );
    printf(" Fuerza: %d\n",Personaje_Fuerza( Player1 ) );
    printf(" Inteligencia: %d\n",Personaje_Inteligencia( Player1 ) );

    ptr_file = fopen( "start.txt", "r" );
    while(1) {
        char c;
        c = fgetc(ptr_file);
        if( feof(ptr_file) ) {
        break;
        }
        printf("%c", c);
    }
    fclose(ptr_file);

    Personaje* Enemigo = Crear_Enemigo( );
    Prueba = Batalla( Player1, Enemigo );
    Borrar_Personaje( Enemigo );

    if ( Prueba != false )
    {
        Prueba = historia( Player1, Start );
    }

    if ( Prueba != false )
    {
        printf("Has acabado el juego.\nPresiona enter para continuar\n" );
    }
    else
    {
        printf("Has muerto.\nPresiona enter para continuar\n" );
    }

    getchar();
	Borrar_Personaje( Player1 );
	return 0;
}
