//C6. Q: число является симметричным в десятичном представлении.
#include <stdio.h>
#include <stdlib.h>

#include <time.h>
#include <math.h>

int CheckQ2(unsigned long long number){
  unsigned long long copyNumber, checkNumber;

  copyNumber = number;
  checkNumber = 0;

  while (copyNumber != 0) {
    checkNumber = checkNumber * 10 + copyNumber % 10;
    copyNumber /= 10;
  }
  return number == checkNumber;
}

int main(){
  srand(time(NULL));

  unsigned long long number, buffer;
  int withQ, withoutQ;

  withQ = withoutQ = 0;

  for(int i = 0; number != 0; i++){
    buffer = number;

    number = rand() % 20000 - 9999;
    printf("Generated number = %d\n", number);

    abs(CheckQ2(number)) && abs(CheckQ2(buffer)) ? withQ++ : withoutQ++;
  }

  printf("Number with q: %d\n", withQ);
  printf("Numbers without q: %d\n", withoutQ);

  return 0;
}
