/*
#include <algorithm>
#include <iostream>
using std::min;


int main()
{
	int x = 12, y = 14;
	std::cout << min(x,y) ;
	std::cout << std::max(x,y) ;
	return 0;
}
*/

/*
#include <iostream>
#include <set>

using namespace std;

set<int>& newset()
{
	set<int> s;
	return s;
}

int main (int argc, char const * argv[])
{
	set<int>& s = newset();
	cout << "Hello World " __FILE__ <<  endl;
	s.insert(5); // seg fault
		return 0;

}
*/

/*
int a[3][5];
struct Bar;
struct Foo
{
	Foo() {}
	//Foo(const Bar& b) {}
};
struct Bar
{
	Bar() {};
};
int main()
{
	Foo foo;
	foo = Bar();

	return 0;

};

*/

/*
#include <iostream>
#include <vector>
using namespace std;

template <int N>
struct S { enum { value = S<N/2>::value + (N%2) }; };
template <>
struct S<0> { enum { value = 0 }; };

int main()
{
	vector<int> v5;
	v5.push_back(1); 
	v5.push_back(1); 
	v5.push_back(1); 
	v5.push_back(1); 
	v5.push_back(1); 
	vector<int> v0;
	cout << sizeof(v5) << " " << sizeof(v0) << endl; // same size
	cout << S<65535>::value << endl; 
	return 0;
}
*/

#include <iostream>

using namespace std;

class C 
{
	string name;
public:
	C() { cout << "default ctr" << endl; } 
	C(const C& ) { cout << "Copy ctr" << endl; }
	C(string n): name(n) {};
	C& operator=(C ) { cout << "assign op" << endl;  return *this; } 
	~C() { cout << "destructor " << name << endl; }
};

// what is order of output? Woof, Bar, Foo 
class Woof
{
public:
	Woof() { cout << "Woof" ; } 
};
class Foo
{
public: 
	Foo(){ cout << "Foo"; }
};
class Bar: public Foo
{
public: 
	Bar(): woof(new Woof()) { cout << "Bar"; } 
	Woof* woof;
};

void foo(bool x)
{
	// what is order of destructor calls ?
	C a("a"); 
	C b("b");
	if (x) return;
	C c("c");
}

C getC()
{
	cout << "getC" << endl;
	C c = C();
	return c;
}

void myFunction(const ostream_iterator<int>& p) 
{
	cout << endl;
}
int main (int argc, char const * argv[])
{

	int N = 10;
	for (int i=0; i<N; ++i) cout << i << " " ;
	cout << endl;
	for (int i=0; i<N; i++) cout << i << " " ;
	cout << endl;
	int x[3][5];
	//cout << decltype(x) << endl;
	Bar* bar = new Bar();
	//myFunction(nullptr); // compile error
	const int& b = 5;
	cout << "Hello World " __FILE__ << endl;
//	C x = getC(); // -fno-elide-constructors, otherwise no copy ctr called
	foo(true);
	return 0;
}
