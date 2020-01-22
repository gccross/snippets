#include <iostream>
using namespace std;
void solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    for (int i = 1; i <= N; ++i ) 
    {
        bool fizz = false;
        if (0 == i%2)  { cout << "Codility"; fizz = true; }
        if (0 == i%3)  { cout << "Test"; fizz = true; }
        if (0 == i%5)  { cout << "Coders"; fizz = true; }
        if (!fizz) cout << N;
        cout << endl;
    }
}

int main (int argc, char const * argv[])
{
		solution(24);
		return 0;

}
