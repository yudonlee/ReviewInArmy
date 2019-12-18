#pragma once
#include <iostream>
#include <vector>
using namespace std;

#define BLACK -1
#define NOBODY 0
#define WHITE 1
#define GROUND_SIZE 19
class Omok {
private:
	size_t width_, height_;
	size_t turn_;
	vector<string> result;
public:
	Omok() :width_(GROUND_SIZE), height_(GROUND_SIZE), turn_(NOBODY) {
		string result_row("");
		for (size_t i = 0; i <= height_; ++i) { // it makes result to be printed.every execution will have different number of row or column,so i use vector string.
			for (size_t j = 0; j <= width_; ++j)
				result_row += ".";
			result.push_back(result_row);
			result_row.clear();
		}
	}
	int put(int x, int y); //if return value is same with previous turn,then it needs to be again. the reason that return value is same is like input x,y is out of range or stone is already there.
	void IsOmok(int* winner, int last_x, int last_y) const; // the meaning of void const method is 2 things. 1st, any variable cannot be changed in this method.2nd,only const method can be called in this method.
	//two lines below are needed to execute operator <<. because operator overloading does not use friend.so ostream cannot access private member varaible.
	//I want to make 2 parameter.the last input in x,y will use to check whether omok or not.because latest omok is the key in winning and if using them, it is more fast to check omok.
	int Turn() const { return turn_; }
	vector<string> Result() const { return result; } // ostream overloading is not usign freind ,so i make a getter for result.
};
ostream& operator<<(ostream& os, Omok& omok);