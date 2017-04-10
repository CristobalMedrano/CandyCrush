#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 

// #define

#define DEBUG2
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
#define MCEREZA 4
#define MFRUTILLA 5
#define MMANZANA 6
#define TUTIFRUTI 7
#define LLAVE 8

// Estructuras

typedef struct Tablero
{
	int Filas;
	int Columnas;
	int **matrizSTablero;
	int idGuardado;
	int Dificultad;
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
	int candyMCereza;
	int candyMFrutilla;
	int candyMManzana;
	int candyTutifruti;
	int candyLlave;
	int Dificultad;
	//int nivel;
} Params ;

typedef struct Dulce
{
	int Fruta;
	int Dureza;
	int Poder;
} Candy ;

typedef struct Posicion
{
	int* exDulces;

} Position ;




// Cabecera

// Menu Cabecera
// MenuCrearTablero
Params* crearParametrosTablero(int Dificultad, int N, int M);
void completarParametros(Params* nuevoParametro, int Dificultad, int N, int M);
int verificarDificultad(int Dificultad, int Candy, int *CanRestante);
int* obtenerListaCaramelo(int N,int M,Params *params);

int** obtenerMatrizCandy(int N,int M,Params *params);
int convertirFruta(Board* b, int Filas, int Columnas);

// MenuJugarModoPrueba
void jugarMover();
Board* createBoard(int N, int M, Params params);
void saveBoard(Board* b, int* id);
Board* loadBoard(int id);
Position* checkCandies(Board* b);
int validarTablero(int** mTablero, int N, int M);
void print(Board *b);

// MenuPrincipal
void jugar();
char* obtenerFecha(int *id);
char* obtenerNombre(int *id);
int obtenerID();

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

int verificarFilasColumnas(int dificultad, int N, int M);
int verificarDulces(int** Tablero, int dificultad, int N, int M);





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
	int** mTablero = obtenerMatrizCandy(N, M, &params);

	// Guardamos el tablero temporal.
	nuevoTablero->matrizSTablero = mTablero;
	// Guardamos la cantidad de filas.
	nuevoTablero->Filas = N;
	// Guardamos la cantidad de columnas.
	nuevoTablero->Columnas = M;
	// Guardamos la dificultad.
	nuevoTablero->Dificultad = params.Dificultad;
	print(nuevoTablero);

	return nuevoTablero;
}

int** obtenerMatrizCandy(int N,int M,Params *params)
{
	int **mTablero = (int **)malloc(N * sizeof(int *));
					for (int i = 0; i < N; ++i)
					mTablero[i] = (int *)malloc(M * sizeof(int));

	// Mientras validar tablero sea falso, regeneramos el tablero.
	int* listaCaramelo;
	int seleccionador;
	int i;
	int j;
	int validar = FALSE;
	while(validar != TRUE)
	{

		listaCaramelo = obtenerListaCaramelo(N, M, params);

		seleccionador = 0;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < M; j++)
			{
				mTablero[i][j] = listaCaramelo[seleccionador];
				seleccionador++;
			}
		}
		validar = validarTablero(mTablero, N, M);
	}

 
	//while
	// mientras checkcandy encuentra tres en linea, crea denuevo
	// El tablero..

	return mTablero;
}

int validarTablero(int** mTablero, int N, int M)
{

	int dulce;
	int i;
	int j;

	// Revisar Filas
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M-2; j++)
		{
			dulce = mTablero[i][j];
			if (mTablero[i][j] == dulce && mTablero[i][j+1] == dulce 
				&& mTablero[i][j+2] == dulce)
			{
				return FALSE; // Si el mapa no es valido
			}
		}
	}
	// Revisar Columnas
	for (j = 0; j < M; j++)
	{
		for (i = 0; i < N-2; i++)
		{
			dulce = mTablero[i][j];
			if (mTablero[i][j] == dulce && mTablero[i+1][j] == dulce 
				&& mTablero[i+2][j] == dulce)
			{
				return FALSE; // Si el mapa no es valido
			}
		}
	}
	return TRUE; // Si el mapa esta validado
}

