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
	int Filas;
	int Columnas;
	int **matrizSTablero;
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
	int tipoCandy;
} Candy ;


// Cabecera

// Menu Cabecera
// MenuCrearTablero
Params* crearParametrosTablero(int Dificultad, int N, int M);
void completarParametros(Params* nuevoParametro, int Dificultad, int N, int M);
int verificarDificultad(int Dificultad, int Candy, int *CanRestante);

int* ordenarCandy(int N,int M,Params *params);
int convertirFruta(Board* b, int Filas, int Columnas);

// MenuJugarModoPrueba
void jugarMover();
Board* createBoard(int N, int M, Params params);
void guardarTablero();
void cargarTablero();
void verificarTablero();
void verificarCaramelos();
void validarTablero(int** mTablero, int i, int j, int N, int M);
void print(Board *b);

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
	Board * nuevoTablero = (Board*)malloc(sizeof(Board));
	
	int **mTablero = (int **)malloc(N * sizeof(int *));
	for (int i = 0; i < N; ++i)
    mTablero[i] = (int *)malloc(M * sizeof(int));

	//nuevoTablero->matrizSTablero
	int* lista = ordenarCandy(N, M, &params);

	#ifdef DEBUG
	for (int i = 0; i < (N*M); ++i)
	{
		printf("%d",lista[i] );
	}
	#endif

	int posicionar = 0;
	// Rellenamos el tablero con -1, para evitar tener otro valor en la memoria.
	for (int i = 0; i < N; ++i)
	{
   		for (int j = 0; j < M; ++j)
		{			
			//Tablero[i][j].matrizSTablero = "A";

			mTablero[i][j] = lista[posicionar];
			posicionar++;
		}
	}
	nuevoTablero->matrizSTablero = mTablero;
	nuevoTablero->Filas = N;
	nuevoTablero->Columnas = M;
	print(nuevoTablero);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			validarTablero(mTablero,i ,j, N, M);
		}
	}
	nuevoTablero->matrizSTablero = mTablero;
	nuevoTablero->Filas = N;
	nuevoTablero->Columnas = M;


	return nuevoTablero;
}

