
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string addStrings(string string1, string string2) {
    auto fn = [](string s) -> double
    {
        size_t n_right=1, n_left=0;
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
                res  += digit / (10*n_right);
                ++n_right;
            }
            else
            {
                res += 10 * n_left; 
								res += digit;
                ++n_left;
            }
        }
        return res;
    };



    double gauche = fn(string1);
    double droit = fn(string2); 
    double d = gauche + droit;
    stringstream stm;
    stm << d;
    return stm.str();
}

int main()
{
    string string1;
    getline(cin, string1);

    string string2;
    getline(cin, string2);

    string result = addStrings(string1, string2);

    cout << result << "\n";

    return 0;
}
