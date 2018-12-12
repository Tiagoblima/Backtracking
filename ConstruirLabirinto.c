#include <stdio.h>
#include <time.h>
#include <stdlib.h>



void construirLabirinto(int** lab,int n){

	int i,j;
	
	
	
	int pattern_p =0;
	
	srand(time(NULL));
	
	for(i=0;i<n;i++){
		
		for(j=0;j<n;j++){
			
			lab[i][j] = rand()%2;	
		}
	}
	for(i=0;i<n;i++){
		
		for(j=0;j<n;j++){
			
			if(lab[i][j]==1){
				
				lab[i][j] = ' ';	
			}
		
		}
			
	}

}
void gerarCoordIniciais(int** lab,int* x,int* y,int* x1,int* y1,int n){

//	printf("\ngerarCoordIniciais");

	srand(time(NULL));
	*x = rand()%n;
	*y = rand()%n;
	

	while(lab[*y][*x]==0){	

		*x = rand()%n;
		*y = rand()%n;	
	}
	lab[*y][*x] = 88;
	*x1 = rand()%n;
	*y1 = rand()%n;
	
	
	while(lab[*y1][*x1]==0 || (*x1 == *x && *y1 == *y)){	
		*x1 = rand()%n;
		*y1 = rand()%n;
	}
	
	
}
void salvarCoordIniciais(int* x,int* y,int* x1,int* y1,int n){
	
	
	
	//
	FILE* file = fopen("labirinto.txt","w");
	printf("\nCoordIniciais: \nJ&M: %i %i",*y,*x);	
	printf("\nSaida: %i %i\n",*y1,*x1);
	fprintf(file,"%i",n);
	fputs("\n",file);
	fprintf(file,"%i",*x);
	fputs(" ",file);
	fprintf(file,"%i",*y);
	
	fputs("\n",file);

	fprintf(file,"%i",*x1);
	fputs(" ",file);
	fprintf(file,"%i",*y1);
	
	fputs("\n",file);

	fclose(file);
}


void salvarLabirinto(int** lab,int n){
	
	

	FILE* file = fopen("labirinto.txt","a");
	
	int i,j;
	for(i=0;i<n;i++){
		
		for(j=0;j<n;j++){
			
			
			fprintf(file,"%i",lab[i][j]);
			fputs(" ",file);
		}
		fputs("\n",file);
	}

	fclose(file);	
}

int main(){
	
	int n;
	printf("Digite o tamanho do labirinto: ");
	scanf("%i",&n);
	
		int i,j;
	
	int** lab = malloc(n*sizeof(int*));
	
	 for(i=0;i<=n;i++){
	 	lab[i] = malloc(sizeof(int));
	 }
	
	
	
	
	int x,y,x1,y1;
	construirLabirinto(lab,n);
	gerarCoordIniciais(lab,&x,&y,&x1,&y1,n);
	salvarCoordIniciais(&x,&y,&x1,&y1,n);
	
	salvarLabirinto(lab,n);

	
//	system("cls");
	for(i=0;i<n;i++){

		for(j=0;j<n;j++){

			if(i==y1 && j==x1){
				printf("S ");
			}else if(lab[i][j]==0){
				printf("%i ",lab[i][j]);	
			}else{
				printf("%c ",lab[i][j]);
			}
				
		}
		printf("\n");
	}

	return 0;
}

