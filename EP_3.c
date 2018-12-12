#include <stdio.h>
#include <locale.h>
#include <stdlib.h>  


typedef struct{
	
	int x_a,y_a;
	char c;
}Path;
void lerTamLab(int* n){
	
	FILE* file = fopen("labirinto.txt","r"); 
	fscanf(file,"%i",n);
	fclose(file);
}
void lerArquivo(int** lab,int* x,int* y,int* x1,int* y1,int n){
	
	
	FILE* file = fopen("labirinto.txt","r"); 
	
	fseek(file,1,SEEK_SET);
	
	fscanf(file,"%i",x);
	fscanf(file,"%i",y);
	
	
	fscanf(file,"%i",x1);
	fscanf(file,"%i",y1);
	

	char c;
	int i,j,el;
	for(i=0;i<n;i++){
		
		for(j=0;j<n;j++){
			
			fscanf(file,"%i",&el);
			lab[i][j] = el;
		}
	
	}
	
	fclose(file);
	

}
int qtd = 0;
void report(int v[],int p){

	v[qtd] = p;	
	qtd++;
}
///Feito em sala

int moveUp(int** lab, int x,int* y){
			

	if(*y>0){
		if(lab[*y-1][x]==0 || lab[*y-1][x]==88){
		
			return 0;
		}else if(lab[*y-1][x]==42){
			return 0;
		}
		
		(*y)--;
	
		return 1;
	}
	
	return 0;
		
}
int moveRight(int** lab, int* x,int y,int n){
	
	if(*x<n-1){
		
		if(lab[y][*x+1]==0 || lab[y][*x+1]==88){
		
			return 0;
		}else if(lab[y][*x+1]==42){
			return 0;
		}
		(*x)++;
		return 1;
	}
		return 0;	
}

int moveDown(int** lab, int x,int* y,int n){
	
	if(*y<n-1){
		
		if(lab[*y+1][x]==0 || lab[*y+1][x]==88){
		
			return 0;
		}else if(lab[*y+1][x]==42){
			return 0;
		}
		(*y)++;
		return 1;
	}
	return 0;
}
int moveLeft(int** lab, int* x,int y){
	
	if(*x>0){
		
		if(lab[y][*x-1]==0 || lab[y][*x-1]==88){
		
			return 0;
		}else if(lab[y][*x-1]==42){
			return 0;
		}
		(*x)--;
		return 1;
	}
	return 0;	
}

void backtracking(int** lab,int x,int y,int x1,int y1,int n){

	setlocale(LC_ALL,"");
	
	Path* path = (Path*) malloc(n*n*sizeof(Path));
	

	int i,j;
	int game = 1;
	int w_p = 0;
	int no_path = 0;
	
	while(game){

		
		printf("Posição Inicial: %i %i\n",y,x);
		printf("Saida: %i %i\n",y1,x1);
		path[w_p].x_a = x;
		path[w_p].y_a = y;
	
		
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
		
			
		if(moveUp(lab,x,&y)){
			path[w_p].x_a = x;
			path[w_p].y_a = y+1;
			w_p++;
			lab[y][x] = 88;
			
			no_path = 0;
		}else if(moveRight(lab,&x,y,n)){
			path[w_p].x_a = x-1;
			path[w_p].y_a = y;
			w_p++;
			lab[y][x] = 88;
			no_path = 0;
		}else if(moveDown(lab,x,&y,n)){
			path[w_p].x_a = x;
			path[w_p].y_a = y-1;
			w_p++;
			lab[y][x] = 88;
			no_path = 0;
		}else if(moveLeft(lab,&x,y)){
			path[w_p].x_a = x+1;
			path[w_p].y_a = y;
			w_p++;
			lab[y][x] = 88;
			no_path = 0;
		}else{
		
			if(w_p>0){
				w_p--;
			}
			x = path[w_p].x_a;
			y = path[w_p].y_a;
			no_path++;
			lab[y][x] = 88;
		}
		if(no_path>=w_p){
			lab[path[w_p].y_a][path[w_p].x_a] = 42;
			printf("Não há saida!\n");
			
		}
		
		if(x==x1 && y==y1){
			game = 0;
		}
		system("pause");
		system("cls");
	}
	
	
	printf("Chegamos à saida!\n");
	
	 
	

		
}

void main(){




	int x,y,x1,y1;
	char pattern[4];
	

	int i;
	
	int n;
	
	lerTamLab(&n);
	
	int** lab = (int**) malloc(n*sizeof(int*));
	for(i=0;i<n;i++){
		lab[i] = malloc(n*sizeof(int));
	}
	
	
	lerArquivo(lab,&x,&y,&x1,&y1,n);

	backtracking(lab,x,y,x1,y1,n);
	
	
	
}
