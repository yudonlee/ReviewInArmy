//priorityQueue.cpp
#include <iostream>
#include <stdio.h>
using namespace std;
#define left(i) 2*i
#define right(i) 2*i+1
#define parent(i) i/2
int g_heap_size; //it reduces making field varible  by using global value.
int ExtractMax(int* element); //return value is number of array.
void Increase_key(int* element,int index, int key);
void MaxHeapify(int* element, int index);
void insert(int* element, int key);
void swap_element(int* element, int left, int right) {
	int temp = element[left];
	element[left] = element[right];
	element[right] = temp;
}
int main() {
	g_heap_size = 0;
	int heap[30000];
	int mode, key, index;
	while (true) {
		cin >> mode;
		if (mode == 1) {
			cin >> key;
			insert(heap, key);
		}
		else if (mode == 2) {
			cout << ExtractMax(heap) << " ";
		}
		else if (mode == 3) {
			cin >> index >> key;
			Increase_key(heap, index, key);
		}
		else{
			cout << endl;
			for (int i = 1; i <= g_heap_size; i++)
				cout << heap[i] << " ";
			cout << endl;
			break;
		}
	}
	return 0;
}
void MaxHeapify(int* element, int index) {
	//only left node is only child_node
	int left_child = left(index);
	int right_child = right(index);
	if (right_child > g_heap_size) {  //that is missing point!!! i only consider right_child but left_child is also bigger than heap_size in other case.
		if (element[index] <= element[left_child] && left_child <= g_heap_size) {
			swap_element(element, left_child, index);
			MaxHeapify(element, left_child);
		}
	}
	else {
		if (element[left_child] > element[right_child]) {
			if (element[index] <= element[left_child]) {
				swap_element(element, left_child, index);
				MaxHeapify(element, left_child);
			}
		}
		else {
			if (element[index] <= element[right_child]) {
				swap_element(element, right_child, index);
				MaxHeapify(element, right_child);
			}
		}
	}
}
void insert(int* element, int key)
{
	g_heap_size++;
	element[g_heap_size] = -100;
	if (g_heap_size > 1)
		Increase_key(element, g_heap_size, key);
	else
		element[1] = key;
}
int ExtractMax(int* element)
{
	g_heap_size--;
	int result = element[1];
	swap_element(element, 1,g_heap_size + 1);
	MaxHeapify(element, 1);
	return result;
}
void Increase_key(int* element, int index, int key)
{	
	element[index] = key;
	int index_parent = parent(index);
	while (key > element[index_parent]) {
		swap_element(element, index_parent, index);
		index = parent(index);
		index_parent = parent(index);
	} //find the position if increase_key is bigger than parent. 
	MaxHeapify(element, index);
}
/*
//priorityQueue.cpp not using global value.
#include <iostream>
#include <stdio.h>
using namespace std;
#define left(i) 2*i
#define right(i) 2*i+1
#define parent(i) i/2
int g_heap_size;
int ExtractMax(int* element, int number); //return value is number of array.
void Increase_key(int* element,int index, int key);
void MaxHeapify(int number, int* element, int index);
void insert(int* element, int key);
void swap_element(int* element, int left, int right) {
	int temp = element[left];
	element[left] = element[right];
	element[right] = temp;
}
int main() {
	g_heap_size = 0;
	int heap[30000];
	int mode, key, index;
	while (true) {
		cin >> mode;
		if (mode == 1) {
			cin >> key;
			insert(heap, key);
		}
		else if (mode == 2) {
			cout << ExtractMax(heap, g_heap_size) << " ";
		}
		else if (mode == 3) {
			cin >> index >> key;
			Increase_key(heap, index, key);
		}
		else{
			cout << endl;
			for (int i = 1; i <= g_heap_size; i++)
				cout << heap[i] << " ";
			cout << endl;
			break;
		}
	}
	return 0;
}
void MaxHeapify(int number, int* element, int index) {
	//only left node is only child_node
	int left_child = left(index);
	int right_child = right(index);
	if (right_child > number) {  //that is missing point!!! i only consider right_child but left_child is also bigger than heap_size in other case.
		if (element[index] <= element[left_child] && left_child <= number) {
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
void insert(int* element, int key)
{
	g_heap_size++;
	element[g_heap_size] = -100;
	if (g_heap_size > 1)
		Increase_key(element, g_heap_size, key);
	else
		element[1] = key;
}
int ExtractMax(int* element, int number)
{
	g_heap_size--;
	int result = element[1];
	swap_element(element, 1, number);

	MaxHeapify(number - 1, element, 1);
	return result;
}
void Increase_key(int* element, int index, int key)
{
	element[index] = key;
	int index_parent = parent(index);
	while (key > element[index_parent]) {
		swap_element(element, index_parent, index);
		index = parent(index);
		index_parent = parent(index);
	} //find the position if increase_key is bigger than parent.
	MaxHeapify(g_heap_size, element, index);
}

*/