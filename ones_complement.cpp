#include <iostream>

using namespace std;

int main (int argc, char const * argv[])
{
	string s;
	cout << "Hello World " __FILE__ << endl;
	cout << "Enter something... " << endl;
	while (getline(cin,s))
	{
		int x = atoi(s.c_str());
		cout << (x ^ -1) + 1 << endl; 
	}
		
		return 0;

}
