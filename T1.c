#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>

typedef float (*funcao)(float);

float f1(float x){
	return pow(x,5)-((10/9)*pow(x,3))+(5*x)/21;
}

float f2(float x){
	return x-x*log(x);
}

float f3(float x){
	return 10*x+pow(x,2);
}

int menu_inicial() {
	int op;
	
	printf("\n\n\nMENU INICIAL\n1- Método da Bisseção\n2- Método da Posição Falsa\n3- Método da Posição Falsa Modificado\n4- Método de Newton\n5- Método de Newton Modificado\n6- Derivada Primeira\n7- Derivada Segunda\n8- Jacobiano\n9- Hessiana\n10- Sair do Programa\nOpção: ");
	scanf(" %d", &op);
	
	return op;
}

float bissecao(float e, int it, float a, float b){
	int i;
	float x;
	
	
	printf("\n\nMÉTODO DA BISSEÇÃO\n\n");
	for(i = 1; i <= it; i++){
		printf("\n\n\n\nk = %d", i);
		x = (a+b)/2;
		
		
		printf("\n(%f + %f)/2 = %f", a, b, x);
		printf("\nf(%f) = %f", x, f1(x));
		printf("\n|f(%f)| = %f", x, fabs(f1(x)));
		
		if (fabs(f1(x)) < e) {
			printf("\nO módulo de f(x) é menor que a precisão. (%f < %f)", fabs(f1(x)), e);
			return x;
		}
		else {
			printf("\nf(a)*f(x) < 0?");
			if( f1(a)*f1(x) < 0){
				printf(" Sim: b recebe o valor de x.");
				b = x;
				printf("\nb = %f", b);
			} else {
				printf(" Não: a recebe o valor de x.");
				a = x;
				printf("\na = %f", a);
			}
			printf("\n|b - a| = |%f|", b-a);
			
			if( fabs(b-a) < e) {
				printf("\nO módulo da diferença entre b e a é menor que a precisão. (%f < %f)", fabs(b-a), e);
				return x;
			}	
		}
	}
	printf("\nO método atingiu o número máximo de iterações.");
	return x;
}

float posicao_falsa(float e, int it, float a, float b){
	int i;
	float x;
	
	printf("\n\nMÉTODO DA POSIÇÃO FALSA\n\n");
	
	for(i = 1; i <= it; i++){
		printf("\n\nk = %d", i);
		x = (a*f1(b)-b*f1(a))/(f1(b)-f1(a));
		
		printf("\nx = %f", x);
		printf("\nf(%f) = %f", x, f1(x));
		printf("\n|f(%f)| = %f", x, fabs(f1(x)));
		
		if (fabs(f1(x)) < e) {
			printf("\nO módulo de f(x) é menor que a precisão. (%f < %f)", fabs(f1(x)), e);
			return x;
		}
		else {
			printf("\nf(a)*f(x) < 0?");
			if( f1(a)*f1(x) < 0){
				printf(" Sim: b recebe o valor de x.");
				b = x;
				printf("\nb = %f", b);
			} else {
				printf(" Não: a recebe o valor de x.");
				a = x;
				printf("\na = %f", a);
			}
			printf("\n|b - a| = |%f|", b-a);
			
			if( fabs(b-a) < e) {
				printf("\nO módulo da diferença entre b e a é menor que a precisão. (%f < %f)", fabs(b-a), e);
				return x;
			}	
		}
	}
	printf("\nO método atingiu o número máximo de iterações.");
	return x;
}

