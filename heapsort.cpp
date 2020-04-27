#include <deque>
#include <iostream>
#include <functional>

using namespace std;

template <typename T, typename C>
void heapify(T arr[], size_t n, size_t i, C cmp) 
{
	deque<size_t> dq {i};
	while (!dq.empty())
	{
		size_t cur = dq.front();
		dq.pop_front();
		if (cur < n) 
		{
			size_t largest = i;
			size_t l = 2*i + 1;
			size_t r = 2*i + 2;

			if (l < n && cmp(arr[l], arr[largest]))
				largest = l;
			if (r < n && cmp(arr[r],  arr[largest]))
				largest = r;

			if (i != largest)
			{
				swap(arr[i], arr[largest]);
				dq.push_back(largest);
			}
		}
	}
}

template <typename T, typename C = std::greater<T>>
void make_heap(T arr[], size_t n, C cmp = std::greater<T>())
{
	for (int i = n/2-1; i>=0; --i)
	{
		heapify(arr,n,i,cmp);
	}
}


int main (int argc, char const * argv[])
{
	cout << "Hello World " __FILE__ << endl;

	string s("kitkatticklemyfat");
	make_heap(s.data(), s.length());
	cout << s << endl;
	make_heap(s.data(), s.length(), std::less<char>());
	cout << s << endl;
	return 0;

}
