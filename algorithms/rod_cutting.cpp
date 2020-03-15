#include <iostream>
#include <stdio.h>
#include "rod_cutting.h"
using namespace std;
int bottom_up_rod_cutting(int number, int* price, int* rod, int* slice);
void rod_cutting_print(int number,int rod_length ,int* slice);
int main() {
	int number;
	int* price,*rod,*slice;
	cin >> number;
	price = new int[number+1], rod = new int[number+1],slice = new int[number+1];
	price[0] = 0, rod[0] = 0, slice[0] = 0;
	for (int i = 1; i <= number; i++)
		cin >> price[i];
	int rod_length = bottom_up_rod_cutting(number, price, rod, slice);
	rod_cutting_print(number,rod_length ,slice);
	return 0;
}

int bottom_up_rod_cutting(int number, int* price, int* rod, int* slice)
{
	for (int i = 1; i <= number; i++) {
		int max = price[i];
		slice[i] = i;
		for (int j = 0; j < i; j++) {
			if (max < rod[j] + price[i - j]) {
				max = rod[j] + price[i - j];
				slice[i] = j;
			}
		}
		rod[i] = max;
	}
	return rod[number];
}

void rod_cutting_print(int number,int rod_length, int* slice)
{
	cout << rod_length << endl;
	int index = number;
	while (index > 0) {
		cout << slice[index] << " ";
		index = index - slice[index];
	}
	cout << endl;
}
