#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>


typedef struct elemento{
	int valor;
	struct elemento *anterior;
}elemento;

typedef struct pilha{
	elemento *topo;
}pilha;


pilha* criaPilha(){
	pilha*p=(pilha*)malloc(sizeof(pilha));
	p->topo=NULL;	
	return p;
}

void liberaPilha(pilha* p){
	while(p->topo!=NULL){
		elemento *aux;
		aux=p->topo;
		p->topo=p->topo->anterior;
		free(aux);	
	}
	free(p);
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

int estaVazia(pilha *p){
	if(p->topo==NULL){
		return 1;
		//condição verdadeira, está vazia
	}
	else{
		return 0;
		//condição falsa, não está vazia
	}
	
}

int empilha(pilha* p, int v){
	elemento*novo=(elemento*)malloc(sizeof(elemento));
	int verifica = estaCheia(novo);
	if (verifica==1){
		novo->valor=v;
		novo->anterior=p->topo;
		p->topo=novo;
		return 1;
	}
	else{
		return 0;
	}
}


int desempilha(pilha* p, int* v){
	int verifica=estaVazia(p);
	if(verifica==0){
		elemento *aux;
		aux=p->topo;
		*v=p->topo->valor;
		p->topo=p->topo->anterior;
		free(aux);
		return 1;
	}
	else{
		return 0;
	}
	
}
	



int main () {
	setlocale(LC_ALL, "Portuguese");
	pilha *p;
	int v, r=0, opcao=1, valor;
	p=criaPilha();
	while (opcao!=0) {
		printf("Escolha a opção que deseja fazer:\n1-Empilhar.\n2-Desempilhar.\n3-Limpar a memória.\n0-Sair do Programa.\n");
		scanf("%i", &opcao);
		
		if(opcao==1){
			printf("\nDigite o valor que deseja empilhar:\n");
			scanf("%i", &valor);
			r=empilha(p, valor);
			if(r==0){
				printf("\nErro ao empilhar\n\n");
			}
			else if (r==1){
				printf("\nO %i foi empilhado com sucesso no topo da pilha.\n\n", valor);
			}
		}
		
		else if (opcao==2){
			r=desempilha(p, &v);
			if (r==0){
				printf("\nErro ao desempilhar.\n\n");
			}
			else if (r==1){
				printf("\nO %i foi desempilhado.\n\n", v);
			}
		}
		
		else if (opcao==3){
			liberaPilha(p);	
		}
		
		else{
			printf("\nDigite uma opção válida.");
		}
	}


	return 0;
}
