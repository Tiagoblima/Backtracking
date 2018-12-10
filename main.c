#include<stdio.h>
#include <time.h>
typedef struct
{	
  int coluna[8];
  int linha[8];
  int map[8][8];
  int ataque[8][8];
}Rainha;


int cima(Rainha rainhas[], int outras,int* linha, int* coluna, int ultima){
	

	if(*linha > 0){
		
		
		if(rainhas[outras].ataque[*linha-1][*coluna] == 1){
			
			return 0;
			
		}
		(*linha)--;	
		return 1;
	}
	

	return 0;
	
}
int baixo(Rainha rainhas[], int outras,int* linha, int* coluna, int ultima){
	

	if(*linha < 7){
		
		// Se a próxima linha está sob ataque ele retorna a linha anterior e
		// devolve 0;
		if(rainhas[outras].ataque[*linha+1][*coluna] == 1){
			(*linha--);
			return 0;
			
		}
		(*linha)++;
		return 1;
	}
	

	return 0;
	
}

int esquerda(Rainha rainhas[], int outras,int* linha, int* coluna, int ultima){
	

	if(*coluna > 0){
		
		
		if(rainhas[outras].ataque[*linha][*coluna-1] == 1){
			
			return 0;	
			
		}
		(*coluna)--;	
		return 1;
	}
	

	return 0;
	
}

int direita(Rainha rainhas[], int outras,int* linha, int* coluna, int ultima){
	

	if(*coluna < 7){
		
		
		if(rainhas[outras].ataque[*linha][*coluna+1] == 1){
		
			return 0;		
		}
		(*coluna)++;	
		return 1;
	}
	

	return 0;
	
}
//Recebe os array de linhas, colunas e diagonais sob ataque,
// uma rainha e a ultima posicao dos arrays que esta preenchida
//Devolve 0 se a rainha esta sob ataque e 1 se estiver segura 
int backtracking(Rainha rainhas[8], int ultima, int tabuleiro[][8])
{
	
	printf("\nBacktracking\n\n");
	int outras = -1; // verifica se outras rainhas
	time_t seconds;
	
	srand(time(&seconds));
    int linha = rainhas[ultima].linha[0];
	int coluna = rainhas[ultima].coluna[0];

	int l, k;
	l = 0;
	k = 0;

	tabuleiro[linha][coluna] = 9;
	while(outras < ultima){
		
	
		if(coluna == 7){
			coluna = 0;	
		} 
		
		outras++;
		printf(" outras: %i ultima: %i\n", outras, ultima);
		int i,j;
		
		
		
		for(i = 0; i < 8; i++)
		  {
		    for(j = 0; j < 8; j++)
		    {
		    	if(tabuleiro[i][j] == 9)
		    		printf("%i ",tabuleiro[i][j]);
		      	else{
		      		printf("%i ", rainhas[outras].ataque[i][j]);
				}	
		    }
		    puts("");
		  }
		
		printf("linha: %i: coluna: %i\n", linha, coluna);
	
		// tentativa a direita
	
		// Se estiver em uma posição atacada tente...
		
	
		
		if(rainhas[outras].ataque[linha][coluna] == 1){
				
				for(i = 0; i < 8; i++)
				  {
				    for(j = 0; j < 8; j++)
				    {
				      tabuleiro[i][j] = 0;
				    }
				  }
	 	   
	 	   if(baixo(rainhas, outras, &linha, &coluna, ultima)){
	 	   	
	 	   	
	 	   		rainhas[ultima].map[linha][coluna] = 1;
				rainhas[ultima].linha[k++] = linha-1;
				tabuleiro[linha][coluna] = 9;
				outras = -1;
				
			}else if(direita(rainhas, outras, &linha, &coluna, ultima)){
		
		
				rainhas[ultima].map[linha][coluna] = 1;
				rainhas[ultima].coluna[l++] = coluna-1;
				tabuleiro[linha][coluna] = 9;
				outras = -1;
			
			}else if(cima(rainhas, outras, &linha, &coluna, ultima)){
		
				rainhas[ultima].map[linha][coluna] = 1;
				rainhas[ultima].linha[k++] = linha+1;
				tabuleiro[linha][coluna] = 9;
				outras = -1;
				
			}else{
				
				if(linha < 7)
					linha++;	
				else
					linha = 0;
				
					
				if(coluna < 7)		
					coluna++;
				else{
					coluna = 0;
				}
				
				printf("k: %i\n", k);
			
				
				
				tabuleiro[linha][coluna] = 9;
				 
				 outras = -1;
				 printf("Sem saida!\n");	
			}
			
				
		}
		if(k == 7){
			k = 0;
		}
		if(l == 7){
			l = 0;
		}
		// tentativa a esquerda
		
	 
	
		//system("pause");
		system("cls");
		
		
	}	
	
	rainhas[ultima].coluna[0] = coluna;
	rainhas[ultima].linha[0] = linha;
 	
  return 1;
}


