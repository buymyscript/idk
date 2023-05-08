#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Init(int size, int *array){

	for(int i = 0; i < size; i++){
		array[i] = rand() % 2000;
	}

}

int Print(int size, int *array){

	for(int i = 0; i < size; i++){
		printf(" %4d ", *array++);
	}
}

int QSortArray(int size, int *array){
	int count = 0 , i , j;
	//ShellSort
	for(int localSize = size / 2; localSize > 0; localSize /= 2){
		for(int i = localSize; i < size; ++i){
			for (int j = i - localSize; j >= 0 && array[j] > array[j + localSize]; j -= localSize){
				int temp = array[j];
				array[j] = array[j + localSize];
				array[j + localSize] = temp;
			}
		}
	}
	//find Q
	for (i = 0; i < size; i++){
			if (array[i] != array[i - 1] && array[i] % 2 == 0){
				count++;
			}
	}
	return count;
}

int QRandArray(int size, int *array){
	int count = 0;
	int i, j = 0;

	for (i = 0; i < size; i++){

			for (j = 0; j < i && array[i] != array[j]; j++);

			if (j == i && array[i] % 2 == 0){
				count++;
			}
	}
	return count;
}

int QShrtArray(int size, int *array){
	int count = 0;
	int countArray[2000] = {0};

	for(int i = 0; i < size; i++){
		if(array[i] % 2 == 0)
			countArray[array[i]]++;
	}

	for(int i = 0; i < 2000; i++){
		if(countArray[i] != 0){
			count++;
		}
	}

	return count;
}


int main(){
	srand(time(NULL));

	int *array = NULL;
	int size = 0;


	printf("Enter size of array: \n");
	scanf("%d", &size);

	//array = (int*)malloc(sizeof(int) * size);
	array = (int*)calloc(size, sizeof(int));

	Init(size, array);
	Print(size, array);

	printf("\n %d \n", QRandArray(size, array));
	printf("\n %d \n", QSortArray(size, array));
	printf("\n %d \n", QShrtArray(size, array));

	free(array);
	return 0;
}
