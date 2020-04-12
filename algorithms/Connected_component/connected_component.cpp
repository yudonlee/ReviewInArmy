#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define BLACK 2
#define GRAY 1
#define WHITE 0
using namespace std;
struct vertex {
	int group = 0;
	int visit = WHITE;
};
int Connected_component(int number, vector<vector<int>> edge);
void Dfs(int number,int group_num, vector<vector<int>> edge);
void Dfs_visit(int vertex, int group_num,vector<vector<int>> edge);
vertex list[1000];

int main() {
	int x, y, number;
	cin >> number;
	vector<vector<int>> edge(number + 1);
	int index = 0;
	while (scanf("%d %d", &x, &y)==2)
		edge[x].push_back(y);
	for (int i = 1; i <= number; i++)
		sort(edge[i].begin(), edge[i].end());
	int result = Connected_component(number, edge);
	cout << result << endl;
	for (int i = 1; i <= number; i++)
		cout << list[i].group << endl;
	return 0;
}

int Connected_component(int number, vector<vector<int>> edge)
{
	int group_num = 0;
	for (int i = 1; i <= number; i++) {
		if(list[i].visit == WHITE){
			group_num++;
			Dfs_visit(i, group_num, edge);
		}

	}
	return group_num;
}

void Dfs_visit(int vertex, int group_num, vector<vector<int>> edge)
{
	list[vertex].group = group_num;
	list[vertex].visit = GRAY;
	for (vector<int>::iterator iter = edge[vertex].begin(); iter != edge[vertex].end(); iter++) {
		if (list[(*iter)].visit == WHITE) {
			list[(*iter)].group = group_num;
			Dfs_visit(*iter, group_num, edge);
		}
	}
	list[vertex].visit = BLACK;

}
