#include <iostream>
using namespace std;

int main(const int argc, const char * const argv[]) {
	int T;
	cin >> T;
	while (T--)
	{
        int n, edges = 0;
        cin >> n;
        while (n >= 3) 
        {
            edges += n%3;
            n -= n%3;
            n/=3;
            ++edges;
        }
        
		edges += n - 1;
        cout << edges << endl;
	}
	return 0;
}
