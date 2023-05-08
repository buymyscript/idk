//C8: число начинается на 1. T: каждая цифра, входящая в число,встречается ровно два раза

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <time.h>

int InitArray(int *array,int size){
  for(int i = 0; i < size; i++){
    array[i] = rand() % 1000;
  }
}
int PrintArray(int *array, int size){
  for(int i = 0; i < size; i++){
    printf("%4d", array[i]);
  }
}

int CheckT(int number){
  int checkArray[10] = {0};
  int size, count = 0;

  int *bufferArray = NULL;
  bufferArray = (int*)malloc(sizeof(int) * (1 + (int)log10(number)));

  size = _msize(bufferArray) / sizeof(bufferArray[0]);

  for(int i = size - 1;i >= 0; i--){
    bufferArray[i] = number % 10;
    number /= 10;
  }

  for(int i = 0; i < size; i++){
    checkArray[bufferArray[i]]++;
  }
  for(int i = 0; i < 9; i++){
    if(checkArray[i] == 2){
      count++;
    }
	}

  //return
  if(count % 2 == 0){
    return 1;
  }
  else{
    return 0;
  }

}
int CheckQ(int number){
  if(number < 10){
    return number;
  }else{
    do{
      number /= 10;
    }while(number >= 10);
  }
  return number == 1 ? 1: 0;
}
int SortQ(int *array,int size){

}
int deleteT(int *array, int size){

}

int main() {
  srand(time(NULL));

  int size = 0;
  int *array = NULL;

  printf("enter size of array: ");
  scanf("%d",&size);

  array = (int*)malloc(sizeof(int) * size);

  InitArray(array,size);
  PrintArray(array, size);
  printf("\n%d\n", CheckQ(2));

  free(array);
  return 0;
}
