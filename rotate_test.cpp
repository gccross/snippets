#include <algorithm>
#include <iostream>
#include <random>

using namespace std;

int main (int argc, char const * argv[])
{
	//random_device rd;
	mt19937 mt(random_device{}());
	uniform_int_distribution<> dist(-20, 20);

	vector<int> v;
	generate_n(back_inserter(v),100, bind(dist,mt));
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));
	
	rotate(v.begin(), v.end(), v.end());
	cout << endl << "Hello World " __FILE__ << endl << endl;; 

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));
	cout.flush();

	// dangerous, should check it == last.
	vector<int>::iterator it = rotate(v.begin(), v.begin(), v.end());
	cout << endl << "Index: " << distance(v.begin(), it) << " Value: " << *it << endl;
	
	std::cout << "before sort:      ";
	for (int n: v)
		std::cout << n << ' ';
	std::cout << '\n';

	// insertion sort
	for (auto i = v.begin(); i != v.end(); ++i) {
		vector<int>::iterator it = std::upper_bound(v.begin(), i, *i);
		it = std::rotate(it, i, i+1);
	}

	std::cout << "after sort:       ";
	for (int n: v)
		std::cout << n << ' ';
	std::cout << '\n';

	// simple rotation to the left
	std::rotate(v.begin(), v.begin() + 1, v.end());

	std::cout << "simple rotate left  : ";
	for (int n: v)
		std::cout << n << ' ';
	std::cout << '\n';

	// simple rotation to the right
	std::rotate(v.rbegin(), v.rbegin() + 1, v.rend());

	std::cout << "simple rotate right : ";
	for (int n: v)
		std::cout << n << ' ';
	std::cout << '\n';
	return 0;

}
	
/* 
	from the cppreference

        #include <vector>
        #include <iostream>
        #include <algorithm>

        int main()
        {
            std::vector<int> v{2, 4, 2, 0, 5, 10, 7, 3, 7, 1};

            std::cout << "before sort:      ";
            for (int n: v)
                std::cout << n << ' ';
            std::cout << '\n';

            // insertion sort
            for (auto i = v.begin(); i != v.end(); ++i) {
                std::rotate(std::upper_bound(v.begin(), i, *i), i, i+1);
            }

            std::cout << "after sort:       ";
            for (int n: v)
                std::cout << n << ' ';
            std::cout << '\n';

            // simple rotation to the left
            std::rotate(v.begin(), v.begin() + 1, v.end());

            std::cout << "simple rotate left  : ";
            for (int n: v)
                std::cout << n << ' ';
            std::cout << '\n';

            // simple rotation to the right
            std::rotate(v.rbegin(), v.rbegin() + 1, v.rend());

            std::cout << "simple rotate right : ";
            for (int n: v)
                std::cout << n << ' ';
            std::cout << '\n';

        }
*/
