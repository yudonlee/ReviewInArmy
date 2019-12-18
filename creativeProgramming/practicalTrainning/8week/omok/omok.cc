#include "omok.h"
int Omok::put(int x, int y) {
	if (x < 0 || x > GROUND_SIZE || y < 0 || y > GROUND_SIZE)
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
		return turn_; //이부분이 빠져있었음.
	}
	else
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
	/*first case
	for (int i = last_y; i >= 0; i--) {
		for (int j = last_x; j >= 0; j--) {
			cout << "result[" << last_y << "][" << last_x << "][: " << result[last_y][last_x] << " result["
				<< j << "][" << i << "]" << result[j][i] << endl;
			if (result[last_y][last_x] == result[j][i])
				left_length++;
			else
				break;
		}
	}
	for (int i = last_y; i <= GROUND_SIZE; i++) {
		for (int j = last_x; j <= GROUND_SIZE; j++) {
			cout << "result[" << last_y << "][" << last_x << "][: " << result[last_y][last_x] << " result["
				<< j << "][" << i << "]" << result[j][i] << endl;
			if (result[last_y][last_x] == result[j][i])
				right_length++;
			else
				break;
		}
	}
	if (left_length + right_length == 4) {
		cout << "left legnth : " << left_length << " right length: " << right_length << endl;
		*winner = turn_;
		return;
	}
	else
		left_length = 0, right_length = 0;
		
	for (int i = last_y; i >= 0; i--) {
		//cout << "result[" << last_y << "][" << last_x << "][: " << result[last_y][last_x] << " result["
		//	<< j << "][" << i << "]" << result[j][i] << endl;
		if (result[last_y][last_x] == result[last_x][i])
			left_length++;
		else
			break;
	}
	for (int i = last_y; i <= GROUND_SIZE; i++) {
		cout << "result[" << last_y << "][" << last_x << "][: " << result[last_y][last_x] << " result["
			<< last_x << "][" << i << "]" << result[last_x][i] << endl;
		if (result[last_y][last_x] == result[last_x][i])
			right_length++;
		else
			break;
	}
	if (left_length + right_length == 4) { // 6 ,7 mok is not winner.
		cout << "left legnth : " << left_length << " right length: " << right_length << endl;
		*winner = turn_;
		return;
	}
	else
		left_length = 0, right_length = 0;
	for (int i = last_y; i <= GROUND_SIZE; i++) {
		for (int j = last_x; j <= GROUND_SIZE; j++) {
			if (result[last_y][last_x] == result[j][i])
				right_length++;
			else
				break;
		}
	}
	for (int i = last_y; i >= 0; i--) {
		for (int j = last_x; j >= 0; j--) {
			if (result[last_y][last_x] == result[j][i])
				left_length++;
			else
				break;
		}
	}
	if (left_length + right_length == 4) {
		cout << "left legnth : " << left_length << " right length: " << right_length << endl;
		*winner = turn_;
		return;
	}
	else
		left_length = 0, right_length = 0;
	
	for (int i = last_x; i <= GROUND_SIZE; i++) {
		if (result[last_y][last_x] == result[last_y][i])
			right_length++;
		else
			break;
	}
	for (int i = last_x; i >= 0; i--) {
		if (result[last_y][last_x] == result[last_y][i])
			left_length++;
		else
			break;
	}
	if (left_length + right_length == 4) { // 6 ,7 mok is not winner.
		*winner = turn_;
		return;
	}
	else
		left_length = 0, right_length = 0;
		*/
}
/*
void Omok::IsOmok(int* winner,int last_x,int last_y) const {
	int left_length =0, right_length=0;
	int count = 0;
	if (turn_ == BLACK) {
		for (int i = last_y; i >= 0; i--) {
			for (int j = last_x; j >= 0; j--) {
				if (result[j][i] == 'o')
					left_length++;
				else
					break;
			}
		}
		for (int i = last_y; i <= GROUND_SIZE; i++) {
			for (int j = last_x; j <= GROUND_SIZE; j++) {
				if (result[j][i] == 'o')
					right_length++;
				else
					break;
			}
		}
		if (left_length + right_length == 4) {
			*winner = turn_;
			return;
		}
		else
			left_length = 0, right_length = 0;

		for (int i = last_y; i >= 0; i--) {
			if (result[last_x][i] == 'o')
				left_length++;
			else
				break;
		}
		for (int i = last_y; i <= GROUND_SIZE; i++) {
			if (result[last_x][i] == 'o')
				right_length++;
			else
				break;
		}
		if (left_length + right_length == 4) { // 6 ,7 mok is not winner.
			*winner = turn_;
			return;
		}
		else
			left_length = 0, right_length = 0;
		for (int i = last_y; i <= GROUND_SIZE; i++) {
			for (int j = last_x; j <= GROUND_SIZE; j++) {
				if (result[j][i] == 'o')
					right_length++;
				else
					break;
			}
		}
		for (int i = last_y; i >=0; i--) {
			for (int j = last_x; j >= 0; j--) {
				if (result[j][i] == 'o')
					left_length++;
				else
					break;
			}
		}
		if (left_length + right_length == 4) {
			*winner = turn_;
			return;
		}
		else
			left_length = 0, right_length = 0;
		for (int i = last_x; i <= GROUND_SIZE; i++) {
			if (result[last_y][i] == 'o')
				right_length++;
			else
				break;
		}
		for (int i = last_x; i >= 0; i--) {
			if (result[last_y][i] == 'o')
				left_length++;
			else
				break;
		}
		if (left_length + right_length == 4) { // 6 ,7 mok is not winner.
			*winner = turn_;
			return;
		}
		else
			left_length = 0, right_length = 0;
	}
	else {
		for (int i = last_y; i >= 0; i--) {
			for (int j = last_x; j >= 0; j--) {
				if (result[j][i] == 'x')
					left_length++;
				else
					break;
			}
		}
		for (int i = last_y; i <= GROUND_SIZE; i++) {
			for (int j = last_x; j <= GROUND_SIZE; j++) {
				if (result[j][i] == 'x')
					right_length++;
				else
					break;
			}
		}
		if (left_length + right_length == 4) {
			*winner = turn_;
			return;
		}
		else
			left_length = 0, right_length = 0;

		for (int i = last_y; i >= 0; i--) {
			if (result[last_x][i] == 'x')
				left_length++;
			else
				break;
		}
		for (int i = last_y; i <= GROUND_SIZE; i++) {
			if (result[last_x][i] == 'x')
				right_length++;
			else
				break;
		}
		if (left_length + right_length == 4) { // 6 ,7 mok is not winner.
			*winner = turn_;
			return;
		}
		else
			left_length = 0, right_length = 0;
		for (int i = last_y; i <= GROUND_SIZE; i++) {
			for (int j = last_x; j <= GROUND_SIZE; j++) {
				if (result[j][i] == 'x')
					right_length++;
				else
					break;
			}
		}
		for (int i = last_y; i >= 0; i--) {
			for (int j = last_x; j >= 0; j--) {
				if (result[j][i] == 'x')
					left_length++;
				else
					break;
			}
		}
		if (left_length + right_length == 4) {
			*winner = turn_;
			return;
		}
		else
			left_length = 0, right_length = 0;
		for (int i = last_x; i <= GROUND_SIZE; i++) {
			if (result[last_y][i] == 'x')
				right_length++;
			else
				break;
		}
		for (int i = last_x; i >= 0; i--) {
			if (result[last_y][i] == 'x')
				left_length++;
			else
				break;
		}
		if (left_length + right_length == 4) { // 6 ,7 mok is not winner.
			*winner = turn_;
			return;
		}
		else
			left_length = 0, right_length = 0;
	}
}*/
ostream& operator<<(ostream& os, Omok& omok) {
	vector<string> print = omok.Result();
	for (int j = 0; j < GROUND_SIZE; j++) {
		for (int i = 0; i < GROUND_SIZE; i++)
			os << print[j][i];
		os << endl;
	}
	return os;
}
