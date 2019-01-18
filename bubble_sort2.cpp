#include <iostream>
#include <array>
#include <type_traits>

using namespace std;

template <typename FwdIt>
const FwdIt bubblesort(FwdIt first, FwdIt last)
{
	using type = typename iterator_traits<FwdIt>::value_type;
	const FwdIt head(first);
	FwdIt next;
	while (first!=last) {
		next = first; 
		while (++next!=last)
		{
			if (*first>*next)  {  type temp = *next; *next = *first; *first = temp; }
		}
		++first;
	}
	return head;
}
int main (int argc, char const * argv[])
{
	cout << "Hello World " __FILE__ << endl;

	array<int, 9> a{ 4, -27, 9, -3, 6, 42, 14, 11, 12 };
	bubblesort(a.begin(), a.end());
	for (auto i: a)  cout << i << ' ' ;
	cout << endl;
	bubblesort(a.begin(), a.end());
	for (auto i: a)  cout << i << ' ' ;
	cout << endl;
	reverse(a.begin(), a.end());
	for (auto i: a)  cout << i << ' ' ;
	cout << endl;
	bubblesort(a.begin(), a.end());
	for (auto i: a)  cout << i << ' ' ;
	cout << endl;

	int b[] = { 5, -26, 10, -2, 7, 43, 15, 12, 9 };
	bubblesort(&b[0], &b[0]+9);
	for (auto i: b)  cout << i << ' ' ;
	cout << endl;
	return 0;

}
