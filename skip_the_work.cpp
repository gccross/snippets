#include <chrono>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>


using namespace std;

int main (int argc, char const * argv[])
{
	int T;
	cin >> T;
	chrono::time_point<chrono::system_clock> t1 = chrono::system_clock::now();
	while (T--)
	{
		int N;
		cin >> N;
		
		vector<int> dp(N+1,0);
		dp[0] = 0;
		cin >> dp[1];

		for (int i = 2; i<N+1; ++i)
		{
			int a;
			cin >> a;

			dp[i] =  a + min(dp[i-1], dp[i-2]);
		}
		cout << min(dp[N],dp[N-1])  << endl;
	}
	cout << "Executed in " << (chrono::system_clock::now() - t1).count() << "ms" << endl;
	return 0;

}
/*
2
1
10
25
835 356 72 350 823 485 556 216 626 357 526 357 337 271 869 361 896 22 617 112 717 696 585 41 423

Given an array A[ ] denoting the time taken to complete N tasks, determine the minimum amount of time required to finish the tasks considering that you can skip any task, but skipping two consecutive tasks is forbidden.


For example
For the array arr [] = {10, 5, 2, 4, 8, 6, 7, 10}
the output will be  22  (Skip the tasks taking more time ,avoiding consective skipping(10,2,8,10). Tasks done in: 5+4+6+7)


Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow.
The first line of each test case contains a positve integer N, denoting the length of the array A[ ].
The second line of each test case contains a N space seprated positve integers, denoting the elements of the array A[ ].


Output
Print out the minimum time taken to complete the tasks.


Constraints
1 <= T <= 100
0 <   N <= 30
0 <= A[ ] <= 1000


Examples

Input
4
4
10 5 7 10
6
5 6 7 8 9 10
2
10 20
5
22 10 15 3 5

Output
12
21
10
13


*/

