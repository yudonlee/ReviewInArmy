#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
struct Point {
	int x_, y_;
	Point();
	Point(int x,const Point& p);
	explicit Point(int c) : x_(c), y_(c) {}
	Point(int x, int y);
};
Point operator+(const Point& lhs, const Point& rhs);
Point operator-(const Point& lhs, const Point& rhs);
Point operator+(const Point& lhs, const Point& rhs);