#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

typedef struct aluno{
	char nome[20];
	int matricula;
	float nota[3];
	float media;
}alunos;

void leitura(alunos *v, int num){
	for(int i=0; i<num; i++){
		setbuf(stdin, NULL);
		printf("Digite o nome do aluno: \n");
		gets(v[i].nome);
		printf("Digite a matrícula do aluno: \n");
		scanf("%i", &v[i].matricula);
		printf("Digite a primeira nota do aluno: \n");
		scanf("%f", &v[i].nota[0]);
		printf("Digite a segunda nota do aluno: \n");
		scanf("%f", &v[i].nota[1]);
		printf("Digite a segunda nota do aluno: \n");
		scanf("%f", &v[i].nota[2]);
	}
}

void media(alunos *v, int num){
	for(int i=0; i<num; i++){
		v[i].media=(v[i].nota[0]+v[i].nota[1]+v[i].nota[2])/3;
	}
}

int buscasequencial(alunos *v, int num, int chave){
	
	for (int i=0; i<num; i++){
		if(v[i].matricula==chave){
			return i;
		}
	}
	return -1;
}

void ordena (alunos *v, int num){
	int i, j, aux;
	for(j=num-1; j>0; j--){
		for(i=0; i<j; i++){
			if(v[i+1].matricula < v[i].matricula){
				aux=v[i].matricula;
				v[i].matricula=v[i+1].matricula;
				v[i+1].matricula=aux;
			}
		}
	}
	
}

int buscabinaria(alunos *v, int num, int chave){
	int i;
	int inicio=0;
	int fim=num-1;
	do{
		i=(inicio+fim)/2;
		if(chave>v[i].matricula){
			inicio=i+1;
		}
		else{
			fim=i-1;
		}
	}
	while(chave!=v[i].matricula && inicio<=fim);{
		if(chave==v[i].matricula){
			return i;
		}
		else{
			return -1;
		}
	}
}

void imprime(alunos *v, int posicao){
	printf("\nDados do aluno com o número de matrícula %i:\nNome: %s.\nNota 01: %2.f.\nNota 02: %2.f.\nNota 03: %2.f.\nMedia: %2.f.", v[posicao].matricula, v[posicao].nome, v[posicao].nota[0], v[posicao].nota[1], v[posicao].nota[2], v[posicao].media);
}

int main () {
	setlocale(LC_ALL, "Portuguese");
	alunos *v;
	int num, chave, posicao, opcao=1;
	printf("Digite quantos elementos terá seu vetor: \n");
	scanf("%i", &num);
	
	v=(alunos*)malloc(num*sizeof(alunos));
	
	leitura(v, num);
	media(v, num);
	
	while(opcao!=0){
		printf("Digite o número que corresponde à opção que deseja executar:\n1-Busca Sequencial.\n2-Busca Binária");
		scanf("%i", &opcao);
		
		if(opcao==1){
			printf("Digite o número de matrícula: \n");
			scanf("%i", &chave);
			posicao=buscasequencial(v, num, chave);
			
			
			if(posicao==-1){
				printf("\nO número de matrícula buscado não existe.\n");
			}
			else{
				imprime(v, posicao);
			}
		}
		
		else if(opcao==2){
			printf("Digite o número que você quer buscar dentro do vetor: \n");
			scanf("%i", &chave);
			ordena(v, num);
			posicao=buscabinaria(v, num, chave);
			
			if(posicao==-1){
				printf("\nO número de matrícula buscado não existe.\n");
			}
			else{
			imprime(v, posicao);
			}
		}
		else if(opcao!=1&&opcao!=2&&opcao!=0){
			printf("Digite uma opção válida.\n");
		}
	
	}
	
	free(v);
	return 0;
}
