#include "point2d.h"
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	vector<pair<Point, string>> data;
	string mode, var, lhs, rhs;
	char oper;
	while (true) {
		cout << "\n\nthis program is '2D point class'" << endl;
		cout << "program has three mode. 1.set 2.eval 3.quit" << endl;
		cout <<"set Var X Y.if you want to set then you type in variable stored in value, then you input x and y(x,y must be integer!)"<<endl;
		cout << "if you want x is equal to y then you only type in one value just like : set Var X" << endl;
		cout << "if variable in set cannot be durable,so only first varaible can be alive(although duplicated variable is input,the program don't notice aobut that." << endl;
		cout << "eval Var1 operator Var2.operator can work three mode( '*','+','-')"<<endl;
		cout<<"if you want to evaluate variable to variable.or not you can type in integer to integer like :eval integer operator operator,integer to varaible like: eval varaible opertaor integer" << endl;
		cout << "you can just like that: eval x + y ,eval x - y, eval x * y, eval x - -y,eval x + 3(vice versa)" << endl;
		cout << "if you want to quit this program,then only type in 'quit'\n\n";
		cin >> mode;
		if (mode.find("set") != string::npos) {
			string var;
			string y_;
			int x = INIT, y = INIT;
			cin >> var >> x;
			if (cin.fail()) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "input error" << endl;

			}
			else {
				getline(cin, y_);
				y_.erase(remove(y_.begin(), y_.end(), ' '), y_.end());  //this line remove space so if input is " 3  4 5 " ,then return value is 345. 
				if (y_ == "") { //this case is that parameter is only 1.
					Point input(x);
					data.emplace_back(make_pair(input, var));
				}
				else {
					if (atoi(y_.c_str()) != 0 || lhs == "0") { // y_ is string so we have to check whether string is integer or not.
						y = stoi(y_);
						Point input(x, y);
						data.emplace_back(make_pair(input, var));
					}
					else
						cout << "input error" << endl;
				}
			}
		}
		else if (mode.find("eval") != string::npos) {
			cin >> lhs >> oper >> rhs;
			Point* lhs_;
			Point* rhs_;
			Point result;
			int l_flag = INIT, r_flag = INIT;
			vector<pair<Point, string>>::iterator l_it = data.begin();
			vector<pair<Point, string>>::iterator r_it = data.begin();
			if (lhs.find("-") != string::npos) {
				if (atoi(lhs.c_str()) != 0 || lhs == "0") { 
					l_flag = INTEGER;
				}
				else {
					lhs = lhs.erase(0, 1);
					while (l_it != data.end()) {
						if (l_it->second == lhs) { 
							l_flag = MINUS;
							break;
						}
						else
							l_it++;
					}
				}
			}
			else {
				if (atoi(lhs.c_str()) != 0 || lhs == "0") {
					l_flag = INTEGER;
				}
				else {
					while (l_it != data.end()) {
						if (l_it->second == lhs) {
							l_flag = PLUS;
							break;
						}
						else
							l_it++;
					}
				}
			}
			if (rhs.find("-") != string::npos) {
				if (atoi(rhs.c_str()) != 0 || rhs == "0") {
					r_flag = INTEGER;
				}
				else {
					rhs = rhs.erase(0, 1);
					while (r_it != data.end()) {
						if (r_it->second == rhs) {
							r_flag = MINUS;
							break;
						}
						else
							r_it++;
					}
				}
			}
			else {
				if (atoi(rhs.c_str()) != 0 || rhs == "0") {
					r_flag = INTEGER;
				}
				else {
					while (r_it != data.end()) {
						if (r_it->second == rhs) {
							r_flag = PLUS;
							break;
						}
						else
							r_it++;
					}
				}
			}
			if ((l_flag == INIT) || (r_flag == INIT)) {
				cout << "input error" << endl;
			}
			else if ((l_flag == INTEGER) || (r_flag == INTEGER)){
				if (l_flag == INTEGER) {
					if (r_flag == INTEGER) {
						lhs_ = new Point(stoi(lhs));
						rhs_ = new Point(stoi(rhs));			
					}
					else if (r_flag == PLUS) {
						lhs_ = new Point(stoi(lhs));
						rhs_ = new Point(r_it->first.x_, r_it->first.y_);
					}
					else {
						lhs_ = new Point(stoi(lhs));
						rhs_ = new Point(-1 * r_it->first.x_, -1 * r_it->first.y_);
					}

				}
				else if(l_flag == PLUS){
					if (r_flag == INTEGER) {
						lhs_ = new Point(l_it->first.x_, l_it->first.y_);
						rhs_ = new Point(stoi(rhs));
					}
					else if (r_flag == PLUS) {
						lhs_ = new Point(l_it->first.x_, l_it->first.y_);
						rhs_ = new Point(r_it->first.x_, r_it->first.y_);
					}
					else {
						lhs_ = new Point(l_it->first.x_, l_it->first.y_);
						rhs_ = new Point(-1 * r_it->first.x_, -1 * r_it->first.y_);
					}
				}
				else {
					if (r_flag == INTEGER) {
						lhs_ = new Point(-1 * l_it->first.x_, -1 * l_it->first.y_);
						rhs_ = new Point(stoi(rhs));
					}
					else if (r_flag == PLUS) {
						lhs_ = new Point(-1 * l_it->first.x_, -1 * l_it->first.y_);
						rhs_ = new Point(r_it->first.x_, r_it->first.y_);
					}
					else {
						lhs_ = new Point(-1 * l_it->first.x_, -1 * l_it->first.y_);
						rhs_ = new Point(-1 * r_it->first.x_, -1 * r_it->first.y_);
					}
				}
				eval(lhs_, rhs_, oper);
			}
			else {
				Point result;
				if (l_flag == PLUS) {
					if (r_flag == PLUS) {
						lhs_ = new Point(l_it->first.x_, l_it->first.y_);
						rhs_ = new Point(r_it->first.x_, r_it->first.y_);
					}
					else { 
						lhs_ = new Point(l_it->first.x_, l_it->first.y_);
						rhs_ = new Point(-1 * r_it->first.x_, -1 * r_it->first.y_);
					}
				} 
				else {
					if (r_flag == PLUS) {
						lhs_ = new Point(-1 * l_it->first.x_, -1 * l_it->first.y_);
						rhs_ = new Point(r_it->first.x_, r_it->first.y_);
					}
					else {
						lhs_ = new Point(-1 * l_it->first.x_, -1 * l_it->first.y_);
						rhs_ = new Point(-1 * r_it->first.x_, -1 * r_it->first.y_);
					}
				}
				eval(lhs_, rhs_, oper);
			}
		}
		else if (mode.find("quit") != string::npos) {
			cout << " in quit\n";
			break;
		}
		else {
			cout << "test" << endl;
		}
	}
}




