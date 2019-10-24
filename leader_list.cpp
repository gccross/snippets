#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <utility>
using namespace std;

template <typename It>
class solve
{
public: 
    void operator()(It first, It last) 
    {
        leaders(first, last);
        copy(leader_list.rbegin(), leader_list.rend(), ostream_iterator<uint32_t>(cout, " ")); 
        cout << endl;
    }
private: 
    void leaders(It first, It last)
    {
        It next = first;
        ++next;
        if (next == last) leader_list.push_back(*first);
        else {
            leaders(next, last);
            if (*first > *next) 
				leader_list.push_back(*first);
        }
    }
    vector<uint32_t> leader_list;
};

int main() {
    size_t T;
    cin >> T;
    while (T--){
        size_t N;
        cin >> N;
        uint32_t  a[N];
		for (size_t i = 0; i<N; ++i)
			cin >> a[i];

        solve<uint32_t*>()(a, a+N);
        
    }
	//code
	return 0;
}
