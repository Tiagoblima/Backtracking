#include<stdio.h>

typedef struct
{
  int coluna;
  int linha;
}Rainha;

//Recebe os array de linhas, colunas e diagonais sob ataque,
// uma rainha e a ultima posicao dos arrays que esta preenchida
//Devolve 0 se a rainha esta sob ataque e 1 se estiver segura 
int verifica(int linhas[], int colunas[], int dPrinc[], int dSec[], Rainha a, int ultima)
{
  int i;
  for(i = 0; i <= ultima; i++)
  {
    if(a.linha == &linhas[i])
	{
		return 0;	
	} 
    if(a.coluna == &colunas[i])
    {
    	return 0;
	}
    if(a.linha + &dPrinc[i] == a.coluna)
    {
    	return 0;
	}
    if(a.linha + a.coluna == &dSec[i])
    {
    	return 0;
	}
  }
  return 1;
}

int main()
{
  puts("As oito rainhas");

  //Inicialização do tabuleiro
  int tabuleiro [8][8];

  int i, j;

  for(i = 0; i < 8; i++)
  {
    for(j = 0; j < 8; j++)
    {
      tabuleiro[i][j] = 0;
    }
  }

  //Array de Rainhas 
  //e array com linhas, colunas e diagonais sob ataque
  Rainha rainhas[8];
  int linhas[8];
  int colunas[8];
  int diagPric[8];
  int diagSec[8];

  //Variáveis auxiliares
  int ultima = 0;
  int final = 0;
  int col = 0;
  
  while(final != 8)
  {
    rainhas[ultima].linha = ultima;
    rainhas[ultima].coluna = col;

    //Atualizando os arrays linhas e colunas sob ataque
    linhas[ultima] = rainhas[ultima].linha;
    colunas[ultima] = rainhas[ultima].coluna; 

    //Atualizando os arryas de diagonais sob ataque
    //Diagonal principal == i + t = j, t = j - i da rainha atual
    //Diagonal secundária == i + j = t, t = i + j da rainha atual
    diagPric[ultima] = rainhas[ultima].coluna - rainhas[ultima].linha;
    diagSec[ultima] = rainhas[ultima].linha + rainhas[ultima].coluna;

    int verif = verifica(&linhas[ultima], &colunas[ultima], &diagPric[ultima], &diagSec[ultima], rainhas[ultima], ultima); 
    

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
	

    //Condição de parada do while
    if(final == 8) break;

  }

  


  //Impressão do tabuleiro
  puts("\n");
  for(i = 0; i < 8; i++)
  {
    for(j = 0; j < 8; j++)
    {
      printf("%i ",tabuleiro[i][j]);
    }
    puts("");
  }

}
