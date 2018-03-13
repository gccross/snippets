#include <iostream>
using namespace std;

char fig[] = "Fig";
char mulberry[] = "Mulberry";

template <size_t n>
void  myfunc(char (&a)[n])
{
		cout << "generic template ... " << a << " sizeof: " << sizeof(a) << endl;
};

template <>
void  myfunc(char (&a)[4])
{
		cout << "overloaded ... " << a << " sizeof: " << sizeof(a) << endl;
};


template <size_t>
void pos_function(size_t n)
{
	cout << "size of n is not 3, it is " << n << endl;
}

template<>
void pos_function<3>(size_t pos)
{
	cout << "size of n is 3" << endl;
}

int main () 
{ 
	myfunc(fig);
	myfunc(mulberry);
	pos_function<5>(5);
	pos_function<3>(3);
	return 0;
}
