#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

// #define

#define DEBUG
#define FALSE 0
#define TRUE 1
#define SIN_INGRESO -1

// #define Menu
#define MENU_CREAR_TABLERO 3
#define MENU_JUGAR_MODO_PRUEBA 2
#define MENU_PRINCIPAL 1
#define MENU_SALIR 0

// #define MENU_CREAR_TABLERO
#define FACIL 1
#define INTERMEDIO 2
#define DIFICIL 3
#define VOLVER_MENU_JUGAR_MODO_PRUEBA 0

// #define MENU_JUGAR_MODO_PRUEBA
#define JUGAR_MOVER 1
#define CREAR_TABLERO 2
#define GUARDAR_TABLERO 3
#define CARGAR_TABLERO 4
#define VERIFICAR_TABLERO 5
#define VERIFICAR_CARAMELOS 6
#define MOSTRAR_TABLERO 7
#define VOLVER_MENU_PRINCIPAL 0

// #define MENU_PRINCIPAL
#define JUGAR 1
#define JUGAR_MODO_PRUEBA 2
#define SALIR 0

// #define MENU_SALIR
#define CONF_SALIR 1
#define CONF_NO_SALIR 0

// #define CompletarParametros
#define CEREZA 0
#define FRUTILLA 1
#define MANZANA 2
#define DURAZNO 3
#define UVA 4
#define MCEREZA 5
#define MFRUTILLA 6
#define MMANZANA 7
#define MDURAZNO 8
#define MUVA 9
#define CAMPANA 10
#define TUTIFRUTI 11
#define LLAVE 12

// Estructuras

typedef struct Tablero
{
	int cantidadFilas;
	int cantidadColumnas;
} Board ;

typedef struct Juego
{

} Game ;

typedef struct Parametros
{
	int candyCereza;
	int candyFrutilla;
	int candyManzana;
	int candyDurazno;
	int candyUva;
	int candyMCereza;
	int candyMFrutilla;
	int candyMManzana;
	int candyMDurazno;
	int candyMUva;
	int candyCampana;
	int candyTutifruti;
	int candyLlave;
	int Dificultad;
	//int nivel;
} Params ;

typedef struct Posicion
{
	int posX;
	int posY;

} Position ;

typedef struct Dulce
{
	int tipo;
} Candy ;


// Cabecera

// Menu Cabecera
// MenuCrearTablero
void crearParametrosTablero(int Dificultad);


// MenuJugarModoPrueba
void jugarMover();
Board* createBoard(int N, int M, Params params);
void guardarTablero();
void cargarTablero();
void verificarTablero();
void verificarCaramelos();
void mostrarTablero();

// MenuPrincipal
void jugar();

// Verificacion - Validacion
int obtenerOpcionIngresada(int valMin, int valMax, int tipoMenu);
void seleccionMenu(int tipoMenu);

//Seleccion Menu
void menuPrincipal();
void menuJugarModoPrueba();
void menuCrearTablero();
void menuSalir();

void mostrarMenu(int tipoMenu);
void mostrarMenuPrincipal();
void mostrarMenuJugarModoPrueba();
void mostrarMenuCrearTablero();
void mostrarMenuSalir();



// Funciones

/*enum code {
	OK, 
	ERR_FILE_NOT_FOUND,
	ERR_FILE_NOT_PERM,
	IMPOSSIBLE_VALID_BOARD,
};*/

void jugarMover(){}

// Funcion que crea un tablero valido.
Board* createBoard(int N, int M, Params params)
{

}

void guardarTablero(){}
void cargarTablero(){}
void verificarTablero(){}
void verificarCaramelos(){}
void mostrarTablero(){}

