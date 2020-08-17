#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct node {
	int parent;
}node;
typedef struct edge {
	int _src;
	int _dest;
	int _weight;
}edge;
bool cmp(const edge & a, const edge & b){
	if (a._weight < b._weight) return true;
	else if (a._weight > b._weight) return false;
	else {
		if (a._src < b._src) return true;
		else if (a._src > b._src) return false;
		else {
			if (a._dest < b._dest) return true;
			else
				return false;
		}
	}
}
int find_set(node* vertex,int number) {
	if (vertex[number].parent == number)
		return number;
	return find_set(vertex, vertex[number].parent);
}
void Union(node* vertex, int src, int dest) {
	int x = find_set(vertex, src);
	int y = find_set(vertex, dest);
	if (x < y)
		vertex[x].parent = y;
	else
		vertex[y].parent = x;
}
void mst_kruskal(node* vertex, vector<edge> edges);
int main() {
	
	node vertex[1001];
	int num_of_vertex;
	cin >> num_of_vertex;
	for (int i = 1; i <= num_of_vertex; i++)
		vertex[i].parent = i;
	int src, dest, weight;
	vector<edge> edges;
	while (scanf("%d %d %d", &src, &dest, &weight) == 3) {
		if (src < dest)
			edges.push_back({ src, dest, weight });
		else
			edges.push_back({ dest,src,weight });
	}
	sort(edges.begin(), edges.end(), cmp);
	mst_kruskal(vertex, edges);
	return 0;
}

void mst_kruskal(node* vertex, vector<edge> edges)
{
	int selected_edge=0;
	vector<edge> result;
	for (vector<edge>::iterator iter = edges.begin(); iter != edges.end(); ++iter) {
		if (find_set(vertex, (*iter)._src) != find_set(vertex, (*iter)._dest)) {
			result.push_back(*iter);
			selected_edge++;
			Union(vertex,(*iter)._src, (*iter)._dest);
		}
	}
	cout << selected_edge << endl;
	for (vector<edge>::iterator iter = result.begin(); iter != result.end(); ++iter) {
		cout << (*iter)._src <<" " <<(*iter)._dest << " "<< (*iter)._weight << endl;
	}
}
