#include "replyAdmin.h"
#include <algorithm>
#include <vector>
using namespace std;
ReplyAdmin::ReplyAdmin() {
}
ReplyAdmin::~ReplyAdmin() {
}
void ReplyAdmin::printChat() {
    int i = 0;
    for (list<string>::iterator itr = chats.begin(); itr != chats.end(); itr++) {
        cout << i++ << " " << *itr << endl;
    }
}
bool ReplyAdmin::addChat(string _chats) {
    chats.push_back(_chats);
    return true;
}
bool ReplyAdmin::removeChat(int _index) {
    int size = chats.size();
    if ( size < _index)
        return false;
    else {
        list<string>::iterator itr = chats.begin();
        advance(itr, _index);
        itr = chats.erase(itr);
        return true;
    }
}
bool ReplyAdmin::removeChat(int* _indices, int _count) {
    vector<int> indices(_indices, _indices + _count);
    sort(indices.begin(), indices.end());
    int trials = 0;
    int size = chats.size();
    if ( size < _count)
        return false;
    else {
        for (int i = 0; i < _count; i++) {
            if (indices[i] - trials > _count == true) 
                return false;
            else {
                removeChat(indices[i] - trials);
                trials++;
     
            }

        }
    }
    return true;
}
bool ReplyAdmin::removeChat(int _start, int _end) {
    int size = chats.size();
    if ( size <= _end)
        return false;
    int trials = 0;
    list<string>:: iterator start = chats.begin();
    list<string>::iterator end = chats.begin();
    advance(start, _start);
    advance(end, _end);
    chats.erase(start, end);
    return true;
}
