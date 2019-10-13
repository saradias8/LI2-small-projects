#include <stdio.h>
#include <string.h>

int toupper(int c);

int counts(char sentence[], char letter, int size) {
  int conta=0, i;

  for(i=0;i<size;i++)
    if(toupper(sentence[i]) == letter) conta++;

  return conta;
}

int main() {
  char sentence[256];
  char letters[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int numbers[256], i, j, size, max=0;

  printf("sentence: ");
  fgets(sentence,256,stdin); //gets sentence
  size = strlen(sentence);

  for(int l=0; l<26; l++) { // counts how many times each letter appears
    numbers[l] = counts(sentence,letters[l],size);
    if(numbers[l]>max)
      max = numbers[l]; // in the end max = biggest nr of stars
  }

  for(i=0;i<max;i++) {
    for(j=0;j<26;j++) {
      if(max-numbers[j] == i) {
        printf("⭒ ");
        numbers[j]--; }
      else
        printf("  ");
    }
    printf("\n");
  }

  for(i=0; i<26; i++)
    printf("%c ", letters[i]);

  printf("\n");
  return 0;
}
