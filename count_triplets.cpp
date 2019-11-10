#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

int main(int argc, char const * const argv[]) {
	size_t T;
	cin >> T;
	while (T--) {
	    size_t N;
	    cin >> N;
	    int a[N];
	    copy_n(istream_iterator<int>(cin), N, a);
        sort (a, a+N );
        
        int count = 0;

	    for (int i=0; i<N-2; ++i)
	        for (int j=i+1; j<N-1; ++j)
	            if (binary_search(a+2, a+N, a[i] + a[j])) ++count;
	            
	    
	    cout << (count == 0 ? -1 : count) << endl;
	}
	return 0;
}
