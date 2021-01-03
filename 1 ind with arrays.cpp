#include <iostream>
#include <string>
using namespace std;

int main() {
	string number14;
	cout << "Enter the number in base 14:";
	cin >> number14;
	int number10 = 0;
	int digit = 0;
	for (int i = 0; number14[i]; i++)
	{

		if (number14[i] == 'A') { digit = 10; }
		else if (number14[i] == 'B') { digit = 11; }
		else if (number14[i] == 'C') { digit = 12; }
		else if (number14[i] == 'D') { digit = 13; }

		else if (number14[i] < 'A') {
			digit = number14[i] - '0';
		}
		number10 += digit * pow(14, number14.length() - i - 1);
	}
	cout << "the number in base 10:" << number10 << endl;
	string currentnumber = "";
	string number03 = "";
	do {
		currentnumber = (number10 % 3) + '0';
		number10 = number10 / 3;
		number03 += currentnumber;
	} while (number10 > 0);
	int i = number03.length();
	string number3;
	for (i; i >= 0; i--) {
		number3 += number03[i];

	}
	cout << "the number in base 3:" << number3;
}