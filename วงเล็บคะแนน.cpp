#include <cmath> 
#include <exception>
#include <iostream>
#include <iterator>
#include <fstream>

using namespace std;


// in a sequence of parens eg. (()(()))(), find the closing brace.  Eg. index 8 in the example
//                             ^      ^
//                             |      |
//                             |      |
//                           first   closing 
//                           
template <typename InputIt>
InputIt find_close(InputIt first, InputIt last)
{
	unsigned left_parens(0), right_parens(0);
	while (first != last) {

		if (*first == ')') ++right_parens;
		else ++left_parens;

		if (right_parens == left_parens) break;
		++first;
	}
	return first;
}

// calculate score in a sequence of parens eg. (()(()))(), 
// eg:  () = 1
//      (A) = 2 x A  eg. (()) = 2,  ((())) = 4
//      A B = A + B  eg. ()() = 2, ()()() = 3, ()(()) = 3, (()(())) = 6
template <typename InputIt>
unsigned score(InputIt first, InputIt last)
{
	if (first==last) return 0;

	InputIt close_brace(find_close (first, last));
	
	unsigned result(0);
	if (close_brace == first) result = 0;
	else if (++first == close_brace) result = 1;
	else result = 2*score(last,close_brace);

	result+=score(++close_brace,last);

	return result;
}

int main (int argc, char const * const argv[])
{
	cout << "Hello World " __FILE__ << endl;
	
	ifstream fs;
	if (1 < argc) {
		fs.open(argv[1]);
		cin.rdbuf(fs.rdbuf());
	}
	
#if 1
	string line;
	while (getline(cin, line))
		cout << "The score is: " << score(line.begin(), line.end()) << endl;
#else
	// can we make the algorithm work on the input stream? 
	cout << "The stream score is: " << score(istream_iterator<char>(cin), istream_iterator<char>()) << endl; 
#endif
	return 0;

}
