#include <stdio.h>
#include <stdlib.h>

// Esto es header :o que lindi :3.
void tablero();

void abrirArchivo();

// Menus

void menu();
void menuSalir(int *opIngresada);
void menuJugar(int *opIngresada);
void menuJugarTester(int *opIngresada);
//Board* createBoard(int N, int M, Params params, code *statusCode);
// probando random
int completarTablero();

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
	int x;
	int y;
	int random = 0;

    for (x = 0; x < CanFilas; ++x)
    {
    	for (y = 0; y < CanColumnas; ++y)
    	{
    		MatrizTablero[x][y] = completarTablero();
    		//printf("Cordenadas en x: %d, en y: %d\n", x, y);
    	}
    }

    // Muestra MatrizTablero por pantalla.
    for (x = 0; x < CanFilas; ++x)
    {
    	printf("\n");
    	for (y = 0; y < CanColumnas; ++y)
    {
    		//completarTablero(random);
    		//printf("%i\n", random);
    		printf("%i",MatrizTablero[x][y]);
    		//printf("Cordenadas en x: %d, en y: %d del valor: %i\n", x, y, MatrizTablero[x][y]);
    	}
    }
}

// Funcion que retorna un numero random, equivalente a la aleatoriedad de los caramelos.
int completarTablero()
{
	int numeroRandom = rand() % 6;
	return numeroRandom;
}

void menu()
{
	int opIngresada = -1;
	do 
	{
		printf("\n##############################\n");
		printf("#        Candy Crush         #\n");
		printf("#            V.01            #\n");
		printf("# Paradigmas de Programacion #\n");
		printf("##############################\n");
		printf("\n");
		// Verificacion de la opcion ingresada.
		do
		{
			printf("Menu del juego, ingrese numero de opcion deseada: \n");
			printf("0.- Jugar\n");
			printf("1.- Jugar en modo de Prueba\n");
			printf("2.- Salir\n"); // Verificar el cambio de numero de identacion, aun no se cambian.
			fflush(stdin); // Limpiamos buffer de entrada.
			if ((scanf("%d", &opIngresada) == 0) || (opIngresada < 0 || opIngresada > 2))
			{
			    while (getchar() != '\n');
			    printf("\n- ERROR - Ingrese una opcion VALIDA.\n");
			    fflush(stdin); // Limpiamos buffer de salida.
			}

		} while (opIngresada < 0 || opIngresada > 2);

		switch (opIngresada)
		{
			case 0: printf("Opcion no habilitada\n");
			case 1: menuJugarTester(&opIngresada);
					//tablero(15,10);
					break;
		    case 2: menuSalir(&opIngresada);
					break;
		}
	} while(opIngresada != 1); // Menu principal.	
}

void menuJugarTester(int *opIngresada)
{
	int respuesta = -1;
	do
	{
		// Condicion de entrada.
		if (*opIngresada == 1)
		{
			// Verificacion de los datos de entrada.
			do
			{
				printf("Menu Jugar (ingrese numero)\n");
				printf("0.- Jugar (Mover)\n");
				printf("1.- Crear Tablero\n");
				printf("2.- Guardar Tablero\n");
				printf("3.- Cargar Tablero\n");
				printf("4.- Verificar Tablero\n");
				printf("5.- Verificar Caramelos\n");
				printf("6.- Mostrar Tablero\n");
				printf("7.- Volver al Menu Anterior\n");
				fflush(stdin);
				if ((scanf("%d", &respuesta) == 0) || (respuesta < 0 || respuesta > 7))
				{
				    while (getchar() != '\n');
				    printf("\n- ERROR - Ingrese una opcion VALIDA.\n");
				    fflush(stdin);
				}
			} while (respuesta < 0 || respuesta > 7);
		}

	} while (respuesta != -1);
}

void menuSalir(int *opIngresada)
{
	int respuesta = -1;
	do
	{
		// Condicion de Salida.
		if (*opIngresada == 2)	
		{
			// Verificacion de la respuesta de salida.
			do
			{
				printf("- ¿Esta seguro que desea salir? (ingrese numero)\n");
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

/*Board* createBoard(int N, int M, Params params, code *statusCode)
{


}*/

/*
createBoard: Función que genera un tablero válido para el juego de dimensiones N por M. En la estructura “Params” al menos debe contener los tipos de dulces,
la cantidad de cada uno de estos a ubicar en el tablero y la dificultad; puede incluir otra información extra en esta estructura (Configuraciones, comodines,
etc).

	Board* createBoard(int N, int M, Params params, code *statusCode)

saveBoard: Procedimiento que almacena en un archivo el estado de un tablero y autogenera un id el cual es retornado a través del parámetro por referencia “id”.
Dicho id permitirá posteriormente cargar un tablero existente a través de la función loadBoard. Junto con el tablero se debe almacenar la fecha y hora en que 
fue almacenado. En caso de error debe indicar la causa mediante el parámetro statusCode.

	void saveBoard(board *b, int *id, code *statusCode)

loadBoard: Función que recibe el “id” de tablero y lo retorna si es que éste se encuentra almacenado en un archivo, en caso de ocurrir un error debe retornar 
NULL e indicar el detalle del error en statusCode.

	board* loadBoard(int id, code *statusCode)

checkBoard: Función que permite verificar si un tablero, sea éste creado o cargado desde un archivo, cumple con los criterios para ser considerado como 
válido (ej: que se respetan condiciones elementales del juego, dimensiones consistentes con los datos, etc.). El retorno de la función es de tipo booleano.
Verdadero en caso de que se trate de un tablero válido y falso en el caso contrario, en statusCode debe quedar el detalle de la causa de la 
invalidez del tablero.
		
	int checkBoard(board *b, code *statusCode)

play: Función que permite realizar una jugada sobre el tablero, retorna el puntaje obtenido por la jugada. Una jugada involucra:
Intercambiar la posición de un dulce con otro adyacente.
Verificar si luego de esto existen dulces para eliminar (llamando a checkCandies). En caso de no existir dulces a eliminar o no quedan turnos se termina el 
juego perdiendo, en caso de no quedar recubrimientos duros se termina el juego ganando el nivel.
Eliminar los dulces correspondientes que fueron obtenidos por checkCandies.
Debilitar los recubrimientos duros de los dulces adyacentes a la explosión.
Hacer aparecer nuevos dulces en las posiciones que quedaron disponibles, puede desplazar verticalmente como lo hace el juego candy Crush o alguna otra forma
de que aparezcan estos nuevos dulces.
Volver al paso b.
		
	int play(board *b, Position pOri, Position pDes, int *turnos, code *statusCode)

checkCandies: Permite verificar si en el tablero existen dulces que se pueden eliminar debido a que forman una fila de tres o más dulces del mismo tipo, en
caso de existir varios grupos distintos de dulces formando una línea de más de 3, se debe retornar el primer grupo encontrado.

	Position *checkCandies(board * b, code *statusCode)

“checkCandies” retorna un arreglo con el primer grupo de posiciones que forme una línea de más de 3 dulces, el tablero no se ve modificado por esta función.

print: Procedimiento que imprime en pantalla un tablero usando caracteres ASCII.
	
	void print(board *b, code *statusCode)

Menú en main: Debe incluir un menú que permita probar cada una de las funciones/procedimientos descritos anteriormente. Esto es, crear un tablero, grabar
o cargar un tablero, verificar un tablero, realizar una jugada, verificar dulces para eliminar y visualizar el tablero. En caso de implementar requerimientos 
extras, estos se deben incluir en el menú.

*/
