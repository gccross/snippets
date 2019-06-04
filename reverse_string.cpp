// reverse a string 
// also demonstrates printing types at compile-time
// also lambda 

#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>
#include <memory>

using namespace std;

unique_ptr<char> reverse(const char * const p)
{
	size_t nchars(strlen(p)), len(nchars+1);
	unique_ptr<char> result(new char[len]);
	reverse_copy(p,p+nchars,result.get());
	result.get()[len] = '\0';
	return result;
}


// A little mechanism to have the compiler tell us types deduced
template <typename T> 
struct FD;
auto f = [](auto&& T){ typename FD<decltype(T)>::type x; };

int main (int argc, const char* const argv[])
{
	char const *p = "seven";
	unique_ptr<char> p2 = reverse(p);

	f(p2); // force compiler error to determine the type of p2

	auto f0 = [](char* p){ cout << p << endl; };

	f0(p2.get());

	//same thing but in place. lambda just for giggles, should use std::swap()
	auto f1 = [&p2]() mutable { 
		char temp,  * const p = p2.get();
		size_t nchars = strlen(p), endpos(nchars-1);
		for (size_t i=0; i<(endpos)/2 ; ++i )
		{
			temp=p[i];
			p[i] = p[endpos-i];
			p[endpos-i] = temp;
		}
	};

	f1();
	f0(p2.get());

	// using swap and iterators, in place
	string s("Who has seen the wind?");
	auto f2 = [&s]() {
		for (string::iterator i=s.begin(), j=s.end()-1; i<j ; ++i, --j)
			swap(*i,*j);
	};
	f2();
	f0(s.data());
	return 0;
}
