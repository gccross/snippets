#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    using vitype=vector<int>::const_iterator;

    int pivotIndex(const vector<int>& nums) {
        if (!nums.size()) return -1;
        int left_total{0}, right_total{accumulate(nums.begin()+1, nums.end(),0)};
        vitype vit=nums.begin(); 
        while (vit!=nums.end()){
            if (left_total == right_total) return distance(nums.begin(),vit);
            else if (vit == nums.end() -1 ) return -1;
            left_total += *vit;
            right_total -= *(vit+1) ;
            ++vit;
        }
    }
};


int main (int const argc, char const * const argv[] )
{

	Solution s;
	cout << s.pivotIndex(vector<int>{-1,-1,0,1,1,0});
	return 0;
}
