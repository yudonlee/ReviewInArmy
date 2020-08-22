#include <iostream>
#include <algorithm>

using namespace std;

int Answer;
int min(int* A, int* B, int N, int K);

int main(int argc, char** argv)
{
	int T, test_case, N, K;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> N >> K;
		int* A = new int[N];
		int* B = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> B[i];
		}
		sort(A, A + N), sort(B, B + N);
		cout << "Case #" << test_case + 1 << endl;
		cout << min(A,B,N,K) << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}

int min(int* A, int* B, int N, int K)
{
	int m_of_M = A[0] + B[K-1];
	if (K == 1)
		return m_of_M;
	else {
		for (int i = 1; i < K; i++) {
			int M = A[i] + B[K - i-1];
			if (m_of_M < M)
				m_of_M = M;
		}
		return m_of_M;
	}
}