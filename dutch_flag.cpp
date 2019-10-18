#include <algorithm>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>
using namespace std;

template <typename It>
void quicksort(It first, It last)
{
	if (last <= first) return; // base case
	It median = first, left = first, right = last;
	while (right > left) {
		while (*left < *median) ++left;
		while (*right > *median) --right;

		if (left > right) break;
		
		swap(*left, *right);

		++left;
		--right;
			
		quicksort(first, right);
		quicksort(left, last);
	}
}

void dutch_flag2()
{
	size_t N;
	cin >> N;
	vector<unsigned short> v(N);
	copy(istream_iterator<unsigned short>(cin), istream_iterator<unsigned short>(), back_insert_iterator<vector<unsigned short>>(v)); 
	
	quicksort(v.begin(), v.end());
	for (unsigned short i : v) cout << i << ' ';
	cout << endl;
}


void dutch_flag()
{
    size_t N;
    cin >> N;
    string s;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin,s);
    
    size_t a[3] {0,0,0};
    
    while (N--) {
        char c = s[2*N];
        switch (c) {
            case '0': ++a[0]; break;
            case '1': ++a[1]; break;
            case '2': ++a[2]; break;
            default: break;
        }
    }
    for (size_t i=0; i<2; ++i)
        while (a[i]--) cout << i;
    cout << endl;
}

int main() {
	size_t T;
	cin >> T;
	while (T--)
	    dutch_flag2();
	return 0;
}
