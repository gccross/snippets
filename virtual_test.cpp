#include<iostream>
using namespace std;

class base {
	public:
		virtual void show() {  // Note the virtual keyword here
			cout<<"In base \n";
		}
};


class derived: public base {
	public:
		void show() {
			cout<<"In derived \n";
		}
};

class derived2: public derived {
	public:
		void show() {
			cout << "In derived2 " << endl;
		}

};

class Base
{
	public:
		virtual int f(int i)
		{
			cout << "f(int) Base: ";
			return i+3;
		}
};
class Derived : public Base
{
	public:
		int f(int i) 
		{
			cout << "f(int) Derived: ";
			return i+3;
		}
		double f(double d) 
		{
			cout << "f(double) Double: ";
			return d+3.3;
		}
};

void print(base &b) {
	b.show();
}

int main(void) {
	base b;
	derived d;
	derived2 dd;
	print(b);
	print(d);
	print(dd);
	Derived D;
	Base& dp (D);
	cout << dp.f(3) << '\n';
	cout << dp.f(3.3) << '\n';
	return 0;
}
