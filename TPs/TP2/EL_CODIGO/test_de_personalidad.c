#include "test_de_personalidad.h"
#include <stdio.h>
#include <stdbool.h>

static const char ERROR = 'E';
static const char POLAR = 'I';
static const char PANDA = 'P';
static const char PARDO = 'G';
static const char ANIME = 'A';
static const char MUSICA_POP = 'M';
static const char LIMPIEZA = 'L';
static const char BAMBU = 'B';
static const char PESCADO = 'P';
static const char FOCAS = 'F';
static const int PISO_MINIMO = 1;
static const int PISO_MAXIMO = 18;
static const int GRITO_MINIMO = 1;
static const int GRITO_MAXIMO = 18;
static const int VALOR_CANAL_LIMPIEZA = 1;
static const int VALOR_CANAL_ANIME = 2;
static const int VALOR_CANAL_MUSICA_POP = 3;
static const int VALOR_FOCAS = 3;
static const int VALOR_BAMBU = 6;
static const int VALOR_PESCADO = 9;
static const int PUNTAJE_MINIMO_POLAR = 5;
static const int PUNTAJE_MAXIMO_POLAR = 24;
static const int PUNTAJE_MINIMO_PANDA = 25;
static const int PUNTAJE_MAXIMO_PANDA = 43;
static const int PUNTAJE_MINIMO_PARDO = 44;
static const int PUNTAJE_MAXIMO_PARDO = 63;



    /*
     Post:Si el char ingresado es diferente a A, M o L, devuelve true */
  bool es_canal_no_valido (char eleccion_canal){
        return (eleccion_canal != ANIME  && eleccion_canal != MUSICA_POP && eleccion_canal != LIMPIEZA);
  }

  /* Pre: -
     Post:  Pregunta por un canal (char) al usuario.
     eleccion_canal va a ser ANIME (A), MUSICA_POP(M) o LIMPIEZA(L)
     Si el usuario no ingresa uno de esos 3 chars, le vuelve a preguntar al usuario*/
  void encuesta_canal(char* eleccion_canal){
    printf("Vas a ver televisión un rato, pones el canal de: Anime (%c), Musica Pop (%c), Limpieza (%c).\n", ANIME, MUSICA_POP, LIMPIEZA );
    scanf(" %c", eleccion_canal);

    while (es_canal_no_valido(*eleccion_canal)){
  		printf("Letra no valida, ingresar Anime (%c), Musica Pop (%c) o Limpieza (%c).\n", ANIME, MUSICA_POP, LIMPIEZA);
  		scanf(" %c", eleccion_canal);
  	}
  }

  /* Pre: -
     Post:Si el char ingresado es diferente a B, P o F, devuelve true */
  bool es_alimento_no_valido (char eleccion_alimento){
    return (eleccion_alimento != BAMBU  && eleccion_alimento != PESCADO && eleccion_alimento != FOCAS);
  }

  /* Pre: -
     Post: Pregunta por un alimento (char) al usuario.
     eleccion_alimento va a ser FOCAS (F), BAMBU(B) o PESCADO(P)
     Si el usuario no ingresa uno de esos 3 chars, le vuelve a preguntar al usuario */
  void encuesta_alimento(char* eleccion_alimento){
    printf("Solo podes guardar un alimento en tu vianda: Bambú (%c), Pescado (%c), Focas (%c).\n", BAMBU, PESCADO, FOCAS);
    scanf(" %c", eleccion_alimento);

    while (es_alimento_no_valido(*eleccion_alimento)) {
      printf("Letra no valida, ingresar Bambu (%c), Pescado (%c) o Focas (%c).\n", BAMBU, PESCADO, FOCAS);
  		scanf(" %c", eleccion_alimento);
    }
  }

  /* Pre: -
     Post:Si el int ingresado no está entre PISO_MINIMO(1) y PISO_MAXIMO(18), devuelve true */
  bool es_piso_no_valido (int eleccion_piso){
    return (eleccion_piso < PISO_MINIMO || eleccion_piso > PISO_MAXIMO);
  }

  /* Pre: -
     Post: Pregunta por un puntaje de piso al usuario. eleccion_piso va a ser un puntaje (int) entre 1 y 18 (inclusive). Este va a ser sumado en formula_puntaje_total
     Si el usuario no ingresa uno de esos numeros, le vuelve a preguntar al usuario*/
  void encuesta_piso(int* eleccion_piso){
      printf("Te compras una torre con tus dos hermanos de 18 pisos. ¿En que piso te gustaría vivir?\n");
      scanf(" %i", eleccion_piso);

      while(es_piso_no_valido(*eleccion_piso)){
        printf("Ese piso no existe, elegi entre %i y %i \n", PISO_MAXIMO, PISO_MINIMO);
        scanf(" %i", eleccion_piso);
      }
  }

  /* Pre: -
     Post:Si el int ingresado no está entre PISO_MINIMO(1) y PISO_MAXIMO(18), devuelve true */
  bool es_grito_valido (int eleccion_grito){
    return (eleccion_grito < GRITO_MINIMO || eleccion_grito > GRITO_MAXIMO);
  }

  /* Pre: -
     Post: Pregunta por un puntaje de grito al usuario. eleccion_grito va a ser un puntaje (int) entre 1 y 18 (inclusive). Este va a ser sumado en formula_puntaje_total
     Si el usuario no ingresa uno de esos numeros, le vuelve a preguntar al usuario*/
  void encuesta_grito (int* eleccion_grito){
    printf("¡Oh, una rata! ¿Que tan fuerte gritas del %i al %i? Siendo %i no gritar y %i desgarrarse la garganta.\n", GRITO_MINIMO, GRITO_MAXIMO, GRITO_MINIMO, GRITO_MAXIMO);
    scanf(" %i", eleccion_grito);

    while (es_grito_valido(*eleccion_grito)) {
      printf("No podes elegir esa opcion, tiene que ser entre %i y %i \n", GRITO_MINIMO, GRITO_MAXIMO);
      scanf(" %i", eleccion_grito);
    }
  }

  /* Pre: Que eleccion_canal sea un char de tipo LIMPIEZA(L), ANIME(A), MUSICA_POP(M).
     Post: Segun el char ingresado, se devuelve el int equivalente. Este va a ser el multiplicador usado en la cuenta final */
  int pasaje_de_canal_a_numero (char eleccion_canal){
    if (eleccion_canal == LIMPIEZA){
      return VALOR_CANAL_LIMPIEZA;
    }
    else if (eleccion_canal == ANIME){
      return VALOR_CANAL_ANIME;
    }
    else if (eleccion_canal == MUSICA_POP){
      return VALOR_CANAL_MUSICA_POP;
    }
    else{
      return 0;
    }
  }

  /* Pre: Que eleccion_alimento sea un char de tipo FOCAS(F), BAMBU(B), PESCADO(P).
     Post: Segun el char ingresado, se devuelve el int equivalente. Este va a ser un multiplicador en la cuenta final (formula_puntaje_total)*/
  int pasaje_de_alimento_a_numero (char eleccion_alimento){
    if (eleccion_alimento == FOCAS){
      return VALOR_FOCAS;
    }
    else if (eleccion_alimento == BAMBU){
      return VALOR_BAMBU;
    }
    else if (eleccion_alimento == PESCADO){
      return VALOR_PESCADO;
    }
    else{
      return 0;
    }
  }

  /* Pre: -Que valor_numerico_canal sea 1, 2 o 3
          -Que valor_numerico_comida sea 3, 6, o 9
          -Que eleccion_piso esté entre 1 y 18 (inclusive)
          -Que eleccion_grito esté entre 1 y 18 (inclusive)
     Post: Va a retorar, despues de hacer el calculo,un int entre 5 y 63 (inclusive) */
  int formula_puntaje_total(int valor_numerico_comida, int valor_numerico_canal, int eleccion_piso , int eleccion_grito){

      return (valor_numerico_comida * valor_numerico_canal) + eleccion_piso + eleccion_grito;
  }

  /* Pre: Que puntaje_total sea un int 5 y 63 (inclusive).
     Post: Segun el rango en el que se encuentre el puntaje_total, imprime por pantalla a que oso equivale (POLAR, PANDA o PARDO) */
  void determinacion_del_personaje (int puntaje_total){
    if (puntaje_total >= PUNTAJE_MINIMO_POLAR && puntaje_total <= PUNTAJE_MAXIMO_POLAR) {
    printf("Tu personalidad es de oso - Polar (%c) -.\n", POLAR);
    }

    else if (puntaje_total >= PUNTAJE_MINIMO_PANDA && puntaje_total <= PUNTAJE_MAXIMO_PANDA) {
      printf("Tu personalidad es de oso - Panda (%c) -.\n",PANDA);
    }

    else if (puntaje_total >= PUNTAJE_MINIMO_PARDO && puntaje_total <= PUNTAJE_MAXIMO_PARDO) {
      printf("Tu personalidad es de oso - Pardo (%c) -.\n", PARDO);
      }

    else{
      printf("me parece que vos y yo vamo a tener un problema\n");
      }
  }

