#include <fstream>
#include <iostream>
#include <istream> 
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
using namespace std;

int main(int argc, const char * const * argv)
{
	ifstream ifs;
	if (1<argc) {
		ifs.open(argv[1]);
		cin.rdbuf(ifs.rdbuf());
		cin.tie(&cout);
	}

	vector<string> words;
	string word;
	auto it(back_inserter(words));
	while (cin >> word)  *it = word; 
	// could use this too:
	//copy (istream_iterator<string>(*is),istream_iterator<string>(), back_inserter(words));

	for (auto&& i: words) cout << i << endl;
	cout << endl << "word count: " << words.size() << endl;

	//verify with wc if we have a file
	if (1 == argc) return 0;

	string cmd("wc -w ");
	cmd += argv[1];
	cout << "verify with `" << cmd << "`:";
	cout.flush();

	FILE* f = popen(cmd.c_str(),"r+");
	const uint MAX_LINE = 2048;
	char line[MAX_LINE];
	while (NULL!=fgets(line,MAX_LINE,f)) cout << line; 
	fflush(f);
	pclose(f);
	return 0;
}
