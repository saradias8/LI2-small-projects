#include <stdio.h>
#include "tabuleiro.h"

void estado(char array[3][4])
{
  int i,j;

  for(i=0;i<3;i++) {
    for(j=0;j<4;j++)
      printf("%c",array[i][j]);
    printf("\n");
  }
  printf("\n");
}

int verifica(int linha, int coluna)
{
  int r=0;
  if(linha > 3 || coluna > 4 || linha < 1 || coluna < 1)
     r=1;
  return r;
}

void updates(char array[3][4])
{
  int i,j;

  FILE *tab;
  tab = fopen("tabuleiro.txt","w+");

  fputs("3 4\n",tab);

  for(i=0;i<3;i++) {
    for(j=0;j<4;j++)
      fprintf(tab,"%c",array[i][j]);
    fputs("\n",tab);
  }
  fclose(tab);
}

int ocupado(int linha, int coluna, char array[3][4])
{
  int r=0;
  if(array[linha][coluna] != '.') r=1;
  return r;
}

int altera(char array[3][4])
{
  int line,column;
  char x[10];

  printf("\nPosição do tabuleiro a alterar:\n");
  printf("Linha ");
  scanf("%d",&line);
  printf("Coluna ");
  scanf("%d",&column);

  if(verifica(line,column) != 0) {
    printf("A posição escolhida não é válida.\n\n");
    return 1; }

  if(ocupado(line-1,column-1,array) != 0) {
    printf("A posição escolhida já está ocupada.\n\n");
    return 1; }

  printf("Trocar por 'x' ou 'o'?\n");
  scanf("%s",x);

  array[line-1][column-1] = *x;

  updates(array);

  return 0;
}

void reset(char array[3][4])
{
  int i,j;

  for(i=0;i<3;i++)
    for(j=0;j<4;j++)
      array[i][j] = '.';

  updates(array);
}
