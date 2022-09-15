#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

typedef struct pontos{
	//struct das variáveis de cada coisa necessária para a conferência
	float x, y;
	int quadrante;
}pontos;

pontos leitura (){
	//ler os valores, inicialização
	pontos a;
	printf("Digite os valores que corresponderão ao ponto, o primeiro no eixo x e depois no ponto y:\n");
	scanf("%f %f", &a.x, &a.y);
	return a;
}

int leituraquadrante (){
	//ler o quadrante para a conferência
	int a;
	printf("Digite o código que deseja fazer a coferência do quadrante: \n0-Origem\n1-Primeiro Quadrante\n2-Segundo Quadrante\n3-Terceiro Quadrante\n4-Quarto Quadrante\n5-Eixo x com y negativo\n6-Eixo x com y positivo\n7-Eixo y com x positivo\n5-Eixo y com x negativo\n");
	scanf("%d", &a);
	return a;
}

float calculo (pontos a, pontos b){
	//calculo da distância
	float distancia;
	distancia=sqrt(((b.x-a.x)*(b.x-a.x))+((b.y-a.y)*(b.y-a.y)));
	return distancia;
}

pontos quadranteconferencia(pontos a){
	//função para definir em qual quadrante se encontra
	if((a.x==0)&&(a.y==0)){
		a.quadrante=0;
		//quadrante=0 os pontos estão na origem
	}
	else if((a.x>0)&&(a.y>0)){
		a.quadrante=1;
		//quadrante=1 os pontos estão no primeiro quadrante
	}
	else if((a.x<0)&&(a.y>0)){
		a.quadrante=2;
		//quadrante=2 os pontos estão no segundo quadrante
	}
	else if((a.x<0)&&(a.y<0)){
		a.quadrante=3;
		//quadrante=3 os pontos estão no terceiro quadrante
	}
	else if((a.x>0)&&(a.y<0)){
		a.quadrante=4;
		//quadrante=4 os pontos estão no quarto quadrante
	}
	else if((a.x==0)&&(a.y<0)){
		a.quadrante=5;
		//quadrante=5 os pontos estão no eixo x com y negativo
	}
	else if((a.x==0)&&(a.y>0)){
		a.quadrante=6;
		//quadrante=6 os pontos estão no eixo x com y positivo
	}
	else if((a.x>0)&&(a.y==0)){
		a.quadrante=7;
		//quadrante=7 os pontos estão no eixo y com x positivo
	}
	else if((a.x<0)&&(a.y==0)){
		a.quadrante=8;
		//quadrante=8 os pontos estão no eixo y com x negativo
	}
	return a;
}

int maiorponto(pontos a){
	//função para definir se o x ou o y é maior
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
		printf("Digite o item que corresponde a ação que deseja fazer.\n1-Analisar qual quadrante um ponto se encontra.\n2-Conferência se um ponto está em um determinado quadrante.\n3-Retornar a distância entre dois pontos.\n4-Retornar o maior valor de coordenada de um ponto.\n");
		scanf("%d", &escolha);
	
		if(escolha>4){
			printf("Digite uma opção válida.\n\n");
		}
		
		else if(escolha==1){
			a=leitura();
			a=quadranteconferencia(a);
			if(a.quadrante==0){
			printf("O ponto de coordenada(%.2f, %.2f) está na origem.\n\n", a.x, a.y);
			}
			else if(a.quadrante==1){
				printf("O ponto de coordenada(%.2f, %.2f) está no primeiro quadrante.\n\n", a.x, a.y);
			}
			else if(a.quadrante==2){
				printf("O ponto de coordenada(%.2f, %.2f) está no segundo quadrante.\n\n", a.x, a.y);
			}
			else if(a.quadrante==3){
				printf("O ponto de coordenada(%.2f, %.2f) está no terceiro quadrante.\n\n", a.x, a.y);
			}
			else if(a.quadrante==4){
				printf("O ponto de coordenada(%.2f, %.2f) está no quarto quadrante.\n\n", a.x, a.y);
			}
			else if(a.quadrante==5){
				printf("O ponto de coordenada(%.2f, %.2f) está no eixo x com y negativo.\n\n", a.x, a.y);
			}
			else if(a.quadrante==6){
				printf("O ponto de coordenada(%.2f, %.2f) está no eixo x com y positivo.\n\n", a.x, a.y);
			}
			else if(a.quadrante==7){
				printf("O ponto de coordenada(%.2f, %.2f) está no eixo y com x positivo.\n\n", a.x, a.y);
			}
			else if(a.quadrante==8){
				printf("O ponto de coordenada(%.2f, %.2f) está no eixo y com x negativo.\n\n", a.x, a.y);
			}
			
		}
		
		else if(escolha==2){
			a=leitura();
			quadrante=leituraquadrante();
			a=quadranteconferencia(a);
			
			if(a.quadrante==quadrante){
				printf("Os pontos (%.2f, %.2f) estão no quadrante indicado.\n\n", a.x, a.y);
			}
			else{
				printf("Os pontos (%.2f, %.2f) não estão no quadrante indicado.\n\n", a.x, a.y);
			}
			
		}
	
		else if(escolha==3){
			a=leitura();
			b=leitura();
			distancia=calculo(a, b);
			printf("A distância entre os pontos A(%.2f, %.2f) e B(%.2f, %.2f) é igual a: %f\n\n",a.x, a.y, b.x, b.y, distancia);
		}
		
		else if(escolha==4){
			a=leitura();
			maiorcoordenada=maiorponto(a);
			if(maiorcoordenada==0){
				printf("O ponto x: %.2f é maior que o ponto y: %.2f.\n\n", a.x, a.y);
			}
			if(maiorcoordenada==1){
				printf("O ponto y: %.2f é maior que o ponto x: %.2f.\n\n", a.y, a.x);
			}
			if(maiorcoordenada==2){
				printf("O ponto x: %.2f é igual ao ponto y: %.2f.\n\n", a.x, a.y);
			}
		}
	}	

	return 0;
}
