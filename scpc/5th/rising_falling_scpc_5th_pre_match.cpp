#include <iostream>
using namespace std;
int Answer;
int cal(int* result, int number, int answer) {
	if (result[number] != 0)
		return result[number]+answer;
	else {
		if (number == 1)
			return answer;
		else if (number % 2 == 0) {
			number /= 2;
			return cal(result, number, answer + 1);
		}
		else if (number != 1 && number % 2 == 1) {
			number += 1;
			return cal(result, number, answer + 1);
		}
	}
}
int main(int argc, char** argv)
{
	int T, test_case;
	
	cin >> T;
	int result[1000001] = { 0, };
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		int n1, n2;
		cin >> n1 >> n2;
		if (n1 % 2 == 0) {
			for (int i = n1; i <= n2; i += 2) {
				int add = cal(result, i, 0);
				result[i] = add;;
				Answer += add;
			}
			for (int i = n1 + 1; i <= n2; i += 2) {
				int add = cal(result, i, 0);
				result[i] = add;;
				Answer += add;
			}
		}
		else {
			for (int i = n1 + 1; i <= n2; i += 2) {
				int add = cal(result, i, 0);
				result[i] = add;;
				Answer += add;
			}
			for (int i = n1; i <= n2; i += 2) {
				int add = cal(result,i, 0);
				result[i] = add;;
				Answer += add;
			}
		}
		/*if (n1 % 2 == 0) {
			for (int i = 0; i <= (n2-n1)/2; i++) {
				int add =  cal(result,n1+i,0);
				result[i] = add;;
				Answer += add;
			}
			for (int i = 1; i <= (n2 - n1) / 2; i++) {
				int add = cal(result, n1 + i, 0);
				result[i] = add;;
				Answer += add;
			}
		}
		else {
			for (int i = 1; i <= (n2 - n1) / 2; i++) {
				int add = cal(result, n1 + i, 0);
				result[i] = add;;
				Answer += add;
			}
			for (int i = 0; i <= (n2 - n1) / 2; i++) {
				int add = cal(result, n1 + i, 0);
				result[i] = add;;
				Answer += add;
			}

		}*/
		 /////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}