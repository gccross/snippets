#include <iostream>
#include <vector>
using namespace std;

template <typename T> class myarray
{
public:
	myarray(T* _data):data(_data){};
	~myarray() = 0; //disallow derivation
	const T& operator[] (size_t pos) const {
		return const_cast<myarray&>(*this)[pos];
	};
	T& operator[] (size_t pos) {
		return data[pos];
	};

private:
	T* data;
};

template <typename T> myarray<T>::~myarray() {}

template <typename T> const myarray<T> operator+ (myarray<T> left, myarray<T> right) { return left; } 

// std::forward example
template <typename T> f(T&& arg){ string(forward<T>(arg)); }

const string &cs;
string &s; 
string && rs;

f(string("Hello world"));


int main ()
{
	auto v(vector<char>{'e','a','i','o','u'});
	for (auto i: v) cout << i << " " ;
	cout << endl;
		
	return 1;

}
