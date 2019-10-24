#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

template <typename It>
It get_max(It first, It last)
{
    It max = first;
    while (++first != last)
    {
        max = (*first > *max) ? first : max;
    }
    return max;
}
int main() {
	//code
	size_t T;
	cin >> T;
	while (T--) {
	    size_t N, K;
	    cin >> N;
	    vector<uint16_t> v;
	    copy_n(istream_iterator<uint16_t>(cin), N, back_inserter(v));
	    cin >> K;
	    vector<uint16_t>::iterator max = get_max(v.begin(), v.begin() + K);
	    for (vector<uint16_t>::iterator it=v.begin()+K; it!=v.end(); ++it){
	        if (*it < *max) *max = *it;
	        max = get_max(v.begin(), v.begin() + K);
	    }
	    cout << *max  << endl;
	}
	return 0;
}