void crearParametrosTablero(int Dificultad)
{
	Params* nuevoParametro = malloc(sizeof(Params));
	completarParametros(nuevoParametro, Dificultad);

	free(nuevoParametro);
}
void completarParametros(Params* nuevoParametro, int Dificultad)
{
	int TotalCandy = 100;
	int presionarBatidora = 0;
	int CanRestante = 0;
	srand(time(NULL));   // should only be called once

	int candyCereza = 0;
	int candyFrutilla = 0;
	int candyManzana = 0;
	int candyDurazno = 0;
	int candyUva = 0;
	int candyMCereza = 0;
	int candyMFrutilla = 0;
	int candyMManzana = 0;
	int candyMDurazno = 0;
	int candyMUva = 0;
	int candyCampana = 0;
	int candyTutifruti = 0;
	int candyLlave = 0;

	while (CanRestante < TotalCandy)
	{
		presionarBatidora = (rand() % (TotalCandy+1));
		switch(presionarBatidora)
		{
			case CEREZA: candyCereza += 
						 verificarDificultad(Dificultad, CEREZA, &CanRestante);
						 break;
			case FRUTILLA: candyFrutilla += 
						   verificarDificultad(Dificultad, FRUTILLA, &CanRestante);
						   break;
			case MANZANA: candyManzana +=
						  verificarDificultad(Dificultad, MANZANA, &CanRestante);
						  break;
			case DURAZNO: candyDurazno +=
						  verificarDificultad(Dificultad, DURAZNO, &CanRestante);
						  break;
			case UVA: candyUva +=
					  verificarDificultad(Dificultad, UVA, &CanRestante);
					  break;
			case MCEREZA: candyMCereza +=
						  verificarDificultad(Dificultad, MCEREZA, &CanRestante);
						  break;
			case MFRUTILLA: candyMFrutilla += 
							verificarDificultad(Dificultad, MFRUTILLA, &CanRestante);
						    break;
			case MMANZANA: candyMManzana +=
						   verificarDificultad(Dificultad, MMANZANA, &CanRestante);
						   break;
			case MDURAZNO: candyMDurazno +=
						   verificarDificultad(Dificultad, MDURAZNO, &CanRestante);
						   break;
			case MUVA: candyMUva +=
					   verificarDificultad(Dificultad, MUVA, &CanRestante);
					   break;
			case CAMPANA: candyCampana +=
						  verificarDificultad(Dificultad, CAMPANA, &CanRestante);
						  break;
			case TUTIFRUTI: candyTutifruti +=
							verificarDificultad(Dificultad, TUTIFRUTI, &CanRestante);
							break;
			case LLAVE: candyLlave +=
						verificarDificultad(Dificultad, LLAVE, &CanRestante);
						break;
		}
	}

	// Completo los parametros iniciales.
	nuevoParametro->candyCereza = candyCereza;
	nuevoParametro->candyFrutilla = candyFrutilla;
	nuevoParametro->candyManzana = candyManzana;
	nuevoParametro->candyDurazno = candyDurazno;
	nuevoParametro->candyUva = candyUva;
	nuevoParametro->candyMCereza = candyMCereza;
	nuevoParametro->candyMFrutilla = candyMFrutilla;
	nuevoParametro->candyMManzana = candyMManzana;
	nuevoParametro->candyMDurazno = candyMDurazno;
	nuevoParametro->candyMUva = candyMUva;
	nuevoParametro->candyCampana = candyCampana;
	nuevoParametro->candyTutifruti = candyTutifruti;
	nuevoParametro->candyLlave = candyLlave;

	#ifdef DEBUG
	printf("candyCereza = %d\n", nuevoParametro->candyCereza);
	printf("candyFrutilla = %d\n", nuevoParametro->candyFrutilla);
	printf("candyManzana = %d\n", nuevoParametro->candyManzana);
	printf("candyDurazno = %d\n", nuevoParametro->candyDurazno);
	printf("candyUva = %d\n", nuevoParametro->candyUva);
	printf("candyMCereza = %d\n", nuevoParametro->candyMCereza);
	printf("candyMFrutilla = %d\n", nuevoParametro->candyMFrutilla);
	printf("candyMManzana = %d\n", nuevoParametro->candyMManzana);
	printf("candyMDurazno = %d\n", nuevoParametro->candyMDurazno);
	printf("candyMUva = %d\n", nuevoParametro->candyMUva);
	printf("candyCampana = %d\n", nuevoParametro->candyCampana);
	printf("candyTutifruti = %d\n", nuevoParametro->candyTutifruti);
	printf("candyLlave = %d\n", nuevoParametro->candyLlave);
	#endif

}

