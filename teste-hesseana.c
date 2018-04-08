#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

float funcao(int num_x, float x[]) {
	return pow(x[0], 2)+(3*x[1]);
}

//Hesseano:
void Hesseana(float E, int num_x, float x[num_x], float matriz[num_x][num_x]){
	int i, j, z;
	int k; //Contador de iterações
	float f_x, h = 1, f1, f2, erro1, erro2;
	
	float x1[num_x], x2[num_x], x3[num_x], x4[num_x]; //Vetores auxiliares
		
	for(i = 0; i < num_x; i++){
		for(j = 0; j < num_x; j++){
			if (i == j) {
							
				for(k = 1; k <= 15; k++) {
					
					for(z = 0; z < num_x; z++) {
						x1[z] = x[z]+h;
						x2[z] = x[z]-h;
					}
						
					f_x = ((funcao(num_x, x1)-(2*funcao(num_x, x))+(funcao(num_x, x2)))/(4*pow(h, 2)));
							
					if(k == 1) 
						f1 = f_x;
								
					else if (k == 2) {
						f2 = f_x;
									
						if (fabs(f_x) > 1)
							erro1 = fabs(f2-f1)/fabs(f_x);
						else
							erro1 = fabs(f2-f1)/1;
								
								
						if (erro1 < E) {
							matriz[i][j] = f_x;
							break;
						}			
					}	
					else if (k == 3) {
						f1 = f2;
						f2 = f_x;
									
						if (fabs(f_x) > 1)
							erro2 = fabs(f2-f1)/fabs(f_x);
						else
							erro2 = fabs(f2-f1)/1;
							
						if ((erro2 < E) || (erro2 > erro1)) {
							matriz[i][j] = f_x;
							break;
						}		
					}
					else {
						erro1 = erro2;
						f1 = f2;
						f2 = f_x;
									
						if (fabs(f_x) > 1)
							erro2 = fabs(f2-f1)/fabs(f_x);
						else
							erro2 = fabs(f2-f1)/1;
						
						if ((erro2 < E) || (erro2 > erro1)) {
							matriz[i][j] = f_x;
							break;
						}		
					}
					
					printf("\nmatriz[%d][%d] = %.2f", i, j, f_x);
					h = h/2;
				}
			} //Fim if (i == j)
			else { // i =/= j
				
				for(k = 1; k <= 15; k++) {
					
				
					for(z = 0; z < num_x; z++) {
						x1[z] = x[z]+h;
						x4[z] = x[z]-h;
						
						if(z%2 == 0) {
							x2[z] = x[z]+h;
							x3[z] = x[z]-h;
						}
						else {
							x2[z] = x[z]-h;
							x3[z] = x[z]+h;
						}
					}
							
					f_x = ((funcao(num_x, x1)-(funcao(num_x, x2))-(funcao(num_x, x3))+(funcao(num_x, x4)))/(4*pow(h, 2)));
							
					if(k == 1) 
						f1 = f_x;
								
					else if (k == 2) {
						f2 = f_x;
									
						if (fabs(f_x) > 1)
							erro1 = fabs(f2-f1)/fabs(f_x);
						else
							erro1 = fabs(f2-f1)/1;
								
								
						if (erro1 < E) {
							matriz[i][j] = f_x;
							break;
						}
							
					}	
					else if (k == 3) {
						f1 = f2;
						f2 = f_x;
									
						if (fabs(f_x) > 1)
							erro2 = fabs(f2-f1)/fabs(f_x);
						else
							erro2 = fabs(f2-f1)/1;
							
						if ((erro2 < E) || (erro2 > erro1)) {
							matriz[i][j] = f_x;
							break;	
						}	
					}
					else {
						erro1 = erro2;
						f1 = f2;
						f2 = f_x;
									
						if (fabs(f_x) > 1)
							erro2 = fabs(f2-f1)/fabs(f_x);
						else
							erro2 = fabs(f2-f1)/1;
						
						if ((erro2 < E) || (erro2 > erro1)) {
							matriz[i][j] = f_x;
							return;
						}		
					}
					printf("\nmatriz[%d][%d] = %.2f", i, j, f_x);
					h = h/2;
				}	
			}
		}
	}	
}

int main () {
	float vetor[2];
	float matriz[2][2];
	int i, j;
	
	vetor[0] = 2.9;
	vetor[1] = 3.35;
	
	Hesseana(0.01, 2, vetor, matriz);
	
	printf("\nMatriz Hesseana:\n");
	for(i = 0; i < 2; i++) {
		for(j = 0; j < 2; j++) {
			printf(" %.2f ", matriz[i][j]);
		}
		printf("\n");
	}
	
}