int* obtenerListaCaramelo(int N,int M,Params *params)
{

	int* listaCaramelo = malloc(sizeof(int)*(N*M));
	int candyCereza = params->candyCereza;
	int candyFrutilla = params->candyFrutilla;
	int candyManzana = params->candyManzana;
	int candyDurazno = params->candyDurazno;
	int candyMCereza = params->candyMCereza;
	int candyMFrutilla = params->candyMFrutilla;
	int candyMManzana = params->candyMManzana;
	int candyTutifruti = params->candyTutifruti;
	int candyLlave = params->candyLlave;

	int candySeleccionado = -1;
	int count = 0;
	
	while (count < (N*M))
	{
		candySeleccionado = (rand() % 9);
		switch (candySeleccionado)
		{
			case CEREZA:if (candyCereza != 0)
						{ 
							listaCaramelo[count] = candySeleccionado;
							candyCereza--;
							count++;		
						}
			
			break;
				
						
			case FRUTILLA: if(candyFrutilla != 0)
						{
							listaCaramelo[count] = candySeleccionado;
							candyFrutilla--;
							count++;					
					 	}
						 break;
			case MANZANA: if(candyManzana != 0)
						 {
						 	listaCaramelo[count] = candySeleccionado;
						 	candyManzana--;
						 	count++;					 
						 }
						 break;
			case DURAZNO: if(candyDurazno != 0)
						 {
						 	listaCaramelo[count] = candySeleccionado;
						 	candyDurazno--;
						 	count++;					 
						 }
						 break;
			case MCEREZA: if(candyMCereza != 0)
						 {
						 	listaCaramelo[count] = candySeleccionado;
						 	candyMCereza--;
						 	count++;						 
						 }
						 break;
			case MFRUTILLA: if(candyMFrutilla != 0)
						 {
						 	listaCaramelo[count] = candySeleccionado;
						 	candyMFrutilla--;
						 	count++;						 	
						  }
						 break;
			case MMANZANA: if(candyMManzana != 0)
						 {
						 	listaCaramelo[count] = candySeleccionado;
						 	candyMManzana--;
						 	count++;						 
						 }
						 break;
			case TUTIFRUTI: if(candyTutifruti != 0)
						 {
						 	listaCaramelo[count] = candySeleccionado;
						 	candyTutifruti--;
						 	count++;						 
							 }
						 break;
			case LLAVE: if(candyLlave != 0){
						
							listaCaramelo[count] = candySeleccionado;
							candyLlave--;
							count++;						
						}
						break;
		}	
	}
	
	return listaCaramelo;	
}

void saveBoard(Board* b, int* id)
{
	// Obtenemos la ID del tablero a guardar.
	*id = obtenerID();

	// Guardamos la id.
	b->idGuardado = *id;
	
	// generamos el nombre del archivo.
	char* saveID = obtenerNombre(id);

	//Obtenemos el puntero del archivo a leer.
	FILE *archivoSalida;
	archivoSalida = fopen(saveID, "w");
    
    if(archivoSalida == NULL)
    {
        printf("Error al abrir archivo\n");
    }

    fprintf(archivoSalida, "%d", b->Dificultad);
    fprintf(archivoSalida, " ");
    fprintf(archivoSalida, "%d", b->Filas);
    fprintf(archivoSalida, " ");
    fprintf(archivoSalida, "%d ", b->Columnas);
    int i;
	int j;

	// Escribimos cada posicicion de la matriz en el archivo.
	for (i = 0; i < b->Filas; i++)
	{
		for (j = 0; j < b->Columnas; j++)
		{
			fprintf(archivoSalida, "%d ", b->matrizSTablero[i][j]);
		}
		//fprintf(archivoSalida,"\n");
	}

	//Escribimos la hora.
	char* hora = obtenerFecha(id);
	fprintf(archivoSalida, "\n%s", hora);
    fclose(archivoSalida);
}