int verificarDificultad(int Dificultad, int Candy, int *CanRestante){

	int arregloDulcesFACIL[5] = {CEREZA, FRUTILLA, MANZANA, MCEREZA, CAMPANA};
	int arregloDulcesINTERMEDIO[9] = {CEREZA, FRUTILLA, MANZANA, DURAZNO, MCEREZA, 
									  MFRUTILLA, MMANZANA, CAMPANA, TUTIFRUTI};
	int arregloDulcesDIFICIL[13] = {CEREZA, FRUTILLA, MANZANA, DURAZNO, UVA,
									MCEREZA, MFRUTILLA, MMANZANA, MDURAZNO, MUVA,
								    CAMPANA, TUTIFRUTI, LLAVE};
	/* int lenFacil = sizeof(arregloDulcesFACIL)/sizeof(int)); Sirve para sacar
	largo de una lista.*/
	if (Dificultad == FACIL)
	{
		for (int i = 0; i < 5; ++i)
		{
			if(Candy == arregloDulcesFACIL[i]){
				*CanRestante += 1;
				return 1;
			}
		}
		return 0;
	}

	if (Dificultad == INTERMEDIO)
	{
		for (int i = 0; i < 9; ++i)
		{
			if(Candy == arregloDulcesINTERMEDIO[i]){
				*CanRestante += 1;
				return 1;
			}
		}
		return 0;
	}

	if (Dificultad == DIFICIL)
	{
		for (int i = 0; i < 13; ++i)
		{
			if(Candy == arregloDulcesDIFICIL[i]){
				*CanRestante += 1;
				return 1;
			}
		}
		return 0;
	}
}

void jugar()
{
	#ifdef DEBUG
		printf("Estoy jugando...\n");
	#endif
}

int obtenerOpcionIngresada(int valMin, int valMax, int tipoMenu)
{
	int leerOpcion = SIN_INGRESO;
	do
	{
		fflush(stdin); // Limpiamos buffer de entrada.
		if ((scanf("%d", &leerOpcion) == 0) || (leerOpcion < valMin || leerOpcion > valMax))
		{
			// Obtenemos el contenido del buffer que sea distinto a salto de linea.
		    while (getchar() != '\n');
		    #ifdef DEBUG
				printf("Opcion ingresada = %d", leerOpcion);
			#endif
		    printf("\n- ERROR - Ingrese una opcion VALIDA.\n\n");
		    mostrarMenu(tipoMenu);
		    fflush(stdin); // Limpiamos buffer.
		}
		
	} while (leerOpcion < valMin || leerOpcion > valMax);
	#ifdef DEBUG
		printf("Opcion ingresada = %d\n\n", leerOpcion);
	#endif

	// Retorno la opcion ingresada ya validada.
	return leerOpcion;
}


void seleccionMenu(int tipoMenu)
{
	switch (tipoMenu)
	{
		case MENU_PRINCIPAL: mostrarMenu(MENU_PRINCIPAL);
							 menuPrincipal();					 
							 break;
		case MENU_JUGAR_MODO_PRUEBA: mostrarMenu(MENU_JUGAR_MODO_PRUEBA); 
									 menuJugarModoPrueba();
									 break;
		case MENU_CREAR_TABLERO: mostrarMenuCrearTablero(MENU_CREAR_TABLERO);
								 menuCrearTablero();
								 break;
		case MENU_SALIR: mostrarMenu(MENU_SALIR);
						 menuSalir();
				 		 break;
	}
}

void menuPrincipal()
{
	// Muestra el MenuPrincipal.
	int opcionIngresada = obtenerOpcionIngresada(0, 2, MENU_PRINCIPAL);

	switch (opcionIngresada)
	{
		case JUGAR: jugar();
					break;
		case JUGAR_MODO_PRUEBA: seleccionMenu(MENU_JUGAR_MODO_PRUEBA);
								break;
		case SALIR: seleccionMenu(MENU_SALIR);
					break;
	}
}

