#include <iostream>
using namespace std;

int main(){
	int iVar = 10;
	float fVar = 10;
	double dVar = 10;
	
	//checking variable size
	cout << "Size of int: " << sizeof(iVar) << endl;
	cout << "Size of float: " << sizeof(fVar) << endl;
	cout << "Size of double: " << sizeof(dVar) << endl;

	cout << "Size of long: " << sizeof(long) << endl;

	return 0;
}
