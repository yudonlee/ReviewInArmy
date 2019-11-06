#include "binary_search.h"
#include <iostream>
#include <string.h>
void BinarySearch::sortArray(){
    for(int i = 1 ; i < mArrayCount; i++){
        int temp = mArray[i];
        int j = i - 1;
        while(temp < mArray[j] && j >= 0){
            mArray[j+1] =mArray[j];
            j--;
        }
        mArray[j+1] = temp;
    }
}

BinarySearch::BinarySearch(int *_array,int _arrayCount){
    mArray = new int[_arrayCount]; //does it need to be allocated? memcpy i cannot sure.
    /*for(int i = 0; i < _arrayCount;i++)
        mArray[i] = _array[i]; // prevent shallow copy.
    */
    memcpy(mArray,_array,sizeof(int)*_arrayCount);
    mArrayCount = _arrayCount;
    sortArray();
}
BinarySearch::~BinarySearch(){
    delete mArray;
    mArrayCount = 0;
}
int BinarySearch::getIndex(int _element){
    int m, L = 0,R = mArrayCount - 1;
    while( L  <= R ){
       m = L + R / 2;
       if(mArray[m] < _element)
           L = m + 1;
       else if ( mArray[m] > _element)
           R = m - 1;
       else
           return m;
    }
    return -1;
}

