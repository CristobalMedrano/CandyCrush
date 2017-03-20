#include <stdio.h>
#include <stdlib.h>

// Esto es header :o que lindi :3.
void tablero();
void menu();
void menuSalir(int *opIngres);
void abrirArchivo();

// Hasta aqui.

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

int main()
{
	// Inicia el programa
	// Ejecuta menu del programa
	menu();
	//Ejecuta Tablero
	
	return 0;
}

void tablero(int CanFilas, int CanColumnas)
{
	// CanFilas --> Cantidad de Filas.
	// CanColumnas --> Cantidad de Columnas.
	// x --> Posicion Horizontal.
	// y --> Posicion Vertical.

	int MatrizTablero[CanFilas][CanColumnas];

	// Rellena MatrizTablero con -1.
    for (int x = 0; x < CanFilas; ++x)
    {
    	for (int y = 0; y < CanColumnas; ++y)
    	{
    		MatrizTablero[x][y] = -1;
    		//printf("Cordenadas en x: %d, en y: %d\n", x, y);
    	}
    }

    // Muestra MatrizTablero por pantalla.
    for (int x = 0; x < CanFilas; ++x)
    {
    	printf("\n");
    	for (int y = 0; y < CanColumnas; ++y)
    	{
    		printf("%i",MatrizTablero[x][y]);
    		//printf("Cordenadas en x: %d, en y: %d del valor: %i\n", x, y, MatrizTablero[x][y]);
    	}
    }
}

void menu()
{
	int opIngresada = -1;
	do 
	{
		printf("\n##############################\n");
		printf("#        Candy Crush         #\n");
		printf("#            V.00            #\n");
		printf("# Paradigmas de Programacion #\n");
		printf("##############################\n");
		printf("\n");
		// Verificacion de la opcion ingresada.
		do
		{
			printf("Menu del juego, ingrese numero de opcion deseada: \n");
			printf("0.- Jugar\n");
			printf("1.- Salir\n");
			fflush(stdin); // Limpiamos buffer de entrada.
			if ((scanf("%d", &opIngresada) == 0) || (opIngresada < 0 || opIngresada > 1))
			{
			    while (getchar() != '\n');
			    printf("\n- ERROR - Ingrese una opcion VALIDA.\n");
			    fflush(stdin); // Limpiamos buffer de salida.
			}

		} while (opIngresada < 0 || opIngresada > 1);

		switch (opIngresada)
		{
			case 0: tablero(15,10);
					break;
		    case 1: menuSalir(&opIngresada);
					break;
		}
	} while(opIngresada != 1); // Menu principal.	
}

void menuSalir(int *opIngresada)
{
	int respuesta = -1;
	do
	{
		// Condicion de Salida.
		if (*opIngresada == 1)	
		{
			// Verificacion de la respuesta de salida.
			do
			{
				printf("¿Esta seguro que desea salir? (ingrese numero)\n");
				printf("0.- No\n");
				printf("1.- Si\n");
				fflush(stdin);
				if ((scanf("%d", &respuesta) == 0) || (respuesta < 0 || respuesta > 1))
			{
			    while (getchar() != '\n');
			    printf("\n- ERROR - Ingrese una opcion VALIDA.\n");
			    fflush(stdin);
			}
			} while (respuesta < 0 || respuesta > 1);

			// Seleccion de menu.
			switch (respuesta)
			{	case 0: *opIngresada = 0;
						respuesta = 1;
						// Modifica la opcion ingresada y el valor de respuesta.
						// Vuelve al menu principal.
						break;
				case 1:	*opIngresada = 1;
						respuesta = 1;
						// modifica la opcion ingresada y sale del programa
						break;
				 
			} // Fin del Switch
		} // Fin del if.

	} while(respuesta != 1); // Opcion de salir.
}

void abrirArchivo()
{

}
