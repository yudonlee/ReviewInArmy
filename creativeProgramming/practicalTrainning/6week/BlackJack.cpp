/*#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string>
using namespace std;
#define BLACKJACK 21
int compareSum1(int* array, int count) {
	int blackjack = 21;
	int* diff = new int[count];
	for (int i = 0; i < count; i++) {
		diff[i] = abs(blackjack - array[i]);
	}
	int min = diff[0];
	int index = 0;
	for (int i = 1; i < count; i++) {
		if (min > diff[i]) {
			min = diff[i];
			index = i;
		}
	}
	if (min == 0) {
		return blackjack;
	}
	else
		return array[index];

}
int sec() {
	int aCount = 0;
	int sum = 0;
	int number;
	int* aSum;
	std::cin >> number;
	while (true) {
		for (int i = 0; i < number; i++) {
			string input;
			std::cin >> input;
			cout << "input is " << input << endl;
			cout << " input bool return is: " << atoi(input.c_str());
			if (isdigit(atoi(input.c_str()))){
				if (atoi(input.c_str()) > 0 && atoi(input.c_str()) < 11)
					sum += atoi(input.c_str());
				else {
					perror("that is not card in BlackJack! wow\n");
					break;
				}
				cout << "sum is:" << sum << endl;
			}
			else {
				cout << "not digit!\n";
				if (input == "A")
					aCount++;
				else if (input == "J")
					sum += 10;
				else if (input == "Q")
					sum += 10;
				else if (input == "K")
					sum += 10;
				else {
					perror("that is not card in BlackJack!\n");
					break;
				}
			}
		}
		aSum = new int[aCount + 1];
		int j = 0;
		while (j <= aCount){
			aSum[j] = 1 * j + 10 * (aCount - j) + sum;
			if (aSum[j] > 21)
				break;
		}
		cout << " j is : " << j << endl;
		int result = compareSum(aSum, j);
		if (result == BLACKJACK)
			cout << "BLACKJACK" << endl;
		else
			cout << result << endl;
	}
	return 0;
}
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
#define BLACKJACK 21
#define Astatus -100
enum Status {
	blackjack,
	exceed,
	few,
};
int compareSum(int* array, int count) {
	if (count == 0)
		return array[0];
	int* diff = new int[count+1];
	for (int i = 0; i <= count; i++) {
		diff[i] = abs(BLACKJACK - array[i]);
	}
	int min = diff[0];
	int index = 0;
	for (int i = 1; i <= count; i++) {
		if (min > diff[i]) {
			min = diff[i];
			index = i;
		}
	}
	return array[index];

}
int isStatus(int result) {
	if (result == BLACKJACK)
		return blackjack;
	else if (result > BLACKJACK)
		return exceed;
	else
		return few;
}
int main() {
	int aCount = 0;
	int sum = 0;
	int number;
	int figure;
	int* aSum;
	int result;
	while (true) {
		cin >> number;
		for (int i = 0; i < number; i++) {
			cin >> figure;
			if (cin.fail()) {
				cin.clear(); //this is important line because now cin status is failed. if cin doesnt be cleaned, cin status is still failed.
				char ch;
				cin >> ch;
				if (ch == 'A')
					figure = Astatus;
				else if (ch == 'J')
					figure= 10;
				else if (ch == 'Q')
					figure= 10;
				else if (ch == 'K')
					figure = 10;
				else
					return 0;
			}
			if (figure > 0 && figure < 11)
				sum += figure;
			else if (figure == Astatus)
				aCount++;
			else
				return 0; // when wrong input occur, program is exited.
		}
		if (aCount == 0)
			result = isStatus(sum);
		else {
			aSum = new int[aCount + 1];
			int j = 0;
			while (j <= aCount) {
				aSum[j] = 10 * j + 1 * (aCount - j) + sum;
				if (aSum[j] > 21)
					break;
				cout << "Asum is :" << aSum[j] << endl;
				j++;
			}
			cout << "j is :" << j << endl;
			sum = compareSum(aSum, j);
			result = isStatus(sum);
		}
		if (result == blackjack)
			cout << "BlackJack" << endl;
		else if (result == exceed)
			cout << "exceed" << endl;
		else
			cout << sum << endl;
	}
	return 0;
}
