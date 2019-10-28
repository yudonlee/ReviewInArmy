#include "replyAdmin.h"
using namespace std;
ReplyAdmin:: ReplyAdmin(){
    chats = new string[200];
}
ReplyAdmin::~ReplyAdmin(){
    delete chats;
}
int ReplyAdmin::getChatCount(){
    int i;
    for(i=0; i<NUM_OF_CHAT; ++i){
    if(chats[i].empty() == true)
        break;
    }
    return i; 
}

void ReplyAdmin::printChat(){
    int count = getChatCount();
    for(int i = 0;i<count;++i){
        cout << i <<" " <<chat[i]<<endl;
    }
}
bool ReplyAdmin::addChat(string _chats){
    int count = getChatCount();
    chats[count] = _chat;
    printChat();
    if(count ==200)
        return false;
    else
        return true;
}
bool ReplyAdmin::removeChat(int _index){
    if(chats[i].empty() == true)
        return false;
    else{
        chats[i].clear();
        return true;
    }
}
bool removeChat(int *_indices,int _count){
    int count = getChatCount();
    int trials = 0;
    if( count < _count)
           return false;
    else{
        for(int i=0; i<_count;i++){
            if(chats[_indices[i]-trials].empty() ==true)
                return false;
            else{
                chats[_indices[i]-tirals].clear();  //this is only working when the indices is sorted,so it need indices sorted function.
                trails++;
            }
                
        }        
    }
    return true;
}
bool removeChat(int _start,int _end){
    int count = getChatCount();
    int trials = 0;
    int start = _start;
    int end = _end;
    if( count < _end - _start + 1)
           return false;
    else
        for(int i=start; i=<end;i++){
            if(chats[i].empty() ==true)
                return false;
            else{
                chats[i-trials].clear();
                trials++;
            }
                
        }        
    return true;
}
