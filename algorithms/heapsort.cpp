#include <iostream>
#include <stdio.h>
using namespace std;
#define left(i) 2*i
#define right(i) 2*i+1
int extract_keys(int* element, int number); //return value is number of array.
void BuildMaxHeap(int number,int* element);
void Heapsort(int number, int* element);
void MaxHeapify(int number,int* element, int index);
void swap_element(int* element, int left, int right) {
	int temp = element[left];
	element[left] = element[right];
	element[right] = temp;
}
int main() {
	int number;
	int first_source;
	cin >> number;
	cin >> first_source;
	int* element = new int[number + 1];
	for (int i = 1; i <= number; i++)
		cin >> element[i];
	/*Heapsort(number, element); the problem doesn't want to show the sorted array.so i make the annotation.
	for (int i = 1; i <= number; i++)
		cout << element[i] << " "; */
	int first_line;
	int heap_size = number;
	BuildMaxHeap(heap_size, element);
	for (int i = 1; i < first_source + 1 && i < number + 1; i++){
		first_line = extract_keys(element, heap_size);
		cout << first_line << " "; 	//cout << element[i] << " "; // vs warns C6385 that is danger with reading index over array scope.(ex array(3) is only reading 0,1,2) 
		heap_size--;
	}
	cout << endl;
	for(int i = 1; i < number-first_source +1; i++)
		cout << element[i] << " ";
	return 0;
}
void MaxHeapify(int number,int* element, int index) {
	//only left node is only child_node
	int left_child = left(index);
	int right_child = right(index);
	if (right_child > number) {  //that is missing point!!! i only consider right_child but left_child is also bigger than heap_size in other case.
		if (element[index] <= element[left_child] && left_child <=number) {
			swap_element(element, left_child, index);
			MaxHeapify(number, element, left_child);
		}
	}
	else {
		if (element[left_child] > element[right_child]) {
			if (element[index] <= element[left_child]) {
				swap_element(element, left_child, index);
				MaxHeapify(number, element, left_child);
			}
		}
		else {
			if (element[index] <= element[right_child]) {
				swap_element(element, right_child, index);
				MaxHeapify(number, element, right_child);
			}
		}
	}
}
int extract_keys(int* element, int number)
{
	int result = element[1];
	swap_element(element, 1, number);
	MaxHeapify(number - 1, element, 1);
	return result;
}
void BuildMaxHeap(int number,int* element)
{
	int heap_size = number;
	for (int i = heap_size / 2; i >= 1; i--)
		MaxHeapify(heap_size,element,i);
}

void Heapsort(int number, int* element)
{
	int heap_size = number;
	BuildMaxHeap(heap_size,element);
	for (int i = heap_size; i >= 2; i--) {
		swap_element(element, number, 1);
		number--;
		MaxHeapify(number, element, 1);
	}
}