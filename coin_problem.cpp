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
#include <numeric>
#include <string>
#include <sstream>
#include <vector>


using namespace std;

// given an existing stack of coins, and a purse, add to the stack with appropriate coins to total the amount desired
int main(int argc, const char* const argv[]) {

    unsigned n_tests(0);
    cin >> n_tests;
    while (n_tests--) {
        unsigned V(0), N(0) ;
        cin >> V >> N;

	// next line of input is the set of coin denominations.  
	typedef vector<pair<unsigned,unsigned>> coin_stack_type;
	typedef coin_stack_type::iterator coin_iterator_type;
	typedef coin_stack_type::reverse_iterator coin_reverse_iterator_type;

        coin_stack_type coin_stack;

	// read it as a whole line
        string line;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,line);
        istringstream s(line);
	
	// denominations have been read, now put into a structure
	{
		vector<unsigned> temp;
		copy(istream_iterator<unsigned>(s), istream_iterator<unsigned>(), back_insert_iterator<vector<unsigned>>(temp));

		// sort and unique them
		sort(temp.begin(), temp.end(),greater<unsigned>()); 
		unique(temp.begin(), temp.end());

		// sanity check
		if (V < *temp.rbegin()) { cout << -1 << endl; return 0; }

		for (vector<unsigned>::value_type& t: temp) coin_stack.push_back(make_pair(t, 0));

	} // end temp

	// helper functions
	const auto sum_coins = [](coin_iterator_type first,coin_iterator_type last)->unsigned long
			{ 
				unsigned long res(0);
				for (coin_iterator_type it=first; last!=it; ++it) res+=it->first*it->second;
				return res;
			};
	const auto sum_number_coins = [](coin_stack_type& cs)->unsigned 
			{
				unsigned long res(0);
				for (coin_iterator_type it=cs.begin(); cs.end()!=it; ++it) res += it->second;
				return res;
			};
	const auto more_combos = [] (coin_stack_type& cs) ->bool {
				for (coin_iterator_type it = cs.begin(); cs.end()-1!=it; ++it) // all but the last
					if (it->second) return true;
				return false;
			};

	// other administriviae
	coin_iterator_type denomination_it;
	coin_reverse_iterator_type denomination_reverse_it;
	unsigned res(numeric_limits<unsigned>::max());
	unsigned number_exact_change(0);
	unsigned remainder(V);

	// now, let's get to calclating

	// find combos of coins that total V
	do {

		// find which domination we last used
		for (denomination_reverse_it = coin_stack.rbegin(); 
			denomination_reverse_it!=coin_stack.rend() && 0==denomination_reverse_it->second; 
			++denomination_reverse_it);
	
		// if this is the first time through, (eg. stack is empty)
		// start at the first denomination of coin_stack to build the next combo
		if (coin_stack.rend() == denomination_reverse_it)
			--denomination_reverse_it;
		else if (coin_stack.rbegin() == denomination_reverse_it) {
			// pop a coin off the base and build a new combo
			coin_reverse_iterator_type coin_pop_it = denomination_reverse_it + 1;
			while (coin_stack.rend() != coin_pop_it && 0 == coin_pop_it->second ) ++coin_pop_it;
			if (coin_stack.rend() == coin_pop_it) break; // nothing more can do
			else --coin_pop_it->second;		// pop a coin
			denomination_reverse_it = --coin_pop_it; // start next denomination up
		}  else {
			--denomination_reverse_it->second; // pop a coin
			--denomination_reverse_it; // start next denomination up
		}

		// now calculate the new remainder
		remainder = V - sum_coins(coin_stack.begin(), --denomination_reverse_it.base());

		// now with the remaining denominations, try to make the total again
		for (denomination_it = --denomination_reverse_it.base(); 
			denomination_it != coin_stack.end(); 
			++denomination_it)
		{
			unsigned quotient = remainder / denomination_it->first;
			denomination_it->second = quotient;
			remainder = remainder % denomination_it->first;
		}


		if (!remainder) {
			++number_exact_change;
			unsigned new_res = sum_number_coins(coin_stack);
			if (res > new_res) res = new_res;
			
		}
	} while (more_combos(coin_stack) && number_exact_change < 50); //enough at 50


	cout << (numeric_limits<unsigned>::max() == res ? -1 : res)  << endl;
    }

	
    return 0;
}
