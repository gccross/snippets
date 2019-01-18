/*

This demonstrates the use of non-type template arguments and variadic template 
arguments.

The code in the comment here came from stackoverflow.com, a contributor
by the name of Georg Fritzche.  I learned from it. 

_________________________________________________________________________________

template<unsigned... args> struct ArrayHolder {
    static const unsigned data[sizeof...(args)];
};

template<unsigned... args> 
const unsigned ArrayHolder<args...>::data[sizeof...(args)] = { args... };

template<size_t N, template<size_t> class F, unsigned... args> 
struct generate_array_impl {
    typedef typename generate_array_impl<N-1, F, F<N>::value, args...>::result result;
};

template<template<size_t> class F, unsigned... args> 
struct generate_array_impl<0, F, args...> {
    typedef ArrayHolder<F<0>::value, args...> result;
};

template<size_t N, template<size_t> class F> 
struct generate_array {
    typedef typename generate_array_impl<N-1, F>::result result;
};

// usage
template<size_t index> struct MetaFunc { 
    enum { value = index + 1 }; 
};

void test() {
    const size_t count = 5;
    typedef generate_array<count, MetaFunc>::result A;

    for (size_t i=0; i<count; ++i) 
        std::cout << A::data[i] << "\n";
}

_________________________________________________________________________________

The code in the next comment here demonstrates static_assert for array sizes

template <typename ValueType, int size>
struct FixedArray
{
	ValueType mArr[size > 0 ? size : 1];

};


FixedArray<int,10> a ;
static const int A(sizeof(a.mArr)/sizeof(a.mArr[0]));
static_assert(A==10, "error A!=10") ;

_________________________________________________________________________________
*/


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

template< typename T, T... args>
struct UniqueSet
{
	static const T data[sizeof ...(args)] = { args... };
};

template <size_t n, typename T, T... args>
struct gen_unique_set {
	typedef typename gen_unique_set<n-1, T, a[n], args...>::result result;
};

template <typename T,  T... args>
struct gen_unique_set<0, T, T... args> {
	typedef UniqueSet<T, a[0], args...> result;
};

wchar_t myArr[] =  { L'§',L'è', L'é', L'ò', L'ò', L'ò', L'ù', L'ﬁ', L'Æ', L'Æ' };

typedef typename gen_unique_set<sizeof(myArr)/sizeof(myArr[0]) - 1, wchar_t, myArr>::result A;


int main () 
{ 
	myfunc(fig);
	myfunc(mulberry);
	pos_function<5>(5);
	pos_function<3>(3);

	return 0;
}