//this is my trial and error to get only one parameter vs two parameter. although i can use "getline function" in input and split that string,i think that way is not my style.
/*int flag, input;
int x = INIT, y = INIT;
int count = 0;
cin >> var;
while ((flag = scanf_s(" %d", &input)) != EOF && count < 2) {
	cout << "flag is:" << flag << endl;
	if (count == 0) {
		x = input;
	}
	else
		y = input;
	count++;
}
cout << "x is: " << x << "y is :" << y << endl;
cout << "flag is:" << flag << endl;
if (flag != 1) {
	while (getchar() != '\n');
	cout << "input error" << endl;
	count = 3;
}
cout << "flag is:" << flag << endl;
cout << "count: " << count << endl;
//if (cin.fail)
	//cin.clear;
if (count == 1) {
	Point input(x); 
	data.emplace_back(make_pair(input, var));
}
else if (count == 2) {
	Point input(x, y); 
	data.emplace_back(make_pair(input, var));
}
else
	cout << "input error\n";
count = 0;
/*string var;
int x = INIT, y = INIT;
cin >> var >> x;
if (cin.fail())
	cin.clear();
else {
	char inp = cin.get();
	if (inp == '\n') {
		Point input(x);
		data.emplace_back(make_pair(input, var));
	}
	else {
		if (isdigit(inp)) {
			string y_;
			cin >> y_;
			y_ = inp + y_;
			Point input(x, stoi(y_));
			data.emplace_back(make_pair(input, var));
		}
	}
; 
			}*/
			/*
			int flag;
			int input;
			int x = INIT, y = INIT;
			int count = 0;
			cin >> var;
			cout << scanf_s(" %d", &input) << endl;
			while (flag = scanf_s(" %d", &input) !=EOF  && count < 2){
				if (count == 0){
					x = input;
				}
				else
					y = input;
				count++;
			}
			cout << "x is: " << x << "y is :" << y << endl;
			cout << "flag is:" << flag << endl;
			if (flag == 0) {
				while (getchar() != '\n');
				cout << "input error" << endl;
				count = 3;
			}
			cout << "flag is:" << flag << endl;
			cout << "count: " << count << endl;
			//if (cin.fail)
				//cin.clear;
			if (count == 1) {
					Point input(x); 
					data.emplace_back(make_pair(input, var));
			}
			else if (count == 2) {
				Point input(x, y); 
				data.emplace_back(make_pair(input, var));
			}
			//input = scanf_s("%d %d", &x, &y);
			/*cin >> var >> x >> y;
			if (cin.fail()) {
				cout << "input error!!" << endl;
				}
			else {
				cout << "in input" << endl;
				Point input(x, y); 
				data.emplace_back(make_pair(input, var));
			}*/