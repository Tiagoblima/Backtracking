#include <stdio.h>
#include <locale.h>
#include <stdlib.h>  


typedef struct{
	
	int x_a,y_a;
}Path;
//// Leitura do labirinto
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
//////////////////////////////////////////


// Navegação 
// Mover-se para cima
int moveUp(int** lab, int x,int* y){
			
	//Se não estou na borda
	if(*y>0){
		//Se é um obstaculo ou a posição já foi visitada
		//sinalize como um caminho a não ser seguido 
		//devolvendo zero 
		if(lab[*y-1][x]==0 || lab[*y-1][x]==42){
		
			return 0;
		}
		// Se a posição é um "candidato" visite-o
		(*y)--;
	
		return 1;
	}
	//Se já é a borda devolda zero
	return 0;
		
}
int moveRight(int** lab, int* x,int y,int n){
	
	if(*x<n-1){
		
		if(lab[y][*x+1]==0 || lab[y][*x+1]==42){
		
			return 0;
		}
		(*x)++;
		return 1;
	}
		return 0;	
}

int moveDown(int** lab, int x,int* y,int n){
	
	if(*y<n-1){
		
		if(lab[*y+1][x]==0 || lab[*y+1][x]==42){
		
			return 0;
		}
		(*y)++;
		return 1;
	}
	return 0;
}
int moveLeft(int** lab, int* x,int y){
	
	if(*x>0){
		
		if(lab[y][*x-1]==0 || lab[y][*x-1]==42){
		
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
	int w_p = 0; // Verifica o quanto foi andado 
	int tentativas = 0;
	
	while(game){

		
		printf("Posição Atual: %i %i\n",y,x);
		printf("Saida: %i %i\n",y1,x1);
		printf("Número de tentativas: %i\n", tentativas);
		path[w_p].x_a = x;
		path[w_p].y_a = y;
	
		tentativas++;
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
			
			lab[y+1][x] = 42;  // Adiciona * ao caminho já visitado
			lab[y][x] = 88;
		
			
		}else if(moveRight(lab,&x,y,n)){
			
			path[w_p].x_a = x-1;
			path[w_p].y_a = y;
			w_p++;
			
			
			lab[y][x-1] = 42; 
			lab[y][x] = 88;
		
			
		}else if(moveDown(lab,x,&y,n)){
			
			path[w_p].x_a = x;
			path[w_p].y_a = y-1;
			w_p++;
			
			lab[y-1][x] = 42;
			lab[y][x] = 88;
		
		}else if(moveLeft(lab,&x,y)){
			
			path[w_p].x_a = x+1;
			path[w_p].y_a = y;
			w_p++;
			
			lab[y][x+1] = 42;			
			lab[y][x] = 88;
	
		}else{
		
			if(w_p > 0){
				w_p--;
			}
			x = path[w_p].x_a;
			y = path[w_p].y_a;
			
			lab[path[w_p+1].y_a][path[w_p+1].x_a] = 42;
			
			lab[y][x] = 88;
		}
		
	
		if(x==x1 && y==y1){
			game = 0;
		}
		system("pause");
		system("cls");
	}
	
	
	printf("Chegamos à saida!\n");
	printf("Número de tentativas: %i\n", tentativas);
	 
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
		

		
}

void main(){
       

	int x,y,x1,y1;

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
