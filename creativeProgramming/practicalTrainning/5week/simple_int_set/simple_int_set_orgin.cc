#include <string.h>
#include "simple_int_set.h"
using namespace std;
void SimpleIntSet:: sortElements(){
    for(int i=1;i< mElementCount;i++){  
        /*I use insertion sort when i make code in sophomore_2nd_semester algorithm class.it is so slow algorithm,but so simple to use it.       
        */
        int temp =mElements[i];
        int j=i-1;
        while(temp < mElements[j] && j>=0){
            mElements[j+1] =mElements[j];
            --j;
        }
        mElements[j+1]=temp;
    }
}
SimpleIntSet::SimpleIntSet(int *_elements, int _count){
    mElementCount = _count;
    mElements = new int[200];
    for(int i=0; i<_count ; i++)
        mElements[i] = _elements[i];
    sortElements(); // if this function's return type is not void , then i think the code is more simple. but i follow skeletone code.
    int count = mElementCount;
    int trials = 0;        
    for(int i = 0;i<count - trials;i++){
        if(mElements[i] == mElements[i+1]){
            trials++;
            for(int j = i; j < count - trials ; j++)
                mElements[j] = mElements[j+1]; // so if 1 1 2 3 -> 1 2 3 3 the last one is estimated garbage data.
        }
    }
    /* 
    mElementCount = count - trials; //this represent num of element when remove duplicated one.
    int *element = new int[mElementCount];    
    memcpy(element,mElementCount,sizeof(int)*mElementCount);
    mElements = element;
    */
}
int SimpleIntSet::elementCount()const{
    return mElementCount;
}
int* SimpleIntSet:: elements()const{
    /*int count = mElementCount;
    int trials = 0;        
    for(int i = 0;i<count - trials;i++){
        if(mElements[i] == mElements[i+1]){
            trials++;
            for(int j = i; j < count - trials ; j++)
                mElements[j] = mElements[j+1]; // so if 1 1 2 3 -> 1 2 3 3 the last one is estimated garbage data.
        }
    }   
    mElementCount = count - trials; //this represent num of element when remove duplicated one.
   */ 
    return mElements;    
}

SimpleIntSet* SimpleIntSet:: unionSet(SimpleIntSet& _operand){
    cout <<"left set: ";
    this->printSet();
    cout <<"right set: ";
    _operand.printSet();
    int leftCount = mElementCount;
    int rightCount = _operand.elementCount();     //why _operand->elementCount()is errored. because pointer- > , address is .
    int* element = new int[leftCount+rightCount];
    int* left = this->elements();
    int* right = _operand.elements();
    int count = 0;
    if(leftCount > rightCount){
        int i,j;
        for(i=0; i < rightCount; i++){
            for(j=0; j < leftCount; j++){
                if(right[i] > left[j])
                    element[count++] = left[j];
                else{
                    element[count++] = right[j];
                    break;
                }
            }
        }
        if( j < leftCount - 1)
            for( j < leftCount; j++;)
                element[count++] = left[j];
        if( i < rightCount - 1) 
            for( i < rightCount; i++;)
                element[count++] = right[i];
    }
    else{
        int i,j;
        for(i=0; i < leftCount; i++){
            for(j=0; j < rightCount; j++){
                if(left[i] > right[j])
                    element[count++] = right[j];
                else{
                    element[count++] = left[j];
                    break;
                }
            }
        }
        if( j < rightCount - 1)
            for( j < rightCount; j++;) // why j++; ? dont be right just j++?"
                element[count++] = right[j];
        if( i < leftCount - 1) 
            for( i < leftCount; i++;)
                element[count++] = left[i];
    }
    mElements = element;
    mElementCount = count;
    /*cout <<"{ ";
    for(int i = 0; i < count; i++)
        cout << element[i]<< " ";
    cout<<"}"<<endl;
   */
}
SimpleIntSet* SimpleIntSet::differenceSet(SimpleIntSet& _operand){
    int* left = elements();
    int leftCount = elementCount();
    int* right = _operand.elements();
    int rightCount = _operand.elementCount();
    int trials;
    for(int i=0; i < leftCount - trials; i++){
        for(int j = 0; j < rightCount; j++){
            if(left[i] == right[j]){
                for(int k = i; k < leftCount - trials; k++)
                    left[k] = left[k+1];
            }
        }
    }
    mElementCount = leftCount - trials;
    mElements = left;
    /*cout <<"{ ";
    for(int i = 0; i < leftCount - trials; i++)
        cout << left[i]<< " ";
    cout<<"}"<<endl;*/
}
SimpleIntSet* SimpleIntSet:: intersectSet(SimpleIntSet& _operand){
    int max;
    int* left = elements();
    int leftCount = elementCount();
    int* right = _operand.elements();
    int rightCount = _operand.elementCount();
    int count = 0;
    if( leftCount> rightCount)
        max = leftCount;
    else
        max = rightCount;
    int* element = new int[max];
    if(leftCount > rightCount){
        int i,j;
        for(i=0; i < rightCount; i++){
            for(j=0; j < leftCount; j++){
                if(right[i] < left[j])
                    break;
                else if(right[i] == left[j]){
                    element[count++] = right[i];                        
                }
            }
        }
    }
    else{
        int i,j;
        for(i=0; i < leftCount; i++){
            for(j=0; j < rightCount; j++){
                if(left[i] < right[j])
                    break;
                else if(right[j] == left[i]){
                    element[count++] == left[i];
                }
            }
        }
    }
    mElements = element;
    mElementCount = count;
    /*vector<int> result;
    }
    int* left = elements();
    int leftCount = elementCount();
    int* right = _operand.elements();
    int rightCount = _operand.elementCount();
    if(leftCount > rightCount){
        for(int i=0; i < rightCount; i++){
            for(int j = 0; j<leftCount ; j++){
                if(right[i] == left[j]){
                    result.push_back(right[i]);
                    break;
                }
                else if(right[i] < left[j])
                    break;
                else{} //no need to do.
            }
        }
    }
    else
        for(int i=0; i < leftCount; i++){
            for(int j = 0; j<rightCount ; j++){
                if(left[i] == right[j]){
                    result.push_back(left[i]);
                    break;
                }
                else if(left[i] < right[j])
                    break;
                else{} //no need to do.
            }
        }
    cout <<"{ ";
    vector<int>::iterator iter;
    for(iter = result.begin(); iter != result.end(); iter++)
        cout << *iter<< " ";
    cout<<"}"<<endl;
   */
}
SimpleIntSet:: ~SimpleIntSet(){
    delete mElements;
   mElementCount = 0;
}
void SimpleIntSet:: printSet(){
    for(int i=0; i < mElementCount; i++)
        cout<<mElements[i]<<" ";
    cout<<"}"<<endl;
}
