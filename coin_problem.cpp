//	Given a value V. You have to make change for V cents, given that you have infinite supply of each of 
//	C{ C1, C2, .. , Cm} valued coins.  	Find the minimum number of coins to make the change.
//	
//	Input:
//	The first line of input contains an integer T denoting the number of test cases. 
//	The first line of each test case is V and N, V is the value of cents and N is the number of coins. 
//	The second line of each test case contains N input C[i], value of available coins.
//	
//	Output:
//	Print the minimum number of coins to make the change, if not possible print "-1".
//	
//	Constraints:
//	1 ≤ T ≤ 100
//	1 ≤ V ≤ 106
//	1 ≤ N ≤ 106
//	1 ≤ C[i] ≤ 106
//	
//	Example:
//	Input:
//	1
//	7 2
//	2 1
//	
//	Output:
//	4
//	
//	Explanation :
//	Testcase 1: We can use coin with value 2 three times, and coin with value 1 one times to change a total of 7.
//	
//	
//	Input:
//	7685 27
//	55 38 85 57 69 90 70 98 20 66 17 43 94 96 68 93 84 74 37 97 11 71 73 39 54 83 82
//	
//	Its Correct output is:
//	79
//	
//	And Your Code's output is:
//	80
//	
//	Input:
//	8777 5
//	86 7 43 67 6
//	
//	Its Correct output is:
//	103
//	
//	And Your Code's output is:
//	102
//	
#include <algorithm>
#include <functional>
#include <limits>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, const char* const argv[]) {

    unsigned n_tests(0);
    cin >> n_tests;
    while (n_tests--) {
        unsigned V(0), N(0) ;
        cin >> V >> N;

	// next line of input is the set of coin denominations.  we call it the purse. 
	typedef vector<unsigned> coin_purse_type;
	typedef coin_purse_type::iterator coin_iterator_type;
	typedef coin_purse_type::reverse_iterator coin_reverse_iterator_type;
        coin_purse_type coin_purse;
        coin_purse.reserve(N);

	// read it as a whole line
        string line;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,line);
        istringstream s(line);
	
	// denominations have been read, now put into a structure
        copy(istream_iterator<unsigned>(s), istream_iterator<unsigned>(), back_insert_iterator<coin_purse_type>(coin_purse));

	// sort and unique them
	sort(coin_purse.begin(), coin_purse.end(),greater<unsigned>()); 
	unique(coin_purse.begin(), coin_purse.end());

	// sanity check
	if (V < *coin_purse.rbegin()) { cout << -1 << endl; return 0; }


	// the coin stack is a collection of the denominations provided which total the value we seek
	// seed it with one coin of the first biggest denomination
	coin_purse_type coin_stack; 
	coin_stack.reserve(2048);
	coin_stack.push_back(*coin_purse.begin());

	// other administriviae
	coin_reverse_iterator_type combo_basis(coin_stack.rbegin());
	coin_iterator_type denomination_iterator;
	unsigned res(numeric_limits<unsigned>::max());

	// now, let's get to calclating
	do {
		unsigned remainder(V);

		// find combos of coins that total V
		while (remainder && coin_stack.rend()!= combo_basis ) {

			// position the denomination pointer to the next smaller denomination
			denomination_iterator = find(coin_purse.begin(), coin_purse.end(), *combo_basis);
			++denomination_iterator;  

			// pop the next coin from the base, so we can build another coin combo
			coin_stack.erase(--(combo_basis++).base(),coin_stack.end());

			// start at the lowest denomination of coin_stack if is the first time through)
			if (coin_stack.rend() == combo_basis && coin_purse.end()!=denomination_iterator) --denomination_iterator;

			// now calculate the new remainder
			remainder = V - accumulate(coin_stack.begin(), coin_stack.end(), 0);

			// now with the remaining denominations, try to make the total again
			for (; denomination_iterator != coin_purse.end(); ++denomination_iterator)
			{
				unsigned quotient = remainder / *denomination_iterator;
				coin_stack.insert(coin_stack.end(), quotient, *denomination_iterator);
				remainder = remainder % *denomination_iterator;
			}

			combo_basis = coin_stack.rbegin();
		}

		if (!remainder) {
			unsigned new_res =  coin_stack.size();
			if (res > new_res) res = new_res;
		}

	} while (coin_stack.rend() != combo_basis && coin_stack.size() < 150);  // this could be a long time, if no combos can work

	cout << (numeric_limits<unsigned>::max() == res ? -1 : res)  << endl;
    }

	
    return 0;
}
