#include<stdio.h>
#include <time.h>
typedef struct
{	
  int coluna[8];
  int linha[8];
  int x_a, y_a;
  int loc[64][8][8];
  int ataque[8][8];
}Rainha;


int direita(Rainha rainhas[], int* i, int outras,int* linha, int* coluna, int ultima){
	

	
	while(linha <= 7 && rainhas[outras].ataque[*coluna][*linha] == 1){
		rainhas[ultima].loc[*(i++)][*coluna][*linha] = 9;
		*(linha++);
	}
	
	
	if(*linha > 7){
		return 0;
	}
	return 1;
	
}
//Recebe os array de linhas, colunas e diagonais sob ataque,
// uma rainha e a ultima posicao dos arrays que esta preenchida
//Devolve 0 se a rainha esta sob ataque e 1 se estiver segura 
int backtracking(Rainha rainhas[8], int ultima)
{
	int outras = ultima - 1; // verifica se outras rainhas
	
    int coluna = rainhas[ultima].coluna[0];
	int linha = rainhas[ultima].linha[0];
	
	
	while(outras > 0){
		
		int i,j;
		i = 0;
		j = 0;
		// tentativa a direita
		direita(rainha, )
		
		// tentativa a esquerda
		while(rainhas[outras].ataque[k][l] == 1){
			
			rainhas[ultima].linha[++i] = --l;
			
			if(l == 0){
				i = 0;
				l = rainhas[ultima].linha[i];
			}
		}
		
		
		for(i = 0; i < 8; i++)
		  {
		    for(j = 0; j < 8; j++)
		    {
		      printf("%i ",rainhas[ultima].ataque[linha][coluna]);
		    }
		    puts("");
		  }
	
		
	}	
	
	
 
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
  
  
  int i, j;
  for(i = 0; i < 8; i++)
  {
    for(j = 0; j < 8; j++)
    {
      tabuleiro[i][j] = 0;
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
  		}
    }
  }
/*
for(i = 0; i < 8; i++)
  {
    for(j = 0; j < 8; j++)
    {
    	for(k = 0; k < 8; k++)
    	{
      		printf("%i", rainhas[i].ataque[j][k]);
  		}
  		printf("\n");
    }
    printf("\n");
  }

  */

  //Variáveis auxiliares
  int ultima = 0; //ultima rainha inserida
  int final = 1;
  int col = 0;
  
  srand(time(NULL));
while(final)
  {
  	
 	int l = rand()%8;
 	int k = rand()%8;
 	
 	
    rainhas[ultima].linha[0] = l;
    rainhas[ultima].coluna[0] = k;
    
	int verif = verifica(rainhas, ultima); 	
	
	
	

	printf("rainhas[ultima].linha[0]: %i\n", rainhas[ultima].linha[0]);
	printf("rainhas[ultima].coluna[0]: %i\n",  rainhas[ultima].coluna[0]);
    //Atualizando os arrays linhas e colunas sob ataque
    
	int m,n,i,j;
	
	
	m = rainhas[ultima].linha[0];
	n = rainhas[ultima].coluna[0];
	
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
	      printf("%i ",rainhas[ultima].ataque[i][j]);
	    }
	    puts("");
	  }
	
	final = 0;

     
    
/*
    //Se a posicao atual da rainha estiver sob ataque e 
    //a rainha atual não tiver atingido a última coluna do tabuleiro
    //Andar uma casa a direita
    if((verif == 0) && (rainhas[ultima].coluna < 8))
    {
      tabuleiro[rainhas[ultima].linha][rainhas[ultima].coluna] = 0;
      rainhas[ultima].coluna++;

      col = rainhas[ultima].coluna;
    }
	
    //Se a rainha estiver sob ataque e estiver na ultima coluna
    //Apaga a rainha atual e faz a rainha anterior andar uma casa a direita
    if((verif == 0) && (rainhas[ultima].coluna >= 8))
    {
      rainhas[ultima].linha = 0;
      rainhas[ultima].coluna = 0;

      linhas[ultima] = 0;
      colunas[ultima] = 0;
      
      diagPric[ultima] = 0;
      diagSec[ultima] = 0;
      
      ultima--;

      rainhas[ultima].coluna++;
    }
	
	//Colocando '1' nas posições ocupadas pela rainha
	int a = rainhas[ultima].linha;
	int b = rainhas[ultima].coluna;
    tabuleiro[a][b] = 1;
	
    //Se for a ultima rainha e ela estiver segura
    //Fim do while
    if((verif == 1) && (ultima == 7))
    {
      final = 8;
    }
	
    //Se a rainha estiver segura mas não for a ultima
    //Insere uma nova rainha
    if((verif == 1) && (ultima < 8))
    {
      ultima++;
    }
    
    

	
	 for(i = 0; i < 8; i++)
	  {
	    for(j = 0; j < 8; j++)
	    {
	      printf("%i ",tabuleiro[i][j]);
	    }
	    puts("");
	  }
    //Condição de parada do while
    if(final == 8) break;
	
	ultima++;
	printf("ultima: %i\n", ultima);
  	printf("final: %i\n", ultima);
  	printf("verif: %i\n", verif);
	system("pause");
	system("cls");
  }

  


  //Impressão do tabuleiro
  puts("\n");
  for(i = 0; i < 8; i++)
  {
    for(j = 0; j < 8; j++)
    {
      printf("%i ",tabuleiro[i][j]);
    }
    puts("");*/
  }


  
  
  return 0;
}
  
 