void inicializa(Rainha rainhas[], int tabuleiro[8][8]){
	
	
}
int main()
{
	
	
  puts("As oito rainhas");

  //Inicialização do tabuleiro
  int tabuleiro [8][8];



  //Array de Rainhas 
  //e array com linhas, colunas e diagonais sob ataque
  Rainha rainhas[8];
  
    int tabuleiro1[8][8]; // mostra as rainhas
  int i, j;
  for(i = 0; i < 8; i++)
  {
    for(j = 0; j < 8; j++)
    {
      tabuleiro[i][j] = 0;
      tabuleiro1[i][j] = ' ';
    }
  }
  
 int k;
 for(i = 0; i < 8; i++)
  {
    for(j = 0; j < 8; j++)
    {
    	for(k = 0; k < 8; k++)
    	{
      		rainhas[i].ataque[j][k] = 0;
      		rainhas[i].linha[k] = 0;
      		rainhas[i].coluna[k] = 0;
      		rainhas[i].map[j][k] = 0;
  		}
    }
  }


  //Variáveis auxiliares
  int ultima = 0; //ultima rainha inserida
  int final = 0  ;
  int col = 0;
  
  int linha = 0;
  int coluna = 0;

  srand(time(NULL));
while(final <= 7)
  {
  	printf("final: %i\n", final);
 
 	
 	if(ultima > 0){
 		rainhas[ultima].linha[0] = rainhas[ultima-1].linha[0];
 		rainhas[ultima].coluna[0] = rainhas[ultima-1].coluna[0];
	 }else{
	 	rainhas[ultima].linha[0] = 0;
    	rainhas[ultima].coluna[0] = 0;
	 }
    
    

    
	backtracking(rainhas, ultima, tabuleiro); 	
	

	

//	printf("rainhas[ultima].linha[0]: %i\n", rainhas[ultima].linha[0]);
//	printf("rainhas[ultima].coluna[0]: %i\n",  rainhas[ultima].coluna[0]);
    //Atualizando os arrays linhas e colunas sob ataque
    
	int m,n,i,j;
	
	 
	
	m = rainhas[ultima].linha[0];
	n = rainhas[ultima].coluna[0];
	
	tabuleiro1[m][n] = ultima;
	
	
	
	
	rainhas[ultima].ataque[m][n] = 1;

	
 	//Enquanto a próxima linha tiver vazia
 	
	while(rainhas[ultima].ataque[m][++n] == 0){
 	
 		
		if(n == 8){
		
			n = -1;	
		}else{
			rainhas[ultima].ataque[m][n] = 1;
		}
		
	 }
	 
	 
	while(rainhas[ultima].ataque[++m][n] == 0){
 	
 		
		if(m == 8){
		
			m = -1;	
		}else{
			rainhas[ultima].ataque[m][n] = 1;
		}
		
	 }
	
	 
    //Atualizando os arryas de diagonais sob ataque
    //Diagonal principal == i + t = j, t = j - i da rainha atual
    //Diagonal secundária == i + j = t, t = i + j da rainha atual
	 
	 	m = rainhas[ultima].linha[0];
		n = rainhas[ultima].coluna[0];
	
	 
	 
	 
	 while(m <= 7 && n <= 7){
	 	
	 	rainhas[ultima].ataque[m++][n++] = 1;
	 }
	 
	 	m = rainhas[ultima].linha[0];
		n = rainhas[ultima].coluna[0];
	 
   while(m >= 0 && n >= 0){
   		
	 	rainhas[ultima].ataque[m--][n--] = 1;
	}
	
	m = rainhas[ultima].linha[0];
	n = rainhas[ultima].coluna[0];
	
	while(m <= 7 && n >= 0){
   		
	 	rainhas[ultima].ataque[m++][n--] = 1;
	}
	
	
	m = rainhas[ultima].linha[0];
	n = rainhas[ultima].coluna[0];
	
	while(m >= 0 && n <= 7){
   		
	 	rainhas[ultima].ataque[m--][n++] = 1;
	}
	
	
	 
	for(i = 0; i < 8; i++)
	  {
	    for(j = 0; j < 8; j++)
	    {
	      tabuleiro[i][j] = 0;
	    }
	  }

	  
	 for(i = 0; i < 8; i++)
	  {
	    for(j = 0; j < 8; j++)
	    {
	    	if(tabuleiro1[i][j] == 32){
	    		printf("  ");
			}else{
				 printf("%i ", tabuleiro1[i][j]);
			}
	      
	    }
	    printf("\n");
	  }
	system("pause");
	system("cls");
	ultima++;
	


	
	final++;

    
}


  
  
  return 0;
}
  
 
