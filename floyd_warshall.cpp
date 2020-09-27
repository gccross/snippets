#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main (int argc, char const * argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int adj[n][n], ans[n][n];
		for (int i=0; i<n; ++i)
		{
			for (int j=0; j<n; ++j)
			{
				cin >> adj[i][j];
				ans[i][j] = adj[i][j];
			}
		}

		int i=0;
		int j=0;
		int dist = 0;
		vector<bool> vis_sub(n, false);
		vector<bool> vis_loop(n, false);
		vector<int> stk(n+1,0);
		int stk_top = 0;
		for (int i=0; i<n; ++i)
		{
			stk[++stk_top] = i;
			vis_loop[i] = true;
			while (stk_top)
			{
				int j = 0;
				while (j<n)
				{
					if (vis_loop[j]==false &&  INT_MAX != adj[i][j]) 
					{
						vis_loop[j] = true;
						dist += adj[i][j];
						ans[stk.front()][j] = min(ans[stk.front()][j],dist);
						stk[++stk_top] = j;
						i = j;
						j = 0;
					}
					else
					{
						++j;
					}
				}
				dist-=adj[stk[stk_top]][i];
				j = i;
				i = stk[stk_top];
				--stk_top;
			}
			vector<bool>(n,false).swap(vis_loop);
		}

		cout << endl;
		for (int i=0; i<n ; ++i)
		{
			for (int j: ans[i])
				cout << j << ' ' ;
			cout << endl;
		}

	}
	return 0;
}
/*
   The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph. The Graph is represented as Adjancency Matrix, and the Matrix denotes the weight of the edegs (if it exists) else INF (1e7).

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. The first line of each test case contains an integer V denoting the size of the adjacency matrix. The next V lines contain V space separated values of the matrix (graph). All input will be integer type.

Output:
For each test case output will be V*V space separated integers where the i-jth integer denote the shortest distance of ith vertex from jth vertex. For INT_MAX integers output INF.

Constraints:
1 <= T <= 20
1 <= V <= 100
1 <= graph[][] <= 500

Example:
Input
2
2
0 25
INF 0
3
0 1 43
1 0 6
INF INF 0

Output
0 25
INF 0
0 1 7
1 0 6
INF INF 0


Actually, they fixed input to be 1000000 not INF.
2
2
0 25
10000000 0
3
0 1 43
1 0 6
10000000 10000000 0

16
0 462 22 821 72 895 186 665 418 948 629 309 433 444 657 950 751 0 591 360 431 28 387 865 403 410 476 746 91 388 892 928 735 364 0 313 919 446 218 115 121 -2 425 112 669 220 567 336 180 680 937 0 903 122 327 300 -3 741 73 483 497 526 233 399 816 979 125 139 0 908 581 367 385 713 728 820 187 407 403 764 106 945 455 405 858 0 939 743 169 946 846 604 791 705 140 387 466 966 728 601 116 -2 0 192 845 393 267 583 575 465 1 988 591 117 296 408 532 164 357 0 637 343 313 493 957 467 208 459 216 684 436 954 295 914 962 850 0 769 717 127 715 654 954 726 5 556 205 311 974 99 485 342 747 0 191 17 250 510 846 821 980 72 515 778 36 173 702 360 33 481 0 439 522 206 456 487 294 471 53 861 144 389 971 -9 741 80 192 0 121 692 65 977 523 55 60 401 195 458 936 907 181 979 750 982 0 863 319 448 360 623 281 775 847 787 527 180 789 278 270 343 761 0 324 418 749 210 835 171 973 40 -9 919 309 182 260 70 527 133 0 399 337 856 384 629 -7 593 778 530 783 577 171 415 931 942 102 0

Expected Output:

0 145 22 211 72 91 93 28 143 20 211 37 158 235 94 358
134 0 151 339 206 28 159 157 197 149 340 166 91 301 160 415
3 123 0 214 75 69 71 6 121 -2 189 15 136 213 72 336
180 145 177 0 109 122 180 115 -3 175 73 124 236 279 181 399
128 242 125 139 0 194 196 131 136 123 212 140 187 338 197 461
106 251 128 311 178 0 131 134 169 126 317 143 264 273 132 387
96 179 118 172 108 -10 -8 62 159 116 245 71 192 134 -7 369
251 117 268 379 315 145 199 0 314 266 313 278 208 341 200 459
183 235 180 363 255 181 183 118 0 178 319 127 248 325 184 516
5 125 27 216 77 71 73 8 148 0 191 17 138 215 74 363
164 72 161 175 36 100 216 151 33 159 0 160 163 206 217 487
56 108 53 236 128 54 56 -9 174 51 192 0 121 198 57 389
63 55 60 274 135 83 131 66 181 58 249 75 0 273 132 396
283 297 281 445 306 313 315 180 303 278 270 295 388 0 316 418
87 170 109 163 99 -19 -17 53 150 107 236 62 183 125 -16 360
121 235 118 132 -7 83 85 124 129 116 171 133 180 227 86 0

*/
