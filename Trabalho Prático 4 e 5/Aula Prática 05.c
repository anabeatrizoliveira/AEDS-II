#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define MAX 3

typedef struct fila{
	int inicio, fim;
	int vetor[MAX];
}fila;


fila* criaFila(){
	fila *f;
	f=(fila*)malloc(sizeof (fila));
	f->inicio=0;
	f->fim=0;
	return f;
}

void liberaFila(fila* f){
	free(f);
}


int enfileira(fila* f, int v){
	int valor=estaCheia(f);
	if(valor==0){
		f->vetor[f->fim]=v;
		f->fim=f->fim+1;
		return 1;
	}
	else{
		return 0;
	}
}


int desenfileira(fila* f, int* v){
	int valor=estaVazia(f);
	if(valor==0){
		*v=f->vetor[f->inicio];
		f->inicio=f->inicio+1;
		return 1;
	}
	else{
		return 0;
	}
	
}
	


int estaVazia(fila *f){
	if(f->fim==0){
		return 1;
		//condição verdadeira está vazia
	}
	else{
		//condição falsa, não está vazia
		return 0;
	}
}


int estaCheia(fila *f){
	if(f->fim==MAX){
		return 1;
		//condição verdadeira, está cheia
	}
	else{
		//condição falsa, não está cheia
		return 0;
	}
}


int main () {
	setlocale(LC_ALL, "Portuguese");
	fila *f;
	int v, r=0, opcao=1, valor;
	f=criaFila();
	while (opcao!=0) {
		printf("Escolha a opção que deseja fazer:\n1-Enfileirar.\n2-Desenfileirar.\n3-Limpar a memória.\n0-Sair do Programa.\n");
		scanf("%i", &opcao);
		
		if(opcao==1){
			printf("\nDigite o valor que deseja enfileirar:\n");
			scanf("%i", &valor);
			r=enfileira(f, valor);
			if(r==0){
				printf("\nErro ao enfileirar\n\n");
			}
			else if (r==1){
				printf("\nO %i foi enfileirado com sucesso no fim da fila.\n\n", valor);
			}
		}
		
		else if (opcao==2){
			r=desenfileira(f, &v);
			if (r==0){
				printf("\nErro ao desenfileirar o %i.\n\n", v);
			}
			else if (r==1){
				printf("\nO %i foi desenfileirado.\n\n", v);
			}
		}
		
		else if (opcao==3){
			liberaFila(f);	
		}
		
		else{
			printf("\nDigite uma opção válida.");
		}
	}


	return 0;
}
