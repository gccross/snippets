// grade students from leetcode.com
// round up to nearest 5 
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


template <typename T> class FD;
int main (int argc, char const * argv[])
{
	cout << "Hello World " __FILE__ << endl;


	ifstream f;
	if (1 < argc) {
		f.open(argv[1]);
		cin.rdbuf(f.rdbuf());
	}

	string line;
	getline(cin,line);
	
	while(getline(cin, line))
	{
		uint grade;
		istringstream(line) >> grade;
		auto m1 = [&grade] (){  
				if (grade >= 38 && grade%5 > 2) { 
					grade += 5-grade%5 ;
				} 
				return grade; 
			};
		FD<decltype(m1) >();
		FD<decltype(cin)>();
		cout << m1() << endl;
	}
		


	return 0;

}
