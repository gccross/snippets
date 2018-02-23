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
		cout << "specialized ... " << a << " sizeof: " << sizeof(a) << endl;
};

int main () 
{ 
	myfunc(fig);
	myfunc(mulberry);
	return 0;
}
