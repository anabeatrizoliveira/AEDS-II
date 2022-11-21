#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define MAX 3

typedef struct lista{
	int vet[MAX];
	int fim;
}lista;


lista* criaLista(){
	lista *l;
	l=(lista*)malloc(sizeof (lista));
	l->fim=0;
	return l;
}

void liberaLista(lista* l){
	
	free(l);
}

int estaVazia(lista *l){
	if(l->fim==0){
		return 1;
		//condição verdadeira está vazia
	}
	else{
		//condição falsa, não está vazia
		return 0;
	}
}

int estaCheia(lista *l){
	if(l->fim==MAX){
		return 1;
		//condição verdadeira, está cheia
	}
	else{
		//condição falsa, não está cheia
		return 0;
	}
}

int inserirFim(lista* l, int v){
	
	if(estaCheia!=1){
		l->vet[l->fim] = v;
		l->fim += 1;
		return (1);
	}	
		
	else{
		return (0);
	}
}

int  inserirPosicao(lista* l, int p, int v){
	int i = 0;
	if(estaCheia==1)
	{
		return  (0);
	}
	else if(p>l->fim)
	{
		return (0);
	}
	for(i=l->fim;i>=p;i--)
	{
		l->vet[i] = l->vet[i-1];
	} 
	l->vet[p] = v;
	l->fim += 1;		
	return (1);
}

int  removerFim(lista* l, int* v){

	if(estaVazia(l))
	{
		return (0);
	}

	l->fim -= 1;
	*v = l->vet[l->fim];

	return (1);
}

int  removerPosicao(lista* l, int p, int* v){
	if(estaVazia(l))
	{
		return (0);
	}

	if(p > l->fim)
	{
		return (0);
	}
	
	*v = l->vet[p];

	for(int i = p; i <= l->fim; i++)
	{
		l->vet[i] = l->vet[i+1];
	}
	l->fim -= 1;		
	return (1);
}

int  recuperarPorChave(lista* l, int chave){
	for(int i=0; i<l->fim; i++)
	{
		if(l->vet[i] == chave)
		{
			return (i+1);
		}
	}
	return (0);
}

int  recuperarPorPosicao(lista* l, int p){
	if(p > l->fim)
	{
		return (0);
	}
	return (l->vet[p]);
}

int  contarItens(lista* l){
	if(l->fim <= 0)
	{
		return (0);
	}

	return(l->fim);
}

void imprimir(lista* l){
	printf("\n");
	for(int i=0; i<l->fim;i++)
	{
		printf(" %d == %d\n", (i+1), l->vet[i]);
	}
}



int main () {
	setlocale(LC_ALL, "Portuguese");
	int opcao=1, valor, posicao, r=0;
	
	lista *l = criaLista();
	
	while(opcao!=0){
		printf("Digite a opção que deseja fazer com sua lista:\n1- Inserir elemento por posição.\n2- Inserir elemento no final.\n3- Remover elemento por posição.\n4- Remover elemento no final.\n5- Recuperar elemento por chave.\n6- Recuperar elemento por posição.\n7- Contar os elementos.\n8- Imprimir.\n9- Libera lista.\n0- Sair. \n\n");
		scanf("%i", &opcao);	
	
		if(opcao==1){
			printf("\nDigite o valor deseja inserir?\n");
			scanf("%d", &valor);
			printf("Em qual posição?\n");
			scanf("%d", &posicao);
			
			r=inserirPosicao(l, posicao-1, valor);
			
				if(r==1){
					printf("\nValor %d inserido com sucesso!\n\n", valor);
				}
				else{
					printf("\nErro ao inserir o valor %d!\n\n", valor);
				}
			}
		
		
		else if(opcao==2){
			printf("\nQual valor deseja inserir?\n");
			scanf("%d", &valor);
			
			r=inserirFim(l, valor);
			
				if(r==1){
					printf("\nValor %d inserido com sucesso!\n\n", valor);
				}
				else{
					printf("\nErro ao inserir o valor %d!\n\n", valor);
				}
			
		}
	
		else if(opcao==3){
			printf("\nDe qual posicao deseja remover?\n");
			scanf("%d", &posicao);
			
			r=removerPosicao(l, posicao-1, &valor);
			
				if(r==1){
					printf("\nValor %d removido com sucesso!\n\n", valor);
				}
				else{
					printf("\nErro ao remover valor!\n\n");
				}
			
		}
		
		
		else if(opcao==4){
			
			r=removerFim(l, &valor);
			
				if(r==1){
					printf("\nValor %d removido do fim com sucesso!\n\n", valor);
				}
				else{
					printf("\nErro ao remover valor do fim!\n\n");
				}
			
		}
		
		else if(opcao==5){
			
			printf("\nQual a posicao do elemento?\n");
			scanf("%d", &posicao);
			
			r=recuperarPorPosicao(l, posicao-1);
			
				if(r==1){
					printf("\nElemento == %d\n\n", r);
				}
				else{
					printf("\nErro ao achar a posição!\n\n");
				}
			
		}
		
		else if(opcao==6){
			
			printf("\nQual a posicao do elemento?\n");
			scanf("%d", &valor);
			
			r=recuperarPorChave(l, valor);
			
				if(r==1){
					printf("\nPosição == %d\n\n", r+1);
				}
				else{
					printf("\nErro ao achar a chave!\n\n");
				}
			
		}
	
		else if(opcao==7){
			printf("\nTotal de elementos %d\n\n", contarItens(l));
		}
	
		else if(opcao==8){
			imprimir(l);
		}
		
		else if(opcao==9){
			liberaLista(l);	
		}
	
	
	}
	
	return 0;
}


