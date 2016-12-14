#include <iostream>
using namespace std;

void count_bovine(const std::list<unsigned int>& secret, const std::list<unsigned int>& guess)
{
	list<unsigned int>::iterator it(guess.begin()), secret_it(secret.begin());

	size_t secret_pos=0, guess_pos=0, ncows=0, nbulls=0;
	for (;secret_it!= secret.end(); ++secret_pos, ++secret_it)
	{
		for (; guess_it!=guess.end(); ++guess_it, ++guess_pos)
		{
			if (*guess_it == *secret_it)
			{
				++ncows;
				if (guess_pos == secret_pos)
				{
					++nbulls;
				}
			}      
		}
	}  
	cout << ncows << " cows, " << nbulls << " bulls" << endl;
}

