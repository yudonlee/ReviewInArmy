#include <iostream>

using namespace std;
int result[1000001];
int sum[1000001];
int Answer;
int cal(int number) {
	if (result[number] == 0) {
		if (number % 2 == 0)
			result[number] = cal(number / 2) + 1; //i want to do this way,but i can't do that. so i refer to the code from https://blog.naver.com/PostView.nhn?blogId=rhkd865&logNo=221837196368.
		else if(number%2 == 1)
			result[number] = cal(number + 1) + 1;
	}
	return result[number];
	
}
int main(int argc, char** argv)
{
	int T, test_case, n1, n2;
	result[1] = 0, result[2] = 1;
	for (int i = 2; i <= 1000001; i++)
		sum[i] = sum[i - 1] + cal(i);
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> n1 >> n2;
		Answer = sum[n2] - sum[n1 - 1];
		cout << "Case #" << test_case + 1 << "\n" << Answer << "\n";
	}
	return 0;//Your program should return 0 on normal termination.
}