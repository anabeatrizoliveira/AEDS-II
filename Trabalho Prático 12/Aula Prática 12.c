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
 
 void mergesort(int a[], int n){
 	int meio;
 	if(n>1){
 		meio=n/2;
 		mergesort(a, meio);
 		mergesort(a+meio,n-meio);
 		intercala(a,n);
	 }
 }

void intercala(int a[], int n){
	vetor*tmp=(vetor*)malloc(sizeof(vetor));
	int meio=n/2;
	int i, j, k;
	i=0;
	j=meio;
	k=0;
	
	while(i<meio&&j<n){
		if(a[i]<a[j]){
			tmp->vetor[k]=a[i];
			i++;
		}
		else{
			tmp->vetor[k]=a[j];
			j++;
		}
		k++;
	}
	
	if (i==meio){
		while(j<n){
			tmp->vetor[k]=a[j];
			j++;
			k++;
		}
	}
	else {
		while(i<meio){
			tmp->vetor[k]=a[i];
			i++;
			k++;
		}
	}
	
	for(i=0; i<n; i++){
		a[i]=tmp->vetor[i];
	}
	free(tmp);
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
	
	mergesort(a.vetor, MAX);
	
	
	printf("\nO vetor digitado ordenado pelo método MergeSort é: \n\n");
	imprime(a.vetor, MAX);

	
	
	return 0;
}
