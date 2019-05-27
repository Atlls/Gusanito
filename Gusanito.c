#include <stdio.h>
#include <stdlib.h>

int detVidaGusano(float p, float d, float n, float r);

void detVidaGusano2(float p, float d, float n, float r, int *cont, int *vida);

int main(){
	
	float P, D, N, R;
	int cont, vida;
	
	printf("Hay un Guisanito que esta en un huequito de P cantidad de metros. El guisanito");
	printf(" por dia se mueve D cantida de metros, luego cuando descanza en la noche, el guisanito");
	printf(" resvala N cantidad de metros; adicial a esto, el guisano pierde energia y se mueve");
	printf(" R cantidad de metros que el dia anterior. \n\n");
	
	printf("Coloque P: (Profundidad del huequito)");
	printf("\nColoque D: (Cantidad de metros que sube diario)");
	printf("\nColoque N: (Cantidad de metros que resbala)");
	printf("\nColoque R: (Cantidad de metros que deja de subir por dia)\n");
	
	scanf("%f", &P);
	scanf("%f", &D);
	scanf("%f", &N);
	scanf("%f", &R);
	
	cont = 0; vida = 0;
	
	detVidaGusano2(P,D,N,R,&cont,&vida);
	
	printf("Es 1 si salio con vida, es 0 si se murio:\n*Dias: %i,Vivo?: %i*\n\n", cont, vida);
	//printf("Es 1 si salio con vida, es 0 si se murio:\n*%i*\n", detVidaGusano(P,D,N,R));
	
	system("pause");
	
	return 0;
}

void detVidaGusano2(float p, float d, float n, float r, int *cont, int *vida){

		p -= d; //P = 1, d = 6;
		
		if(p > 1 && d > 1){
			
			*cont = *cont + 1;
			detVidaGusano2(p+n,d-r,n,r,&*cont,&*vida);
			
		}else{
				
			if(p <= 0){
				*vida = 1;
			}else{
				*vida = 0;
			}
		
		}
	printf("\nP = %.2f\nD = %.2f\nN = %.0f\nR = %.2f\ncont = %i\nvida = %i\n",p,d,n,r,*cont,*vida);
}

int detVidaGusano(float p, float d, float n, float r){
	
	int aux;
	
		p -= d;
		
		printf("P = %.2f, D = %.2f, N = %.0f, R = %.2f\n",p,d,n,r);
		
		if(p <= 0){
			
			aux = 1;
			
		}else if(d <= 0){
		
			aux = 0;
		
		}else{
			
			aux = detVidaGusano(p+n,d-r,n,r);
			
		}
		
		return aux;

		
}
