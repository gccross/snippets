// For international characters (Mac OSX):
//
// Be sure terminal LANG=en_US.UFT-8
//
// In vim, be sure encoding is utf-8.  
//
// Startup locale will be 'C'.  So we need to imbue en_US.UTF-8 on wcout to display the wide characters. 
//
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main () 
{
	cout << "Your prefered locale is: " << locale("").name() << endl;
	cout << "Your default locale is: " << locale().name() << endl;

	// The codecvt facet of the en_US.UTF-8 locale, will convert the wide characters to UTF-8 when 
	// sent through any fstream (wcout in this case).
	wcout.imbue(locale("en_US.UTF-8") );

	vector v{ L'§',L'è', L'é', L'ò', L'ò', L'ò', L'ù', L'ﬁ', L'Æ', L'Æ'};

	copy (v.begin(), unique(v.begin(), v.end()), ostream_iterator<wchar_t, wchar_t>(wcout, L" "));
	cout << endl;

	// The full  name of Bangkok.
	// Set your environment for your terminal with LANG=en_US.UTF-8 and vim encoding to utf-8. 
	// As I understand, the codecvt facet of the C locale will make a degenerate conversion (eg. no conversion).
	// codecvt<char,char,mbstate_t> is the facet.
	const string s{"กรุงเทพมหานคร อมรรัตนโกสินทร์ มหินทรายุธยา มหาดิลกภพ  นพรัตนราชธานีบูรีรมย์ อุดมราชนิเวศน์มหาสถาน อมรพิมานอวตารสถิต  สักกะทัตติยวิษณุกรรมประสิทธิ์"};
	cout << s << endl;
	
	// Let's try to convert this for internal use.
	mbstate_t mbs;
	char const *p = s.c_str();
	wchar_t wc[s.length()];
	size_t wchars_written = mbsrtowcs(wc,&p,s.length(),&mbs);

	wcout.imbue(locale("en_US.UTF-8"));
	if (NULL == p) cout << "Problem with mbsrtowcs : " << p << endl;
	else cout << "mbsrtowcs success! number of wchars written:" <<  wchars_written << endl;

	wcout << "The converted string: " << endl << wc << endl;
	cout << "The converted characters: " << endl ; 
	for (auto&& c: wc) wcout << c << L'\t';
	cout <<endl;
	return 0;
}

