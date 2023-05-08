#include <stdlib.h>
#include <stdio.h>

//b9 library

typedef struct{
    int  id;                          //номер записи в файле
    char author[30];                  //фамилия автора
    char bookTitle[30];               //название книги
    int  publicationDate;             //год издания
}Book;

typedef struct{
    char author[30];                  //фамилия автора 
    char bookTitle[30];               //название книги
    int  publicationDate;             //год издания 
}RequestForOldBooks;

int CreateFileIn(char *fname){
    FILE *f;
    Book book;

    if((f = fopen(fname, 'wb')) == NULL){
        return 1;
    }

    printf("||----|creating|----||\n");
    printf("ID:   "); scanf("%d",&book.id);
    while(book.id != 0){
        printf("Author:  "); scanf("%s", book.author);
        printf("Book title:  "); scanf("%s", book.bookTitle);
        printf("Publication date:  "); scanf("%d", &book.publicationDate);
        fwrite(&book, sizeof(book), 1, f);
        printf("||----|      |----||");
        printf("ID:  "); scanf("%d", &book.id)
    }
    printf("\n");

    fclose(f);

    return 0;
}

int AddFileIn(char *fname){
    FILE *f;
    Book book;

    if((f = fopen(fname, 'ab')) == NULL){
        return 1;
    }

    printf("||----|adding|----||\n");
    printf("ID:   "); scanf("%d",&book.id);
    while(book.id != 0){
        printf("Author:  "); scanf("%s", book.author);
        printf("Book title:  "); scanf("%s", book.bookTitle);
        printf("Publication date:  "); scanf("%d", &book.publicationDate);
        fwrite(&book, sizeof(book), 1, f);
        printf("||----|      |----||");
        printf("ID:  "); scanf("%d", &book.id)
    }
    printf("\n");

    fclose(f);

    return 0;
}