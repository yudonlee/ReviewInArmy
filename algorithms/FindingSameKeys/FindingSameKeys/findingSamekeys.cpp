#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int main(){
    vector<int> keys(100000, 0);
    int size1 = 0,size2 = 0,input,sameKeys = 0;
    cin >> size1 >> size2;
    for (int i = 0; i < size1; i++) {
        cin >> input;
        if (input < 1)
            cout << "input is must be bigger than 0";
        else {
            keys[input + 1]++; //sets do not allow duplicate values.therefore, this mechanism is not a problem.
            if (keys[input + 1] > 1)
                sameKeys++;
        }
    }
    for (int i = 0; i < size2; i++) {
        cin >> input;
        if (input < 1)
            cout << "input is must be bigger than 0";
        else {
            keys[input + 1]++;
            if (keys[input + 1] > 1)
                sameKeys++;
        }
    }
    cout << sameKeys << endl;
    return 0;
}