#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

namespace george {
template <typename It>
bool next_permutation(It first, It last, bidirectional_iterator_tag)
{
    if (first == last) return false;
    It i{last};
    if (first == --i) return false;
    
    It i1, i2;
    while (true) {
        i1 = i;
        if (*--i < *i1) {
            i2 = last;
            while (*i >= *--i2);
            iter_swap(i,i2);
            reverse(i1,last);
            return true;
        }
        if (first == i) {
            reverse (first, last);
            return false;
        }
            
    }
}
template <typename It>
bool next_permutation(It first, It last)
{
    return george::next_permutation(first, last, typename iterator_traits<It>::iterator_category());
}
} //namespace george 

int main() {
    unsigned short T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s;
        getline(cin,s);
        bool res = george::next_permutation(s.begin(), s.end());

        if (res) cout << s;
        else cout << "not possible" ;
        cout << endl;
    }
	//code
	return 0;
}
