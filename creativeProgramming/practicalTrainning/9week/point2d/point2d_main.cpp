#include "point2d.h"
#include <map>
#define MINUS 1
#define PLUS 2
using namespace std;
int main() {
	vector<pair<Point, string>> data;
	string mode, var, lhs, rhs, oper;
	while (true) {
		cin >> mode;
		if (mode.find("set") != string::npos) {
			cout << " in set\n";
			int x =0, y = 0;
			cin >> var >> x >> y;
			cout << "in 1" << endl;
			Point input(x, y);
			cout << "in 2" << endl;
			data.emplace_back(make_pair(input, var));
			//data.emplace_back(pair<Point,string>(input,var));
			cout << "in 3" << endl;
			for (int i = 0; i < data.size(); i++)
			{
				cout << "in 4 \n";
				cout << "data "<<i<<":" << data[i].second << endl;
				cout << "x y :" << data[i].first.x_ << " "<< data[i].first.y_ << endl;
			}
		}
		else if (mode.find("eval") != string::npos) {
			cout << " in eval\n";
			cin >> lhs >> oper >> rhs;
			int l_flag = 0, r_flag = 0;
			vector<pair<Point, string>>::iterator l_it = data.begin();
			vector<pair<Point, string>>::iterator r_it = data.begin();
			if (lhs.find("-") != string::npos) {
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
			if (rhs.find("-") != string::npos) {
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
			if ((l_flag == 0) || (r_flag == 0))
				cout << "input error" << endl;
			else {
				Point result;
				if (l_flag == PLUS) {
					if (r_flag == PLUS) {
						cout << "PLUS PLUS\N";
						cout << "lhs x y" << l_it->first.x_ << l_it->first.y_ << endl;
						Point lhs(l_it->first.x_, l_it->first.y_);
						Point rhs(r_it->first.x_, r_it->first.y_);
						result = lhs + rhs;
					}
					else { //minus임
						cout << "PLUS MINUS\N";
						Point lhs(l_it->first.x_, l_it->first.y_);
						Point rhs(1,r_it->first);
						result = lhs + rhs;
					}
				} //여기서 lhs rhs 만들어주면됨.
				else {
					if (r_flag == PLUS) {
						cout << "minus PLUS\N";
						Point lhs(l_it->first);
						Point rhs(r_it->first.x_, r_it->first.y_);
						result = lhs + rhs;
					}
					else { //minus임
						cout << "MINUS PLUS\N";
						Point lhs(1,l_it->first);
						Point rhs(1,r_it->first);
						result = lhs + rhs;
					}
				}
				cout << "(" << result.x_ << ", " << result.y_ << ")" << endl;
			}
		}
		else if (mode.find("quit")) {
			cout << " in quit\n";
			break;
		}
		else
			cout << "input error" << endl;
	}
}