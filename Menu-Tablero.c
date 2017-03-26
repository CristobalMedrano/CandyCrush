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

// #define MENU_PRINCIPAL
#define JUGAR 1
#define JUGAR_MODO_PRUEBA 2
#define SALIR 0

#define CONF_SALIR 1
#define CONF_NO_SALIR 0



// Cabecera

// Menu Cabecera
void jugar();

int obtenerOpcionIngresada(int valMin, int valMax);
void seleccionMenu(int tipoMenu);
void menuSalir();
void menuPrincipal();
void menuJugarModoPrueba();
void mostrarMenuSalir();
void mostrarMenuPrincipal();
void mostrarMenuJugarModoPrueba();


// Funciones

void jugar()
{
	#ifdef DEBUG
		printf("Estoy jugando...\n");
	#endif
}

int obtenerOpcionIngresada(int valMin, int valMax)
{
	int leerOpcion = SIN_INGRESO;
	do
	{
		fflush(stdin); // Limpiamos buffer de entrada.
		if ((scanf("%d", &leerOpcion) == 0) || (leerOpcion < valMin || leerOpcion > valMax))
		{
			// Obtenemos el contenido del buffer que sea distinto a salto de linea.
		    while (getchar() != '\n');
		    printf("\n- ERROR - Ingrese una opcion VALIDA.\n");
		    fflush(stdin); // Limpiamos buffer.
		}

		#ifdef DEBUG
			printf("Opcion ingresada = %d\n", leerOpcion);
		#endif

	} while (leerOpcion < valMin || leerOpcion > valMax);

	// Retorno la opcion ingresada ya validada.
	return leerOpcion;
}


void seleccionMenu(int tipoMenu)
{
	switch (tipoMenu)
	{
		case MENU_SALIR: menuSalir();
						 break;
		case MENU_PRINCIPAL: menuPrincipal();
							 break;
		case MENU_JUGAR_MODO_PRUEBA: menuJugarModoPrueba();
									 break;
	}
}

void menuJugarModoPrueba()
{
	#ifdef DEBUG
		printf("Estoy jugando en modo de pruebas...\n");
	#endif
}

void menuSalir()
{
	// Muestra el MenuSalir.
	mostrarMenuSalir();
	int opcionIngresada = obtenerOpcionIngresada(0, 1);
	
	switch (opcionIngresada)
	{
		case CONF_SALIR: printf("Estoy saliendo...\n");;
					break;
		case CONF_NO_SALIR: seleccionMenu(MENU_PRINCIPAL);
					   break;
	}
}

void menuPrincipal()
{
	// Muestra el MenuPrincipal.
	mostrarMenuPrincipal();
	int opcionIngresada = obtenerOpcionIngresada(0, 2);

	switch (opcionIngresada)
	{
		case JUGAR: jugar();
					break;
		case JUGAR_MODO_PRUEBA: menuJugarModoPrueba();
								break;
		case SALIR: seleccionMenu(MENU_SALIR);
					break;
	}
}

void mostrarMenuSalir()
{
	printf("- Esta seguro que desea salir?, ingrese numero de opcion deseada:\n");
	printf("1.- Si\n");
	printf("0.- No\n");
}

void mostrarMenuPrincipal()
{
	printf("\n##############################\n");
	printf("#        Candy Crush         #\n");
	printf("#            V.02            #\n");
	printf("# Paradigmas de Programacion #\n");
	printf("##############################\n");
	printf("\n");
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


int main(int argc, char const *argv[])
{
	seleccionMenu(MENU_PRINCIPAL);
	return 0;
}