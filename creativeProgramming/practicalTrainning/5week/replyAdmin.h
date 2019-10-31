//replyAdmin.h

#ifndef HW04_replyAdmin_H
#define HW04_replyAdmin_H

#include <iostream>
#include <stdbool.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctype.h>
using namespace std;

const int NUM_OF_CHAT = 200;

class ReplyAdmin{
    private:
        string* chats;
    public:
        ReplyAdmin();
        ~ReplyAdmin();
        
        int getChatCount();
        void printChat();
        bool addChat(string _chat);
        bool removeChat(int _index);
        bool removeChat(int *_indices,int _count);
        bool removeChat(int _start,int _end);      
};

#endif