void test_de_personalidad(char* personalidad_detectada){
  char eleccion_canal;
  char eleccion_alimento;
  int eleccion_piso = 0;
  int eleccion_grito = 0;
  int valor_numerico_canal = 0;
  int valor_numerico_comida = 0;
  int puntaje_total = 0;

  encuesta_canal(&eleccion_canal);

  valor_numerico_canal = pasaje_de_canal_a_numero(eleccion_canal);

  encuesta_alimento(&eleccion_alimento);

  valor_numerico_comida = pasaje_de_alimento_a_numero (eleccion_alimento);

  encuesta_piso(&eleccion_piso);

  encuesta_grito(&eleccion_grito);

  puntaje_total = formula_puntaje_total (valor_numerico_comida, valor_numerico_canal, eleccion_piso, eleccion_grito);

  determinacion_del_personaje(puntaje_total);

  if (puntaje_total >= PUNTAJE_MINIMO_POLAR && puntaje_total <= PUNTAJE_MAXIMO_POLAR) {
    *personalidad_detectada = POLAR;
  }

  else if (puntaje_total >= PUNTAJE_MINIMO_PANDA && puntaje_total <= PUNTAJE_MAXIMO_PANDA) {
      *personalidad_detectada = PANDA;
  }

  else if (puntaje_total >= PUNTAJE_MINIMO_PARDO && puntaje_total <= PUNTAJE_MAXIMO_PARDO) {
      *personalidad_detectada = PARDO;
    }

  else{
    printf("me parece que vos y yo vamo a tener un problema\n");
    *personalidad_detectada = ERROR;
    }
}
