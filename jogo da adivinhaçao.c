// incluindo as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// definindo as constantes
#define NUMERO_DE_TENTATIVAS 3

int main(){

	// declarando variaveis que serao usadas mais a frente
	int chute, acertou, nivel, totaldetentativas, x, y, continuar;

	// definindo a quantidade de pontos inicial
	double pontos = 1000;
	
	// QUESTÃO 1 - gerando um numero secreto a partir de um intervalo definido
  printf("Qual o número inicial do intervalo?\n");
  scanf("%d",&x);
  printf("Qual o número final do intervalo?\n");
  scanf("%d",&y);
  
	srand(time(0));
	int numerosecreto = x + rand() % y;
  
	// escolhendo o nivel de dificuldade
	printf("Qual o nível de dificuldade?\n");
	printf("(1) Fácil (2) Médio (3) Difícil\n\n");
	printf("Escolha: ");

	scanf("%d", &nivel);
  
// QUESTÃO 2 - definindo quantidade de tentativa por nível com #define
  #define FACIL 20;
  #define MEDIO 15;
  #define DIFICIL 6;

	switch(nivel) {
		case 1: 
			totaldetentativas = FACIL;
			break;
		case 2:
			totaldetentativas = MEDIO;
			break;
		default:
			totaldetentativas = DIFICIL;
			break;
	}

	// loop principal do jogo

  //IMPLEMENTAÇÃO DO-WHILE//
  int ultimo;
  int i = 1;
		do { printf("-> Tentativa %d de %d\n", i, totaldetentativas);

		printf("Chute um número: ");
		scanf("%d", &chute);

// QUESTÃO 4 - salvando o ultimo valor e comparado com o subsequente de modo que não aceite um número igual
    
    if (chute == ultimo){
      printf("Número repetido! Tente outro.");
      i--;
    }
    
		// tratando chute de numero negativo
		if(chute < 0) {
			printf("Você não pode chutar números negativos\n");
			i--;
			  continue;
		}
    
		// verifica se acertou, foi maior ou menor
		acertou = chute == numerosecreto;

		if(acertou) {
			break;
		} else if(chute > numerosecreto) {
			printf("\nSeu chute foi maior do que o número secreto!\n\n");
		} else {
			printf("\nSeu chute foi menor do que o número secreto!\n\n");
		}

		// calcula a quantidade de pontos
		double pontosperdidos = abs(chute - numerosecreto) / 2.0;
		pontos = pontos - pontosperdidos;

   ultimo = chute;
    
	} while( i <= totaldetentativas && i++);
      

	// imprimindo mensagem de vitoria ou derrota
	printf("\n");
	if(acertou) {
		printf("             OOOOOOOOOOO               \n");
		printf("         OOOOOOOOOOOOOOOOOOO           \n");
		printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
		printf("    OOOOOO      OOOOO      OOOOOO      \n");
		printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
		printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
		printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
		printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
		printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
		printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
		printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
		printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
		printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
		printf("         OOOOOO         OOOOOO         \n");
		printf("             OOOOOOOOOOOO              \n");
		printf("\nParabéns! Você acertou!\n");
		printf("Você fez %.2f pontos. Até a próxima!\n\n", pontos);
	} else {

        printf("       \\|/ ____ \\|/    \n");   
        printf("        @~/ ,. \\~@      \n");   
        printf("       /_( \\__/ )_\\    \n");   
        printf("          \\__U_/        \n");

		printf("\nVocê perdeu! Tente novamente!\n\n");
	}
  
  // QUESTÃO 3 - loop while para verificar se deseja jogar novamente.
  printf("Você deseja jogar novamente?\n[1] SIM\n[OUTRO] NÃO\n");
  scanf("%d", &continuar);
  while (continuar == 1){
    return main();
    if (continuar != 1){
      break;
    }
    }
    }
  
  