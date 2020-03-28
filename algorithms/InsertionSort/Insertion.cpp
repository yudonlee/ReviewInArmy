#include <stdio.h>
#include <iostream>
using namespace std;
int* insertion_sort(int* keys, int number);
void insertion_sort_test(int* keys, int number);
int main() {
	int number;
	int* keys;
	int input;
	cin >> number;
	keys = new int[number];
	for (int i = 0; i < number; i++) {
		cin >> keys[i];
	}
	keys = insertion_sort(keys, number);
	//insertion_sort_test(keys, number);
	//what is the better idea for insertion sort? no making unnecessary varaibles or 
	for (int i = 0; i < number; i++)
		cout << keys[i] << " ";
	delete[] keys;
	return 0;
}

int* insertion_sort(int* keys, int number)
{
	int* result;
	for (int i = 1; i < number; i++) {
		int temp = keys[i];
		int j = i - 1;
		while (keys[j] > temp && j >= 0) {
			keys[j + 1] = keys[j];
			j--;
		}
		keys[j+1] = temp;
	}
	result = keys;
	return result;
}

void insertion_sort_test(int* keys, int number)
{
	for (int i = 1; i < number; i++) {
		int temp = keys[i];
		int j = i - 1;
		while (keys[j] > temp&& j >= 0) {
			keys[j + 1] = keys[j];
			j--;
		}
		keys[j + 1] = temp;
	}
}
