#include <iostream>
using namespace std;

int main(){
	int a  = 10;

	cout << "Result: " << ++a << endl;
	cout << "Result: " << a++ << endl;
	// both of them results in 11.because  operator precedence of increment is more important than left shift 
	return 0;
}
