#include <stdio.h>
#include <iostream>
using namespace std;
void mergeSort(int* array, int left, int right);
void merge(int* array, int left, int right);
int main() {
	int number;
	cin >> number;
	int* result = new int[number+1];
	for (int i = 1; i <= number; i++)
		cin >> result[i];
	mergeSort(result, 1, number); // Depending on the heapsorting algorithm, the starting index of the array is from 1,making the code more readable. 
	for (int i = 1; i <= number; i++)
		cout << result[i] << endl;
	delete[] result;
	return 0;
}

void mergeSort(int* array, int left, int right)
{
	if (left < right) {
		int m = (left + right) / 2;
		mergeSort(array, left, m);
		mergeSort(array, m + 1, right);
		merge(array, left, right);
	}
}

void merge(int* array, int left, int right)
{
	int* result = new int[right - left + 1];
	int index = 0;
	int l_start = left;
	int l_last = (left + right) / 2;
	int r_start = l_last + 1;
	int r_last = right;
	while (l_start <= (l_last) && r_start <= (r_last)) {
		if (array[l_start] < array[r_start])
			result[index++] = array[r_start++];
		else
			result[index++] = array[l_start++];
	}
	if (l_start != l_last+1) // code for element not flushed. 
		for (int i = l_start; i < l_last + 1; i++)
			result[index++] = array[i];
	if (r_start != (r_last+1)) // code for element not flushed. 
		for (int i = r_start; i < r_last + 1; i++)
			result[index++] = array[i];
	for (int i = 0; i < index; i++)
		array[left++] = result[i];
	delete[] result;
}
