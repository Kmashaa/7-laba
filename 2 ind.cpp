#include <iostream>
#include<string>
using namespace std;
int main()
{
	string numberdop;
	cout << "Enter additional code:";
	cin >> numberdop;
	int i = 0;
	if (numberdop[0] == '0') {}
	else {
		if (numberdop[numberdop.length() - 1] == '1') { numberdop[numberdop.length() - 1] = '0'; }
		else {
			numberdop[numberdop.length() - 1] = '1';
			while (numberdop[numberdop.length() - i - 2] == '0') { numberdop[numberdop.length() - i - 2] = '1'; i++; }
			numberdop[numberdop.length() - 2 - i] = '0';
		}
	}
	string number;
	string numberobr = numberdop;
	if (numberobr[0] == '0')
	{
		number = numberobr;
	}
	else {
		number += '1';
		for (int i = 1; i < numberobr.length(); i++)
		{
			if (numberobr[i] == '0') { number+= '1'; }
			else { number+= '0'; }
		}
	}
	cout <<"Straight code:"<< number;
}