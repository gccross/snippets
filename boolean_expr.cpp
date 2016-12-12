#include <iostream>     // std::cout
#include <set>       // std::vector
#include <string>       // std::string
#include <sstream>

using namespace std;

set<string> permutations;

void permute(const string& left, const string& right)
{

	if (right.length() < 2) return;
	ostringstream expr, paren_left, new_left, new_right;

	size_t pos = right.find_first_of(')');
	string t(right.begin(), right.begin() + (pos==string::npos?right.length():pos));
	if (t.length()%2 ) // odd
	{
		// left is something like "X op", right is something like "X op X op X"

 
		//associate left

		new_left << left << '(' ;
		new_right << right << ')';
		expr << new_left.str() << new_right.str();
		if (permutations.insert(expr.str()).second == false) cout << "odd: " << expr.str() << " already in set" << endl;

		// associate left again
		new_left << string(right.begin(), right.begin()+2);
		string new_right_str(new_right.str());
		permute(new_left.str(), string(new_right_str.begin()+2, new_right_str.end()));

		// associate right
		new_left.str(string());
		new_left << left <<  right[0] ;
		permute(new_left.str(), string(right.begin()+1, right.end())) ;
	}
	else  // even
	{
		// left is something like "X op X op X", right is something like "op X"

		//associate right
		paren_left << '(' << left << ')';
		expr << paren_left.str() << right; 
		if (permutations.insert(expr.str()).second == false) cout << "even: " << expr.str() << " already in set" << endl;

		//associate right again
		new_left << paren_left.str() << string(right.begin(), right.begin()+2) ;
		permute(new_left.str(), string(right.begin()+2,right.end())); 	

		//associate left
		new_left.str(string());
		new_left << paren_left.str()  << right[0] ;  
		permute(new_left.str(),	string(right.begin()+1,right.end()));
	}
}

int main () {

	unsigned int line_no=0;
	string s;
	//for (; cin; line_no++)
	{
		//cin >> s;
		s="F^T|F&T^F";
		cout << "line " << line_no << ":\t" << s << endl;
		if (s.length() < 3) 
		{
			cout << "Error: Please provide a string more than 3 charactors" << endl;
			return 1;
		}
			
		permute(string(s.begin(), s.begin()+3), string(s.begin()+3, s.end()));
		for (const string& permutation: permutations) cout << permutation << endl; 
	}	

	return 0;
}
