/*

   The objective of this code is to wrap a collection of functions in to a class 
   together so they can be called via overload resolution.

   reference_wrapper's operator T&() causes ambiguity for our overload solution 

   see John's solution below, which only provides an operator(), and no operator T&()


#include <functional>
#include <iostream>

using func = void (*) (int, int); //typedef void (*func) (int, int);
// the name 'func' now denotes a pointer to function:
void example(int, int) {}
func f_alias = example;


template<typename F1, typename F2>
struct overload2 : public F1, public F2
{
	overload2(const F1 & f1, const F2 & f2)
		: F1(f1), F2(f2)
	{}
	//  using F1::operator();
	//  using F2::operator();
};

void f(double d)
{
	std::cout << "double d = " << d << std::endl;
}

void g(int x)
{
	std::cout << "x = " << x << std::endl;
}


int main()
{
	std::reference_wrapper<decltype(f)> fw(f);
	std::reference_wrapper<decltype(g)> gw(g);
	overload2<std::reference_wrapper<decltype(f)>,
		std::reference_wrapper<decltype(g)>> F(fw, gw);
	F(2.5);
	F(3)r
}

*/

#include <iostream>

int f1(int)
{
	std::cout << "void f1(int)" << std::endl;
	return(0);
}

int f2(double)
{
	std::cout << "void f2(double)" << std::endl;
	return(0);
}

template<typename C>
struct functorize;

template<typename R, typename... Ps>
struct functorize<R (Ps...)>
{
	functorize(R (&f)(Ps...))
		: f(f)
	{}
	R operator()(Ps... args) const
	{
		return(f(args...));
	}
	R (*f)(Ps...);
};

struct A 
{
	int operator()(int x){ 	return f1(x); };
};

struct B
{
	int operator()(double x){ return f2(x); };
};

struct C : B, A
{

};

struct c5 : functorize<int (int)>, functorize<int (double)>
{
	c5(int (&f1)(int), int (&f2)(double))
		: functorize<int (int)>(f1), functorize<int (double)>(f2)
	{}
	//  using functorize<int (int)>::operator(), functorize<int (double)>::operator();
};

int main()
{
	c5 c5_obj(f1, f2);
	c5_obj(3.3);
	c5_obj(3);
	C c;
	c(3);
	c(3.3);

}

