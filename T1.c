#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>

typedef float (*funcao)(float);

float f1(float x){
	return pow(x,3)-(2*x)+4;
}

float f2(float x){
	return x-x*log(x);
}

float f3(float x){
	return 10*x+pow(x,2);
}

int menu_inicial() {
	int op;
	
	printf("\nMENU INICIAL\n1- Método da Bisseção\n2- Método da Posição Falsa\n3- Método da Posição Falsa Modificado\n4- Método de Newton\n5- Método de Newton Modificado\n6- Derivada Primeira\n7- Derivada Segunda\n8- Jacobiano\n9- Hessiana\n10- Sair do Programa\nOpção: ");
	scanf(" %d", &op);
	
	return op;
}

float x(){ //Permite ao usuário indicar o valor de X
	float x;
	
	printf("\nx =");
	scanf(" %f", &x);
	return x;
}

float bissecao(float e, int it, float f1(float x), float a, float b, int *cont_it){
	int i;
	float x;
	
	
	printf("\n\nMÉTODO DA BISSEÇÃO\n\n");
	for(i = 1; i <= it; i++){
		printf("\nk = %d", i);
		x = (a+b)/2;
		
		printf("\nx = %f", x);
		
		printf("\nf(x) = %f", f1(x));
		if (fabs(f1(x)) < e)
			return x;
		else {
			printf("\nf(a)*f(x) < 0?");
			if( f1(a)*f1(x) < 0){
				printf(" Sim: b recebe o valor de x.");
				b = x;
			} else {
				printf(" Não: a recebe o valor de x.");
				a = x;
			}
			if( fabs(b-a) < 0)
				printf("\n|b - a| = |%f|", b-a);
				return x;
		}
	}
}

//float menu_funcoes(float (*funcao)(float)) {
//	int op;
//	float x;
//	printf("\nQual função deseja calcular?\n\n1- x^3-2x+4\n2- x-x*ln(x)\n3- 10*x+x^2\nOpção: ");
//	scanf(" %d", op);
//	
//	switch(op) {
//		case 1:
//			funcao = &f1;
//			break;
//		case 2:
//			funcao = &f2;
//			break;
//		case 3:
//			funcao = &f3;
//			break;
//		default:
//			funcao = &f1;
//			break;
//	}
//	
//}

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
				x = x();
				bissecao(0.001, 10, f1(x), -2, 3, 0);
				break;
			case 2: //Método da Posição Falsa
				break;
			case 3: //Método da Posição Falsa Modificado
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