int* ordenarCandy(int N,int M,Params *params)
{
	int TotalCandy = (N*M);
	int candySeleccionado = 0;
	int *arregloDulces = (int*)malloc(sizeof(int)*TotalCandy);
	int i = 0;

	int candyCereza = params->candyCereza;
	int candyFrutilla = params->candyFrutilla;
	int candyManzana = params->candyManzana;
	int candyDurazno = params->candyDurazno;
	int candyUva = params->candyUva;
	int candyMCereza = params->candyMCereza;
	int candyMFrutilla = params->candyMFrutilla;
	int candyMManzana = params->candyMManzana;
	int candyMDurazno = params->candyMDurazno;
	int candyMUva = params->candyMUva;
	int candyCampana = params->candyCampana;
	int candyTutifruti = params->candyTutifruti;
	int candyLlave = params->candyLlave;

	while(i < TotalCandy)
		// Selecciona un caramelo al azar.
	{	candySeleccionado = (rand() % 13);
		switch (candySeleccionado)
		{
			case CEREZA: if(candyCereza != 0)
						 {
						 	//Pone el caramelo dentro de una lista.
						 	arregloDulces[i] = candySeleccionado;
						 	//Resta 1 a la cantidad de cerezas.
						 	candyCereza--;
						 	//Aumenta el contador en 1.
						 	i++;
						 }
						 break;
			case FRUTILLA: if(candyFrutilla != 0)
						 {
						 	//Pone el caramelo dentro de una lista.
						 	arregloDulces[i] = candySeleccionado;
						 	//Resta 1 a la cantidad de cerezas.
						 	candyFrutilla--;
						 	//Aumenta el contador en 1.
						 	i++;
						 }
						 break;
			case MANZANA: if(candyManzana != 0)
						 {
						 	//Pone el caramelo dentro de una lista.
						 	arregloDulces[i] = candySeleccionado;
						 	//Resta 1 a la cantidad de cerezas.
						 	candyManzana--;
						 	//Aumenta el contador en 1.
						 	i++;
						 }
						 break;
			case DURAZNO: if(candyDurazno != 0)
						 {
						 	//Pone el caramelo dentro de una lista.
						 	arregloDulces[i] = candySeleccionado;
						 	//Resta 1 a la cantidad de cerezas.
						 	candyDurazno--;
						 	//Aumenta el contador en 1.
						 	i++;
						 }
						 break;
			case UVA: if(candyUva != 0)
						 {
						 	//Pone el caramelo dentro de una lista.
						 	arregloDulces[i] = candySeleccionado;
						 	//Resta 1 a la cantidad de cerezas.
						 	candyUva--;
						 	//Aumenta el contador en 1.
						 	i++;
						 }
						 break;
			case MCEREZA: if(candyMCereza != 0)
						 {
						 	//Pone el caramelo dentro de una lista.
						 	arregloDulces[i] = candySeleccionado;
						 	//Resta 1 a la cantidad de cerezas.
						 	candyMCereza--;
						 	//Aumenta el contador en 1.
						 	i++;
						 }
						 break;
			case MFRUTILLA: if(candyMFrutilla != 0)
						 {
						 	//Pone el caramelo dentro de una lista.
						 	arregloDulces[i] = candySeleccionado;
						 	//Resta 1 a la cantidad de cerezas.
						 	candyMFrutilla--;
						 	//Aumenta el contador en 1.
						 	i++;
						 }
						 break;
			case MMANZANA: if(candyMManzana != 0)
						 {
						 	//Pone el caramelo dentro de una lista.
						 	arregloDulces[i] = candySeleccionado;
						 	//Resta 1 a la cantidad de cerezas.
						 	candyMManzana--;
						 	//Aumenta el contador en 1.
						 	i++;
						 }
						 break;
			case MDURAZNO: if(candyMDurazno != 0)
						 {
						 	//Pone el caramelo dentro de una lista.
						 	arregloDulces[i] = candySeleccionado;
						 	//Resta 1 a la cantidad de cerezas.
						 	candyMDurazno--;
						 	//Aumenta el contador en 1.
						 	i++;
						 }
						 break;
			case MUVA: if(candyMUva != 0)
						 {
						 	//Pone el caramelo dentro de una lista.
						 	arregloDulces[i] = candySeleccionado;
						 	//Resta 1 a la cantidad de cerezas.
						 	candyMUva--;
						 	//Aumenta el contador en 1.
						 	i++;
						 }
						 break;
			case CAMPANA: if(candyCampana != 0)
						 {
						 	//Pone el caramelo dentro de una lista.
						 	arregloDulces[i] = candySeleccionado;
						 	//Resta 1 a la cantidad de cerezas.
						 	candyCampana--;
						 	//Aumenta el contador en 1.
						 	i++;
						 }
						 break;
			case TUTIFRUTI: if(candyTutifruti != 0)
						 {
						 	//Pone el caramelo dentro de una lista.
						 	arregloDulces[i] = candySeleccionado;
						 	//Resta 1 a la cantidad de cerezas.
						 	candyTutifruti--;
						 	//Aumenta el contador en 1.
						 	i++;
						 }
						 break;
			case LLAVE: if(candyLlave != 0)
						 {
						 	//Pone el caramelo dentro de una lista.
						 	arregloDulces[i] = candySeleccionado;
						 	//Resta 1 a la cantidad de cerezas.
						 	candyLlave--;
						 	//Aumenta el contador en 1.
						 	i++;
						 }
						 break;
		}
	}

	/*for (int j = 0; j < TotalCandy; ++j)
	{
		printf(" %d ", arregloDulces[j]);
	}
	#ifdef DEBUG
	printf("candyCereza = %d\n", params->candyCereza);
	printf("candyFrutilla = %d\n", params->candyFrutilla);
	printf("candyManzana = %d\n", params->candyManzana);
	printf("candyDurazno = %d\n", params->candyDurazno);
	printf("candyMCereza = %d\n", params->candyMCereza);
	printf("candyMFrutilla = %d\n", params->candyMFrutilla);
	printf("candyMManzana = %d\n", params->candyMManzana);
	printf("candyMDurazno = %d\n", params->candyMDurazno);
	printf("candyCampana = %d\n", params->candyCampana);
	printf("candyTutifruti = %d\n", params->candyTutifruti);
	printf("Dificultad = %d\n", params->Dificultad);
	#endif*/
	
	// Falta hacer funcion que seleccione un caramelo random y lo retorne
	// descontando la cantidad ya tenida.

	return arregloDulces;
}

