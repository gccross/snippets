#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <utility>
#include <vector>

using namespace std;

class Solution {

	int C;
	int shortest_path; 
	vector<int> path;

public:
	Solution(int cols): C(cols), shortest_path( numeric_limits<int>::max()) {};
	int count_paths(int const * m, size_t const row, size_t const col)
	{
		int subtotal=0, max_negative_subtotal = 0;
		if (0 == row || 0 == col) {

			// add up the row or col, recording the most negative value
			if (0 == row) 
					for (size_t c=0; c<=col; ++c) {
						subtotal += m[c];
						max_negative_subtotal = min(subtotal, max_negative_subtotal);
					}
			else // 0 == col
					for (int r = 0; r<=row*C; r+=C)
					{
						subtotal += m[r];
						max_negative_subtotal = min(subtotal, max_negative_subtotal);
					}

			// now add up the rest of the path, recording the most negative value
			// go backward through the vector, since we need to go forward through the path
			for (vector<int>::reverse_iterator it = path.rbegin();  it!=path.rend(); ++it){
				subtotal += *it;
				max_negative_subtotal = min(subtotal, max_negative_subtotal);
			}

			shortest_path = min(max_negative_subtotal*-1 +1, shortest_path);

		} else {
			// continue up the path
			path.push_back(m[row*C + col]);
			count_paths(m, row-1, col); 
			count_paths(m, row, col-1);
			path.pop_back();
		}

		return shortest_path;
	}
};

int main(const int argc, const char * const argv[])
{

	size_t T, R, C;
	cin >> T;
	while (T--)
	{
		cin >> R;
		cin >> C;

		Solution s(C);
		int m[R*C];
		for (int r=0; r<R; ++r)
			for (int c=0; c<C; ++c)
				cin >> m[r*C+c];

		// easy check
		for (int r=0; r<R; ++r) {
			for (int c=0; c<C; ++c) {
				cout << m[r*C+c] << "\t";
			}
			cout << endl;
		}
	
		//for each path to m[R-1][C-1]
		//	accumulate values in each cell
		// 		while keeping a telltale of greatest negative subtotal
		//	value of path is (greatest negative subtotal) * -1 +1;

		cout << s.count_paths(m, R-1, C-1) << endl;
	} 
	return 0 ;
}
// From G4G
//
// Given a grid with each cell consisting of positive, negative or no points i.e, zero points. 
// We can move across a cell only if we have positive points ( > 0 ). 
// Whenever we pass through a cell, points in that cell are added to our overall points. 
// We need to find minimum initial points to reach cell (m-1, n-1) from (0, 0) by following these certain set of rules :
//  
// 		1.From a cell (i, j) we can move to (i+1, j) or (i, j+1).
// 		2.We cannot move from (i, j) if your overall points at (i, j) is <= 0.
// 		3.We have to reach at (n-1, m-1) with minimum positive points i.e., > 0.
//  
// Example:
//  
// Input: points[m][n] = { {-2, -3,   3},  
//                         {-5, -10,  1},  
//                         {10,  30, -5}  
//                       };
// Output: 7
// Explanation:  
// 7 is the minimum value to reach destination with  
// positive throughout the path. Below is the path.
//  
// (0,0) -> (0,1) -> (0,2) -> (1, 2) -> (2, 2)
//  
// We start from (0, 0) with 7, we reach(0, 1)  
// with 5, (0, 2) with 2, (1, 2) with 5, (2, 2)
// with and finally we have 1 point (we needed  
// greater than 0 points at the end).
// 
// Input:
// 
// The first line contains an integer 'T' denoting the total number of test cases.
// In each test cases, the first line contains two integer 'R' and 'C' denoting the number of rows and column of array.  
// The second line contains the value of the array i.e the grid, in a single line separated by spaces in row major order.
// 
// 
// Output:
// 
// Print the minimum initial points to reach the bottom right most cell in a separate line.
// 
// 
// Constraints:
// 
// 1 ≤ T ≤ 30
// 1 ≤ R,C ≤ 10
// -30 ≤ A[R][C] ≤ 30
// 
// 
// Example:
// 
// Input:
// 2
// 3 3
// -2 -3 3 -5 -10 1 10 30 -5
// 8 7
//-30 -5 29 1 18 30 6 20 -15 -21 -12 -20 -21 -21 9 -4 17 -22 -14 -18 3 -9 -1 -14 14 -2 -17 -5 -20 6 19 -19 -3 -30 -1 19 -30 12 -12 16 25 16 17 -18 14 3 -18 6 19 -13 27 -15 0 -11 1 9
// Output:
// 7
// 31
// 

