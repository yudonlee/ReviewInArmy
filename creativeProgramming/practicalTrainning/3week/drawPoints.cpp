#include <iostream>
#include <stdio.h>
#include <stdbool.h>
struct coordinate {
    unsigned int x;
    unsigned int y;
    coordinate* next;
};
using namespace std;

bool exist(coordinate* head,int x,int y){
    while(head != NULL){
        if(x == head->x && y == head->y)
            return true;
        head = head->next;
    }
    return false;
}
int main(int argc,char** argv){
    int xAxis = 0,yAxis=0;
    int inputX,inputY;
    coordinate* head = new coordinate;
    coordinate* tail = head;
    cin >> inputX >> inputY;
    head->x = inputX;
    head->y = inputY;
    while(inputX >=0 && inputY >=0 ){
        if(inputX > xAxis)
            xAxis = inputX;
        if(inputY > yAxis)
            yAxis = inputY;
        for(int i = 0; i<yAxis+1; i++){
            for(int j = 0; j<xAxis+1; j++){
               if(exist(head,j,i))
                    cout<<"*";
               else
                    cout << ".";
            }
            cout << "\n";
        }
        cin >> inputX >> inputY;
        coordinate* newInput = new coordinate;
        newInput->x = inputX;
        newInput->y = inputY;
        tail ->next = newInput;
        tail = tail->next;
        
    }
    return 0;    

}
