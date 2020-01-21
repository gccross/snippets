#include <iostream>
#include <vector>
using namespace std;

template <int N>
struct S { enum { value = S<N/2>::value + (N%2) }; };
template <>
struct S<0> { enum { value = 0 }; };

int main()
{
	/*
	vector<int> v5;
	v5.push_back(1); 
	v5.push_back(1); 
	v5.push_back(1); 
	v5.push_back(1); 
	v5.push_back(1); 
	vector<int> v0;
	cout << sizeof(v5) << " " << sizeof(v0) << endl; // same size
	*/
	cout << S<65535>::value << endl; 
	return 0;
}
