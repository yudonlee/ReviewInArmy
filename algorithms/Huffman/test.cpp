//The reason I put this file in here together is because I realized the answer to fixing the fatal mistake I made when I was doing the huffman.
#include <stdio.h>
#include <iostream>
using namespace std;
void check(){
	for(int i =1; i<10;i++){
		int test;
		test = i;
		int* test1;
		test1 = new int(test);
		cout << i <<"th address is: "<<&test<<endl; 
		cout <<i<<"th address is:"<<test1<<endl;
		cout <<i<<"th test1 value: "<<*test1<<endl;
	}
}
int main(){
	check();
return 0;

}

