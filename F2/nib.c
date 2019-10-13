//
// Created by sara on 22-02-2019.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nib.h"

int equal(char a[], char b[]) {
    int k=0;

    for(int i=0;i<4;i++) {
        if (a[i] == b[i]) k++;
    }
    if (k != 4) k=0;
    return k;
}

void banco(char *nib) {
    char nb[4] = "0007";
    char bpi[4] = "0010";
    char sdt[4] = "0018";
    char bbva[4] = "0019";
    char ab[4] = "0023";
    char barc[4] = "0032";
    char mil[4] = "0033";
    char cgd[4] = "0035";
    char mont[4] = "0036";
    char deu[4] = "0043";
    char ca[4] = "0045";
    char pop[4] = "0046";
    char bic[4] = "0079";
    char ctt[4] = "0193";
    char bki[4] = "0269";
    char *all[] = {"Novo Banco",nb,"BPI",bpi,"Santander Totta",sdt,"BBVA",bbva,
                   "Activo Bank",ab,"Barclays",barc,"Millennium BCP",mil,
                   "Caixa Geral de Depósitos",cgd,"Montepio",mont,"Deutsche Bank",deu,
                   "Crédito Agrícola",ca,"Popular",pop,"BIC",bic,"Banco CTT",ctt,"Bankinter",bki};

    for(int x=1;x<30;x+=2)
        if (equal(nib,all[x])==4) {
            printf("Banco: %s\n", all[x-1]);
            break; }
}

void nrConta(char *nib) {
  int i=9, t=0;

  printf("Nº de Conta: ");
  while(i<19) {

    if(t==1) {
      printf("%c", nib[i]);
      i++; }

    if(nib[i] == '0' && t == 0) i++;

    if(nib[i] != '0' && t == 0) {
      t=1; i++;
      printf("%c", nib[i]); }
  }
  printf("\n");
}

void nrControlo(char *nib) {
    char new[2];

    for(int i=19,x=0;i<21;i++,x++)
        new[x] = nib[i];

    printf("Números de Controlo: %s\n",new);
}

void nibEspacos(char *nib) {
    int i,j=0;
    char new[26];

    for(i=0;i<26;i++) {

        if( i==4 || i==9 || i==21 ) {
            new[i++] = ' ';
            new[i] = nib[j];
        }
        else new[i] = nib[j];
        j++;
    }
    printf("O NIB é %s\n", new);
}
