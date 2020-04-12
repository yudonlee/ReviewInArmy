#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#define BLACK 2
#define GRAY 1
#define WHITE 0
using namespace std;
int Topological_sort(int number, vector<vector<int>> edge);
int Dfs(int number, vector<vector<int>> edge);
void Dfs_visit(int vertex, int group_num, vector<vector<int>> edge);
int indegree_array[1001] = { 0, };
int visit[1001] = { 0, };
int main() {
	int x, y, number;
	cin >> number;
	vector<vector<int>> edge(number + 1);
	while (scanf("%d %d", &x, &y) == 2){
		edge[x].push_back(y);
		indegree_array[y]++;
	}
	for (int i = 1; i <= number; i++) {
		sort(edge[i].begin(), edge[i].end());
	}
	int dag_flag = Topological_sort(number, edge);
	if (dag_flag == 0) 
		cout << dag_flag<< endl; //dag not not is dag .
	else{
		cout << dag_flag<< endl;
		for (int i = 1; i <= number; i++)
			cout << indegree_array[i] << " ";
		cout << endl;
	}
	return 0;
}

int Topological_sort(int number, vector<vector<int>> edge)
{
	stack<int> stack;
	vector<int> result; 
	int index = 1;
	int dag_flag = Dfs(number, edge);
	if (dag_flag == 0)
		return 0;
	for (int i = 1; i <= number; i++)
		if (indegree_array[i] == 0)   //push the element whose indegree is 0 to the stack.
			stack.push(i);
	while (!stack.empty()) {
		int vertex = stack.top(); //get the vertex on the top of stack.
		stack.pop(); //if stack is not poped, then top is not removed forever. stack member function "top" cannot remove the element. only return stack's top one.
		result.push_back(vertex);
		for (vector<int>::iterator iter = edge[vertex].begin(); iter != edge[vertex].end(); iter++) {
			indegree_array[(*iter)]--; 
			if (indegree_array[(*iter)] == 0) 
				stack.push((*iter));
		}
		
	}
	for (vector<int>::iterator iter = result.begin(); iter != result.end(); iter++){
		indegree_array[index++] = *iter; // i reuse indegree_array for printing result. 
	}
	return dag_flag;
}

int Dfs(int number, vector<vector<int>> edge)
{
	int group_num = 0;
	for (int i = 1; i <= number; i++) {
		if (visit[i] == WHITE) {
			group_num++;
			Dfs_visit(i, group_num, edge);
		}
	}
	if (group_num == 1)
		return 0;
	else
		return 1;
}

void Dfs_visit(int vertex, int group_num, vector<vector<int>> edge)
{
	visit[vertex] = GRAY;
	for (vector<int>::iterator iter = edge[vertex].begin(); iter != edge[vertex].end(); iter++) {
		if (visit[(*iter)] == WHITE) 
			Dfs_visit(*iter, group_num, edge);
	}
	visit[vertex] = BLACK;

}
