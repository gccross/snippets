#include <iostream>
#include <string>
using namespace std;

#define T 1;
#define F 0;

template<bool right, char op , typename left>
struct do_evaluation{};

template<bool right, char op>
struct do_evaluation<right,op,bool> 
{
	static bool value = right&left;
};

template<bool right, char op>
struct do_evaluation<right,op, char*>
{
	static bool value =  do_evaluation<right,left[0],sizeof(left)==2 ? left[1] : left+1>::value;
};

int main(int argc, char const * const * argv)
{
	static char expr[]= "F|T|T&F^F";

	cout << do_evaluation<true,'&',expr>::value << endl; 
}
