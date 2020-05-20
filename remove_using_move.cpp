namespace george
{
template <typename It, typename Pred>
It remove(It first, It last, Pred pred)
{
	It curr = first;
	while (first++ < last)
		if (!pred(*curr)) ++curr;
		else *curr = move(*first);

	return curr;
}
}

#include <iostream>
#include <string>


int main (int argc, char const * argv[])
{
	std::cout << "Hello World " __FILE__ << std::endl;

	std::string s = "De Multiples Initiatives Dynamisent la Vie Locale";
	std::string::iterator it = george::remove(s.begin(), s.end(), [](const char c) {  return c == 'i'; });
	std::cout << s << '\n' ;
	s.erase(it,s.cend());
	std::cout << s << '\n' ;

	s.swap(string());
	return 0;
}
