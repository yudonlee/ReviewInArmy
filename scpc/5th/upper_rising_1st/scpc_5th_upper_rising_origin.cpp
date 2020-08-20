#include <iostream>

using namespace std;
int result[100001];
int sum[100001];
int Answer;
int cal(int number, int add) {
	if (number == 1) {
		return add;
	}
	else if (result[number] != 0)
		return result[number] + add;
	else if (number % 2 == 0) {
		return cal((number / 2), ++add);
	}
	else if (number % 2 == 1)
		return cal((number + 1), ++add);
}
int main(int argc, char** argv)
{
	int T, test_case, A, n1, n2;
	result[1] = 0, result[2] = 1;
	sum[0] = 0, sum[1] = 0;
	cin >> T;
	for (int i = 1; i <= 100000; i++)
		sum[i] = sum[i - 1] + cal(i, 0);
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> n1 >> n2;
		Answer = sum[n2] - sum[n1 - 1];
		cout << "Case #" << test_case + 1 << "\n";
		cout << Answer << "\n";
	}
	return 0;//Your program should return 0 on normal termination.
}