#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

#define MAX 10

typedef struct vetor{
	int vetor[MAX]
}vetor;

void imprime(int a[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%i\n", a[i]);
	}
}

void bolha(int a[], int n){
	int i, j, aux;
	for(i=0; i<n-1;i++){
		for(j=0; j<n; j++){
			if(a[j]<a[j-1]){
				aux=a[j];
				a[j]=a[j-1];
				a[j-1]=aux;
			}
		}
	}
}

void selecao(int a[], int n){
	int i, j, min, aux;
	for(i=0; i<n-1; i++){
		min=i;
		for(j=i+1; j<n; j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		aux=a[min];
		a[min]=a[i];
		a[i]=aux;
	}
}

void insercao(int a[], int n){
	int i, j, aux;
	for(i=1; i<n; i++){
		aux=a[i];
		j=i-1;
		while(a<a[j]&&j>=0){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=aux;
	}
}

int main () {
	
	setlocale(LC_ALL, "Portuguese");
	vetor a;
	int i=0;
	int opcao=1;
	
	for(i=0; i<MAX; i++){
		printf("Digite o %iº elemento do seu vetor: \n", i+1);
		scanf("%i", &a.vetor[i]);
	}
	
	printf("\nO vetor digitado foi: \n\n");
	imprime(a.vetor, MAX);
	
	while(opcao!=0){
		printf("\nSelecione o método de ordenação que deseja para o seu vetor: \n");
		printf("1- Método Bolha.\n2- Seleção.\n3- Inserção.\n0- Sair do Programa.\n");
		scanf("%i", &opcao);
		
		if(opcao==1){
			bolha(a.vetor, MAX);
			printf("\nSeu vetor ordenado pelo algoritmo BubbleSort: \n\n");
			imprime(a.vetor, MAX);
			
		}
		
		else if(opcao==2){
			selecao(a.vetor, MAX);
			printf("\nSeu vetor ordenado pelo algoritmo SelectionSort: \n\n");
			imprime(a.vetor, MAX);
			
		}
		
		else if(opcao==3){
			selecao(a.vetor, MAX);
			printf("\nSeu vetor ordenado pelo algoritmo InsertionSort: \n\n");
			imprime(a.vetor, MAX);			
		}
		
		else if(opcao>3&&opcao<0){
			printf("Digite uma opção válida.");
		}
	}
	
	
	return 0;
}
