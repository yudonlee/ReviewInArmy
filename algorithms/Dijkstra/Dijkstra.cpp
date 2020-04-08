#include <iostream>
#include <stdio.h>
#include <vector>
#define left(i) 2*i
#define right(i) 2*i+1
#define parent(i) i/2
#define INFINITY 100000
#define WHITE -1
#define BLACK -2
using namespace std;
struct  vertex{
	int node;
	int distance;
	int status;
};
int g_heap_size;
void Increase_key(vertex* element, int index, vertex key);
int Dijkstra(vector< vector<pair<int, int> > > edge, int number,int edge_num);
vertex ExtractMin(vertex* element); //return value is number of array.
void MinHeapify(vertex* element, int index);
void insert(vertex* heap, vertex key,vertex* element);
void swap_element(vertex* element, int left, int right) {

	vertex temp = element[left];
	element[left] = element[right];
	element[right] = temp;
}
int main() {
	int number,distance,dest,vertex,edge;
	int edge_num = 0;
	cin >> number;
	vector<vector<pair<int, int>>> edge_list(number+1); // 중요중요 이거 헷갈림 블로그에 올릴것.
	for (int i = 1; i <= number;i++) {
		cin >> vertex >> edge;
		for(int j =1 ; j<= edge;j++){
			edge_num++;
			cin >> dest >> distance;
			edge_list[i].push_back(make_pair(dest,distance));
		}
	}
	int result = Dijkstra(edge_list, number,edge_num);
	cout <<  result << endl;
	return 0;
}

void Increase_key(vertex* element, int index, vertex key)
{
		element[index]= key;
		int index_parent = parent(index);
		while (key.distance < element[index_parent].distance) {
			swap_element(element, index_parent, index);
			index = parent(index);
			index_parent = parent(index);
		} //find the position if increase_key is smaller  than parent. 
		MinHeapify(element, index);
}

int Dijkstra(vector<vector<pair<int, int>>> edge, int number,int edge_num)
{
	int result;
	vertex* element = new vertex[number + 1]; //this is array for storing the 
	element[1] = { 1,0,WHITE };
	for (int i = 2; i <= number; i++) 
		element[i] = { i,INFINITY ,WHITE};
	vertex* heap = new vertex[edge_num+1];
	insert(heap, element[1],element);
	
	for (int i = 1; i <= number; i++) {
		vertex index = ExtractMin(heap);
		while (element[index.node].status != WHITE) {
			index = ExtractMin(heap);					//this prevent extracing the element already blacked.
		}
		if (i != number) {
			for (vector<pair<int, int>>::iterator iter = edge[index.node].begin(); iter != edge[index.node].end(); iter++) {
				if (element[(*iter).first].distance == INFINITY && element[(*iter).first].status == WHITE) {
					element[(*iter).first].distance = (*iter).second + index.distance;
					vertex key = { (*iter).first,(*iter).second + element[index.node].distance,WHITE };
					insert(heap, key, element);
				}
				else if (element[(*iter).first].distance > element[index.node].distance + (*iter).second && element[(*iter).first].status == WHITE) {
					element[(*iter).first].distance = element[index.node].distance + (*iter).second;
					vertex key = { (*iter).first,(*iter).second + element[index.node].distance,WHITE };
					insert(heap, key, element);
				}
			}
		}
		else
			result = element[index.node].distance;
		element[index.node].status == BLACK;
	}
	return result;
}

void MinHeapify(vertex* element, int index) {
	//only left node is only child_node
	if (index == 0)
		return;
	int left_child = left(index);
	int right_child = right(index);
	if (right_child > g_heap_size) { 
		if (element[index].distance >= element[left_child].distance && left_child <= g_heap_size) {
			swap_element(element, left_child, index);
			MinHeapify(element, left_child);
		}
	}
	else {
		if (element[left_child].distance < element[right_child].distance) {
			if (element[index].distance >= element[left_child].distance) {
				swap_element(element, left_child, index);
				MinHeapify(element, left_child);
			}
		}
		else {
			if (element[index].distance >= element[right_child].distance) {
				swap_element(element, right_child, index);
				MinHeapify(element, right_child);
			}
		}
	}
}
void insert(vertex* heap, vertex key,vertex* element)
{
	if (key.status == BLACK)  // it prevent element blacked from inserting the heap. but when the element is blacked,it cannot remove the element being blacked.so i make 72 line code to block.  pulling out elements that are already black.
		return;
	g_heap_size++;
	heap[g_heap_size].distance = -100;
	if (g_heap_size > 1) {
		//cout << "in increase key g_heap size is : " << g_heap_size << endl;
		Increase_key(heap, g_heap_size, key);
	}
	else
		heap[1] = key;
}
vertex ExtractMin(vertex* element)
{
	g_heap_size--;
	vertex result = element[1];
	if (g_heap_size == 0)
		return result;
	else {
		swap_element(element, 1, g_heap_size + 1);
		MinHeapify(element, 1);
		return result;
	}
}