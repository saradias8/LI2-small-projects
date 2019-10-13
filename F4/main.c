#include <stdio.h>
#include "tabuleiro.h"

int menu(char array[3][4])
{
  int opcao;

  printf("1. Ver estado do tabuleiro\n");
  printf("2. Alterar peças\n");
  printf("3. Reiniciar tabuleiro\n");
  printf("4. Sair do jogo\n");
  printf("Selecione uma opção:\n");
  scanf("%d",&opcao);

  if(opcao == 1) estado(array);
  if(opcao == 2) altera(array);
  if(opcao == 3) reset(array);
  if(opcao == 4) return 1;

  return 0;
}

int main()
{
  char array[3][4], lines[16];
  int t=0,i,j;

  FILE *tab;
  tab = fopen("tabuleiro.txt","r+");

  fseek(tab,4,SEEK_SET);

  while(fgets(lines,100,tab)) {
    for(i=0;i<4;i++) array[j][i] = lines[i];
    j++;
  }

  fclose(tab);

  while(t==0) {
    t = menu(array);
  }
  return 0;
}
