#include <iostream>
#include <vector>
#include <algorithm>
#define NMAX 10
using namespace std;
int a[NMAX], b[NMAX];

int digit(int n, int p)//получение p-го байта
{
	return (n >> (8 * p) & 255);
}
int main()
{
	//заполняем массив случайными числами
	for (int i = 0; i < NMAX; i++){
		a[i] = rand();
	}
	//максимальной число байтов в числе
	int k = sizeof(int);
	//количество элементов в массиве
	int n = NMAX;
	//цикл по всем байтам
	for (int i = 0; i < k; i++){
		//понятно что у байта максимум
		//256 значений
		int c[256] = { 0 };
		//подсчитываю количество элементов
		//в массиве соответствующий каждому
		//байту как и в сортировке подсчетом
		for (int j = 0; j < n; j++){
			c[digit(a[j], i)]++;
		}
		//модифицируем массив с
		//c[i] - номер элемента
		// следующего после i-го блока
		for (int j = 1; j < 256; j++){
			c[j] += c[j - 1];
		}
		//сдвигаем массив
		for (int j = n - 1; j >-1; j--){
			b[--c[digit(a[j], i)]] = a[j];
		}
		for (int j = 0; j < n; j++){
			a[j] = b[j];
		}
	}
	for (int i = 0; i < NMAX; i++){
		cout << a[i] << endl;
	}
	return 0;
}
