#include <iostream>
#include <stdio.h>
using namespace std;
int matrix_chain_multiplication(int* matrix, int scalar, int** min, int** slice);
void print_parenthesis(int i,int j, int** slice);
int main() {
	int scalar, * matrix;
	int** min, ** slice;
	cin >> scalar;
	min = new int* [scalar + 1], slice = new int* [scalar + 1];
	for (int i = 0; i <= scalar; i++) {
		min[i] = new int[scalar + 1];
		slice[i] = new int[scalar + 1];
		min[i][i] = 0, slice[i][i] = i;
	}
	matrix = new int[scalar + 1];
	for (int i = 0; i <= scalar; i++)
		cin >> matrix[i];
	int result = matrix_chain_multiplication(matrix, scalar, min, slice);
	cout << result << endl;
	print_parenthesis(1,scalar, slice);
}

int matrix_chain_multiplication(int* matrix, int scalar, int** min, int** slice)
{
	for (int j = 1; j <= scalar; j++) {
		for (int i = j-1; i > 0; i--) {
			int min_multi = min[i][i] + min[i + 1][j] + (matrix[i - 1] * matrix[i] * matrix[j]);
			int slice_index = i;
			for (int k = 1; k < j - i; k++) {
				if (min_multi > min[i][i + k] + min[i + k + 1][j] + (matrix[i - 1] * matrix[i + k] * matrix[j])) {
					min_multi = min[i][i + k] + min[i + k + 1][j] + (matrix[i - 1] * matrix[i + k] * matrix[j]);
					slice_index = i + k;	
				}
			}
			min[i][j] = min_multi;
			slice[i][j] = slice_index;
		}
	}
	return min[1][scalar];
}

void print_parenthesis(int i,int j, int** slice)
{	
	if (i != j) {
		cout << "(" <<" ";
		print_parenthesis(i, slice[i][j], slice);
		print_parenthesis(slice[i][j]+1, j, slice);
		cout << ")" <<" ";
	}
	else {
		cout << i <<" ";
	}
}
