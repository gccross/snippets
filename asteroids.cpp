#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
		vector<int> asteroidCollision(vector<int> & asteroids) {
			typedef vector<int>::iterator it_type;
			it_type curr = asteroids.begin(), prev;

			do {
				while (asteroids.end()!=curr && *curr < 0) prev = curr++; // note postfix++. keep iterators adjacent, skip over the left-moving
				while (asteroids.end() != curr && *curr > 0) prev = curr++; // note postfix++. skip over the right-moving
				while (asteroids.end() != curr && asteroids.begin() != curr && *curr < 0 && *prev > 0) { 
					// do collisions
					if (*prev + *curr > 0) curr = asteroids.erase(curr); // erase right, preserving iterator
					else if (*prev + *curr < 0) curr = asteroids.erase(prev--);  // erase left, preserving iterator
					else curr = asteroids.erase(prev--, ++curr);  // erase both. preserve iterators, and specify end of range as one past curr.
				}
			} while (asteroids.end() != curr);
			return asteroids;
		}

};

int main(int const argc, char const * const argv[]) {

	Solution s;
	{
	vector<int> v{8,-8};
	for (int i : s.asteroidCollision(v)) cout << i << "\t";
	cout << endl;
	}

	{
	vector<int> v{-8,-7,7,8};
	for (int i : s.asteroidCollision(v)) cout << i << "\t";
	cout << endl;
	}

	{
	vector<int> v{10, 2, -5};
	for (int i : s.asteroidCollision(v)) cout << i << "\t";
	cout << endl;
	}

	{
	vector<int> v{5, 10, -5};
	for (int i : s.asteroidCollision(v)) cout << i << "\t";
	cout << endl;
	}

	{
	vector<int> v{1,-2,-2,-2};
	for (int i : s.asteroidCollision(v)) cout << i << "\t";
	cout << endl;
	}

	{
	vector<int> v{-2,-2,1,-2};
	for (int i : s.asteroidCollision(v)) cout << i << "\t";
	cout << endl;
	}
	return 0;
}
