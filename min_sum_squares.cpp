// Find the minimum number of squares to make the sum of N
//
//
#include <algorithm> 
#include <array>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

template <size_t N>
constexpr auto  gen_array() 
{
	array<size_t, N> result{};
	for (unsigned i=0; i<N; ++i) { result[i] = i*i; }
	return result;
}

// test this out if you like, switch to true
#ifdef false
template <int T> class foo;
foo<gen_array<1000>()[999]> i;
#endif

array<size_t, 100> arr = gen_array<100>();
int main (int argc, char const * argv[])
{

	unsigned tc;
	cin >> tc; 

	while (tc--) {
		
		unsigned N; 
		cin >> N;
		array<size_t, 100>::iterator it_biggest  = upper_bound(arr.begin(), arr.end(), N);

		vector<size_t> dp(N+1,numeric_limits<size_t>::max());
		dp[0] = 0;
		for (array<size_t,100>::iterator it=arr.begin(); it!=it_biggest; ++it) 
			for (vector<size_t>::iterator it2=dp.begin()+*it; it2!=dp.end(); ++it2) 
				if (*(it2 - *it)!= numeric_limits<size_t>::max() && *it2 > *(it2 - *it)+1 )
					*it2 = *(it2 - *it) + 1;
			
		if (numeric_limits<size_t>::max() == dp[N] ) cout << -1 << endl;
		else cout << dp[N] << endl;
	}

	cout << "Hello World " __FILE__ << endl;


	cout << endl;


	return 0;

}