void validarTablero(int** mTablero, int i, int j, int N, int M)
{
	int candy = mTablero[i][j];
	int count = 0;
	while (count < N-3 & count < M - 3)
	{
		int aux;
		// Revisar a la derecha.
		if(mTablero[i][j] == candy && mTablero[i][j+1] == candy && mTablero[i][j+2] == candy)
		{
			printf("Pos1: %d\n", mTablero[i][j]);
			printf("Pos2: %d\n", mTablero[i][j+1]);
			printf("Pos3: %d\n", mTablero[i][j+2]);
			// Generar Random
			// random numero mayor a i o j y menor que n y M
			int x = (rand() % i);
			int y = (rand() % j);
			
			// Ubicar random
			aux = mTablero[i][j];
			printf("CarameloX++ : %d, PosX: %d, PosY: %d\n", aux, i, j);
			mTablero[i][j] = mTablero[x][y];
			printf("CarameloX++ : %d, PosX: %d, PosY: %d\n", mTablero[i][j], x, y);
			mTablero[x][y] = aux;
		}
		// Revisar hacia abajo
		if(M < M-3)
		{
			if (mTablero[i][j] == candy && mTablero[i+1][j] == candy && mTablero[i+2][j] == candy)
			{
				printf("Pos1: %d\n", mTablero[i][j]);
				printf("Pos2: %d\n", mTablero[i+1][j]);
				printf("Pos3: %d\n", mTablero[i+2][j]);
				// Generar Random
				int x = rand() % N+i;
				int y = rand() % M+j;
				
				// Ubicar random
				aux = mTablero[i][j];
				printf("CarameloY++ : %d, PosX: %d, PosY: %d\n", aux, i, j);
				mTablero[i][j] = mTablero[x][y];
				printf("CarameloY++ : %d, PosX: %d, PosY: %d\n", mTablero[i][j], x, y);
				mTablero[x][y] = aux;
			}
		}
		count++;
		printf("Hola estoy en el ciclo\n");
	}
	
	

}

void guardarTablero(){}
void cargarTablero(){}
void verificarTablero(){}
void verificarCaramelos(){}
void print(Board *b)
{
	int Filas = b->Filas;
	// ESTE CODIGO SIRVE
	// b->matrizSTablero[0][0]
	int Columnas = b->Columnas;
	int count = 0;
	int cantFila = 0;


	while(cantFila < Filas)
	{
		count = 0;
		// Ubico numeros de guia superiores.
		if(count == 0 && cantFila == 0)
		{
			printf("\n    ");
			for (int i = 0; i < Columnas; ++i)
			{
				if (i > 9)
				{
					printf("  %d  ", i);
				} else
				{
					printf("   %d  ", i);
				}
			}
		}
		// Ubico linea Horizontal de borde superior de cada fruta.
		if(count == 0)
		{
			printf("\n    #");
			for (int i = 0; i < Columnas; ++i)
			{
				printf("#####");
				printf("#");
			}
			count++;
		}
		
		// Ubico linea Horizontal de espacio antes de la fruta.
		if(count == 1)
		{
			printf("\n    #");
			for (int i = 0; i < Columnas; ++i)
			{
				printf("     ");
				printf("#");
			}
			count++;
		}
		
		// Ubico numero de guias laterales.
		if (count == 2)
		{
			printf("\n  %d ", cantFila);		
		}

		// Ubico linea Horizontal de espacio con Fruta.
		if (count == 2)
		{
			printf("#");
			for (int i = 0; i < Columnas; ++i)
			{
				printf("  %s  ", convertirFruta(b, cantFila, i));
				printf("#");
			}
			count++;
		}

		// Ubico linea Horizontal de espacio despues de la fruta.
		if (count == 3)
		{
			
			printf("\n    #");
			for (int i = 0; i < Columnas; ++i)
			{
				printf("     ");
				printf("#");
			}
			count++;
		}

		// Ubico linea Horizontal de borde inferior para cerrar.
		if (cantFila == Filas-1)
		{
			printf("\n    #");
			for (int i = 0; i < Columnas; ++i)
			{
				printf("#####");
				printf("#");
			}
			count++;
		}
		cantFila++;
	}
	printf("\n\n");
}

