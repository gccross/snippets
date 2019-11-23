#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const * const argv[]) {
	//code
	int T;
	cin >> T;
	while (T--){
		chrono::time_point<chrono::system_clock> t1 { chrono::system_clock::now()};
		int N; 
		cin >> N;
		int a[N];
		copy_n(istream_iterator<int>(cin), N, a);
		vector<int> ans;
		ans.emplace_back(a[0]);
		for (int i=1; i<N; ++i) {
			if (a[i] > *(ans.end()-1))
				ans.emplace_back(a[i]);
			else {
				vector<int>::iterator it = lower_bound(ans.begin(), ans.end(), a[i]);
				*it = a[i];
			}
		}
		cout << ans.size() << endl;;
		cout <<  (chrono::system_clock::now() - t1).count() << endl;
	}
	return 0;
}

/*
2
9
15 27 14 38 26 55 46 65 85
9
2 6 3 4 1 2 9 5 8

Output: 
6
5


*/
