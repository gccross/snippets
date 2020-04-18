
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string addStrings(string string1, string string2) {
	auto fn = [](string s) -> double
	{
		size_t n_right=10, n_left=0;
		double res=0;
		bool fraction = false;
		for  (int i=0;i < s.length(); ++i)
		{
			if (s[i] == '.') 
			{
				fraction = true;
				continue;
			}

			double digit = s[i] - '0';
			if (fraction)
			{
				res += digit/n_right;
				n_right *= 10;
			}
			else
			{
				res *= n_left; 
				res += digit;
				n_left = n_left == 0 ? 10 : n_left*10;
			}
		}
		return res;
	};

	double gauche ;
	double droit ; 
	{
		stringstream stm;
		stm << string1;
		stm >> gauche;
		cout << gauche << endl;
	}

	{
		stringstream stm;
		stm << string2; 
		stm >> droit;
		cout << droit << endl;
	}

	/*
	   double gauche = fn(string1);
	   double droit = fn(string2); 
	 */
	double d = gauche + droit;
	stringstream stm;
	stm << d;
	return stm.str();
}

string addStrings_lib(string string1, string string2)
{
	double d1 = stod(string1);
	double d2 = stod(string2);
	stringstream sm;
	sm << d1+d2;
	return sm.str();
}

string addStrings_digit_by_digit(string s1, string s2)
{
	size_t sig1 = s1.find(".");	
	size_t sig2 = s2.find(".");	

	string mantissa1 = s1.substr(0,sig1);
	string mantissa2 = s2.substr(0,sig2);
	if (sig1 == string::npos) sig1 = s1.length();
	if (sig2 == string::npos) sig2 = s2.length();


	if (sig1 < sig2) 
	{
		swap(mantissa1,mantissa2);
		swap(sig1, sig2);
	}

	size_t const rest1 = s1.length() - sig1;
	size_t const rest2 = s2.length() - sig2;
	size_t const size_needed = max(sig1, sig2) + max(rest1,rest2) + 1;
	string res(size_needed, '\0');

	bool carry = false;

	int i1=0, i2 = 0;

	for ( i1=0; i1 < sig1 - sig2; ++i1)
		res[i1] = mantissa1[i1];
	while (i1 < sig1)
	{	
		res[i1] = mantissa1[i1] - '0' + mantissa2[i2]-'0' + '0' ;
		if (res[i1] > '9') 
		{
			res[i1] -= 10;
			++res[i1-1] ;
		}
		++i1;
		++i2;
	}

	if (i1 < s1.length() || i2 < s2.length())
		res[i1] = '.';

	++i1; ++i2;


	int right1 = s1.length() - i1;
	int right2 = s2.length() - i2;

	if (right1 < right2) 
	{
		swap(s1, s2);
		swap(i1, i2);
	}

	while (i2 < s2.length())
	{
		res[i2] = s1[i1] - '0' + s2[i2] - '0' + '0';
		if (res[i2] > '9')
		{
			int i = i2;
			while (res[i] > '9')
			{
				// oh frik, what to do here
				//  999999
				//      99

				res[i] -= 10;
				if (res[i-1] == '.')
					++res[i-2];
				else
					++res[i-1];
				--i;
			}
		}

		++i1;
		++i2;
	}
	while (i1 < s1.length())
	{
		res[i1] = s1[i1];
		++i1;
	}


	return res;
}


int main()
{
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string string1;
	getline(cin, string1);
	//{
		string string2;
		getline(cin, string2);

		//string result = addStrings(string1, string2);
		//string result2 = addStrings_lib(string1, string2);
		string result3 = addStrings_digit_by_digit(string1, string2);

		cout << "string1:" << string1 << ".  string2:" << string2 << "\n";
		cout << result3 << endl;
		//cout << "raw:" << result << "\t" << ".  from lib:" << result2 << ".  digit-by-digit: " << result3 << "\n";

	//}
	return 0;
}

/*
   Test cases:

works digit_by_digit:
   098702938475029384709876584
   65439848

	0987234598753
	6543

don't work digit_by_digit
   3.14
   0.9
   .2
   3
   25.
   .00000005


   4
   900000000000
 */
