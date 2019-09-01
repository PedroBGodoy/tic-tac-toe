/// Sintese
//   objetivo "Jogo-da-velha"
//   data "01/09/2019"
//   autor "Pedro Henrique Bittencourt UC19105293"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void mostrarTabuleiro(char[3][3]);
int lerValidarJogada();
void inserirJogadaMatriz(char[3][3], int, int);
void mostrarJogador(int);
void alterarJogador(int*);
int verificarVitoria(char[3][3]);

int main(){
	char mat[3][3];
	int l, c;
	int jogada;
	int jogador=0;
	int resultado;
	
	for(l=0;l<3;l++){
		for(c=0;c<3;c++){
			mat[l][c] = ' ';
		}
	}
	
	do{
		system("cls");
		mostrarJogador(jogador);
		mostrarTabuleiro(mat);
		jogada = lerValidarJogada();
		inserirJogadaMatriz(mat, jogada, jogador);
		alterarJogador(&jogador);
		resultado = verificarVitoria(mat);
	}while(jogada != -1 && resultado == -1);

	system("cls");
	mostrarJogador(jogador);
	mostrarTabuleiro(mat);

	printf("\n\n");

	if(resultado == 0)
		printf("Vitoria do jogador X");
	else if(resultado == 1)
		printf("Vitoria do jogador O");
	else
		printf("Jogo finalizado sem vencedores!!!");

	return 0;
}

void mostrarJogador(int jogador){
	if(jogador==0)
		printf("Vez do jogador 'X'\n\n");
	else
		printf("Vez do jogador 'O'\n\n");
}

void mostrarTabuleiro(char mat[3][3]){
	printf("      |     |                |     |    \n");
	printf("   %c  |  %c  |  %c          1  |  2  |  3 \n", mat[0][0], mat[0][1], mat[0][2]);
	printf("  ____|_____|____        ____|_____|____\n");
	printf("      |     |                |     |    \n");
	printf("   %c  |  %c  |  %c          4  |  5  |  6 \n", mat[1][0], mat[1][1], mat[1][2]);
	printf("  ____|_____|____        ____|_____|____\n");
	printf("      |     |                |     |    \n");
	printf("   %c  |  %c  |  %c          7  |  8  |  9 \n", mat[2][0], mat[2][1], mat[2][2]);
	printf("      |     |                |     |    \n");
}

void alterarJogador(int *jogador){
	*jogador = *jogador == 0 ? 1 : 0;
}

int lerValidarJogada(){
	int posicao;
	
	do{
		printf("\nDigite uma posicao para jogar: ");
		fflush(stdin);
		scanf("%d", &posicao);
	}while((posicao < 1 && posicao != -1) || posicao > 9);
	
	return posicao;
}

void inserirJogadaMatriz(char mat[3][3], int posicao, int jogador){
	int l, c;
	
	l=ceil(posicao/3.0)-1;
	c=((posicao+3) % 3)-1;
	c = c==-1 ? 2 : c;
	
	mat[l][c] = jogador==0 ? 'X' : 'O';
}

int verificarVitoria(char mat[3][3]){
	int l, c;
	int posX=0, posO=0;
	
	//HORIZONTAL
	while(posX < 3 && posO < 3 && l < 3){
		for(c=0;c<3;c++){
			if(mat[l][c] == 'X'){
				posX++;
				posO=0;
			}else if(mat[l][c] == 'O'){
				posO++;
				posX=0;
			}else{
				posX=0;
				posO=0;
			}
		}
		l++;
	}
	
	if(posX >= 3)
		return 0;
	else if(posO >= 3)
		return 1;
		
	posX = 0;
	posO = 0;
		
	//VERTICAL
	for(c=0;c<3;c++){
		for(l=0;l<3;l++){
			if(mat[l][c] == 'X'){
				posX++;
				posO=0;
			}else if(mat[l][c] == 'O'){
				posO++;
				posX=0;
			}else{
				posX=0;
				posO=0;
			}
		}
	}
	
	if(posX == 3)
		return 0;
	else if(posO == 3)
		return 1;
		
	posX = 0;
	posO = 0;
		
	//DIAGONAL PRINCIPAL
	for(l=0;l<3;l++){
		if(mat[l][l] == 'X'){
			posX++;
			posO=0;
		}else if(mat[l][l] == 'O'){
			posO++;
			posX=0;
		}else{
			posX=0;
			posO=0;
		}
	}
	
	if(posX == 3)
		return 0;
	else if(posO == 3)
		return 1;
		
	posX = 0;
	posO = 0;
		
	c=2;
	//DIAGONAL SECUNDARIA
	for(l=0;l<3;l++){
		if(mat[l][c] == 'X'){
			posX++;
			posO=0;
		}else if(mat[l][c] == 'O'){
			posO++;
			posX=0;
		}else{
			posX=0;
			posO=0;
		}
		c--;
	}
	
	if(posX == 3)
		return 0;
	else if(posO == 3)
		return 1;
		
	return -1;
}
	
