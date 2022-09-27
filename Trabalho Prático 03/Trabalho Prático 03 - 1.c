#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

void leitura(int *v, int num){
	for(int i=0; i<num; i++){
		printf("Digite o %iº elemento do vetor: \n", i+1);
		scanf("%i", &v[i]);
	}
}

int buscasequencial(int *v, int num, int chave){
	
	for (int i=0; i<num; i++){
		if(v[i]==chave){
			return i;
		}
	}
	return -1;
}

int buscabinaria(int *v, int num, int chave){
	int i;
	int inicio=0;
	int fim=num-1;
	do{
		i=(inicio+fim)/2;
		if(chave>v[i]){
			inicio=i+1;
		}
		else{
			fim=i-1;
		}
	}
	while(chave!=v[i] && inicio<=fim);{
		if(chave==v[i]){
			return i;
		}
		else{
			return -1;
		}
	}
}

void ordena (int *v, int num){
	int i, j, aux;
	for(j=num-1; j>0; j--){
		for(i=0; i<j; i++){
			if(v[i+1] < v[i]){
				aux=v[i];
				v[i]=v[i+1];
				v[i+1]=aux;
			}
		}
	}
	
}

int main () {
	setlocale(LC_ALL, "Portuguese");
	
	int *v;
	int num, chave, posicao;
	
	printf("Digite quantos elementos terá seu vetor: \n");
	scanf("%i", &num);
	
	v=(int*)malloc(num*sizeof(int));
	
	leitura(v, num);
	
	printf("BUSCA SEQUENCIAL.\n");
	printf("Digite o número que você quer buscar dentro do vetor: \n");
	scanf("%i", &chave);
	
	posicao=buscasequencial(v, num, chave);
	
	
	if(posicao==-1){
		printf("\nO número buscado não está dentro do vetor.\n");
	}
	else{
		printf("\nA chave %i está na posição a[%i] do vetor.\n", chave, posicao);
	}
	
	
	printf("BUSCA BINÁRIA.\n");
	printf("Digite o número que você quer buscar dentro do vetor: \n");
	scanf("%i", &chave);
	ordena(v, num);
	posicao=buscabinaria(v, num, chave);
	
	if(posicao==-1){
		printf("\nO número buscado não está dentro do vetor.\n");
	}
	else{
		printf("\nA chave %i está na posição a[%i] do vetor.\n", chave, posicao);
	}
	
	free(v);
	return 0;
}
