#include "replyAdmin.h"
using namespace std;

char* strConvert(string str) {
    char* cstr = new char[str.length() + 1];
    strcpy(cstr, str.c_str());
    return cstr;
}
int main() {
    bool result;
    ReplyAdmin replyadmin;
    replyadmin.addChat("Hello, Reply  Administrator!");
    replyadmin.addChat("I will be a good programmer.");
    replyadmin.addChat("Professor Lim is wise.");
    replyadmin.addChat("Two TAs are kind and helpful.");
    replyadmin.addChat("I think male TA looks cool.");
    while (true) {
        string input;
        cin >> input;
        if (input.find("#") == 0) {
            if (input.find("#remove") != string::npos) {
                cin >> input;
                if (input.find(",") != string::npos) {
                    int* indices = new int[200];
                    int count = 0;
                    char* cinput = strConvert(input);
                    char* number = strtok(cinput, ",");
                    while (number != NULL) {
                        int index = atoi(number); //  - count; //convert char to int.
                        indices[count] = index;
                        number = strtok(NULL, ","); //I dont know why first parameter must be null
                        count++;
                    }
                    result = replyadmin.removeChat(indices, count); // it does not need to plus 1 on count because last action that count++ is fulfilled.
                    if (result == false)
                        exit(0);
                    replyadmin.printChat();
                }
                else if (int index = input.find("-")) {
                    int count = 0;
                    string sbegin = input.substr(0, index);
                    int begin = atoi(sbegin.c_str());
                    string send = input.substr(index + 1, input.length() - index - 1);
                    int end = atoi(send.c_str());
                    result = replyadmin.removeChat(begin, end);
                    if (result == false)
                        exit(0);
                    replyadmin.printChat();
                }
                else if (isdigit(atoi(input.c_str()))) {
                    int index = atoi(input.c_str());
                    result = replyadmin.removeChat(index);
                    if (result == false)
                        exit(0);
                    replyadmin.printChat();
                }
                else
                    return 0;

            }

            else
                return 0;
        }
        else {
            string all;
            getline(cin, all);
            input += all;
            replyadmin.addChat(input);
            replyadmin.printChat();
        }
    }

    return  0;
}