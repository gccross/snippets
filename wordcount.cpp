#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

int main(int argc, char const * const * argv)
{

	size_t linecount=0, wordcount=0, charcount=0;
	string word, line;
	istream* is;
	ifstream ifs;
	if (2 <= argc) 
	{
		ifs.open(argv[1]);
		is = &ifs;
	} else {
		is = &cin;
	}
	
	while (getline(*is,line))
	{
		linecount ++;
		charcount += line.size();
		istringstream iss(line.data());
		while (iss >> word) 
		{
			wordcount++;
			word.clear();
		}
		line.clear();
	}
		
	cout << "Char count: " << charcount << endl;
	cout << "Word count: " << wordcount << endl;
	cout << "Line count: " << linecount << endl;
	
	return 0;
}
