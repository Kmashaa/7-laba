//ѕри вводе букв использовать только большие буквы





#include <iostream>
#include<string.h>
using namespace std;
string addition(string sum,string firstnumberdop,string secondnumberdop, int j){
	for (int j = 14; j >= 0; j--)
	{
		if (firstnumberdop[j] == '0' && secondnumberdop[j] == '0')
		{
			sum[j + 1] = '0';
		}
		if ((firstnumberdop[j] == '1' && secondnumberdop[j] == '0') || (firstnumberdop[j] == '0' && secondnumberdop[j] == '1'))
		{
			sum[j + 1] = '1';
		}
		if (firstnumberdop[j] == '1' && secondnumberdop[j] == '1')
		{
			sum[j + 1] = '0';
			while ((firstnumberdop[j] == '0' && secondnumberdop[j] == '1') || (firstnumberdop[j] == '1' && secondnumberdop[j] == '0') || (firstnumberdop[j] == '1' && secondnumberdop[j] == '1'))
			{
				if (j == 0) { break; }
				if ((firstnumberdop[j - 1] == '1' && secondnumberdop[j - 1] == '1') && j > 0)
				{
					sum[j] = '1'; sum[j - 1] = '1'; j--;
				}
				if (j == 0) { break; }

				if (j > 0 && ((firstnumberdop[j - 1] == '1' && secondnumberdop[j - 1] == '0') || (firstnumberdop[j - 1] == '0' && secondnumberdop[j - 1] == '1')))
				{
					sum[j] = '0'; j--;
				}
				if (j == 0) { break; }

				if (j > 0 && (firstnumberdop[j - 1] == '0' && secondnumberdop[j - 1] == '0'))
				{
					sum[j] = '1';  j--;
				}

			}


		}
	}
	if (sum[0] == '9') { sum.erase(0, 1); }
	
	return(sum);
}
int main() {

	int fnumber10;
	string fcurrentnumber;
	string fnumber02;
	string fznak;
	string fnumber2;


	cout << "Enter the first number in base 10:";
	cin >> fnumber10;

	if (fnumber10 >= 0) { fznak = "0"; }
	else { fznak = "1"; }
	fnumber10 = fabs(fnumber10);

	do {
		fcurrentnumber = (fnumber10 % 2) + '0';
		fnumber10 = fnumber10 / 2;
		fnumber02 += fcurrentnumber;
	} while (fnumber10 > 0);

	int i = fnumber02.length();
	for (i; i >= 0; i--) {
		fnumber2 += fnumber02[i];     //the first number in base 2
	}

	string fnumberobr = fnumber2;
	string fnumberdop;

	if (fznak[0] == '0') { fnumberobr.insert(1, "0"); }
	else { fnumberobr.insert(1, "1"); }
	if (fnumberobr[1] == '0') {}
	else {
		for (int i = 2; i < fnumberobr.length(); i++)
		{
			if (fnumberobr[i] == '0') { fnumberobr[i] = '1'; }
			else { fnumberobr[i] = '0'; }
		}
	}  
	
	fnumberdop = fnumberobr;
	i = 0;
	if (fnumberobr[1] == '0') {}
	else

	{
		if (fnumberobr[fnumberobr.length() - 1] == '0') { fnumberobr[fnumberobr.length() - 1] = '1'; }
		else
		{
			fnumberobr[fnumberobr.length() - 1] = '0';
			while (fnumberobr[fnumberobr.length() - i - 2] == '1') { fnumberobr[fnumberobr.length() - i - 2] = '0'; i++; }
			fnumberobr[fnumberobr.length() - 2 - i] = '1';
		}
		fnumberdop = fnumberobr;


	}
	int snumber10;
	string scurrentnumber;
	string snumber02;
	string sznak;
	string snumber2;

	cout << "Enter the secont number in base 10:";
	cin >> snumber10;

	if (snumber10 >= 0) { sznak = "0"; }
	else { sznak = "1"; }
	snumber10 = fabs(snumber10);

	do {
		scurrentnumber = (snumber10 % 2) + '0';
		snumber10 = snumber10 / 2;
		snumber02 += scurrentnumber;
	} while (snumber10 > 0);

	i = snumber02.length();
	for (i; i >= 0; i--) {
		snumber2 += snumber02[i];			//the second number in base 2

	}
	



	string snumberobr = snumber2;
	string snumberdop;

	if (sznak[0] == '0') { snumberobr.insert(1, "0"); }
	else { snumberobr.insert(1, "1"); }
	if (snumberobr[1] == '0') {}
	else {
		for (int i = 2; i < snumberobr.length(); i++)
		{
			if (snumberobr[i] == '0') { snumberobr[i] = '1'; }
			else { snumberobr[i] = '0'; }
		}
	}
	
	snumberdop = snumberobr;
	i = 0;
	if (snumberobr[1] == '0') {}
	else

	{
		if (snumberobr[snumberobr.length() - 1] == '0') { snumberobr[snumberobr.length() - 1] = '1'; }
		else
		{
			snumberobr[snumberobr.length() - 1] = '0';
			while (snumberobr[snumberobr.length() - i - 2] == '1') { snumberobr[snumberobr.length() - i - 2] = '0'; i++; }
			snumberobr[snumberobr.length() - 2 - i] = '1';
		}
		snumberdop = snumberobr;


	}


	string firstnumberdop = fnumberdop;
	i = 0;
	if (fnumberdop[1] == '1') { firstnumberdop.insert(1, 15 - fnumberdop.length(), '1'); }
	else { firstnumberdop.insert(1, 15 - fnumberdop.length(), '0'); }

	


	string secondnumberdop = snumberdop;
	i = 0;
	if (snumberdop[1] == '1') { secondnumberdop.insert(1, 15 - snumberdop.length(), '1'); }

	else { secondnumberdop.insert(1, 15 - snumberdop.length(), '0'); }

	

	secondnumberdop.erase(0, 1);
	firstnumberdop.erase(0, 1);
	string sum = "999999999999999";
	int j = 14;
	string numberhex;
	sum = addition(sum, firstnumberdop, secondnumberdop, j);
	if (sum[0] == '1') {
		numberhex += '-'; sum.erase(0, 1);
	}
	else {
		numberhex += '+'; sum.erase(0, 1);
	}
	//перевод в двоичный код
	i = 0;
	if (sum[0] == '0') {}
	else {
		if (sum[sum.length() - 1] == '1') { sum[sum.length() - 1] = '0'; }
		else {
			sum[sum.length() - 1] = '1';
			while (sum[sum.length() - i - 2] == '0') { sum[sum.length() - i - 2] = '1'; i++; }
			sum[sum.length() - 2 - i] = '0';
		}
	}
	string numberbin;
	string numberobr = sum;
	if (numberobr[0] == '0')
	{
		numberbin = numberobr;
	}
	else {
		for (int i = 1; i < numberobr.length(); i++)
		{
			if (numberobr[i] == '0') { numberbin += '1'; }
			else { numberbin += '0'; }
		}
	}
	//перевод в дес€тичный код
	int digit;
	int number10=0;
	int p=0;
	for (p;p<numberbin.length();p++) {
		
		digit = numberbin[p] - '0';
		number10 += digit * pow(2, numberbin.length() - p - 1);
	}

		cout << numberhex<<number10<<endl;
}
