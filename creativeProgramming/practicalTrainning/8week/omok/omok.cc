#include "omok.h"
int Omok::put(int x, int y) {
	if (x < 0 || x > GROUND_SIZE || y < 0 || y > GROUND_SIZE) //if input x,y is more than GROUND_SIZE or less than 0,out of board,then it should be taken an input again.
		return turn_;
	if (result[y][x] == '.') {
		if (turn_ == BLACK) {
			result[y][x] = 'x';
			turn_ = WHITE;
		}
		else if (turn_ == WHITE) {
			result[y][x] = 'o';
			turn_ = BLACK;
		}
		else {
			result[y][x] = 'o';
			turn_ = BLACK;
		}
		return turn_; 
	}
	else //it already is occupied so take an input again.
		return turn_;
}
void Omok::IsOmok(int* winner, int last_x, int last_y) const {
	int left_length = 0, right_length = 0;
	int count = 0;

	//first case : when derivative of omok is -1.
	for (int i = 1; last_x-i >= 0 && last_y-i >=0 ; i++) {
		if (result[last_y][last_x] == result[last_y-i][last_x-i])
			left_length++;
		else
			break;
	}
	
	for (int i = 1; last_x + i <= GROUND_SIZE && last_y + i <= GROUND_SIZE; i++) {
		if (result[last_y][last_x] == result[last_y + i][last_x + i])
			right_length++;
		else
			break;
	}
	if (left_length + right_length == 4) {
		*winner = turn_;
		return;
	}
	else
		left_length = 0, right_length = 0;
	//second case:when omok is vertical axis.
	for (int i = 1; last_y - i >= 0; i++) {
		if (result[last_y][last_x] == result[last_y - i][last_x])
			left_length++;
		else
			break;
	}

	for (int i = 1; last_y + i <= GROUND_SIZE; i++) {
		if (result[last_y][last_x] == result[last_y + i][last_x])
			right_length++;
		else
			break;
	}
	if (left_length + right_length == 4) {
		*winner = turn_;
		return;
	}
	else
		left_length = 0, right_length = 0;
	//third case:when omok is horizontal axis.
	for (int i = 1; last_x - i >= 0; i++) {
		if (result[last_y][last_x] == result[last_y][last_x - i])
			left_length++;
		else
			break;
	}

	for (int i = 1; last_x + i <= GROUND_SIZE; i++) {
		if (result[last_y][last_x] == result[last_y][last_x +i])
			right_length++;
		else
			break;
	}
	if (left_length + right_length == 4) {
		*winner = turn_;
		return;
	}
	else
		left_length = 0, right_length = 0;
	//last(fourth) case: when derivative of omok is 1.
	for (int i = 1; last_x - i >= 0 && last_y + i <= GROUND_SIZE; i++) {
		if (result[last_y][last_x] == result[last_y + i][last_x - i])
			left_length++;
		else
			break;
	}

	for (int i = 1; last_x + i <= GROUND_SIZE && last_y - i >= 0; i++) {
		if (result[last_y][last_x] == result[last_y - i][last_x + i])
			right_length++;
		else
			break;
	}
	if (left_length + right_length == 4) {
		*winner = turn_;
		return;
	}
	else
		left_length = 0, right_length = 0;
}
ostream& operator<<(ostream& os, Omok& omok) {
	vector<string> print = omok.Result();
	for (int j = 0; j < GROUND_SIZE; j++) {
		for (int i = 0; i < GROUND_SIZE; i++)
			os << print[j][i];
		os << endl;
	}
	return os;
}