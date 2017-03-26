#include <stdio.h>
#include <stdlib.h>

// #define

#define DEBUG
#define FALSE 0
#define TRUE 1
#define SIN_INGRESO -1

// #define Menu
#define MENU_JUGAR_MODO_PRUEBA 2
#define MENU_PRINCIPAL 1
#define MENU_SALIR 0

// #define MENU_JUGAR_MODO_PRUEBA
#define JUGAR_MOVER 1
#define CREAR_TABLERO 2
#define GUARDAR_TABLERO 3
#define CARGAR_TABLERO 4
#define VERIFICAR_TABLERO 5
#define VERIFICAR_CARAMELOS 6
#define MOSTRAR_TABLERO 7
#define VOLVER 0

// #define MENU_PRINCIPAL
#define JUGAR 1
#define JUGAR_MODO_PRUEBA 2
#define SALIR 0

// #define MENU_SALIR
#define CONF_SALIR 1
#define CONF_NO_SALIR 0



// Cabecera

// Menu Cabecera
// MenuJugarModoPrueba
void jugarMover();
void crearTablero();
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
void menuSalir();

void mostrarMenu(int tipoMenu);
void mostrarMenuPrincipal();
void mostrarMenuJugarModoPrueba();
void mostrarMenuSalir();

// Estructuras

typedef struct
{

} Board ;

typedef struct
{

} Game ;

typedef struct
{

} Params ;

typedef struct
{
	int posX;
	int posY;

} Position ;

typedef struct
{
	
} Candy ;


// Funciones

void jugarMover(){}
void crearTablero(){}
void guardarTablero(){}
void cargarTablero(){}
void verificarTablero(){}
void verificarCaramelos(){}
void mostrarTablero(){}

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
		    printf("\n\n- ERROR - Ingrese una opcion VALIDA.");
		    mostrarMenu(tipoMenu);
		    fflush(stdin); // Limpiamos buffer.
		}

		#ifdef DEBUG
			printf("Opcion ingresada = %d\n\n", leerOpcion);
		#endif

	} while (leerOpcion < valMin || leerOpcion > valMax);

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
		case CREAR_TABLERO: crearTablero();
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
		case VOLVER: seleccionMenu(MENU_PRINCIPAL);
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
	printf("0.- Volver al Menu Anterior\n");
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