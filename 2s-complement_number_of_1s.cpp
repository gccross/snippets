#include <iostream>
using namespace std;

int main(const int argc, const char * const argv[])
{


	int x;
	cin  >> x;
	int c(0);
	int y{~x}, q(x);
	while (x>>=1) ++c; // calculate home many bit places
	int z = 1; 		
	z<<=(c);			// get 1000 ... 00 (as many bit places as just calculated )
	z-= 1;				// get 01111 ... 11 (as many bit places as just calclulated) 
	
	cout << q << "\t" << (y&z) << "\t" << z << "\t" << c << endl;

	// twos complement
	string s;
	cout << "Hello World " __FILE__ << endl;
	cout << "Enter something... " << endl;
	while (getline(cin,s))
	{
		int x = atoi(s.c_str());
		cout << "Using xor (^): " << (x ^ -1) + 1 << endl; 
		cout << "Using not (~): " << ~x  + 1 << endl; 
	}
		
	return 0;
}
