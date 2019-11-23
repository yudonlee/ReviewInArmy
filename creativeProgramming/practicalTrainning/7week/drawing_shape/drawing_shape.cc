#include "drawing_shape.h"

Canvas::Canvas(size_t row, size_t col) {
	row_ = row; 
	col_ = col;
	Draw(cout);
}
Canvas::~Canvas() {
	}
int Canvas::AddShape(const Shape& s) {
	if (s.width % 2 == 0 || s.height <= 1) { // Error when  width is even number or height is less than 1.
		return ERROR_INVALID_INPUT;
	}
	if (s.type == RECTANGLE) { 
		if (s.x + s.width / 2 <= col_ && s.y + s.height / 2 <= row_ && s.x - s.width / 2 >= 0 && s.height - s.y / 2 >= 0)  //if width or height is out of range in Canvas, then Error will occur. if문에 왜 안들어가냐 1이 리턴되는데 ㅅㅂ 다시해볼것
			shapes_.push_back(s);
		else
			return ERROR_OUT_OF_CANVAS;

	}
	else if (s.type == TRIANGE_UP) { 
		if (s.x + s.width/2 - 1 <= col_ && s.x - s.width / 2 - 1 >= 0 && s.y + s.height - 1 <= row_) // Checking width or height whether out of range in Canvas
			shapes_.push_back(s);
		else
			return ERROR_OUT_OF_CANVAS;

	}
	else if (s.type == TRIANGLE_DOWN) {
		if ((s.x + s.width/2) - 1 <= col_ &&  s.x - s.width/2 - 1 >= 0 &&  s.y - s.height +1 >= 0) // Checking width or height whether out of range in Canvas
			shapes_.push_back(s);
		else
			return ERROR_OUT_OF_CANVAS;

	}
	else //if type is not matching enum,then input will cause error.so we take this variable.
		return ERROR_INVALID_INPUT;
	return shapes_.size();
}
void Canvas::DeleteShape(int index) {
	if(shapes_.size() > index)
		shapes_.erase(shapes_.begin() + index);
}
void Canvas::Draw(ostream& os) {
	vector<string> result;
	string result_row("");
	for (size_t i = 0; i <= col_; ++i) { // it makes result to be printed.every execution will have different number of row or column,so i use vector string.
		for (size_t j = 0; j <= row_; ++j)
			result_row += ".";
		result.push_back(result_row);
		result_row.clear();
	}
	for (int i = 0; i < shapes_.size(); i++) {
		int count = 0;
		if (shapes_[i].type == RECTANGLE) { //starting point of x or y in rectangle are left the lower left corner.ending point are the right the higher right corner.
			int x_start_point = shapes_[i].x - (shapes_[i].width / 2);  
			int x_end_point = shapes_[i].x + (shapes_[i].width / 2);
			int y_start_point = shapes_[i].y - (shapes_[i].height / 2);
			int y_end_point = shapes_[i].y + (shapes_[i].height / 2);
			for (int cy = y_start_point; cy <= y_end_point; cy++)
				for (int cx = x_start_point; cx <= x_end_point; cx++)
					result[cy][cx] = shapes_[i].brush;
		}
		else if (shapes_[i].type == TRIANGE_UP) //starting point in x or y is the leftmost point on the underside of the triangle.ending point is most highest point of vertex in triangle.
			for (int cy = shapes_[i].y; cy <= shapes_[i].y + shapes_[i].height - 1; cy++, count++)
				for (int cx = shapes_[i].x - count; cx <= shapes_[i].x + count; cx++) 
					result[cy][cx] = shapes_[i].brush;
		else
			for (int cy = shapes_[i].y; cy >= shapes_[i].y - shapes_[i].height + 1; cy--, count++) // the starting point in x or y is the leftmost point on the upperside of the triangle.ending point is most lowest point of vertex in triangle.
				for (int cx = shapes_[i].x - count; cx <= shapes_[i].x + count; cx++) 
					result[cy][cx] = shapes_[i].brush;
	}
	os << " ";
	for (int i = 0; i < col_; i++)
		os << i % 10; //we need only figure.
	for (int i = 0; i < row_; i++) {
		os << "\n";
		os << i % 10;
		for (int j = 0; j < col_; j++)
			os << result[i][j];
	}
	os << endl;
}
void Canvas::Dump(ostream& os) {
	os << "dump\n";
	for (int i = 0; i < shapes_.size(); i++) {
		os << i;
		if (shapes_[i].type == RECTANGLE) 
			os << " rect " << shapes_[i].x << " " << shapes_[i].y << " " << shapes_[i].width << " " << shapes_[i].height << " " << shapes_[i].brush << endl;
		else if (shapes_[i].type == TRIANGE_UP)
			os << " tri_up " << shapes_[i].x << " " << shapes_[i].y << " " << shapes_[i].height << " " << shapes_[i].brush << endl;
		else 
			os << " tri_down " << shapes_[i].x << " " << shapes_[i].y << " "  << shapes_[i].height << " " << shapes_[i].brush << endl;
	}
}
   