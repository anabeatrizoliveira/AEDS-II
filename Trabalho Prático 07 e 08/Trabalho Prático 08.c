#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>


typedef struct elemento{
	int valor;
	struct elemento *proximo;
}elemento;

typedef struct fila{
	elemento *inicio;
	elemento *fim;
}fila;


fila* criaFila(){
	fila*f=(fila*)malloc(sizeof(fila));
	f->inicio=NULL;	
	f->fim=NULL;	
	return f;
}

void liberaFila(fila* f){
	while(f->inicio!=NULL){
		elemento *aux;
		aux=f->inicio;
		f->inicio=f->inicio->proximo;
		free(aux);	
	}
	free(f);
}

int estaCheia(elemento* novo){
	if(novo!=NULL){
		return 1;
		//condição verdadeira, o espaço de memória foi alocado
	}
	else{
		return 0;
		//condição falsa, o espaço não foi alocado 
	}

}

int estaVazia(fila *f){
	if(f->inicio==NULL){
		return 1;
		//condição verdadeira, está vazia
	}
	else{
		return 0;
		//condição falsa, não está vazia
	}
	
}

int enfileira(fila* f, int v){
	elemento*novo=(elemento*)malloc(sizeof(elemento));
	int verifica = estaCheia(novo);
	if (verifica==1){
		if(f->inicio==NULL){
			novo->valor=v;
			novo->proximo=NULL;
			f->inicio=novo;
			f->fim=novo;
			return 1;
		}
		else{
			novo->valor=v;
			novo->proximo=NULL;
			f->fim->proximo=novo;	
			f->fim=novo;
			return 1;
		}
	
	}
	else{
		return 0;
	}
}


int desenfileira(fila* f, int* v){
	int verifica=estaVazia(f);
	if(verifica==0){
		elemento *aux;
		aux=f->inicio;
		*v=f->inicio->valor;
		f->inicio=f->inicio->proximo;
		free(aux);
			if(f->inicio==NULL){
			f->fim==NULL;
			}
		return 1;
	}

	else{
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
				printf("%i\n\n", f->fim->valor);
			}
		}
		
		else if (opcao==2){
			r=desenfileira(f, &v);
			if (r==0){
				printf("\nErro ao desenfileirar.\n\n");
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
