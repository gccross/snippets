#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;

size_t merge_inv_count(uint64_t a[], size_t len_a, uint64_t b[], size_t len_b)
{
	// a[] and b[] by definition are left and right half of one array
	size_t i=len_a, j=len_b, res=0;
	while (i--) {
		uint64_t temp = a[i];
		uint64_t* it = lower_bound(a+i+1,b+len_b,a[i]);
		res+=distance(a+i+1, it);
		it = move(a+i+1,it,a+i);
		*it = temp;
	}
	return res;
}

size_t sort_and_count(uint64_t a[], size_t len)
{
    if (2 == len) 
		if (a[0] > a[1]) {
			swap(a[0], a[1]);
			return 1;
		} else return 0;
    else if (1 == len) 
        return 0;
    else {
        size_t res = sort_and_count(a,len/2) + sort_and_count(a + len/2,len - len/2);
		res+=merge_inv_count(a, len/2, a+len/2, len - len/2);
		return res;
	}
	
}

int main (int argc, char const * const argv[])
{

    size_t T=0; 
    cin >> T;
    while (T--)
    {   
        size_t N, res=0; 
        cin >> N; 
        uint64_t a[N]; 
        for (size_t i=0; i<N; ++i) cin >> a[i];
        
        res = sort_and_count(a,N);
        
        cout << res << endl;
    }
    return 0;
}

//	Given an array of positive integers. The task is to find inversion count of array.
//	
//	Inversion Count : For an array, inversion count indicates how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. 
//	Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
//	
//	Input:
//	The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, the size of array. The second line of each test case contains N elements.
//	
//	Output:
//	Print the inversion count of array.
//	
//	Constraints:
//	1 ≤ T ≤ 100
//	1 ≤ N ≤ 107
//	1 ≤ C ≤ 1018
//	
//	Example:
//	Input:
//	1
//	5
//	2 4 1 3 5
//	
//	Output:
//	3
//	
//	Explanation:
//	Testcase 1: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
//	
//	

// testcase:
//	1
//	34
//	174 165 142 212 254 369 48 145 163 258 38 360 224 242 30 279 317 36 191 343 289 107 41 443 265 149 447 306 391 230 371 351 7 102
//
// 	Correct output is 238

