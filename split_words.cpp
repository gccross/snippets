#include <fstream>
#include <iostream>
#include <istream> 
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
using namespace std;

vector<string>  split_words(istream  * const is)
{

	string line, word;
	vector<string> words;
	istringstream iss;
	while (getline(*is,line))
	{
		iss.str(line);
		for_each(istream_iterator<string>(iss), istream_iterator<string>(), [&words](const string& s){words.push_back(s);});
		iss.clear();
	}
	return words;
}

int main(int argc, const char * const * argv)
{
	ifstream ifs;
	istream *is;
	if (1<argc) {
		ifs.open(argv[1]);
		is = &ifs;
	} else {
		is = &cin;
	}

	vector<string> words(split_words(is));

	//verify
	for (auto&& i: words) cout << i << endl;
	cout << endl << "word count: " << words.size() << endl;

	cout << "verify with wc: " ;

	is->clear();
	is->seekg(0, ios::beg);
	FILE* f = popen("wc -w "  ,"r+");
	char output[256];
	while (!feof(f)) if (fgets(output, 256, f)!=NULL) cout << output; 
	fflush(f);
	pclose(f);
	return 0;
}
