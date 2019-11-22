#include <iostream>
#include <string>
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
		int ans[N+1];
		fill(ans, ans+N+1, -1);
		ans[0] = 1;
		for (int i=1; i<N; ++i) {
			int count = 0;
			for (int j=0; j<i; ++j) 
				if (a[j] < a[i] && count < ans[j])
					count = ans[j];
			ans[i] = count+1;
		}
		int maxx = 0;
		for_each(ans, ans+N, [&maxx](int i){ if (maxx < i) maxx = i; });
		cout << maxx << endl;;

		cout <<  (chrono::system_clock::now() - t1).count() << endl;
	}
	return 0;
}

/*
1
9
15 27 14 38 26 55 46 65 85

Output: 6
*/
