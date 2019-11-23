#include "drawing_shape.h"
int main() {
	int row, col;
	cin >> row >> col;
	Canvas canvas(row, col);
	int x, y, height, width;
	int deleted_index;
	char brush;
	int judge = 0;
	while (true) {
		string input;
		cin >> input;
		if (input.find("add") != string::npos) {
			cin >> input;
			if (input.find("rect") != string::npos) {
				cin >> x >> y >> width >> height >> brush;
				Shape input = { RECTANGLE,x,y,width,height,brush };
				judge = canvas.AddShape(input);
			}
			else if (input.find("tri_up") != string::npos) {
				cin >> x >> y >> height >> brush;
				Shape input = { TRIANGE_UP,x,y,height*2-1,height,brush }; // width is 2 * height - 1.
				judge = canvas.AddShape(input);
			}
			else if (input.find("tri_down") != string::npos) {
				cin >> x >> y >> height >> brush;
				Shape input = { TRIANGLE_DOWN,x,y,height*2-1,height,brush };
				judge = canvas.AddShape(input);
			}
			else
				cout << "error invalid input" << endl;
		}
		else if (input.find("delete") != string::npos) {
			cin >> deleted_index;
			canvas.DeleteShape(deleted_index);
		}
		else if (input.find("draw") != string::npos)
			canvas.Draw(cout);
		else if (input.find("dump") != string::npos)
			canvas.Dump(cout);
		else if (input.find("quit") != string::npos)
			break;
		else
			cout << "error invalid input" << endl;
		if (judge == ERROR_OUT_OF_CANVAS) {   //this statement is used to judge whether input is error_out_of_canvas or not.
 			cout << "error out of canvas" << endl;
			judge = 0;
		}
		else if (judge == ERROR_INVALID_INPUT) {
			cout << "error invalid input" << endl;
			judge = 0;
		}
	}
}