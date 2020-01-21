#include <iostream>
#include <string>

using namespace std;


class A
{
public:
	virtual ~A() { foo(); } 
	virtual void foo() { cout << "From A" << endl; } 
};

class B : public A
{
	virtual ~B() { foo(); };
	virtual int foo(char c) { cout << "From B" << endl; return 5; }
};

int main () 
{
	A* pa = new B;
	pa->foo('t');
	delete pa;
	
	return 0;
}

/*


class A
{
	string s;
protected:
	A(const string& _s): s(_s) {}
public:
	const string& getname() { return s; }
	const char* speak() { return "???"; }
};

class B : public A
{
public:
	B(const string& _s): A(_s) {}
	const char* speak() { return "Meao"; }

};

int main (int argc, char const * argv[])
{
		B b("Fred");
		A *pA = &b;
		cout << pA->getname() << " " << pA->speak() << endl;
		return 0;

}
*/

/*
struct A { void f(); };
struct B { void f(); };
struct C : A, B {};
int main()
{
	C* pc;

	pc->A();
	pc->A::f();
	pc->B::f();
	pc->A::B::f();
	return 0;
}
*/
