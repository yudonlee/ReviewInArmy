#pragma once
#include <string>
using namespace std;
#ifndef _GRADER_H
#define _GRADER_H

class SubjectPassFail {
public:
	SubjectPassFail(string _name, int _credit, int _pass_cut);
	string GetGrade(int score);
	int credit();
private:
	string name;
	int sub_credit;
	int pass_cut;
	string grade;
};

class SubjectGrade {
public:
	SubjectGrade(string _name, int _credit, int _a_cut,int _b_cut, int _c_cut,int _d_cut);
	string GetGrade(int score);
	int credit();
private:
	string name;
	int sub_credit;
	string grade;
	int a_cut, b_cut, c_cut, d_cut;
};



#endif // !_GRADER_H
