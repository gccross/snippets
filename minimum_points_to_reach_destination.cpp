#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

pair<int,int> min_points(const vector<vector<int>>& v, size_t R, size_t C)
{
	int init{0}, subtotal{0};

	if (R == 1 || C == 1) {
		if (R == 1)
			for (size_t i=0; i<C; ++i) {
				subtotal += v[0][i];
				if (init + subtotal < 1) init += 1 - (init + subtotal);
			}
		else // C == 1
			for (size_t i=0; i<R; ++i) {
				subtotal += v[i][0];
				if (init + subtotal < 1) init += 1 - (init + subtotal);
			}
		return make_pair(init, subtotal);
	}

	const pair<int,int> val_left =  min_points(v, R, C-1);
	const pair<int,int> val_up =  min_points(v, R-1, C);

	int init_left = val_left.first;
	int init_up = val_up.first;
	int subtotal_left = v[R-1][C-1] + val_left.second;
	int subtotal_up = v[R-1][C-1] + val_up.second;

	if (init_left + subtotal_left < 1) init_left += 1 - (init_left + subtotal_left);
	if (init_up + subtotal_up < 1) init_up += 1 - (init_up + subtotal_up);

	if (init_left < init_up)
		return make_pair(init_left, subtotal_left);
	return make_pair(init_up, subtotal_up);
}

int main(const int argc, const char * const argv[])
{

	size_t T, R, C;
	cin >> T;
	while (T--)
	{
		cin >> R;
		cin >> C;

		vector<vector<int>> m(R, vector<int>(C));
		for (size_t r=0; r<R; ++r)
			for (size_t c=0; c<C; ++c)
				cin >> m[r][c];

		// easy check
		for (size_t r=0; r<R; ++r) {
			for (size_t c=0; c<C; ++c) {
				cout << m[r][c] << "\t";
			}
			cout << endl;
		}
	
		//for each path to m[R-1][C-1]
		//	accumulate values in each cell
		// 		while keeping a telltale of greatest negative subtotal
		//	value of path is (greatest negative subtotal) * -1 +1;

		cout << min_points(m, R, C).first << endl;
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
/*
 2
 3 3
 -2 -3 3 -5 -10 1 10 30 -5
 8 7
-30 -5 29 1 18 30 6 20 -15 -21 -12 -20 -21 -21 9 -4 17 -22 -14 -18 3 -9 -1 -14 14 -2 -17 -5 -20 6 19 -19 -3 -30 -1 19 -30 12 -12 16 25 16 17 -18 14 3 -18 6 19 -13 27 -15 0 -11 1 9
*/
