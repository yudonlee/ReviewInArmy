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
			if (present_turn == present_turn)
				cout << "Can not be placed there!\n";
		}
		omok.IsOmok(&winner, x_, y_);
		cout << omok << endl;
		cout << "winner : " << winner << endl;
		if (winner == BLACK || winner == WHITE) {
			if (winner == BLACK)
				cout << "Winner: Black player" << endl;
			else
				cout << "Winner: White player" << endl;
			break;
		}
		prev_turn = present_turn; // �� �Է¹��� ����Ҷ� �ʿ���. ���ο� ���̱⿡ �ٲ�°͵� �ݿ��ؾ� �ϹǷ� �� �������� ������Ʈ ���� �ʿ䰡 ����.
	}
	return 0;
}