#include <stdio.h>
#include <ctype.h>
#define DELIMITERS ".,:;?!\n\t"
#define N 1024
#define SET "bcdfghjklmnpqrstvxz1234567890"
/* B6 в слове нет согласных латинских букв и цифр. */
int Q(char *s){
     int i, count;
     for(i = count = 0; s[i] != '\0'; i++)
        if (strchr(SET, s[i]))
            return 0;
     return 1;
}

int ReadWords(char *fnamer, char *fnamew){
     FILE *f, *g;
     char s[N], *word;
     int i, j, flag[256] = {0};
     if ((f = fopen(fnamer, "r")) == NULL)
        return 1;
     if ((g = fopen(fnamew, "w")) == NULL)
        return 1;
     for (i = 0; DELIMITERS[i]; i++)
        flag[DELIMITERS[i]] = 1;
     while (fgets(s, N, f) != NULL){
         for (i = 0; s[i] && flag[s[i]]; i++)
         ;
         while (s[i]){
             word = s + i;
             while (s[i] && !flag[s[i]])
                i++;
             j = i;
             while (s[i] && flag[s[i]])
                i++;
             s[j] = '\0';
             if (Q(word)){
                 fputs(word, g);
                 fputc('\n', g);
             }
         }
    }
     fclose(f);
     fclose(g);
     return 0;
}
int main( ){
     ReadWords("c:\\source.txt", "c:\\output.txt");
     return 0;
}
