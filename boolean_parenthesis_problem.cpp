#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// gen_parenthesizations
//
// Given an expression of left-associating operators, permute the possible parenthesizations 
//
// eg. T^F|T&F^T
//
//	T^F|T&F^T
//	T^F|T&(F^T)
//	T^F|(T&F^T)
//	T^F|(T&(F^T))
//	T^F|(T&F)^T
//	T^(F|T&F^T)
//	T^(F|T&(F^T))
//	T^(F|(T&F^T))
//	T^(F|(T&(F^T)))
//	T^(F|(T&F)^T)
//	T^(F|T)&F^T
//	T^(F|T)&(F^T)
//	T^(F|T&F)^T
//	T^(F|(T&F))^T

template <typename Iter>
vector<string> gen_parenthesizations(Iter _begin, Iter _end)
{

	vector<string> v;
	ostringstream os;
	
	if ( 2 >= strlen(expression)) {

		// trailing sub-expression on the right eg. '&T' or 'T', just return that
		os << expression ;
		v.push_back(os.str());
		os.str("");

	} else {

		const char* sub_expression = expression + strlen(expression)-3; // rightmost two operands eg. T&F

		// starting from the right, working to the left, each iteration add another operand and operator ( eg. T& )
		// to the expression. Then build the list of permuatations based on the previous iteration 
		while (sub_expression >= expression) {

			vector<string> vtemp;


			if (3 == strlen(sub_expression)) {

				// base case, just the rightmost 3 tokens eg. T^F
				os << sub_expression ;
				vtemp.push_back(os.str());
				os.str("");

				// same but add parenthesis 
				os << '(' << sub_expression << ')' ;
				vtemp.push_back(os.str());	
				os.str("");


			} else {

				// construct all permutations with the right side, 
				// the vector will grow exponentially each loop
				for (vector<string>::iterator it=v.begin();it!=v.end(); ++it) {

					os << string(sub_expression).substr(0,2) <<  *it ;
					vtemp.push_back(os.str());	
					os.str("");


				}

				// same thing again, but enclose in parenthesis
				// no enclosing parenthesis on the entire expression however, that is extraneous 
				// eg. (T&F|T) is the same as T&F|T
				for (vector<string>::iterator it=v.begin();it!=v.end(); ++it) {
					if (sub_expression==expression) break;

					os << '(' << string(sub_expression).substr(0,2) << *it << ')';
					vtemp.push_back(os.str());	
					os.str("");


				}

				// now parenthesis on the leftmost operands eg. (T&F)|T and permute with right
				for (size_t pos=3; pos!=string(sub_expression).length(); pos+=2)
				{
					string left(string(sub_expression).substr(0,pos));
					vector<string> vleft(gen_parenthesizations(left.c_str()));

					for(vector<string>::iterator it=vleft.begin(); it!=vleft.end()-1; ++it) {
						os << '(' << *it << ')' << sub_expression[pos]; // eg. (T&F)^
						string left(os.str());
						os.str("");

						vector<string> vright(gen_parenthesizations(sub_expression+pos+1));
						for (vector<string>::iterator it=vright.begin(); it!=vright.end(); ++it)
						{
							os <<  left << *it;
							vtemp.push_back(os.str());	
							os.str("");
						}
					}
				}
			}

			v = vtemp;
			sub_expression -=2; // add next operand and operator on the left eg. T&
		}
	}

	return v;
}

int main ()
{
	const char my_expression[] = "T^F|T&F^T";
	
	vector<string> v = gen_parenthesizations(my_expression);
	for (vector<string>::iterator it=v.begin(); it!=v.end(); ++it)  cout << *it << endl;
	return 0;
}
