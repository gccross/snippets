#include <algorithm>
#include <iostream> 
#include <vector>
using namespace std;
bool is_prime(int num, int div)
{
	if (1==div) return true;
	return num%div && is_prime(num, div-1);

}

bool is_prime(int a)
{
	return is_prime(a,a-1);
}

vector<int>::iterator find_primes(int a, vector<int>& primes)
{
	int n(1);
	while ((n+=2) <= a) 	
		if (is_prime(n)) primes.push_back(n);
	return primes.begin();
}

int main (int argc, const char* const* argv)
{
	int a=0;
	if (1 >= argc) 
		cin >> a;

	cout << "Is " << a <<  " prime?: "  << boolalpha << is_prime(a) << endl;
	cout << "All the primes in between: " << endl;

	vector<int> primes;
	copy(find_primes(a,primes),vector<int>().end(), ostream_iterator<int>( cout, "\t"));

	return 0;
};
