#include <iostream>
#include <stdio.h>
using namespace std;
string print_test(){
	string result = "afffd";
	return result;
}
char* print_test_char(){
	char* result = (char*)"test test"; //C and C++ differ in type of the string liteal.A conversion from const char* and char* is generally not possible without an explicit cast for safety reasons. 
// first answer by https://stackoverflow.com/questions/1524356/c-deprecated-conversion-from-string-constant-to-char  
//	char* result = new char("aaafsf");
	return result;
}
int main(){
	string test;
	char* test_char;
	test = print_test();
	test_char = print_test_char();
	cout << test<<endl;
	cout << test_char<<endl;
	return 0;
}
