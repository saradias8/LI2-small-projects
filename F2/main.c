#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nib.h"

int menu(char *string, int *t, int *p) {
    int opcao;
    printf("Escolha uma ação.\n");
    printf("1. Ler NIB\n");
    printf("2. Indicar o banco do NIB\n");
    printf("3. Indicar o número da conta\n");
    printf("4. Indicar o número de controlo\n");
    printf("5. Escrever o NIB com um espaço entre cada bloco\n");
    printf("6. Sair do programa\n");
    scanf("%d", &opcao);

    if (opcao == 1) {
        scanf("%s", string);
        if (strlen(string) != 21) {
            printf("Não é um NIB válido.\n");
            *t = 1; }
        else {
          *t = 0; *p = 0;
        }
    }
    if (opcao == 2 && *t==0 && *p==0) banco(string);
    if (opcao == 3 && *t==0 && *p==0) nrConta(string);
    if (opcao == 4 && *t==0 && *p==0) nrControlo(string);
    if (opcao == 5 && *t==0 && *p==0) nibEspacos(string);
    if (opcao == 6) return 1;
    return 0;
}

int main() {
    int t = 0;
    int a=0;
    int b=1;
    char string[128];
    while(t==0) {
        t = menu(string,&a,&b);
    }
    return 0;
}
