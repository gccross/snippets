#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
	public:
		bool canPlaceFlowers(vector<int> const& flowerbed, int n) {

			int num_vacant{0};
			vector<int>::const_iterator curr=find(flowerbed.begin(),flowerbed.end(), 0), next;
			
			while (flowerbed.end()!=curr) {
				next = find(curr, flowerbed.end(), 1);
				int range = distance(curr,next);
				if (range){
					if (flowerbed.begin() != curr) --range	;
					if (flowerbed.end() != next) --range ;
					n -= range/2 + range%2; 
					if (n <= 0 ) return true;
				}
				curr = find(next, flowerbed.end(), 0);
			} 
			return n <= 0;
		}

};

int main(int const argc, char* const argv[])
{
	Solution s;
	string res = s.canPlaceFlowers(vector<int>{0,0,1,0,0}, 2) ? "true": "false" ;
	cout << res << endl; 
	res = s.canPlaceFlowers(vector<int>{0}, 2) ? "true": "false" ;
	cout << res << endl; 
	res = s.canPlaceFlowers(vector<int>{0}, 1) ? "true": "false" ;
	cout << res << endl; 
	res = s.canPlaceFlowers(vector<int>{0,0,1}, 1) ? "true": "false" ;
	cout << res << endl; 
	res = s.canPlaceFlowers(vector<int>{0,0,0,0,0,0}, 3) ? "true": "false" ;
	cout << res << endl; 
	res = s.canPlaceFlowers(vector<int>{0,0}, 2) ? "true": "false" ;
	cout << res << endl; 
	res = s.canPlaceFlowers(vector<int>{1}, 0) ? "true": "false" ;
	cout << res << endl; 
	return 0;

}
