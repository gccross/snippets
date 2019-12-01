#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--){
        int N, res;
        cin >> N;
        if (N < 3) 
            res = 1;
        else {
            vector<int> v(N+1);
            v[0] = 1; v[1] = 1; v[2] = 1;
            int second = 1, third = 1, fourth = 1;
            for (int i = 3; i<N+1; ++i) {
                
                res = (third+fourth)%1000000007;
                fourth = third;
                third = second;
                second = res;
            }
        }
        cout << res << endl;
    }
	//code
	return 0;
}