char* obtenerNombre(int *id)
{
	static char saveID[20];
	// Convertimos la id en string.
	char strID[10];
	sprintf(strID, "%d", *id);

	// Concatenamos el nombre del archivo.
	saveID[0] = '\0';
	strcat(saveID, "save_");
	strcat(saveID, strID);
	strcat(saveID, ".sb");
	return saveID;
}

char* obtenerFecha(int *id)
{
	static char hora[128];
	time_t tiempo = *id;
    struct tm *tlocal = localtime(&tiempo);
    hora[0] = '\0';
    strftime(hora, 128, "Fecha: %d/%m/%y Hora: %H:%M:%S", tlocal);
    return hora;
}

int obtenerID()
{
	int id = (int)time(NULL);
    return id;
}


Board* loadBoard(int id)
{
	int N = 0;
	int M = 0;
	int dificultad;
	Board* cargarTablero;
	int **mTablero;

	FILE *archivoEntrada;
	// Convertimos id en un texto a leer.
	char* loadID = obtenerNombre(&id);

	archivoEntrada = fopen(loadID, "r");
	if(archivoEntrada == NULL)
    {
        printf("Archivo no encontrado.");
    }
    fscanf(archivoEntrada,"%d",&dificultad);
	fscanf(archivoEntrada,"%d",&N);
	fscanf(archivoEntrada,"%d",&M);

	int i;
	int j;
	int valor = 0;
	char inicio;
	char final;

	mTablero =	(int **)malloc(N * sizeof(int *));
				for (int i = 0; i < N; ++i)
				mTablero[i] = (int *)malloc(M * sizeof(int));
	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < M)
		{	
			fscanf(archivoEntrada, "%d", &valor);
			mTablero[i][j] = valor;
			j++;
		}
		i++;
	}


	fclose(archivoEntrada);

	cargarTablero = (Board*)malloc(sizeof(Board));
	// Guardamos el tablero temporal.
	cargarTablero->matrizSTablero = mTablero;
	// Guardamos la cantidad de filas.
	cargarTablero->Filas = N;
	// Guardamos la cantidad de columnas.
	cargarTablero->Columnas = M;
	cargarTablero->idGuardado = id;
	cargarTablero->Dificultad = dificultad;

	printf("Archivo leido Correctamente.\n");
	return cargarTablero;
}

int checkBoard(Board* b)
{
	int** Tablero = b->matrizSTablero;
	int N = b->Filas;
	int M = b->Columnas;
	int id = b->idGuardado;
	int dificultad = b->Dificultad;
	//Verificamos la dificultad, cantidad de filas y dulces.
	int i;
	int j;
	int Candy;
	int CanRestante = (N*M);

	// Primero verificamos la cantidad de filas y colummnas.
	int ver1 = verificarFilasColumnas(dificultad, N, M);

	// Segundo verificamos si los dulces son correctos y acordes
	// al nivel.
	int ver2 = verificarDulces(Tablero, dificultad, N, M);

	// Tercera verficiamos si contador es mayor o igual a 6.

	printf("ver1 :%d\n", ver1);
	printf("ver2 :%d\n", ver2);
	// Si las 3 verificaciones son verdaderas, entonces el tablero
	// es valido. De modo contrario es Falso e invalido.
	if (ver1 == TRUE && ver2 == TRUE)
	{
		return TRUE;
	} else
	{
		return FALSE;
	}
}

int verificarFilasColumnas(int dificultad, int N, int M)
{
	switch (dificultad) 
	{
		case FACIL: if(N == 5 && M == 5)
					{
						return TRUE;
					}
					return FALSE;

		case INTERMEDIO: if(N == 7 && M == 7)
					{
						return TRUE;
					}
					return FALSE;
		case DIFICIL:if(N == 10 && M == 10)
					{
						return TRUE;
					}
					return FALSE;
		default: return FALSE;
	}
}

int verificarDulces(int** Tablero, int dificultad, int N, int M)
{
	int Candy;
	int CanRestante = (N*M);
	int i;
	int j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			Candy = Tablero[i][j];
			if(verificarDificultad(dificultad, Candy, &CanRestante) != 1)
			{
				return FALSE;
			}
		}
	}
	return TRUE;
}

