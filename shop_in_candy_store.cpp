#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>   
using namespace std;

int main(int const argc, const char* const argv[]) {
	size_t T;
	cin >> T;
	while (T--) {
	    size_t N, K;
	    cin >> N >> K;
	    vector<unsigned> a(N);
	    copy_n(istream_iterator<unsigned>(cin), N, a.begin());
	    sort(a.begin(), a.end());

	    unsigned amount = 0;
	    int mid = N;
	    for (int i = 0; i<mid; ++i) {
	        mid -= K;
	        amount += a[i];
	    }
	    cout << amount << " " ;
	    
	    amount = 0;
	    mid = 0;
	    for (int i=N-1; i>=mid; --i) {
	        mid += K;
	        amount += a[i];
	    }
	        
	    cout << amount << endl;
	    
	}
	return 0;
}
/*
In a candy store there are N different types of candies available  and the prices of all the N different types of candies are provided to you.
You are now provided with an attractive offer.
You can buy a single candy from the store and get atmost K other candies ( all are different types ) for free.
Now you have to answer two questions. Firstly, you have to tell what is the minimum amount of money you have to spend to buy all the N different candies. Secondly, you have to tell what is the maximum amount of money you have to spend to buy all the N different candies.
In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.
 

Input  
The first line of the input contains T the number of test cases. Each test case consists of two lines. The first line of each test case contains the values of N and K as described above.  Then in the next line N integers follow denoting the price of each of the N different candies.
 

Output 
For each test case output a single line containing 2 space separated integers , the first denoting the minimum amount of money required to be spent and the second denoting the maximum amount of money to be spent.
Remember to output the answer of each test case in a new line.

Constraints      
1 <= T <= 50
1 <= N <= 1000
 0 <= K <= N-1
1 <= Ai <= 100
 
Expected Time Complexity: O(nlogn);
 
Sample:

1
42 29
35 1 70 25 79 59 63 65 6 46 82 28 62 92 96 43 28 37 92 5 3 54 93 83 22 17 19 96 48 27 72 39 70 13 68 100 36 95 4 12 23 34

Its Correct output is:
4 196





*/

