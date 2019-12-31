#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		if (N < 3) { cout << N << endl; continue; }
		int ans = 0,
			third = 1,
			second = 1,
			first = 2;
		for (int i = 3; i<N+1; ++i)
		{
			ans = first + second + third;
			third = second;
			second = first;
			first = ans;
		}
		cout << ans << endl;
	}
	return 0;
}
