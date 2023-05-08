/*Требуется определить двумерный массив a целых чисел размером 𝑀𝑀 × 𝑁𝑁, заполнить его случайными числами или ввести его
элементы с клавиатуры и в одномерный массив b записать характеристики двумерного массива a в соответствии с вариантом задания.
Программа должна содержать следующие функции:
• инициализация элементов двумерного массива случайными числами или вводимыми с клавиатуры;
• заполнение одномерного массива в соответствии с заданием;
• вывод одномерного массива на экран;
• вывод двумерного массива на экран
A13. Найти максимальные элементы каждого столбца матрицы a размером 𝑀𝑀 × 𝑁𝑁 и сохранить их в одномерном массиве b
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define M 5
#define N 7
#define A -50
#define B 50

int init_array(int array_one[][N],int size_M, int size_N){
    int i,j;
    for (i=0;i < size_M;i++)
        for (j=0;j < size_N;j++)
            array_one[i][j] = A+rand()%(B-A+1);
    return 0;
}

 int show_array_one(int array[],int size){
     int i;
     for (i=0; i < size; i++)
        printf("%5d", array[i]);
        printf("\n");
     return 0;
 }

int show_array_two(int array[][N], int size_M, int size_N){
    int i;
    for (i=0;i < size_M; i++)
        show_array_one(array[i], size_N);
    printf("\n");
    return 0;
}

int max(int array_one[M][N], int array_two[N], int size_M, int size_N){
    int i,j,max;
    for(j=0; j < size_N; j++){
        max = array_one[0][j];
        for(i=0;i < size_M;i++){
            if(array_one[i][j] > max)
                max = array_one[i][j];
            }
        array_two[j] = max;
    }
    return 0;
}

int main(){
    int array_one[M][N],array_two[M];
    srand(time(NULL));
    init_array(array_one,M,N);
    show_array_two(array_one,M,N);
    max(array_one, array_two, M, N);
    printf("\n");
    printf("\n");
    show_array_one(array_two,N);
    return 0;
}
