//При вводе букв использовать только большие буквы


#include <iostream>
using namespace std;
string addition(string number1, string number2, string fnumber, string snumber, string oper,string sum,int imax, int imin)
{
	int i1 = number1.length() - 1;
	int i2 = number2.length() - 1;
	
	string digit;
	int i = 1;
	if (i1 >= i2) { imax = i1; imin = i2; fnumber = number1; snumber = number2; }
	else { imax = i2; imin = i1; fnumber = number2; snumber = number1; }

	for (imax; imin >= 0;)
	{
		int p, v;

		if (fnumber[imax] < 'A') { p = fnumber[imax] - '0'; }
		else {
			p = fnumber[imax] - '0' - 7;
		}

		if (snumber[imin] < 'A') { v = snumber[imin] - '0'; }
		else {
			v = snumber[imin] - '0' - 7;
		}

		if (p + v + sum[1] - '0' < 19)
		{
			digit = (p + v + sum[1] - '0') + '0';
			if (digit[0] > char(57)) {
				digit = digit[0] + char(7);
			}


			sum.insert(2, digit);
			sum.erase(1, 1);
			sum.insert(1, "0");
		}
		else {
			digit = (p + v + sum[1] - '0') % 19 + '0';
			if (digit[0] > char(57)) {
				digit = digit[0] + char(7);
			}
			sum.insert(2, digit);

			sum[1] = (((p + v) / 19)) + '0';

		}
		imin--;
		imax--;
	}


	for (imax; imax >= 0; imax--) {
		int p;

		if (fnumber[imax] < 'A') { p = fnumber[imax] - '0'; }
		else {
			p = fnumber[imax] - '0' - 7;
		}

		if (p - '0' + sum[1] - '0' < 19)
		{
			digit = (p + sum[1] - '0') + '0';
			if (digit[0] > char(57)) {
				digit = digit[0] + char(7);
			}
			sum.insert(2, digit);
			sum.erase(1, 1);
			sum.insert(1, "0");
		}
		else {
			digit = (p + sum[1] - '0') % 19 + '0';
			if (digit[0] > char(57)) {
				digit = digit[0] + char(7);
			}
			sum[1] = (((p + sum[1] - '0') / 19)) + '0';
			sum.insert(2, digit);



		}
	}
	return(sum);
}
string substraction(string number1, string number2, string oper, string sub) {
	int i1 = number1.length() - 1;
	int i2 = number2.length() - 1;
	if (i2 > i1) {
		number1.insert(0, i2 - i1 + 1, 'I');
		i1 = number1.length() - 1;
	}
	else if (i1 > i2) {
		number2.insert(0, i1 - i2, '0'); i2 = number2.length() - 1;
	}
	while (i2 >= 0) {
		int p, v;
		string digit;
		if (number1[i1] < 'A')
		{
			p = number1[i1] - '0';
		}
		else
		{
			p = number1[i1] - '0' - 7;
		}

		if (number2[i2] < 'A')
		{
			v = number2[i2] - '0';
		}
		else
		{
			v = number2[i2] - '0' - 7;
		}


		if (p - v >= 0)
		{
			digit = (p - v) + '0';
			if (digit[0] > char(57))
			{
				digit = digit[0] + char(7);
			}

			sub.insert(2, digit);
			i2--; i1--;
		}
		else {
			digit = fabs(p - v) + '0';
			if (digit[0] <= char(57))
			{
				digit = (19 - (digit[0] - '0') + '0') + char(7);
			}
			sub.insert(2, digit);
			int i = 0;

			while (number1[i1 - i - 1] == '0') { number1[i1 - i - 1] = 'I'; i++; }
			number1[i1 - i - 1] = (number1[i1 - i - 1] - '0' - 1) + '0';
			i2--; i1--;
		}


	} if (i1 > i2) {
		string digit; digit = number1[0];
		sub.insert(2, "I");
	} return(sub);
}
int main() {
	cout << "Enter the first number in base 19:";
	string number1;
	cin >> number1;
	cout << "Enter the second number in base 19:";
	string number2;
	cin >> number2;
	string oper;
	cout << "Enter the operation:+ or -:";
	cin >> oper;
	string sub = "00";
	string sum = "00";
	int imax=0;
	int imin=0;
	string fnumber;
	string snumber;
	if (oper[0] == '+') 
	{
		cout <<"The result of addition:"<< addition(number1, number2, fnumber, snumber, oper, sum, imax, imin) << endl;
	}
	else
	{
		cout << "The result of substraction:" << substraction(number1, number2, oper, sub) << endl;
	}
}
