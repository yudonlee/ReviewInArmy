//SelectionSort.cpp
//this is not usable sorting algorithm,because big o notation is n ^ 2. so professor wants to know step of selection sort.
#include <stdint.h>
#include <iostream>
using namespace std;
void SelectionSort(int* array,int size,int steps);
int main() {
	int size, steps;
	cin >> size >> steps;
	int* result = new int[size + 1];
	for (int i = 1; i <= size; i++)
		cin >> result[i];
	SelectionSort(result,size, steps);
	for (int i = 1; i <= size; i++)
		cout << result[i] << " ";
	cout << endl;
	return 0;
}

void SelectionSort(int* array,int size ,int steps)
{
	int min;
	int temp = 0;
	int index = 0;
	for (int i = 1; i <= steps; i++) {
		min = array[i];
		temp = array[i];
		for (int j = i + 1; j <= size; j++)
			if (min > array[j]) {
				index = j;
				min = array[j];
			}
		array[i] = min;
		array[index] = temp;
	}
}
