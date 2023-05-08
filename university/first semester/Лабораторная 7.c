/*Выделить в строке-предложении s все слова, разделенные символами-разделителями «_.,;:\n\t!?». Обработать выделенные слова в соответствии с вариантом.
  Варианты заданий
A1. Напечатать все слова, начинающиеся на большую и заканчивающиеся на меленькую букву.
*/

#include <stdio.h>
#include <ctype.h>
#define DELIMITERS " .,:;?!\n\t"
#define N 1024

int Check(char *s){
   int i, j;
   if (isupper(s[0])){
      for(i = 1; s[i] != '\0'; i++){
         if (islower(s[strlen(s) - 1]))
            return 1;
      }
   }
   return 0;
}
int main( ){
    char s[N]; // строка-предложение
    char *word; // адрес начала очередного слова (лексемы)
    int i, j, flag[256] = {0};

    fgets(s, N, stdin);
    for (i = 0; DELIMITERS[i]; i++)
        flag[DELIMITERS[i]] = 1;
    for (i = 0; s[i] && flag[s[i]]; i++);
    while (s[i]){
        word = &s[i];
        while (s[i] && !flag[s[i]])
            i++;
        j = i;
        while (s[i] && flag[s[i]])
            i++;
        s[j] = '\0';
        if (Check(word))
            puts(word);
    }
    return 0;
}
