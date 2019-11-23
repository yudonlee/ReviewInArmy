#pragma once
#ifndef HW_drawingShape_H
#define HW_drawingShape_H
#include <vector>
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
enum { RECTANGLE, TRIANGE_UP, TRIANGLE_DOWN};
enum { ERROR_OUT_OF_CANVAS = -1, ERROR_INVALID_INPUT = -2};
struct Shape {
	int type;
	int x, y;
	int width, height;
	char brush;
};
class Canvas {
public:
	Canvas(size_t row, size_t col);
	~Canvas();
	int AddShape(const Shape& s);
	void DeleteShape(int index);
	void Draw(ostream& os);
	void Dump(ostream& os);
private:
	//char** setResult(char** result, Shape& element);
	size_t row_, col_;
	vector<Shape> shapes_;
};
#endif 