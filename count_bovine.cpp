#include <iostream>
#include <memory>
#include <fstream>
#include <list>
using namespace std;

void count_bovine(const std::list<unsigned int>& secret, const std::list<unsigned int>& guess)
{
	list<unsigned int>::const_iterator guess_it, secret_it;

	size_t secret_pos=0, guess_pos=0, ncows=0, nbulls=0;
	for (;secret_it!= secret.end(); ++secret_pos, ++secret_it)
	{
		for (guess_it=guess.begin(); guess_it!=guess.end(); ++guess_it, ++guess_pos)
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

int main (int argc, char const * const * argv)
{
	istream *is;
	ifstream ifs;
	if (argc > 1) {
		ifs.open(argv[1]);
		if (ifs) 
		{
			is=&ifs;
		} else {
			cout << "Couldn't open file : " << argv[1] << endl;	
		}
				
	} else {
		is = &cin;
		cout << "Enter your numbers to guess: " << endl;

	}

	cout << "These are your numbers: " << endl;
	bool more_data(true);
	int n(0);
	while ( more_data )
	{
		*is >> n; 

		if (!is->fail()&&!is->eof())
		{
			cout << n << endl;
		}

		if (is->fail())
		{
			is->clear();
			is->ignore();
		}
		if (is->eof() )
		{
			more_data = false;
		} 
		if (is->bad())
		{
			more_data = false;
		}
		
	}

	
	return 0;

}
