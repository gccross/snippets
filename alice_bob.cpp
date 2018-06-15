#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Given 2 lines of NUM_RANKINGS positive integers, score each position 
// and total in a result like so:
//
// Input:
//
// 2 3 4
// 5 3 2
//
// Output:
//
// 1 1
//
// This is the Alice and Bob ranking problem from hackerrank.com
// https://www.hackerrank.com/challenges/compare-the-triplets/problem
//

// Complete the solve function below.
template <typename InputIt, typename OutputIt>
OutputIt solve(InputIt a_first, InputIt a_last, InputIt b_first, OutputIt it_res) {

    uint alice=0, bob=0;
    for (; a_first!=a_last; a_first++, b_first++) 
    { 
        if (*a_first>*b_first) alice++;
        else if (*b_first>*a_first) bob++;
    }
    
    *it_res=alice;
    *it_res=bob;
    return it_res;
}

int main()
{
    uint const NUM_RANKINGS=3;

    string line;
   
    vector<uint> alice_rank(NUM_RANKINGS);
    vector<uint> bob_rank(NUM_RANKINGS);
    vector<uint> results;

    for (uint i = 0; i < NUM_RANKINGS; i++)  cin >> alice_rank[i];
    for (uint i = 0; i < NUM_RANKINGS; i++)  cin >> bob_rank[i];

    solve(alice_rank.begin(), alice_rank.end(),bob_rank.begin(), back_inserter(results));

    copy(results.begin(), results.end(), ostream_iterator<int>(cout));

    return 0;
}

