#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define MAX 3

typedef struct pilha{
	int topo;
	int vetor[MAX];
}pilha;


pilha* criaPilha(){
	pilha *p;
	p=(pilha*)malloc(sizeof (pilha));
	p->topo=0;
	return p;
}

void liberaPilha(pilha* p){
	free(p);
}


int empilha(pilha* p, int v){
	int valor=estaCheia(p);
	if(valor==0){
		p->vetor[p->topo]=v;
		p->topo=p->topo+1;
		return 1;
	}
	else{
		return 0;
	}
}


int desempilha(pilha* p, int* v){
	int valor=estaVazia(p);
	if(valor==0){
		*v=p->vetor[p->topo-1];
		p->topo=p->topo-1;
		return 1;
	}
	else{
		return 0;
	}
	
}
	


int estaVazia(pilha *p){
	if(p->topo==0){
		return 1;
		//condição verdadeira está vazia
	}
	else{
		//condição falsa, não está vazia
		return 0;
	}
}


int estaCheia(pilha* p){
	if(p->topo==MAX){
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
				printf("\nErro ao desempilhar o %i.\n\n", v);
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
