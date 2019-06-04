#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

// simple demonstration of only defining constructor if template parameter is an integral 
struct value
{
	template <typename T>
	value ( T val, 
		typename enable_if< 
				integral_constant<
					bool, 
					is_integral<T>::value||is_enum<T>::value>::value
				>::type* =0) { cout << "Hello world" << endl; }

};

// a different example to demonstrate forcing compiler message to print enable_if::type
template <typename T> struct S;
S<enable_if_t<true>> var;  //compiler error undefined type S<void>

int main ()
{
	new value(-67);
	new value("generousity"); //compiler error, "generousity" non-integral type
	return 0;
}