int convertirFruta(Board* b, int Filas, int Columnas)
{
	int candyConvertido = -1;
	switch (b->matrizSTablero[Filas][Columnas]) 
	{
		case CEREZA: candyConvertido = "c";
					 return candyConvertido;
		case FRUTILLA:candyConvertido = "f";
					 return candyConvertido;
		case MANZANA:candyConvertido = "m";
					 return candyConvertido;
		case DURAZNO:candyConvertido = "d";
					 return candyConvertido;
		case UVA:candyConvertido = "u";
					 return candyConvertido;
		case MCEREZA:candyConvertido = "C";
					 return candyConvertido;
		case MFRUTILLA:candyConvertido = "F";
					 return candyConvertido;
		case MMANZANA:candyConvertido = "M";
					 return candyConvertido;
		case MDURAZNO:candyConvertido = "D";
					 return candyConvertido;
		case MUVA:candyConvertido = "U";
					 return candyConvertido;
		case CAMPANA:candyConvertido = "B";
					 return candyConvertido;
		case TUTIFRUTI:candyConvertido = "T";
					 return candyConvertido;
		case LLAVE:candyConvertido = "L";
					 return candyConvertido;
	}
	return 0;
}

Params* crearParametrosTablero(int Dificultad, int N, int M)
{
	Params* nuevoParametro = malloc(sizeof(Params));
	completarParametros(nuevoParametro, Dificultad, N, M);
	//free(nuevoParametro);
	return nuevoParametro;
}

void completarParametros(Params* nuevoParametro, int Dificultad, int N, int M)
{
	int TotalCandy = (N*M);
	int presionarBatidora = 0;
	int CanRestante = 0;
	srand(time(NULL));

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
		presionarBatidora = (rand() % (13));
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
	nuevoParametro->Dificultad = Dificultad;

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
	printf("Dificultad = %d\n", nuevoParametro->Dificultad);
	#endif
}

int verificarDificultad(int Dificultad, int Candy, int *CanRestante)
{

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
		case MOSTRAR_TABLERO: //print(b);
							  break;
		case VOLVER_MENU_PRINCIPAL: seleccionMenu(MENU_PRINCIPAL);
					 break;
	}
}

void menuCrearTablero()
{
	int opcionIngresada = obtenerOpcionIngresada(0, 3, MENU_CREAR_TABLERO);
	Params* nuevoParametro;
	Board* nuevoTablero;

	switch (opcionIngresada)
	{
		case FACIL: nuevoParametro = crearParametrosTablero(FACIL, 4, 4);
					nuevoTablero = createBoard(4, 4, *nuevoParametro);
					print(nuevoTablero);
					seleccionMenu(MENU_JUGAR_MODO_PRUEBA);
					break;
		case INTERMEDIO: nuevoParametro = crearParametrosTablero(INTERMEDIO, 7, 7);
						 nuevoTablero = createBoard(7, 7, *nuevoParametro);
						 print(nuevoTablero);
						 seleccionMenu(MENU_JUGAR_MODO_PRUEBA);
						 break;
		case DIFICIL: nuevoParametro = crearParametrosTablero(DIFICIL, 10, 15);
					  nuevoTablero = createBoard(10, 15, *nuevoParametro);
					  print(nuevoTablero);
					  seleccionMenu(MENU_JUGAR_MODO_PRUEBA);
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
	printf("#            V.06            #\n");
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