#include <iostream>
using namespace std;

// Frak fun
template <class>
struct void_type { typedef void type; };

template <typename T, class = void>
struct hasNumerator : false_type {};
template <typename T>
struct hasNumerator <T, 
	typename void_type<decltype( T::Num)>::type> : true_type {};

template <size_t X, size_t Y>
struct Frak {
	static const size_t Num = X, Den = Y;
};

template <size_t multiple, typename X, bool = hasNumerator<X>::value> struct ScalarMultiplication;
template <size_t multiple, typename X> struct ScalarMultiplication<multiple, X, true> {

	typedef Frak<X::Num*multiple, X::Den*multiple> result;
};

template <typename T1, typename T2> 
struct Samebase {
	typedef typename ScalarMultiplication<T1::Den, T2>::result Y;
	typedef typename ScalarMultiplication<T2::Den, T1>::result X;
};

template <size_t X, size_t Y>
struct MCD {
	static const int value = MCD<Y, X%Y>::value;
};
template <size_t X>
struct MCD<X,0> {
	static const int value = X;
};

template <typename T>
struct Simplify {
	static const int mcd { MCD<T::Num,T::Den>::value };
	typedef Frak<T::Num/mcd,T::Den/mcd> result;
};
template <typename T1, typename T2>
struct Sum {
	typedef typename Samebase<T1, T2>::X X;
	typedef typename Samebase<T1, T2>::Y Y;
	typedef Frak<X::Num+Y::Num,X::Den+Y::Den> result;

};

typedef typename Sum<Frak<4,5>,Frak<8,9>>::result myFrak;
typedef typename Simplify<myFrak>::result mySimpleFrak;
typedef typename ScalarMultiplication<3, string>::result three_strings;

int main () 
{
	cout << "Your prefered locale is: " << locale("").name() << endl;
	cout << "Your default locale is: " << locale().name() << endl;

	// The full  name of Bangkok. UTF-8 encoding. 
	const string s{ u8"กรุงเทพมหานคร อมรรัตนโกสินทร์ มหินทรายุธยา มหาดิลกภพ  นพรัตนราชธานีบูรีรมย์ อุดมราชนิเวศน์มหาสถาน อมรพิมานอวตารสถิต  สักกะทัตติยวิษณุกรรมประสิทธิ์"};
	cout << s << endl;

	// Let's try to convert this.
	mbstate_t mbs;

	wchar_t internal[ use_facet<codecvt<wchar_t, char, mbstate_t>>(locale()).max_length() * (s.size() ) ] ;
	wchar_t* to_next;
	const char* from_next;
	codecvt_base::result res = use_facet<codecvt<wchar_t, char, mbstate_t>>(locale("en_US.UTF-8")).in(
			mbs,
			&s[0], &s[s.size()], from_next,
			&internal[0], &internal[s.size()], to_next);
	switch (res) {
		case codecvt_base::partial:
			cout << "Partial conversion performed" << endl;
		case codecvt_base::error:
			cout << "Error in conversion.  Invalid character: " << from_next << endl;
		case codecvt_base::noconv:
			cout << "No conversion required nor performed" << endl;
		default:
			;
	};


	//char const *p = s.c_str();
	//wchar_t wc[s.length()];
	//size_t wchars_written = mbsrtowcs(wc,&p,s.length(),&mbs);

	//if (NULL == p) cout << "Problem with mbsrtowcs : " << p << endl;
	//else cout << "mbsrtowcs success! number of wchars written:" <<  wchars_written << endl;

	wcout.imbue(locale("en_US.UTF-8"));
	wcout << "The converted string: " << endl << internal  << endl;
	wcout.clear();

	wcout << "The " << to_next - internal << " converted characters: " << endl ; 
	for (auto&& c: internal) wcout << c << L' ';

	cout <<  "\n\nFrak Fun: ";
	cout << myFrak::Num << "/" << myFrak::Den << "\t Simplified: " << mySimpleFrak::Num << "/" << mySimpleFrak::Den << endl;
	cout << "Three strings: " << three_strings ; 

	return 0;
}
/*
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <locale>
#include <codecvt>

// utility wrapper to adapt locale-bound facets for wstring/wbuffer convert
template<class Facet>
struct deletable_facet : Facet
{
template<class ...Args>
deletable_facet(Args&& ...args) : Facet(std::forward<Args>(args)...) {}
~deletable_facet() {}
};

int main()
{
// UTF-8 narrow multibyte encoding
std::string data = u8"z\u00df\u6c34\U0001f34c";
// or u8"zAaeo'o"
// or "\x7a\xc3\x9f\xe6\xb0\xb4\xf0\x9f\x8d\x8c";

std::ofstream("text.txt") << data;

// using system-supplied locale's codecvt facet
std::wifstream fin("text.txt");
// reading from wifstream will use codecvt<wchar_t, char, mbstate_t>
// this locale's codecvt converts UTF-8 to UCS4 (on systems such as Linux)
fin.imbue(std::locale("en_US.UTF-8"));
std::cout << "The UTF-8 file contains the following UCS4 code points: \n";
for (wchar_t c; fin >> c; )
std::cout << "U+" << std::hex << std::setw(4) << std::setfill('0') << c << '\n';

// using standard (locale-independent) codecvt facet
std::wstring_convert<
deletable_facet<std::codecvt<char16_t, char, std::mbstate_t>>, char16_t> conv16;
std::u16string str16 = conv16.from_bytes(data);

std::cout << "The UTF-8 file contains the following UTF-16 code points: \n";
for (char16_t c : str16)
std::cout << "U+" << std::hex << std::setw(4) << std::setfill('0') << c << '\n';
}
 */


