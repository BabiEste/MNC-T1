#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <locale.h>

typedef float funcao(float x);

int menu_inicial() {
	int op;
	
	printf("\nMENU INICIAL\n1- Método da Bisseção\n2- Método da Posição Falsa\n3- Método da Posição Falsa Modificado\n4- Método de Newton\n5- Método de Newton Modificado\n6- Derivada Primeira\n7- Derivada Segunda\n8- Jacobiano\n9- Hessiana\n10- Sair do Programa\nOpção: ");
	scanf(" %d", &op);
	
	return op;
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



int main () {
	setlocale(LC_ALL, "Portuguese");
	char reproc = 'S';
	int op_menu_inicial;
	
	
	do {
		op_menu_inicial = menu_inicial();
		switch (op_menu_inicial) {
			case 1: //Método da Bisseção
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
