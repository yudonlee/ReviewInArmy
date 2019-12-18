#include "omok.h"
int main() {
	Omok omok;
	int x_, y_;
	int winner = NOBODY;
	int prev_turn = NOBODY;
	int present_turn = NOBODY;
	while (true) {
		while (prev_turn == present_turn) {
			if (prev_turn == BLACK)
				cout << "White:";
			else
				cout << "Black:";
			cin >> x_ >> y_;
			present_turn = omok.put(x_, y_);
			if (present_turn == prev_turn)
				cout << "Can not be placed there!\n";
		}
		omok.IsOmok(&winner, x_, y_);
		cout << omok << endl;
		if (winner == BLACK || winner == WHITE) {
			if (winner == BLACK)
				cout << "Winner: Black player" << endl;
			else
				cout << "Winner: White player" << endl;
			break;
		}
		prev_turn = present_turn; //this is necessary to get input x and y when condition in while loop is that present turn and previous turn is same. previous turn is now updated because present turn will be changed.
	}
	return 0;
}