
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string addStrings_digit_by_digit(string s1, string s2)
{
	int l1 = s1.find('.');
	if (l1 == string::npos) l1 = s1.length();

	int l2 = s2.find('.');
	if (l2 == string::npos) l2 = s2.length();

	int r1 = s1.length() - l1;
	int r2 = s2.length() - l2;

	if (r1 < r2) 
	{
		swap(l1,l2);
		swap(s1,s2);
	}

	bool carry = false;
	for (int i= s2.length() -1; i > l2; --i )
	{
		int digit = 0;
		if (carry)
		{
			++digit;
			carry = false;
		}
		digit  += s1[l1 + i - l2] - '0' + s2[i] - '0';
		if (digit > 9)
		{
			digit  -= 10;
			carry = true;
		}
		s1[l1+i - l2] = digit + '0';
	
	}

	string res_frac(s1.substr(l1));
	
	if (l1 < l2)
	{
		swap(l1,l2);
		swap(s1,s2);
	}

	string res_mantissa(l1+1, '0');

	for (int i = l1; i> l1 - l2; --i)
	{
		int digit = 0;
		if (carry)
		{
			digit += 1;
			carry = false;
		}

		digit += s1[i-1] - '0' + s2[l2 - (l1 - i) -1] - '0';
		if (digit > 9)
		{
			digit -= 10;
			carry = true;
		}
		res_mantissa[i] = digit + '0';
	}
	for (int i=l1 - l2 ; i>0; --i)
	{
		int digit = 0;
		if (carry)
		{
			digit += 1;
			carry = false;
		}
		digit += s1[i-1] - '0';
		if (digit  > 9)
		{
			digit -= 10;
			carry = true;
		}
		res_mantissa[i] = digit + '0';
	}
	if (carry) res_mantissa[0] = 1 + '0';

	if (!res_frac.empty())
		res_mantissa.append(res_frac);

	return res_mantissa[0] == '0' ? res_mantissa.substr(1): res_mantissa;

}

int main()
{
	int N;
	cin >> N;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (N--)
	{
		string string1, string2;
		getline(cin, string1);
		getline(cin, string2);

		string result3 = addStrings_digit_by_digit(string1, string2);

		cout << "string1:" << string1 << endl;
		cout << "string2:" << string2 << endl;
		cout << "digit-by-digit: " << result3 << "\n";


	}
	return 0;
}

/*
   Test cases:

0987234598753
6543
98702938475029384709876584
65439848
3.14
0.9
.2
3
25.
.00000005


4
900000000000
 */
