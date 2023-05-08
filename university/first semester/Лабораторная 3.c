/*Лабораторная работа № 3. Числовые и функциональные ряды
Для бесконечного числового ряда члены которого вычисляются по формуле, соответствующей индивидуальному варианту, вычислить приближенную сумму двумя способами: сумму первых n членов ряда и сумму с точностью до eps (эпсилон) в двух разных функциях:
double Sum1(int n);
double Sum2(double eps).
Запрещается использование функции pow() и условных операторов «if» и «? : ».
Примечание – При достаточно большом значении n и при достаточно малом значении eps значения двух функций должны
быть примерно одинаковыми.
Вариант В3
*/

#include <stdio.h>
#include <math.h>           

double NumbersInit(int x) {
	return 1.0 / (x * x * x + x + 1.0);
}

double SumN (int n) {
	int znak = -1;
	double sum = 0.0;

	for (int i = 1; i <= n; i++){
		sum += znak * NumbersInit(i);
		znak = -znak;
	}

	return sum;
} 

double SumEps(double eps) {
	int znak = -1;
	double sum = 0.0;
	int i = 1;
	double slag = znak * NumbersInit(i);

	while (fabs(slag) >= eps) {
		sum += slag;
		znak = -znak;
		slag = znak * NumbersInit(++i);
	}

	return sum;
}

int main() {
	int n;
	double eps;

	printf("Enter n: ");
	scanf("%d", &n);
	printf("Sum of all %d was %lf\n", n, SumN(n));

	printf("Enter eps: ");
	scanf("%lf", &eps);
	printf("Sum  with accuaracy was %lf\n", SumEps(eps));
}