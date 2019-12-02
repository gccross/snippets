#include <iostream>
using namespace std;

int main(const int argc, const char * const argv[])
{

	int x;
	cin  >> x;
	int c(0);
	int y{~x}, q(x);
	while (x>>=1) ++c;
	int z = 1;
	z<<=(c);
	z-= 1;
	
	cout << q << "\t" << (y&z) << "\t" << z << "\t" << c << endl;
	return 0;
}
