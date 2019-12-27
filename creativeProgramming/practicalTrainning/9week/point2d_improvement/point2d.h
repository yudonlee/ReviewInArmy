#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
enum flag {
	INIT,
	MINUS,
	PLUS,
	INTEGER,
};
struct Point {
	int x_, y_;
	Point();
	explicit Point(int c) : x_(c), y_(c) {}
	Point(int x, int y);
};
Point operator+(const Point& lhs, const Point& rhs);
Point operator-(const Point& lhs, const Point& rhs);
Point operator*(const Point& lhs, const Point& rhs);
void eval(Point* lhs_, Point* rhs_, char oper);
