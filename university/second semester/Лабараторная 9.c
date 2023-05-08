#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 10
#define A -50
#define B 50

/*С6 Q: число является простым. T: в числе хотя бы одна цифра
встречается более одного раза. Рекурсивно упорядочить массив с
помощью пузырьковой сортировки.*/

/* INIT ARRAY */
void Init(int *array, int size){
    int i;
    for(i = 0; i < size; i++)
    array[i] = A + rand() % (B - A + 1);
}
/* PRINT ARRAY */
void Print(int *array, int size){
    int i;
    for(i = 0; i < size; i++)
    printf("%d ", array[i]);
    putchar('\n');
}
/* 1 NUMBER MORE THAN 1  TIME */
int CheckT(int num){
    int count = 0, digit;
    int digit_seen[10] = {0};
    
    if(num < 0) num = -num;
    
    while(num != 0){
        digit = num % 10;

        if(++digit_seen[digit] > 1){
            count += 1;
        }
        num /= 10;
    } 

    return count > 0 ? 1 : 0;
}

/* CHECK SIMPLE NUMBER */
int CheckQ(int num){
	int i;
    if(num < 0 ) num = -num;

    if (num > 1){
    	for(i = 2; i < num; i++){
            if (num % i == 0 )
				return 0;
        }
        return 1;
    }
    return 0;
}

int CountRecQ(int *array, int *end){
    return array < end ? CheckQ(*array) + CountRecQ(array + 1, end) : 0;
}

int CountItQ(int *array, int size){
    int i, count;
    for(i = count = 0; i < size; i++)
        count += CheckQ(array[i]);
    return count;
}

int SumRecT(int *array, int *end){
    return array >= end ? 0 : CheckT(*array) + SumRecT(array + 1, end);
}

int SumItT(int *array, int size){
    int i, sum;
    for(i = sum = 0; i < size; i++)
        sum += CheckT(array[i]);
    return sum;
}

int CheckRecQ(int *array, int l, int r){
    return l == r ? CheckQ(array[l]) : CheckRecQ(array, l, (l + r)/2) || CheckRecQ(array, (l + r)/2 + 1, r);
}

int CheckItQ(int *array, int size){
	int i;
    for(i = 0; i < size; i++)
        if(CheckQ(array[i])) return 1;
    return 0;
}

int CheckRecT(int *array, int l, int r){
 return l == r ? CheckT(array[l]) : CheckRecT(array, l, (l + r)/2) && CheckRecT(array, (l + r)/2 + 1, r);
}

int CheckItT(int *array, int size){
    int i, flag = 1;
    for( i = 0; i < size; i++)
        if(!CheckT(array[i])) flag = 0;
    return flag;
}


/* RECURSE BUBBLE SORT */
void Sort(int *array, int size){
	int i;
    if (size == 1) return;
    for (i = 0; i <= size - 2; i++) {
        if (array[i] > array[i + 1]) {
            int temp = array[i + 1];
            array[i + 1] = array[i];
            array[i] = temp;
        }
    }

    //RANGE REDUCED AFTER RECURSE:
    Sort(array, size - 1);
}

int main( ){
    int a[N];
    srand(time(NULL));

    Init(a, N);
    Print(a, N);

    printf("count q with recurse = %d\n", CountRecQ(a, a + N));
    printf("count q without recurse = %d\n", CountItQ(a, N));

    printf("sum t with recurse = %d\n", SumRecT(a, a + N));
    printf("sum t without recurse = %d\n", SumItT(a, N));

    printf("check q with recurse = %d\n", CheckRecQ(a, 0, N-1));
    printf("check q without recurse = %d\n", CheckItQ(a, N));

    printf("check t with recurse = %d\n", CheckRecT(a, 0, N-1));
    printf("check t without recurce = %d\n", CheckItT(a, N));
    Sort(a, N);
    Print(a, N);
    return 0;
}
