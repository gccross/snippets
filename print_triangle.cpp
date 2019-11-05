#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>

using namespace std;

int main(int argc, const char * const argv[]) 
{
	size_t N;
	cin >> N;
	char a[N];
	fill(a,a+N, '#');
	cout.setf(ios_base::right);
	int i=N;
	while (i--) {
		cout << setw(N) << string(a, a+N-i) << endl;
	}

	return 0;

}
