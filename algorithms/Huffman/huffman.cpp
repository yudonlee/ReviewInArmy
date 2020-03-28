#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define left(i) 2*i
#define right(i) 2*i+1
#define parent(i) i/2
#define INTERNAL_NODE 0
#define LEAF_NODE 1
int g_heap_size = 0;
int g_result = 0;
#define left(i) 2*i
#define right(i) 2*i+1
typedef struct _element {
	int freq;
	int is_internal;
	int var;
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
Node* extract_keys(Node* heap, int number); //**return value is object. ** key point.
void BuildMinHeap(int heap_size, Heaptype heaptype);
void Huffman(int number, Heaptype heaptype);
void preorder(Node* head, int level);
int calculate_bit(int heap_size);
int main() {
	int heap_size, freq;
	int sum_freq = 0;
	char input[256];
	cin >> heap_size;
	Heaptype heaptype;
	heaptype.heap = new Node[heap_size + 1];
	for (int i = 1; i <= heap_size; i++) {
		cin >> input >> freq;
		sum_freq += freq;
		heaptype.heap[i].source.freq = freq;
		strcpy(heaptype.heap[i].source.name, input);
		heaptype.heap[i].source.is_internal = LEAF_NODE;
		heaptype.heap[1].source.var = 0;
		heaptype.heap[i].left_child = NULL;
		heaptype.heap[i].right_child = NULL;
		heaptype.heap[i].parent = NULL;
	}
	int bit = calculate_bit(heap_size);
	Huffman(heap_size, heaptype);
	cout << sum_freq * bit << endl;
	cout <<g_result << endl;
	return 0;
}
void MinHeapify(int number, Node* heap, int index);
void insert(Node* heap, Node input);
void Increase_key(Node* heap,int index, Node input);
void swap_element(Node* heap, int left, int right) {
	Node temp = heap[left];
	heap[left] = heap[right];
	heap[right] = temp;
}
void MinHeapify(int number, Node* heap, int index) {
	int left_child = left(index);
	int right_child = right(index);
	if (right_child > number) {  
		if (heap[index].source.freq >= heap[left_child].source.freq && left_child <= number) {
			swap_element(heap, left_child, index);
			MinHeapify(number, heap, left_child);
		}
	}
	else {
		if (heap[left_child].source.freq < heap[right_child].source.freq){
			if (heap[index].source.freq >= heap[left_child].source.freq) {
				swap_element(heap, left_child, index);
				MinHeapify(number, heap, left_child);
			}
		}
		else {
			if (heap[index].source.freq >= heap[right_child].source.freq) {
				swap_element(heap, right_child, index);
				MinHeapify(number, heap, right_child);
			}
		}
	}
}

Node* extract_keys(Node* heap, int number)
{
	//Node result = heap[1]; i make the missing point this one.the shallow copy on left_chid,right_child node. only  element structure can be copied succeessfully.
	Node* result = new Node(heap[1]); //so i use "new" to construct new object.
	swap_element(heap, 1, number);
	MinHeapify(number - 1, heap, 1);
	g_heap_size--;
	return result;
}
void BuildMinHeap(int heap_size, Heaptype heaptype)
{
	for (int i = heap_size / 2; i >= 1; i--)
		MinHeapify(heap_size, heaptype.heap, i);
}
void insert(Node* heap,Node input)
{
	g_heap_size++;
	heap[g_heap_size].source.freq = -100;
	if (g_heap_size > 1)
		Increase_key(heap, g_heap_size,input);
	else {
		heap[1] = input;
	}
		
}
void Increase_key(Node* heap,int index, Node input){
	heap[g_heap_size] = input;
	int index_parent = parent(index);
	while (input.source.freq > heap[index_parent].source.freq) {
		swap_element(heap, index_parent, index);
		index = parent(index);
		index_parent = parent(index);
	} 
	MinHeapify(g_heap_size,heap, index);
}

void Huffman(int heap_size, Heaptype heaptype) 
{
	g_heap_size = heap_size;
	BuildMinHeap(heap_size, heaptype);
	while (g_heap_size > 1) {
		Node* left = extract_keys(heaptype.heap, g_heap_size);
		Node* right = extract_keys(heaptype.heap, g_heap_size);
	if (left->source.is_internal == LEAF_NODE && right->source.is_internal == LEAF_NODE) {
			Node* new_internal = new Node;
			new_internal->source.freq = left->source.freq + right->source.freq;
			new_internal->source.is_internal = INTERNAL_NODE;
			if (left->source.freq > right->source.freq) {
				new_internal->left_child = right;
				new_internal->right_child = left;
			}
			else {
				new_internal->left_child = left;
				new_internal->right_child = right;
			}
			insert(heaptype.heap, *new_internal);
		}
		else if (left->source.is_internal == INTERNAL_NODE && right->source.is_internal == INTERNAL_NODE) {
			Node* new_internal = new Node;
			new_internal->source.freq = left->source.freq + right->source.freq;
			new_internal->source.is_internal = INTERNAL_NODE;
			if (left->source.freq > right->source.freq) {
				new_internal->left_child = right;
				new_internal->right_child = left;
			}
			else {
				new_internal->left_child = left;
				new_internal->right_child = right;
			}
			insert(heaptype.heap, *new_internal);
		}
		else {
			Node* new_internal = new Node;
			new_internal->source.freq = left->source.freq + right->source.freq;
			new_internal->source.is_internal = INTERNAL_NODE;
			if (left->source.freq > right->source.freq) {
				new_internal->left_child = right;
				new_internal->right_child = left;
			}
			else {
				new_internal->left_child = left;
				new_internal->right_child = right;
			}
			insert(heaptype.heap, *new_internal);
		}
	}
	preorder(&heaptype.heap[1],0);
	
}

void preorder(Node* head, int level) {
	
	if (head->source.is_internal == LEAF_NODE) {
		head->source.var = level;
		g_result += head->source.var * head->source.freq;
	}
	if (head->left_child != NULL)
		preorder(head->left_child,level+1);
	if (head->right_child != NULL)
		preorder(head->right_child,level+1);
}

int calculate_bit(int heap_size)
{
	int binary=1;
	int bit = 0;
	while (binary < heap_size) {
		binary *= 2;
		bit++;
	}
	return bit;
}

//this is my faliure code. only copying the return value is making an error that the left child and the right child had the same address value as before in iteration statement. 
//void Huffman(int heap_size, Heaptype heaptype)
//{
//	g_heap_size = heap_size;
//	BuildMinHeap(heap_size, heaptype);
//	for (int i = 1; i <= heap_size; i++) {
//		cout <<"in heap "<<i<<"th address"<< &heaptype.heap[i] << endl;
//		cout << "in heap source address" << &heaptype.heap[i].source << endl;
//	}
//	while (g_heap_size > 1) {
//		Node left = extract_keys(heaptype.heap, g_heap_size); //이렇게 됐을때 항상 새로운 left가 만들어지고 그럴줄알았는데 그렇지 못했다.
//		cout << "left address value is :" << &left << endl;
//		Node right = extract_keys(heaptype.heap, g_heap_size);
//		cout << " right address value is: " << &right << endl;
//		if (left.source.is_internal == LEAF_NODE && right.source.is_internal == LEAF_NODE) {
//			Node new_internal;
//			new_internal.source.freq = left.source.freq + right.source.freq;
//			new_internal.source.is_internal = INTERNAL_NODE;
//			if (left.source.freq > right.source.freq) {
//				new_internal.left_child = &right;
//				new_internal.right_child = &left;
//			}
//			else {
//				new_internal.left_child = &left;
//				new_internal.right_child = &right;
//			}
//			insert(heaptype.heap, new_internal);
//			cout << "internal value is: " << new_internal.source.freq << "internal left is: " << new_internal.left_child << "  right is: " << new_internal.right_child << endl;
//			// insert in heap .. g _heap_size ++. 
//		}
//		else if (left.source.is_internal == INTERNAL_NODE && right.source.is_internal == INTERNAL_NODE) {
//			Node new_internal;
//			new_internal.source.freq = left.source.freq + right.source.freq;
//			new_internal.source.is_internal = INTERNAL_NODE;
//			if (left.source.freq > right.source.freq) {
//				new_internal.left_child = &right;
//				new_internal.right_child = &left;
//			}
//			else {
//				new_internal.left_child = &left;
//				new_internal.right_child = &right;
//			}
//
//			insert(heaptype.heap, new_internal);
//			cout << "internal value is: " << new_internal.source.freq << "internal left is: " << new_internal.left_child << "  right is: " << new_internal.right_child << endl;
//		}
//		else {
//			Node new_internal;
//			new_internal.source.freq = left.source.freq + right.source.freq;
//			new_internal.source.is_internal = INTERNAL_NODE;
//			if (left.source.freq > right.source.freq) {
//				new_internal.left_child = &right;
//				new_internal.right_child = &left;
//			}
//			else {
//				new_internal.left_child = &left;
//				new_internal.right_child = &right;
//			}
//			insert(heaptype.heap, new_internal);
//			cout << "internal value is: " << new_internal.source.freq << "internal left is: " << new_internal.left_child << "  right is: " << new_internal.right_child << endl;
//		}
//	}
//	cout << "right value: " << heaptype.heap[1].right_child->source.freq << "right left " << heaptype.heap[1].right_child->left_child->source.freq << endl;
//}
//
