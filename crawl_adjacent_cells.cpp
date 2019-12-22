#include <algorithm>
#include <array>
#include <iostream>
#include <utility>
#include <set>
using namespace std;

set<pair<size_t, size_t>> dp;

template <typename T, size_t rows, size_t cols>
void fn(array<array<T, cols>, rows> const& a, T val, size_t x, size_t y)
{
	pair<size_t, size_t> p = make_pair(x,y);
	if (dp.insert(p).second) 
	{
		cout << "[" << p.first << "," << p.second << "], ";

		if (x > 0 && a[x-1][y] == val) fn(a,val,x-1,y);
		if (y > 0 && a[x][y-1] == val) fn(a,val,x,y-1);
		if (x < a.size()-1 && a[x+1][y] == val) fn(a,val,x+1,y);
		if (y < a[0].size()-1 &&  a[x][y+1] == val) fn(a,val,x,y+1);
	}	

} 

int main(int const argc, char const * const argv[])
{
	// Input:
	//	0 0 1 1 0 0 
	//	0 1 1 0 1 0
	//	0 0 1 1 1 0 
	//	0 1 0 1 0 0 
	//	0 0 0 0 1 0
	//	
	// Output:
	// [2,1], [1,1], [1,2], [0,2], [0,3], [2,2], [2,3], [3,3], [2,4], [1,4], [3,1],

	
	array<array<int, 6>, 5> a {{{ { 0, 0, 1, 1, 0, 0 }}, {{ 0, 1, 1, 0, 1, 0 }}, {{ 0, 0, 1, 1, 1, 0 }}, {{ 0, 1, 0, 1, 0, 0}}, {{ 0, 0, 0, 0, 1, 0 }} }};

	fn<int,5 ,6>(a, 1, 2, 1);
	cout << endl;
	return 0;
}


// BFS solution
/*
int connectedCell(vector<vector<int>> matrix) {
    int max_region = 0;
    auto at = [&](int i, int j) {
        if (i < 0 || i > matrix.size()-1 || j < 0 || j > matrix.front().size()-1)
            return 0;
        return matrix[i][j];
    };
    auto bfs = [&](int i, int j){
        if (matrix[i][j] != 1) return 0;
        matrix[i][j] = -1;
        int region = 1;
        vector<pair<int,int>> todo = {{i,j}};
        vector<int> index_arr = {-1, 0, 1};
        while (!todo.empty()) {
            vector<pair<int, int>> tmp;
            for (auto& p : todo) {
                for (int ii : index_arr) {
                    for (int jj : index_arr) {
                        if (at(p.first + ii, p.second + jj) == 1) {
                            region++;
                            matrix[p.first + ii][p.second + jj] = -1;
                            tmp.push_back({p.first + ii, p.second + jj});
                        }
                    }
                }
            }
            tmp.swap(todo);
        }
        return region;
    };
    for (int i=0; i<matrix.size(); i++) {
        for (int j=0; j<matrix.front().size(); j++) {
            max_region = max(max_region, bfs(i, j));
        }
    }
    return max_region;
}
*/
