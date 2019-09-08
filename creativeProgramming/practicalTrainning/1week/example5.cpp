#include <iostream>
#include <string>
using namespace std;

int main(){
	int arraySize =10;
	int* a = new int[arraySize]();//init to zero
	int* b = new int[arraySize]{1,2,3,1,2,3,1,2,3,0}; // init in manual
	for(int n = 0; n < arraySize; n++){
		cout << "Index["<<n<<"] Data: "<< a[n] << endl;
		cout << "Index["<<n<<"] Data: "<< b[n] << endl;
		cout<<"--------------------------------------"<<endl;

	}
	return 0;

}