float posicao_falsa_modificado(float e, int it, float a, float b){
	int i;
	float x;
	float x1, x2;
	
	printf("\n\nMÉTODO DA POSIÇÃO FALSA MODIFICADO\n\n");
	
	x1 = a;
	x2 = b;
	
	for(i = 1; i <= it; i++){
		
		printf("\nxk-1 = %f\nxk = %f", x1, x2);
		
		printf("\n\nk = %d", i);
		if(f1(x1)*f1(x2) > 0){
			printf("\nf(%f)*(f%f) > 0. Usaremos f(a)/2.", x1, x2);
			x = (a*f1(b)-b*(f1(a)/2))/f1(b)-(f1(a)/2);
		} else {
			x = (a*f1(b)-b*f1(a))/(f1(b)-f1(a));
		}
		
		printf("\nx = %f", x);
		printf("\nf(x) = %f", f1(x));
		if(fabs(f1(x)) < e){
			printf("\n|f(%f)| = |%f| = %f < %f", x, f1(x), fabs(f1(x)), e);
			return x;
		} else {
			if(f1(a)*f1(x) < 0){
				printf("\nf(a)*f(x) < 0: b recebe o valor de x.");
				b = x;
			} else {
				printf("\nf(a)*f(x) > 0: a recebe o valor de x.");
				a = x;
			}
			
			printf("\n|b-a| = |%f - %f| = %f", b, a, fabs(b-a));
			if(fabs(b-a) < e){
				printf("\n%f < %f", fabs(b-a), e);
				return x;
			}
		}
		
		x1 = x2;
		x2 = x;
	}
}

float derivada_primeira(float e, int it, float x){
	int i;
	float fx, h = 1;
	float f1, f2, erro1, erro2;
	
	for(i = 1; i <= it; i++) {
		printf("\n\nk = %d", i);
		
		printf("\nx = %f\nh = %f", x, h);
		
		fx = ((x+h)-(x-h))/2*h;
		
		printf("\nf'(x) = %f", fx);
		
		if(i == 1) {
			f1 = fx;
		}
		else if (i == 2) {
			f2 = fx;
			if (fabs(fx) > 1)
				erro1 = fabs(f2-f1)/fabs(fx);
			else
				erro1 = fabs(f2-f1)/1;
				
			printf("\nerro = %f", erro1);	
			if (erro1 < e)
				return fx;
		}
		else if (i == 3) {
			if (fabs(fx) > 1)
				erro2 = fabs(f2-f1)/fabs(fx);
			else
				erro2 = fabs(f2-f1)/1;
				
			printf("\nerro = %f", erro2);	
			if (erro2 < e)
				return fx;
		}
		else {
			erro1 = erro2;
			if (fabs(fx) > 1)
				erro2 = fabs(f2-f1)/fabs(fx);
			else
				erro2 = fabs(f2-f1)/1;
				
			if(erro2 > erro1)
				return x;
		}
		
		h = h/2;
	}
	return fx;
}


char funcao_reproc() {
	char reproc;
	do {
		printf("\n\nDeseja ir novamente? S/N");
		reproc = toupper(getch());
		system("cls");
	} while (reproc != 'S' && reproc != 'N');
	return reproc;
}


//================ Função Principal ========================================================
int main () {
	setlocale(LC_ALL, "Portuguese");
	char reproc = 'S';
	int op_menu_inicial;
	float x;
	
	
	do {
		op_menu_inicial = menu_inicial();
		switch (op_menu_inicial) {
			case 1: //Método da Bisseção
				bissecao(0.0001, 20, -0.65, -0.52);
				break;
			case 2: //Método da Posição Falsa
				posicao_falsa(0.0001, 20, -0.3, 0.25);
				break;
			case 3: //Método da Posição Falsa Modificado
				posicao_falsa_modificado(0.0001, 20, 0.21, 0.6);
				break;
			case 4: //Método de Newton
				break;
			case 5: //Método de Newton Modificado
				break;
			case 6: //Derivada Primeira
				break;
			case 7: //Derivada Segunda
				break;
			case 8: //Jacobiana
				break;
			case 9: //Hessiana
				break;
			case 10: //Sair do programa
				reproc = funcao_reproc();
				break;
			default: //Qualquer outra opção no menu reinicializará o programa
				reproc = funcao_reproc();
				break;
		}
			
		
	} while (reproc == 'S');
}
