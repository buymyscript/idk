/*  B2
    Определить, сколько точек с координатами (x, y) из полученной таблицы принадлежат:
        • заштрихованной области, включая граничные точки;
        • вне заштрихованной области;
        • граничным точкам заштрихованной области.
*/
#include <stdio.h>
#include <math.h>

#define A -5.0
#define B 5.0

double F(double x) {
    return -x;//x * exp(x) + 2 * sin(x) - sqrt(fabs(pow(x, 3) - pow(x, 2)));
}

double l(double x) {
    return x - 1;
}

double c(double x, double y) {
    return pow(x,2) + pow(y,2);
}


int main() {
    double x, y, h;
    int countIn,countOut,count, n;
	
    count = countIn = countOut = 0;

	double summ = 0;

    printf("n = "); 
	scanf("%d", &n);
    h = (B - A) / (n - 1);



    for (x = A; x <= B; x += h) {

        y = F(x);
        printf("%10.4f%10.4f\n", x, y);
		
		summ = summ + y;
		
        if (c(x, y) <= 1 && -1 <= x && x <= 0 && 1 >= y && y >= 0 || 1 >= x && x >= 0 && l(x) <= y && y <= 0 ){
            countIn++;
        }
        if(!(c(x, y) <= 1 && -1 <= x && x <= 0 && 1 >= y && y >= 0 ||1 >= x && x >= 0 && l(x) <= y && y <= 0 )){
		countOut++;
	}
	if(c(x, y) == 1 && x == -1 && y == 1 || x == 1 &&  y == l(x)){
		count++;
	}	
    }

    printf("Counter of InDots = %d\n", countIn);
    printf("Counter of OutDots = %d\n", countOut);
    printf("Counter of borderDots = %d\n", count);
    printf("Summ of numbers = %.4f\n", summ / n);
}