void menuJugarModoPrueba()
{
	int opcionIngresada = obtenerOpcionIngresada(0, 7, MENU_JUGAR_MODO_PRUEBA);

	switch (opcionIngresada)
	{
		case JUGAR_MOVER: jugarMover();
						  break;
		case CREAR_TABLERO: seleccionMenu(MENU_CREAR_TABLERO);
						  	break;
		case GUARDAR_TABLERO: guardarTablero();
						  	  break;
		case CARGAR_TABLERO: cargarTablero();
						  	 break;
		case VERIFICAR_TABLERO: verificarTablero();
						  		break;
		case VERIFICAR_CARAMELOS: verificarCaramelos();
						  		  break;
		case MOSTRAR_TABLERO: mostrarTablero();
							  break;
		case VOLVER_MENU_PRINCIPAL: seleccionMenu(MENU_PRINCIPAL);
					 break;
	}

}

void menuCrearTablero()
{
	int opcionIngresada = obtenerOpcionIngresada(0, 3, MENU_CREAR_TABLERO);

	switch (opcionIngresada)
	{
		case FACIL: crearParametrosTablero(FACIL);
					break;
		case INTERMEDIO: crearParametrosTablero(INTERMEDIO);
								break;
		case DIFICIL: crearParametrosTablero(DIFICIL);
					break;
		case VOLVER_MENU_JUGAR_MODO_PRUEBA: seleccionMenu(MENU_JUGAR_MODO_PRUEBA);
										 	break; 
	}
}

void menuSalir()
{
	// Muestra el MenuSalir.
	int opcionIngresada = obtenerOpcionIngresada(0, 1, MENU_SALIR);
	
	switch (opcionIngresada)
	{
		case CONF_SALIR: printf("Estoy saliendo...\n");;
					break;
		case CONF_NO_SALIR: seleccionMenu(MENU_PRINCIPAL);
					   break;
	}
}

void mostrarMenu(int tipoMenu)
{
	switch (tipoMenu)
	{
		case MENU_PRINCIPAL: mostrarMenuPrincipal();
							 break;
		case MENU_JUGAR_MODO_PRUEBA: mostrarMenuJugarModoPrueba();
							 		 break;
		case MENU_CREAR_TABLERO: mostrarMenuCrearTablero();
								 break;
		case MENU_SALIR: mostrarMenuSalir();
						 break;
	}
}

void mostrarMenuPrincipal()
{
	printf("\n##############################\n");
	printf("#        Candy Crush         #\n");
	printf("#            V.02            #\n");
	printf("# Paradigmas de Programacion #\n");
	printf("##############################\n\n");
	printf("Menu del juego, ingrese numero de opcion deseada: \n");
	printf("1.- Jugar\n");
	printf("2.- Jugar en modo de Prueba\n");
	printf("0.- Salir\n");
}

void mostrarMenuJugarModoPrueba()
{
	printf("Menu Jugar, ingrese numero de opcion deseada:\n");
	printf("1.- Jugar (Mover)\n");
	printf("2.- Crear Tablero\n");
	printf("3.- Guardar Tablero\n");
	printf("4.- Cargar Tablero\n");
	printf("5.- Verificar Tablero\n");
	printf("6.- Verificar Caramelos\n");
	printf("7.- Mostrar Tablero\n");
	printf("0.- Volver\n");
}

void mostrarMenuCrearTablero()
{
	printf("Menu Crear Tablero, ingrese numero de opcion deseada:\n");
	printf("1.- Nivel Facil\n");
	printf("2.- Nivel Intermedio\n");
	printf("3.- Nivel Dificil\n");
	printf("0.- Volver\n");
}

void mostrarMenuSalir()
{
	printf("- Esta seguro que desea salir?, ingrese numero de opcion deseada:\n");
	printf("1.- Si\n");
	printf("0.- No\n");
}

int main(int argc, char const *argv[])
{
	seleccionMenu(MENU_PRINCIPAL);
	return 0;
}