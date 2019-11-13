#include <algorithm>
#include <iostream>
#include <iterator>
 
using namespace std;
 
unsigned get_bitfield_section(unsigned _num)
{
    unsigned section = 0;
	int num { static_cast<int>(_num) };  // need signed int for next line
    while ((num-=64)  > -1) 
        section++;

    return section;
}
int main(int argc, char const * const argv[]) {
    size_t T;
    cin >> T;
    while (T--) {
        size_t N;
        cin >> N;
        unsigned int a[N];
        
        uint64_t bits[4]; // largest sum can't be > 209 (104+105)
		fill(bits, bits+4, 0UL);
        size_t i{N};
        while (i--) {
            cin >> a[i];
            uint64_t mask = 1UL << (a[i] - 1); // don't forget UL on the constant.  Otherwise, you wrap at 32 bits.
            unsigned section = get_bitfield_section(a[i]);
            bits[section] |= mask;
        }
        
        int count=0;
        for (unsigned i=0; i<N-1; ++i) {
            for (unsigned j=i+1; j<N; ++j) {
                
                uint64_t sum = a[i]+a[j];
                if (sum > 104+105) continue; // according to problem description
                
				uint64_t mask = 1UL << (sum - 1);
                unsigned section = get_bitfield_section(sum);
				
				bool res = mask & bits[section];
                if (res) ++count;
            }
        }
        cout << (count == 0 ? -1 : count) << endl;
    }
    return 0;
}
// Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.
// 
// Input:
// The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting size of array and the second line contains N space separated elements.
// 
// Output:
// For each test case, print the count of all triplets, in new line. If no such triplets can form, print "-1".
// 
// Constraints:
// 1 <= T <= 100
// 3 <= N <= 105
// 1 <= A[i] <= 106
// 
// Example:
// Input:
// 2
// 4
// 1 5 3 2
// 3
// 3 2 7
// Output:
// 2
// -1
// 
// Explanation:
// Testcase 1: There are 2 triplets: 1 + 2 = 3 and 3 +2 = 5
// 

