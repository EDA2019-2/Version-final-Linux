#include "personaje.h"

Personaje* Crear_Personaje( char* name )
{
	Personaje* p = ( Personaje* ) malloc( sizeof( Personaje) );
	if( p ){
		p->nombre = name;
		p->agilidad = 10;
		p->fuerza = 10;
		p->inteligencia = 10;
		p->vida_total = 200;
		p->vida = p->vida_total;
		p->ataques = DLL_New();
		newAtaque( p->ataques, 1 );
	}
	return p;
}

Personaje* Crear_Enemigo( )
{
	srand(time (0));

	FILE* ptr_file;
	char nombre[25];
	int vida, fuerza, intel, agi, type, _atack;

	type = ((rand() % 4) + 1);

	switch (type) {
		case 1:
			ptr_file = fopen( "Enemigo1.txt", "r" );
			break;
		case 2:
			ptr_file = fopen( "Enemigo2.txt", "r" );
			break;
		case 3:
			ptr_file = fopen( "Enemigo3.txt", "r" );
			break;
		case 4:
			ptr_file = fopen( "Enemigo4.txt", "r" );
			break;
		default:
			break;
	}

	fscanf( ptr_file, "%[^\n]\n%d\t%d\t%d\t%d\t%d", nombre, &agi, &vida, &fuerza, &intel, &_atack);
	fclose(ptr_file);

	Personaje* p = ( Personaje* ) malloc( sizeof( Personaje) );
	if( p ){
		p->nombre = nombre;
		p->agilidad = agi;
		p->vida_total = vida;
		p->vida = p->vida_total;
		p->fuerza = fuerza;
		p->inteligencia = intel;
		p->ataques = DLL_New();
		newAtaque( p->ataques, _atack );
	}
	return p;
}

Personaje* Crear_Boss( )
{

	FILE* ptr_file;
	char nombre[25];
	int vida, fuerza, intel, agi;


	ptr_file = fopen( "Boss1.txt", "r" );

	fscanf( ptr_file, "%[^\n]\n%d\t%d\t%d\t%d", nombre, &agi, &vida, &fuerza, &intel);

	fclose(ptr_file);

	Personaje* p = ( Personaje* ) malloc( sizeof( Personaje) );
	if( p ){
		p->nombre = nombre;
		p->agilidad = agi;
		p->vida_total = vida;
		p->vida = p->vida_total;
		p->fuerza = fuerza;
		p->inteligencia = intel;
		p->ataques = DLL_New();
		newAtaque( p->ataques, 6 );
		newAtaque( p->ataques, 5 );
		newAtaque( p->ataques, 4 );
	}
	return p;
}

void Borrar_Personaje( Personaje* this )
{
	if( this ){
		DLL_Delete( this->ataques );
		free( this );
	}
}

void Mejora_Personaje( Item PM, Personaje* this )
{
	while( PM > 0 ){
		char opc; //////////////////
		printf("\n\n\t\t%s\n",Personaje_Nombre( this ) );
        printf(" Vida: %d\n",Personaje_Vida_total( this ) );
        printf(" Agilidad: %d\n",Personaje_Agilidad( this ) );
        printf(" Fuerza: %d\n",Personaje_Fuerza( this ) );
        printf(" Inteligencia: %d\n",Personaje_Inteligencia( this ) );
		printf( "\n Ingresa la habilidad que deseas mejorar: \n"
		        " 1) Vida \n"
				" 2) Agilidad \n"
				" 3) Fuerza \n"
				" 4) Inteligencia \n"
				" \n Opcion seleccionada: "
				);
		scanf("%c", &opc);
		while ( (getchar()) != '\n' );
		switch( opc-48 ){
			case 1:
				this->vida_total += 50;
				break;
			case 2:
			    this->agilidad += 5;
				break;
			case 3:
			    this->fuerza += 5;
				break;
			case 4:
			    this->inteligencia += 5;
			    break;

			default:
			 		PM++;
					break;
		}
		PM--;
		system("clear");
		printf("\n Te quedan %d puntos de mejora!\n", PM);
	}
	this->vida = this->vida_total;
	printf("\n\t\t%s\n",Personaje_Nombre( this ) );
    printf(" Vida: %d\n",Personaje_Vida( this ) );
    printf(" Agilidad: %d\n",Personaje_Agilidad( this ) );
    printf(" Fuerza: %d\n",Personaje_Fuerza( this ) );
    printf(" Inteligencia: %d\n",Personaje_Inteligencia( this ) );
	getchar();
}

char* Personaje_Nombre( Personaje* this )
{
	return this->nombre;
}

int Personaje_Vida( Personaje* this )
{
	return this->vida;
}

int Personaje_Vida_total( Personaje* this )
{
	return this->vida_total;
}

int Personaje_Fuerza( Personaje* this )
{
	return this->fuerza;
}

int Personaje_Inteligencia( Personaje* this )
{
	return this->inteligencia;
}

int Personaje_Agilidad( Personaje* this )
{
	return this->agilidad;
}

DLL* Personaje_Ataques( Personaje* this )
{
	return this->ataques;
}

bool Batalla(Personaje *this, Personaje *that)
{
	printf("%s ha aparecido\n", that->nombre );
	size_t tiro_de_dado;
	size_t i=1;
	Ataque a;
	bool resultado;
	while( this->vida > 0 && that->vida > 0 ){
		if(i%2==0)
		{
			printf("Turno del enemigo \n" );
			a=Ataque_Enemigo( that->ataques );
			//Turno ENEMIGO
			//SIN MENU Elige un numero al azar de 1 a 3 y elige un ataque entre los ataques que conoce el enemigo
			//return Ataque
			//Los daños de ataques enemigos son fijos y no tienen rnd para extender daño

			int ability = a.habilidad;
			if(ability==1)
			{
				tiro_de_dado=(rand() % 15)*(that->agilidad);
			}
			else if(ability==2)
			{
				tiro_de_dado=(rand() % 15)*(that->fuerza);
			}
			else if(ability==3)
			{
				tiro_de_dado=(rand() % 15)*(that->inteligencia);
			}
			if(tiro_de_dado<50)
			{
				i++;
			}else{
			size_t _dano=( a.dano + (rand() % a.dado) );
			this->vida-=_dano;
			i++;
			}
		}
		else
		{
			printf("Tu vida: %d/%d\tVida enemigo: %d/%d\n", this->vida, this->vida_total, that->vida, that->vida_total);
			a=Ataque_Menu( this->ataques );
			//Turno JUGADOR
			//MOSTRAR MENÚ  DE ATAQUES
			//JUGADOR ELIGE ATAQUE return char Ataque Seleccionado

			int ability = a.habilidad;
			if(ability==1)
			{
				tiro_de_dado=(rand() % 15)*(this->agilidad);
			}
			else if(ability==2)
			{
				tiro_de_dado=(rand() % 15)*(this->fuerza);
			}
			else if(ability==3)
			{
				tiro_de_dado=(rand() % 15)*(this->inteligencia);
			}
			if(tiro_de_dado<50)
			{
				i++;
			}else{
			size_t _dano=(a.dano + (rand() % a.dado) );
			that->vida-=_dano;
			i++;
			}

			system("clear");
		}
	}

	if(this->vida<=0)
	{
		resultado = false;
	}
	if(that->vida<=0)
	{
		printf("Ganaste. Persiona enter para continuar\n");
		resultado = true;
		getchar();
	}

	system("clear");
	return resultado;
}
