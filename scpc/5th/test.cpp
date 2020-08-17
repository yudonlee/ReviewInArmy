#include <iostream>
using namespace std;
int main(int argc, char** argv)
{
	int n1,n2;	
	cin >> n1 >> n2;
	if (n1 % 2 == 0) {
		for (int i = n1; i<=n2; i+=2) {
			cout <<"number is: "<<i<<endl;
		}
		for (int i = n1+1; i<=n2; i+=2) {
			cout <<"number is: "<<i<<endl;
		}
	}
		else {
		for (int i = n1; i<=n2; i+=2) {
			cout <<"number is: "<<i<<endl;
		}
		for (int i = n1+1; i<=n2; i+=2) {
			cout <<"number is: "<<i<<endl;
		}
		}	
	return 0;//Your program should return 0 on normal termination.
}