Position* checkCandies(Board* b)
{
	printf("Hola\n");
	int k;
	Position* checkCandy = (Position*)malloc(sizeof(Position));
	int* exDulces;
	int N = b->Filas;
	int M = b->Columnas;
	int i;
	int j;
	int dulce;
	int** mTablero = b->matrizSTablero;
	// Revisamos Filas.
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M-2; j++)
		{	
			dulce = mTablero[i][j];
			// Desde el punto hasta j<M-2
			if(j < (M-2) && mTablero[i][j+1] == dulce
				&& mTablero[i][j+2] == dulce)
			{
				printf("%d\n", mTablero[i][j]);
				printf("%d\n", mTablero[i][j+1]);
				printf("%d\n", mTablero[i][j+2]);
				printf("Condicion?\n");
				k = 0;
				// En caso de necesitar el dulce, meterlo al final.
				while(mTablero[i][j+k] == dulce)
				{
					exDulces[k] = i;
					exDulces[k+1] = (j+k+1);
					k++;	
				}
				checkCandy->exDulces = exDulces;
				return checkCandy;
			}			
		}
	}
	// Revisar colummna;
	printf("for 2\n");
	for (j = 0; j < M; j++)
	{
		for (i = 0; i < N-2; i++)
		{	
			dulce = mTablero[i][j];
			// Desde el punto hasta i<N-2
			if(i < (N-2) && mTablero[i+1][j] == dulce
				&& mTablero[i+2][j] == dulce)
			{
				k = 0;
				while(mTablero[i+k][j] == dulce)
				{
					exDulces = (int*)malloc(sizeof(int)*(k+1));
					printf("soy k%d\n", k);
					exDulces[k] = (i+k);
					k++;
					exDulces[k] = j;
					k++;		
				}
				// Agregar un contador para luego asignar memoria y repartir los dulces.
				// crear una funcion que haga esto, retorna la lista y cantidad.
				checkCandy->exDulces = exDulces;
				return checkCandy;
			}			
		}
	}
	// Retorno falso porque no encontre lista.
	printf("Hola soy falso\n");
	exDulces[0] = -1;
	checkCandy->exDulces = exDulces;
	return checkCandy;
}
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
			// Muestro por pantalla letras desde la A.
			printf("\n  %c ", cantFila+65);		
		}

		// Ubico linea Horizontal de espacio con Fruta.
		if (count == 2)
		{
			printf("#");
			for (int i = 0; i < Columnas; ++i)
			{
				printf("  %c  ", convertirFruta(b, cantFila, i));
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
		// La numeracion asignada al candy, es la letra en ascii.
		case CEREZA: candyConvertido = 99;
					 return candyConvertido;
		case FRUTILLA:candyConvertido = 102;
					 return candyConvertido;
		case MANZANA:candyConvertido = 109;
					 return candyConvertido;
		case DURAZNO:candyConvertido = 100;
					 return candyConvertido;
		case MCEREZA:candyConvertido = 67;
					 return candyConvertido;
		case MFRUTILLA:candyConvertido = 70;
					 return candyConvertido;
		case MMANZANA:candyConvertido = 77;
					 return candyConvertido;
		case TUTIFRUTI:candyConvertido = 84;
					 return candyConvertido;
		case LLAVE:candyConvertido = 76;
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
	int candyCereza = 0;
	int candyFrutilla = 0;
	int candyManzana = 0;
	int candyDurazno = 0;
	int candyMCereza = 0;
	int candyMFrutilla = 0;
	int candyMManzana = 0;
	int candyTutifruti = 0;
	int candyLlave = 0;

	while (CanRestante < TotalCandy)
	{
		presionarBatidora = (rand() % (9));
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
			// Se restringe la cantidad de dulces mejorados.
			case MCEREZA: if (candyMCereza < 10)
						  {
						  	candyMCereza +=
						  	verificarDificultad(Dificultad, MCEREZA, &CanRestante);
						  }
						  break;
			case MFRUTILLA: if (candyMFrutilla < 20)
							{
								candyMFrutilla += 
								verificarDificultad(Dificultad, MFRUTILLA, &CanRestante);
							}
						    break;
			case MMANZANA:  if (candyMManzana < 30)
							{
								candyMManzana +=
						   		verificarDificultad(Dificultad, MMANZANA, &CanRestante);
							} 
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
	nuevoParametro->candyMCereza = candyMCereza;
	nuevoParametro->candyMFrutilla = candyMFrutilla;
	nuevoParametro->candyMManzana = candyMManzana;
	nuevoParametro->candyTutifruti = candyTutifruti;
	nuevoParametro->candyLlave = candyLlave;
	nuevoParametro->Dificultad = Dificultad;

	#ifdef DEBUG
	printf("candyCereza = %d\n", nuevoParametro->candyCereza);
	printf("candyFrutilla = %d\n", nuevoParametro->candyFrutilla);
	printf("candyManzana = %d\n", nuevoParametro->candyManzana);
	printf("candyDurazno = %d\n", nuevoParametro->candyDurazno);
	printf("candyMCereza = %d\n", nuevoParametro->candyMCereza);
	printf("candyMFrutilla = %d\n", nuevoParametro->candyMFrutilla);
	printf("candyMManzana = %d\n", nuevoParametro->candyMManzana);
	printf("candyTutifruti = %d\n", nuevoParametro->candyTutifruti);
	printf("candyLlave = %d\n", nuevoParametro->candyLlave);
	printf("Dificultad = %d\n", nuevoParametro->Dificultad);
	#endif
}

int verificarDificultad(int Dificultad, int Candy, int *CanRestante)
{

	int arregloDulcesFACIL[3] = {CEREZA, FRUTILLA, MCEREZA};
	int arregloDulcesINTERMEDIO[6] = {CEREZA, FRUTILLA, MANZANA, MCEREZA, 
									  MFRUTILLA, TUTIFRUTI};
	int arregloDulcesDIFICIL[9] = {CEREZA, FRUTILLA, MANZANA, DURAZNO,
									MCEREZA, MFRUTILLA, MMANZANA, TUTIFRUTI, LLAVE};

	if (Dificultad == FACIL)
	{
		for (int i = 0; i < 3; ++i)
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
		for (int i = 0; i < 6; ++i)
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
		for (int i = 0; i < 9; ++i)
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
	// Muestra el menu y retorna esa opcion, asi podemos controlar mejor los datos generales
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
		case GUARDAR_TABLERO: //saveBoard(b, &id);
						  	  break;
		case CARGAR_TABLERO: //loardBoard(id);
						  	 break;
		case VERIFICAR_TABLERO: //checkBoard(b);
						  		break;
		case VERIFICAR_CARAMELOS: //checkCandies(b);
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
	Board* Tablero;
	Position* pos;

	switch (opcionIngresada)
	{
		case FACIL: nuevoParametro = crearParametrosTablero(FACIL, 5, 5);
					Tablero = createBoard(5, 5, *nuevoParametro);
					print(Tablero);
					//int id;
					//saveBoard(Tablero, &id);
					//printf("Soy la id del menu: %d\n", id);
					Tablero = loadBoard(1491809684);
					//int error = checkBoard(Tablero);
					//if(error == 1)printf("True\n");
					//if(error == 0)printf("False\n");
					print(Tablero);
					pos = checkCandies(Tablero);
					int* hola = pos->exDulces;

					
				
					seleccionMenu(MENU_JUGAR_MODO_PRUEBA);
					break;
		case INTERMEDIO: nuevoParametro = crearParametrosTablero(INTERMEDIO, 7, 7);
						 Tablero = createBoard(7, 7, *nuevoParametro);
						 print(Tablero);
						 seleccionMenu(MENU_JUGAR_MODO_PRUEBA);
						 break;
		case DIFICIL: nuevoParametro = crearParametrosTablero(DIFICIL, 10, 10);
					  Tablero = createBoard(10, 10, *nuevoParametro);
					  print(Tablero);
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
	printf("#            V.13            #\n");
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
	srand(time(NULL));

	seleccionMenu(MENU_PRINCIPAL);
	return 0;
}