
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

int main()
{
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		string string1;
		while (getline(cin, string1))
		{
			string string2;
			getline(cin, string2);

			string result = addStrings(string1, string2);
			string result2 = addStrings_lib(string1, string2);

			cout << "string1:" << string1 << ".  string2:" << string2 << "\n";
			cout << "raw:" << result << "\t" << ".  from lib:" << result2 << "\n";

		}
    return 0;
}

/*
	 Test cases:

	 3.14
	 0.9
	 .2
	 3
	 25.
	 .00000005


	 4
	 900000000000
*/
