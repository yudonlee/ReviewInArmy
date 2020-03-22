#include <iostream>
#include <stdio.h>
using namespace std;
#define left(i) 2*i
#define right(i) 2*i+1
#define parent(i) i/2
#define INTERNAL_NODE 0
#define LEAF_NODE 1
int g_heap_size = 0;
#define left(i) 2*i
#define right(i) 2*i+1
typedef struct _element {
	int freq;
	int is_internal;
	char name[256];
}element;
typedef struct Node{
    element source;
	Node* parent;
	Node* left_child;
	Node* right_child;
}Node;
typedef struct _Heaptype{
	Node* heap;
	Node* head;
}Heaptype;
Node extract_keys(Node* heap, int number); //return value is number of array.
void BuildMaxHeap(int heap_size, Heaptype heaptype);
void Huffman(int number, Heaptype heaptype);
void MaxHeapify(int number, Node* heap, int index);
void insert(Node* heap, Node input);
void Increase_key(Node* heap,int index, Node input);
void swap_element(Node* heap, int left, int right) {
	Node temp = heap[left];
	heap[left] = heap[right];
	heap[right] = temp;
}
int main() {
	int heap_size, freq;
	char input[256];
	cin >> heap_size;
	Heaptype heaptype;
	heaptype.heap = new Node[heap_size + 1];
	for (int i = 1; i <= heap_size; i++) {
		cin >> input >> freq;
		heaptype.heap[i].source.freq = freq;
		strcpy_s(heaptype.heap[i].source.name, input);
		heaptype.heap[i].source.is_internal = LEAF_NODE;
	}
	Huffman(heap_size, heaptype);
	return 0;
}

void MaxHeapify(int number, Node* heap, int index) {
	//only left node is only child_node
	int left_child = left(index);
	int right_child = right(index);
	if (right_child > number) {  //that is missing point!!! i only consider right_child but left_child is also bigger than heap_size in other case.
		if (heap[index].source.freq <= heap[left_child].source.freq && left_child <= number) {
			swap_element(heap, left_child, index);
			MaxHeapify(number, heap, left_child);
		}
	}
	else {
		if (heap[left_child].source.freq > heap[right_child].source.freq){
			if (heap[index].source.freq <= heap[left_child].source.freq) {
				swap_element(heap, left_child, index);
				MaxHeapify(number, heap, left_child);
			}
		}
		else {
			if (heap[index].source.freq <= heap[right_child].source.freq) {
				swap_element(heap, right_child, index);
				MaxHeapify(number, heap, right_child);
			}
		}
	}
}

Node extract_keys(Node* heap, int number)
{
	Node result = heap[1];
	swap_element(heap, 1, number);
	MaxHeapify(number - 1, heap, 1);
	g_heap_size--;
	cout << "global heap size: " << g_heap_size << endl;;
	return result;
}
void BuildMaxHeap(int heap_size, Heaptype heaptype)
{
	for (int i = heap_size / 2; i >= 1; i--)
		MaxHeapify(heap_size, heaptype.heap, i);
}

void Huffman(int heap_size, Heaptype heaptype)
{
	g_heap_size = heap_size;
	BuildMaxHeap(heap_size, heaptype);
	cout << "after build max heap\n";
	for (int i = 1; i <= heap_size; i++)
		cout <<i << "th is:" << heaptype.heap[i].source.freq << heaptype.heap[i].source.name << endl;
	while (g_heap_size > 1) {
		Node left = extract_keys(heaptype.heap, g_heap_size);
		Node right = extract_keys(heaptype.heap, g_heap_size);
		for (int i = 1; i <= g_heap_size; i++)
			cout << i << "th is:" << heaptype.heap[i].source.freq << endl;
		cout << "\n\n\n\n\n";
		if (left.source.is_internal == LEAF_NODE && right.source.is_internal == LEAF_NODE) {
			cout << "in leaf node & leaf node" << endl;
			Node new_internal;
			new_internal.source.freq = left.source.freq + right.source.freq;
			new_internal.source.is_internal = INTERNAL_NODE;
			if (left.source.freq > right.source.freq) {
				new_internal.left_child = &right;
				new_internal.right_child = &left;
			}
			else {
				new_internal.left_child = &left;
				new_internal.right_child = &right;
			}
			insert(heaptype.heap, new_internal);
			// insert in heap .. g _heap_size ++. 
		}
		else if (left.source.is_internal == INTERNAL_NODE && right.source.is_internal == INTERNAL_NODE) {
			cout << "in internal node & internal node" << endl;
			Node new_internal;
			new_internal.source.freq = left.source.freq + right.source.freq;
			new_internal.source.is_internal = INTERNAL_NODE;
			if (left.source.freq > right.source.freq) {
				new_internal.left_child = &right;
				new_internal.right_child = &left;
			}
			else {
				new_internal.left_child = &left;
				new_internal.right_child = &right;
			}
			insert(heaptype.heap, new_internal);
		}
		else {
			cout << "in leaf node & internal node" << endl;
			Node new_internal;
			new_internal.source.freq = left.source.freq + right.source.freq;
			new_internal.source.is_internal = INTERNAL_NODE;
			if (left.source.freq > right.source.freq) {
				new_internal.left_child = &right;
				new_internal.right_child = &left;
			}
			else {
				new_internal.left_child = &left;
				new_internal.right_child = &right;
			}
			insert(heaptype.heap, new_internal);
		}
	}
	cout << "heap is: " << heaptype.heap[1].source.freq << endl;;
}

void insert(Node* heap,Node input)
{
	cout << "in  insert: " << endl;
	g_heap_size++;
	heap[g_heap_size].source.freq = -100;
	if (g_heap_size > 1)
		Increase_key(heap, g_heap_size,input);
	else {
		heap[1] = input;
	}
		
}
void Increase_key(Node* heap,int index, Node input){
	cout << "in  increase: " << endl;
	heap[g_heap_size] = input;
	int index_parent = parent(index);
	while (input.source.freq < heap[index_parent].source.freq) {
		swap_element(heap, index_parent, index);
		index = parent(index);
		index_parent = parent(index);
	} //find the position if increase_key is bigger than parent. 
	MaxHeapify(g_heap_size,heap, index);
}
//int ExtractMax(Node* heap, char* name, int key)
//{
//	g_heap_size--;
//	int result = element[1];
//	swap_element(element, 1, g_heap_size + 1);
//	MaxHeapify(element, 1);
//	return result;
//}
//