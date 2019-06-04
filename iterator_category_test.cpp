// Not sure what I was doing here
#include <iostream>
#include <functional>
#include <regex>
#include <algorithm>
#include <vector>
using namespace std;

namespace __is_class_imp
{
template <class _Tp> char  __test(int _Tp::*);
template <class _Tp> __two __test(...);
}

template <typename T>
class foo
{
	vector<T> v;
public:
	typedef T value_type;
	foo(T i){ v.push_back(i); }
	const vector<T>& value() const{ return v; }
	vector<T>& value() { return v; }
	foo& operator=(const foo&);
/*	foo1& operator=(foo1&& other)
	{
		swap(v,	other.v);
		return *this;
	}
*/
};

template <typename T>
foo<T>& operator++ (foo<T>& f)
{
	//int* c = a *= 5;
	f.value().push_back(9);
	return f;
} 

template <typename T>
ostream& operator<<(ostream& os, const foo<T>& f)
{
	typedef typename foo<T>::value_type  value_type;
	for_each(f.value().begin(),f.value().end(), [&os](const value_type &  n) {  os << n << "\t"; });
	return os;
}

int main (const int argc, char const * const* argv)
{
	int a = -9;	
	foo<unsigned int> f(a);
	cout << "sizeof __is_class_imp::__test(int) is this: " << sizeof(__is_class_imp::__test<int>(0)) <<endl;
	cout << "sizeof __is_class_imp::__test(iostream) is this: " << sizeof(__is_class_imp::__test<iostream>(0)) <<endl;
	cout << foo<unsigned int>(a)  << endl << ++f  << endl;
	return 0;
}


