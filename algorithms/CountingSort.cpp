#include <iostream>
#include <stdio.h>
using namespace std;
int* Counting(int* array, int range, int number,int* left,int* right,int query);
void result(int* counting_array, int* left, int* right, int query);
int main() {
	int* left, *right;
	int* input;
	int number;
	int range;
	int query_range;
	cin >> number >> range >> query_range;
	left = new int[query_range + 1];
	right = new int[query_range +1];
	input = new int[number];
	for (int i = 0; i < query_range; i++)
		cin >> left[i] >> right[i];
	for (int i = 0; i <number; i++)
		cin >> input[i];
	int* result = Counting(input, range, number,left,right,query_range);
	for (int i = 0; i < number; i++)
		cout << result[i] << " ";
	delete[] left, right, input;
	return 0;
}

int* Counting(int* input, int range, int number,int* left,int* right,int query)
{
	int* counting_array = new int[range+1];
	int* sorted_array = new int[number];
	for (int i = 0; i < number; i++)
		sorted_array[i] = 0;
	for (int i = 0; i <= range; i++)
		counting_array[i] = 0;
	for (int i = 0; i < number; i++)
		counting_array[input[i]]++;
	for (int i = 1; i <= range;i++)
		counting_array[i] = counting_array[i] + counting_array[i - 1];
	result(counting_array, left, right, query);
	for (int i = number-1; i >= 0; i--) {
		sorted_array[counting_array[input[i]]-1] = input[i];
		counting_array[input[i]]--;
	}
	/*for (int i = 0; i < number; i++)
		cout << sorted_array[i] << " ";
	cout << endl;
	*/
	return sorted_array; //왜여기서 input이 변경되지 않는거지.? 멤버변수이기 때문에 값을 넘겨준다는것이 성립이 되지 않는다.!************ 알던것임에도 제대로 인지하지 못했음.
}

void result(int* counting_array, int* left, int* right, int query)
{
	int alpha = 0;
	for (int i = 0; i < query; i++) {
		if (left[i]>0&&counting_array[left[i]] - counting_array[left[i]-1] != 0)
			cout << counting_array[right[i]] - counting_array[left[i]] + 1<< endl;
		else
			cout << counting_array[right[i]] - counting_array[left[i]] << endl;
	}
}
