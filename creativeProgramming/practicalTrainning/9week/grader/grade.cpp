#include "grader.h"
#include <string>
using namespace std;
SubjectPassFail::SubjectPassFail(string _name, int _credit, int _pass_cut) {
	name = _name;
	sub_credit = _credit;
	pass_cut = _pass_cut;
}
string SubjectPassFail::GetGrade(int score) {
	if (score  >= pass_cut)
		return "P";
	else
		return "F";
}
int SubjectPassFail::credit() {
	return sub_credit;
}
SubjectGrade::SubjectGrade(string _name, int _credit, int _a_cut, int _b_cut, int _c_cut, int _d_cut) {
	name = _name;
	sub_credit = _credit;
	a_cut = _a_cut;
	b_cut = _b_cut;
	c_cut = _c_cut;
	d_cut = _d_cut;
}
string SubjectGrade::GetGrade(int score) {
	if (score >= a_cut)
		return "A";
	else if (score >= b_cut)
		return "B";
	else if (score >= c_cut)
		return "C";
	else if (score >= d_cut)
		return "D";
	else
		return "F";

}
int SubjectGrade::credit() {
	return sub_credit;
}
