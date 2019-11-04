#include <algorithm>
#include <iterator>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main(int argc, const char* const argv[])
{
	size_t T;
	cin >> T;
	while (T--) 
	{
		size_t N;
		cin >> N;
		uint16_t a[N];
		copy_n(istream_iterator<uint16_t>(cin), N, a);

		uint16_t l[N];
		uint16_t r[N];

		l[0] = 0; 
		for (int i = 1; i < N;++i) 
			l[i] = max(l[i-1], a[i-1]);	

		r[N-1] = 0;
		for (int i = N-2; i >= 0 ; --i) 
			r[i] = max(r[i+1], a[i+1]);	

		uint32_t water = 0;
		for (int i = 0; i < N ; ++i)
			if ( min(l[i], r[i]) > a[i]) 
				water += min(l[i],r[i]) - a[i];
		
		cout << water << endl;
	}
		

	return 0;
}


/*

	for i in A[1..N] 
	look for a left containing wall:
		• a left containing wall A[i] is any column with a smaller one at A[i+1]
		if A[i] is a left containing wall:
			• search for a right containing wall in A[i+2..N]:
				• a right containing wall A[j] where j > i+1, A[j] > A[i+1]

*/



	
