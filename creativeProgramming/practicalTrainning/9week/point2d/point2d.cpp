#include "point2d.h"
Point::Point() {
	x_ = 0, y_ = 0;
};

/*explicit Point::Point(int c): x_(c),y_(c) { //eval�Ҷ� �׳� ���ڸ����͵� �Ǿ��ϴϱ�

}*/
Point::Point(int x, int y){
	x_ = x;
	y_ = y;
}
Point::Point(int x,const Point& p) { //�̰� -x�϶� ���ο�� ���� lhs�γ־�����ؼ��׷���.
	std ::cout << "call the generator" << std ::endl;
	x_ = -1 * p.x_;
	y_ = -1 * p.y_;
}
Point operator+(const Point& lhs, const Point& rhs) {
	Point result;
	std::cout << "lhs x y " << lhs.x_ << lhs.y_ << " rhs x y" << rhs.x_ << rhs.y_ << "\n";
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