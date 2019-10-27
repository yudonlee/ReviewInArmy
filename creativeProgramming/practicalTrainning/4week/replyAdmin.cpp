#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctype.h>
using namespace std;

const int NUM_OF_CHAT = 200;

char* strConvert(string str){
    char* cstr = new char[str.length()+1];
    strcpy(cstr,str.c_str());
    return cstr;
}
int getChatCount(string *_chatList){
    int i;
    for(i=0; i<NUM_OF_CHAT; ++i){
        string s = _chatList[i];
        if(s.empty() == true)
            break;
    }
    return i;
}
void printChat(string *_chatList){
    int count = getChatCount(_chatList);
    
    for(int i = 0;i<count;++i){
        cout << i <<" " <<_chatList[i]<<endl;
    }
}
void initialization(string *_chatList){
    _chatList[0] = "Hello,Reply Adiministrator!";
    _chatList[1] = "I will be a good programmer";
    _chatList[2] = "This class is awesome";
    _chatList[3] = "Profeesor Lim is wise.";
    _chatList[4] = "Two TAs are kind and helpful.";
    _chatList[5] = "I think male TA looks cool.";
    printChat(_chatList);
}
void insertChat(string *_chatList,string input){
    int count = getChatCount(_chatList);
    _chatList[count] = input;
    printChat(_chatList);
    return;
}
void removeChat(string *_chatList,int index){
    int count = getChatCount(_chatList);
    if( count == 0){
        return;
    }
    else{
          string removed = _chatList[index];
          if(removed.empty() == true)
             cout << "The index is not in DB" << endl;
          else{
             if(index == 0){
                 if(count == 1)
                        _chatList[0].clear();
                else{
                    for(int i=0;i<count-1;i++)
                       _chatList[i]=_chatList[i+1];
                       _chatList[count].clear();
                }     
           }
            else{
                if(count == index-1)
                    _chatList[index].clear();
                 for(int i=index;i<count;i++)
                    _chatList[i]=_chatList[i+1];
                 _chatList[count].clear();
                
            }
            
        }
    }
}

int main(int argc,char** argv){
    string chatList[NUM_OF_CHAT];
    initialization(chatList);
    while(true){
        string input;
        cin >> input;
        if(input.find("#") == 0){
            if(input.find("#remove") != string::npos){
                    cin >> input;
                    if(input.find(",") != string::npos){
                        int count = 0;
                        char *cinput = strConvert(input); 
                        char *number =strtok(cinput,",");
                        cout << "number is : " << number <<endl;
                        while( number != NULL){
                            int index = atoi(number) - count; //convert char to int.
                            cout << index <<endl;
                            number = strtok(number,",");    
                            removeChat(chatList,index);
                            count++;
                        }
                        printChat(chatList);
                    }
                    else if(int index = input.find("-")){
                            int count;
                            string sbegin = input.substr(0,index);
                            int begin = atoi(sbegin.c_str());
                            string send = input.substr(index+1,input.length()-index-1);
                            int end = atoi(send.c_str());
                            for(int i=begin; i <= end;i++){
                                removeChat(chatList,i-count);
                                count++;
                            }
                            printChat(chatList);                       
                    }
                    else if(isdigit(atoi(input.c_str()))){
                            int index = atoi(input.c_str()); 
                            removeChat(chatList,index);
                    }
                            
                    else
                        return 0;
                        
           } 
           else if(input.find("#quit") != string::npos)
                    return 0;
                       
        }
        else
            insertChat(chatList,input);
 


    
    }   
   return 0; 

}
