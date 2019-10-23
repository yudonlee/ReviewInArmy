#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;
string primeFactorization(unsigned int _number);

int main(int argc,char** argv){
    if(argc <1)
        return -1;
    unsigned int number;
    sscanf(argv[1],"%u",&number);
    cout <<primeFactorization(number) << endl;
    return 0;
}
string primeFactorization(unsigned int _number){
    string result;
    int quoient = 2;
        while(quoient <= _number){
            int count=0;
            while(_number % quoient == 0){
                count++;
                _number /= quoient;
            }
            if(count >0){
                stringstream ss;
                ss << quoient << "^"<<count;
                if(result.empty())
                    result = ss.str();
                else
                    result = result + " x "+ss.str();
            }
                //result = to_string(quoient)+ "^"+ to_string(count);
            count =0;
            quoient++; 
        }    
    return result;
}

