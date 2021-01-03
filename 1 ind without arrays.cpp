#include <iostream>
#include <string>
using namespace std;

int main() {
	string number14;
	cout << "Enter the number in base 14:";
	cin >> number14;
	int number10=0;
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
	number10 += digit * pow(14, number14.length() - i-1); }
	int number3 = 0;
	cout << "The number in base 3:";
	for (int j = 0; number10 > 0; j++)
	{
		number3 += (number10 % 3) * powl(10, j);
		number10 /= 3;
	}

	cout << number3 << endl;
}