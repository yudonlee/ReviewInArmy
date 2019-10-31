#include "replyAdmin.h"
#include <algorithm>
#include <vector>
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
        cout << i <<" " <<chats[i]<<endl;
    }
}
bool ReplyAdmin::addChat(string _chats){
    int count = getChatCount();
    chats[count] = _chats;
    if(count ==200)
        return false;
    else
        return true;
}
bool ReplyAdmin::removeChat(int _index){
    int count = getChatCount();
    if(chats[_index].empty() == true)
        return false;
    else{
        if(_index == 0){
            if( count == 1)
                  chats[0].clear();
            else{
                  for(int i=0;i<count-1;i++)
                      chats[i]=chats[i+1];
                      chats[count].clear();
                 }
        }
        else{
            if(count == _index-1)
                 chats[_index].clear();
            for(int i=_index;i<count;i++)
                 chats[i]=chats[i+1];
            chats[count].clear();
          
        }
    return true;
    }
}
bool ReplyAdmin::removeChat(int *_indices,int _count){
    vector<int> indices (_indices,_indices + _count);
    sort(indices.begin(),indices.end());
    int count = getChatCount();
    int trials = 0;
    if( count < _count)
           return false;
    else{
        for(int i=0; i<_count;i++){
            if(chats[indices[i]-trials].empty() ==true){
                return false;
            }// {} removed!
            else{
                removeChat(indices[i]-trials);
                trials++;
                /*if(index == 0){
                      if(count == 1)
                             chatList[0].clear();
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
                             chats[indices[i]-trials].clear();  //this is only working when the indices is sorted,so it need indices sorted function.
                trials++; */
            }
                
        }        
    }
    return true;
}
bool ReplyAdmin::removeChat(int _start,int _end){
    int count = getChatCount();
    int trials = 0;
    int start = _start;
    int end = _end;
    if( count < _end - _start + 1)
           return false;
    else
        for(int i=start; i <= end;i++){
            if(chats[i].empty() ==true)
                return false;
            else{
                removeChat(i-trials);
                trials++;
            }
                
        }        
    return true;
}
