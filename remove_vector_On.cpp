#include <iostream>
#include <random>
#include <vector>
#include <utility>

using namespace std;

int main (int argc, char const * argv[])
{
	cout << "Hello World " __FILE__ << endl;

	{
		random_device rd;
		mt19937 mt(rd());
		uniform_int_distribution<> gen(0,17);
		vector<int>  v(50);

		for (int &i: v) i = gen(mt); 
		copy(v.begin(), v.end(), ostream_iterator<decltype(v)::value_type>(cout, " "));
		cout << endl;

		int random_value = v[0];
		using vit_t = vector<int>::iterator;

		// swap to beginning of vector.  Doesn't preserve order 
		vit_t beg(v.begin());
		for(vit_t it = v.begin(); it!=v.end(); ++it) 
			if (random_value == *it) swap(*it,*beg++);
		
		// erase from beginning to new beginning
		cout << *beg << "\t" ;
		copy(v.begin(), v.end(), ostream_iterator<decltype(v)::value_type>(cout, " "));
		cout << endl;
		vit_t newbeg = v.erase(v.begin(), beg);
		cout << *newbeg << "\t";;
		
		copy(v.begin(), v.end(), ostream_iterator<decltype(v)::value_type>(cout, " "));
		cout << endl;

	}
	// try again, but using erase-remove idiom
	
	{
		random_device rd;
		mt19937 mt(rd());
		uniform_int_distribution<> uid(0,17);
		vector<int> v(71, 0);

		using vit_t = vector<int>::iterator;

		transform(v.begin(), v.end(),v.begin(), [&mt,&uid](int i) { return i+ uid(mt); });

		copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
		
		int random_value = v[0];
		vit_t it(v.begin()), it2(v.begin());

		// remove.  O(n), preserve order
		while (it!=v.end())
		{
			if (random_value != *it && it2 != it) *it2++ = *it;
			++it;
		}
		
		v.erase(it2, v.end());
		copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	
	}

	
	return 0;

}
