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
  int numbers[256], i, size;

  printf("sentence: ");
  fgets(sentence,256,stdin); //gets sentence
  size = strlen(sentence);

  for(int l=0; l<26; l++) // counts how many times each letter appears
    numbers[l] = counts(sentence,letters[l],size);

  for(i=0;i<26;i++) {
    printf("%c ", letters[i]);   //prints letter
    for(int x=0;x<numbers[i];x++)  //prints star x times (count)
      printf("☆ ");
    printf("\n");
  }
  return 0;
}
