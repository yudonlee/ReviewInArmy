// radixNotation.cpp
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
string RadixNotation(unsigned int number,unsigned int radix);

int main(int argc,char** argv){
	if(argc <2)
    	return -1;
    unsigned int radix;
    sscanf(argv[1],"%u",&radix);

    if(radix <2 || radix > 36)
        return -1;
    
    for(int i = 2;i < argc ; ++i){
        unsigned int number;
        sscanf(argv[i],"%u",&number);
        cout << RadixNotation(number, radix)<< endl;
    }
    return 0;
}

string RadixNotation(unsigned int number,unsigned int radix){
    string remainder = "0123456789abcdefghijklmnopqrstuvwxyz";
    string result;
    int remain;
    while(number > radix){
        remain = number % radix;
        number /= radix;
        string prevNum = remainder.substr(remain,1); 
        result =  prevNum+ result;
    }
    result = remainder.at(number) + result;
    return result;
}
