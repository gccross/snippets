#include <iostream>
#include <iomanip>

using namespace std;


int main (int argc, char const * argv[])
{
	cout << "Hello World " __FILE__ << endl;

	auto factorial = [](int N) {
		int res = 0, i=N;
		while (i--)  res += N-i; 
		return res;
	};

	string s;
	cin >> setw(2) >> s;
	int N = stoi(s);

	
	cout << "input: " << N << " factorial: " << factorial(N) << endl;
	return 0;

}
