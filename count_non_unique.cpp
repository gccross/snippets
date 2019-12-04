// Given a string, print the first non-duplicate character (going left to right).
// eg. bloomberg
//
// l
//
// Explanation: l is the first character of the word that has only 1 occurrance 
//
// Possible solutions: 
//
// 1. call string::find for each character O(n).  Print the first value for which find returns npos. Similar to the 2. option here.
// 2. for generic types, not necessarily characters, iterate calling count.  Break on the first which has a count of 1.  O(n).
// 3. insert each element (not necessarily characters) into a hashset (unordered_set) and if the insert fails, 
//    record the element in a vector called 'duplicates'.  In the end check for the first element which is not a duplicate. O(2n);
// 4. if the range of possible characters is limited, you can use a vector or array to record the count for each character as you 
//    iterate. After that, iterate the range again, looking in the vector or array for a count of 1.
// 

#include <algorithm> 
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

struct vector_method_tag{};
struct hashset_method_tag {};
struct find_method_tag {};

template <typename It>
typename It::value_type print_first_unique_in_vector(It first, It last)
{
	It left {first};
	while (left < last) {
		if (count(first,last, *left) == 1) return *left;
		++left;
	}
	return '\0';
}

template <typename It, typename M >
typename It::value_type print_first_unique_in_vector(It first, It last, M);
template <>
char print_first_unique_in_vector(string::iterator first, string::iterator last, vector_method_tag)
{
	string::iterator left{first};
	vector<size_t> count(52);  // bad: assumes only A-Za-z
	while (left < last) 
		++count[*left++ -'A'];

	left = first;
	while (left < last) {
		if (count[*left - 'A'] == 1) break;
		++left;
	}
	return left == last ? '\0' : *left;
}

template <>
char print_first_unique_in_vector(string::iterator first, string::iterator last, hashset_method_tag)
{
	unordered_set<char> uos;
	string duplicates;
	string::iterator left{first};

	while (left < last) {
		if (!uos.insert(*left).second) duplicates.push_back(*left);
		++left;
	}

	left = first;
	while (find(duplicates.begin(), duplicates.end(), *left) != duplicates.end()) ++left;

	return left == duplicates.end() ? '\0' : *left;
}

int main (int argc, char const * const  argv[])
{
	ifstream ifs;
	if (1 < argc) {
		ifs.open(argv[1]);
		cin.rdbuf(ifs.rdbuf());
	}
	
	string line;
	while (getline(cin, line)) {
		cout << print_first_unique_in_vector(line.begin(), line.end(), hashset_method_tag()) << endl;	 
		cout << print_first_unique_in_vector(line.begin(), line.end(), vector_method_tag()) << endl;	 
		cout << print_first_unique_in_vector(line.begin(), line.end() ) << endl;	 
	}
	return 0;

}
