#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

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
		charcount += line.size() + 1;
		istringstream stream(line);
		wordcount += distance(istream_iterator<string>(stream), istream_iterator<string>());
		line.clear();
	}
		
	cout << "Char count: " << charcount << endl;
	cout << "Word count: " << wordcount << endl;
	cout << "Line count: " << linecount << endl;
	
	return 0;
}
