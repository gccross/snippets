#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

class solution {
    
    int lookup_val(int index) {
        int offset = X;
        if (index < offset)
            return a[index];
        else return b[index - offset];
    }
    
    void assign_val(int index, int val) {
        int offset = X;
        if (index < offset)
            a[index] = val;
        else b[index - offset] = val;
     }
        
    void do_solve () {
        
        // shell sort
        for (int gap = X+Y/2; gap > 0; gap /=2) {
            for (int i=gap; i<X+Y; ++i) {
                int temp = lookup_val(i);
                int j = i;
                for (; j >= gap && lookup_val(j-gap) > temp; j-=gap) 
                    assign_val(j, lookup_val(j-gap));
                assign_val(j, temp);
            }
        }
    	
    	copy(a, a+X, ostream_iterator<int>(cout, " "));
    	copy(b, b+Y, ostream_iterator<int>(cout, " "));
    	cout << endl;

    }
    int *a;
    int *b;
    int X, Y;
public:
    solution(int _a[], int _X, int _b[], int _Y)
    : a(_a), b(_b), X(_X), Y(_Y) {}
    void operator()() { do_solve(); }
};

int main(const int argc, const char* const argv[]) {
    
	size_t T;
	cin >> T;
	while (T--){
	    int X, Y;
	    cin >> X >> Y;
	    int a[X],b[Y];
	    copy_n(istream_iterator<int>(cin), X, a);
	    copy_n(istream_iterator<int>(cin), Y, b);
	    
	    solution(a, X, b, Y)();

    }
    	
	return 0;
}
