#include "point2d.h"
using namespace std;
Point::Point() {
	x_ = 0, y_ = 0;
};

/*explicit Point::Point(int c): x_(c),y_(c) {
 this statement can make error,but  i don't know why definition in source code make error  though I only declare function in header in build process .
}*/
Point::Point(int x, int y) {
	x_ = x;
	y_ = y;
}
Point operator+(const Point& lhs, const Point& rhs) {
	Point result;
	result.x_ = lhs.x_ + rhs.x_;
	result.y_ = lhs.y_ + rhs.y_;
	return result;
}
Point operator-(const Point& lhs, const Point& rhs) {
	Point result;
	result.x_ = lhs.x_ - rhs.x_;
	result.y_ = lhs.y_ - rhs.y_;
	return result;
}
Point operator*(const Point& lhs, const Point& rhs) {
	Point result;
	result.x_ = lhs.x_ * rhs.x_;
	result.y_ = lhs.y_ * rhs.y_;
	return result;
}
void eval(Point* lhs_, Point* rhs_, char oper) {
	Point result;
	switch (oper) {
	case '+':
		result = (*lhs_) + (*rhs_);
		break;
	case '-':
		result = (*lhs_) - (*rhs_);
		break;
	case '*':
		result = (*lhs_) * (*rhs_);
		break;
	default:
		cout << "input error so no result get in." << endl;
		return;
		break; //it doesn't be needed, but i just write it.
	}
	cout << "(" << result.x_ << ", " << result.y_ << ")" << endl;
}