#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
struct multiple_lcs {
	int length;
	int prev_x; // previous x coordinate
	int prev_y; //previous y coordinate
};
multiple_lcs max(int up_length, int left_length, int x, int y);
string longest_common_subsequence(string x_axis, string y_axis);
int main() {
	string result;
	string input1, input2;
	cin >> input1 >> input2;
	//sort(input1.begin(), input1.end());
	input1 = " " + input1;
	input2 = " " + input2;
	//sort(input2.begin(), input2.end());
	if (input1.size() >= input2.size())
		result = longest_common_subsequence(input1, input2);
	else
		result = longest_common_subsequence(input2, input1);
	cout << result << endl;
	return 0;
}

multiple_lcs max(int up_length, int left_length, int y, int x)
{
	multiple_lcs result;
	if (up_length >= left_length) {
		result.length = up_length;
		result.prev_x = x;
		result.prev_y = y - 1;
	}
	else
	{
		result.length = left_length;
		result.prev_x = x - 1;
		result.prev_y = y;
	}
	return result;
}

string longest_common_subsequence(string x_axis, string y_axis){
	string result;
	vector<vector<multiple_lcs> > lcs(y_axis.size() + 1, vector<multiple_lcs>(x_axis.size() + 1));
	for (int i = 0; i < y_axis.size(); i++) {
		for (int j = 0; j < x_axis.size(); j++) {
			if (i == 0 || j == 0){
				lcs[i][j].length = 0;
				lcs[i][j].prev_x = 0;
				lcs[i][j].prev_y = 0;
			}
			if ((x_axis[j] == y_axis[i]) && (i > 0 && j > 0))
			{
				lcs[i][j].length = lcs[i - 1][j - 1].length + 1;
				lcs[i][j].prev_x = j - 1;
				lcs[i][j].prev_y = i - 1;
			}
			if ((i > 0 && j > 0) && (x_axis[j] != y_axis[i]))
				lcs[i][j]= max(lcs[i - 1][j].length, lcs[i][j - 1].length,i,j);
			}
	}
	int y = y_axis.size()-1;
	int x = x_axis.size()-1;
	int index_x;
	int index_y;
	while ((x>0 && y>0)) {
		if (x_axis[x] != y_axis[y]) {
			index_x = x, index_y = y; // Without this statement, There was an error because the y value received the previous y coordinate after x value is changed!
			x = lcs[index_y][index_x].prev_x;
			y = lcs[index_y][index_x].prev_y;
		}
		else if(x_axis[x] == y_axis[y] ){
			result = x_axis[x] + result;
			index_x = x, index_y = y; // Without this statement, There was an error because the y value received the previous y coordinate after x value is changed!
			x = lcs[index_y][index_x].prev_x;
			y = lcs[index_y][index_x].prev_y;
		}
	}
	return result;
}
