#include <iostream>
using namespace std;
template <char (&left)[], char (&right)[]> 
void parenthesize (const char[] left, const char[] right) {

	size_t left_len = sizeof(left) - sizeof (right);

	for (int i=0; i<left_len; i++) cout << s[i];
	cout << '(' << right << ')' << endl;

	cout << '(';
	for (int i=0; i<left_len+1; i++) cout << s[i];
	cout << ')' << right+1 << endl;

	parenthesize(left,right+2);
}

template <char (&s)[3] s> 
void parenthesize(const char[] s){
	cout << '('
	for (int i=0; i<2; i++) cout << s[i];
	cout << endl;
	
}

int main ()
{
	char my_expression[] = "T&F^T";
	parenthesize(my_expression, my_expression);
	return 0;
}
