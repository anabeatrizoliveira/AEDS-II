#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

typedef struct pontos{
	//struct das vari�veis de cada coisa necess�ria para a confer�ncia
	float x, y;
	int quadrante;
}pontos;

pontos leitura (){
	//ler os valores, inicializa��o
	pontos a;
	printf("Digite os valores que corresponder�o ao ponto, o primeiro no eixo x e depois no ponto y:\n");
	scanf("%f %f", &a.x, &a.y);
	return a;
}

int leituraquadrante (){
	//ler o quadrante para a confer�ncia
	int a;
	printf("Digite o c�digo que deseja fazer a cofer�ncia do quadrante: \n0-Origem\n1-Primeiro Quadrante\n2-Segundo Quadrante\n3-Terceiro Quadrante\n4-Quarto Quadrante\n5-Eixo x com y negativo\n6-Eixo x com y positivo\n7-Eixo y com x positivo\n5-Eixo y com x negativo\n");
	scanf("%d", &a);
	return a;
}

float calculo (pontos a, pontos b){
	//calculo da dist�ncia
	float distancia;
	distancia=sqrt(((b.x-a.x)*(b.x-a.x))+((b.y-a.y)*(b.y-a.y)));
	return distancia;
}

pontos quadranteconferencia(pontos a){
	//fun��o para definir em qual quadrante se encontra
	if((a.x==0)&&(a.y==0)){
		a.quadrante=0;
		//quadrante=0 os pontos est�o na origem
	}
	else if((a.x>0)&&(a.y>0)){
		a.quadrante=1;
		//quadrante=1 os pontos est�o no primeiro quadrante
	}
	else if((a.x<0)&&(a.y>0)){
		a.quadrante=2;
		//quadrante=2 os pontos est�o no segundo quadrante
	}
	else if((a.x<0)&&(a.y<0)){
		a.quadrante=3;
		//quadrante=3 os pontos est�o no terceiro quadrante
	}
	else if((a.x>0)&&(a.y<0)){
		a.quadrante=4;
		//quadrante=4 os pontos est�o no quarto quadrante
	}
	else if((a.x==0)&&(a.y<0)){
		a.quadrante=5;
		//quadrante=5 os pontos est�o no eixo x com y negativo
	}
	else if((a.x==0)&&(a.y>0)){
		a.quadrante=6;
		//quadrante=6 os pontos est�o no eixo x com y positivo
	}
	else if((a.x>0)&&(a.y==0)){
		a.quadrante=7;
		//quadrante=7 os pontos est�o no eixo y com x positivo
	}
	else if((a.x<0)&&(a.y==0)){
		a.quadrante=8;
		//quadrante=8 os pontos est�o no eixo y com x negativo
	}
	return a;
}

int maiorponto(pontos a){
	//fun��o para definir se o x ou o y � maior
	if (a.x > a.y){
		return 0;
	}
	else if (a.x < a.y){
		return 1;
	}
	else if (a.x == a.y){
		return 2;
	}
	
}
int main () {
	
	setlocale(LC_ALL, "Portuguese");
	pontos a, b;
	float distancia;
	int escolha=1, quadrante, maiorcoordenada;
	
	while(escolha>0){
		printf("Digite o item que corresponde a a��o que deseja fazer.\n1-Analisar qual quadrante um ponto se encontra.\n2-Confer�ncia se um ponto est� em um determinado quadrante.\n3-Retornar a dist�ncia entre dois pontos.\n4-Retornar o maior valor de coordenada de um ponto.\n");
		scanf("%d", &escolha);
	
		if(escolha>4){
			printf("Digite uma op��o v�lida.\n\n");
		}
		
		else if(escolha==1){
			a=leitura();
			a=quadranteconferencia(a);
			if(a.quadrante==0){
			printf("O ponto de coordenada(%.2f, %.2f) est� na origem.\n\n", a.x, a.y);
			}
			else if(a.quadrante==1){
				printf("O ponto de coordenada(%.2f, %.2f) est� no primeiro quadrante.\n\n", a.x, a.y);
			}
			else if(a.quadrante==2){
				printf("O ponto de coordenada(%.2f, %.2f) est� no segundo quadrante.\n\n", a.x, a.y);
			}
			else if(a.quadrante==3){
				printf("O ponto de coordenada(%.2f, %.2f) est� no terceiro quadrante.\n\n", a.x, a.y);
			}
			else if(a.quadrante==4){
				printf("O ponto de coordenada(%.2f, %.2f) est� no quarto quadrante.\n\n", a.x, a.y);
			}
			else if(a.quadrante==5){
				printf("O ponto de coordenada(%.2f, %.2f) est� no eixo x com y negativo.\n\n", a.x, a.y);
			}
			else if(a.quadrante==6){
				printf("O ponto de coordenada(%.2f, %.2f) est� no eixo x com y positivo.\n\n", a.x, a.y);
			}
			else if(a.quadrante==7){
				printf("O ponto de coordenada(%.2f, %.2f) est� no eixo y com x positivo.\n\n", a.x, a.y);
			}
			else if(a.quadrante==8){
				printf("O ponto de coordenada(%.2f, %.2f) est� no eixo y com x negativo.\n\n", a.x, a.y);
			}
			
		}
		
		else if(escolha==2){
			a=leitura();
			quadrante=leituraquadrante();
			a=quadranteconferencia(a);
			
			if(a.quadrante==quadrante){
				printf("Os pontos (%.2f, %.2f) est�o no quadrante indicado.\n\n", a.x, a.y);
			}
			else{
				printf("Os pontos (%.2f, %.2f) n�o est�o no quadrante indicado.\n\n", a.x, a.y);
			}
			
		}
	
		else if(escolha==3){
			a=leitura();
			b=leitura();
			distancia=calculo(a, b);
			printf("A dist�ncia entre os pontos A(%.2f, %.2f) e B(%.2f, %.2f) � igual a: %f\n\n",a.x, a.y, b.x, b.y, distancia);
		}
		
		else if(escolha==4){
			a=leitura();
			maiorcoordenada=maiorponto(a);
			if(maiorcoordenada==0){
				printf("O ponto x: %.2f � maior que o ponto y: %.2f.\n\n", a.x, a.y);
			}
			if(maiorcoordenada==1){
				printf("O ponto y: %.2f � maior que o ponto x: %.2f.\n\n", a.y, a.x);
			}
			if(maiorcoordenada==2){
				printf("O ponto x: %.2f � igual ao ponto y: %.2f.\n\n", a.x, a.y);
			}
		}
	}	

	return 0;
}
