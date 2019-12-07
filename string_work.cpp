#include <iostream>
#include <string>
using namespace std;


template <typename It>
It find_first_duplicated(It first, It last)
{
	if (first == last) return first;
	It pred = first;
	while (++first < last)
	{
		It it = first;
		while (it != last && *it++ != *pred);
		if (it != last) break;
		++pred;
	}
	return first == last ? first : pred;
}
template <typename It>
It find_first_non_duplicated(It first, It last)
{
	if (first == last) return first;
	It pred = first;
	while (++first < last) 
	{
		It it = first;
		while (it < last && *it++ != *pred);
		if (it == last) break;
		++pred;
	}
	return first == last ? first : pred;
}

template <typename It>
It remove_adjacent_duplicate(It first, It last)
{
	if (first == last) return first;
	It prev = first;
	while (++first < last)
	{
		if (*prev != *first)
			*++prev = *first;
	}
	return ++prev;
}
template <typename It>
It remove_adjacent_duplicate(It first, It last, typename It::value_type v)
{
	if (first == last) return first;
	bool found = false ;
	It prev = first;
	while (++first < last)
	{
		if (*prev != v || *first != v)
			*++prev = *first;
	}
	return ++prev;
}

int main(int const argc, const char* const argv[])
{
	string input;
	getline(cin, input);
	string::iterator new_end = remove_adjacent_duplicate(input.begin(), input.end(), ' ');
	cout << input.substr(0,distance(input.begin(),new_end))  << endl;

	new_end = remove_adjacent_duplicate(input.begin(), new_end);
	cout << input.substr(0,distance(input.begin(),new_end))  << endl;

	string::iterator it = find_first_non_duplicated(input.begin(), input.end());
	if (it != input.end())
		cout << *it << endl;
	else 
		cout << "all duplicates" << endl;

	it = find_first_duplicated(input.begin(), input.end());
	if (it != input.end())
		cout << *it << endl;
	else 
		cout << "no duplicates" << endl;
	return 0;
}

// string - 
//
// 	remove duplicates
//	remove adjacent duplicates
//	find first non-duplicated
//	find first duplicate
//	remove duplicate spaces

