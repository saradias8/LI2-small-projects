#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void classifica(int a, int b, int c) {
    if (a == b) {
        if (a==c) printf("Triângulo equilátero\n");
        else printf("Triângulo isósceles\n");
    }
    else {
        if (a == c || b == c) printf("Triângulo isósceles\n");
        else printf("Triângulo escaleno\n");
    }
}

void area(int a, int b, int c) {
    float abc,s;
    s = (a+b+c)/2;
    abc = sqrt(s*(s-a)*(s-b)*(s-c));
    printf("Área: %f", abc);
}

int valida(int a, int b, int c) {
    if(abs(b-c)<a && a<b+c
       && abs(a-c)<b && b<a+c
       && abs(b-a)<c && c<b+a) return 0;
    else return 1;
}

int main() {
    int a, b, c;
    printf("Introduza os valores dos lados do triângulo:\n");
    scanf("%d %d %d", &a, &b, &c);
    if (valida(a,b,c) == 0) {
        classifica(a,b,c);
        area(a,b,c);
        return 0;
    }
    else {
        printf("Estes valores não podem constituir um triângulo.\n");
        return 1;
    }

}
