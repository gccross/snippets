// For international characters:
//
// Be sure terminal LANG=en_US.UFT-8
//
// In vim, be sure encoding is utf-8.  
//
// Startup locale will be 'C'.  So we need to imbue en_US (latin1?) on wcout to display the wide characters.
//
// :w
#include <algorithm>
#include <iostream>
#include <locale>
#include <type_traits>

using namespace std;
template< typename T, T... args>
struct UniqueSet
{
	static const T data[sizeof...(args)];
};

template< typename T, T... args> const T UniqueSet<T, args...>::data[sizeof...(args)] = { args... };

template <bool b> 
struct next_step {
	static const size_t value = 1;
};
template <> 
struct next_step<true> {
	static const size_t value = 0;
};

// no duplicate found, add current element to unique set
template <bool skip, int pos1, size_t pos2, size_t n, typename T, T const (&a)[n],  T... args>
struct gen_unique_set_impl {
	typedef typename gen_unique_set_impl<a[pos1-1]==a[pos2-1], 
					pos1-1,
					pos2-1,
					n, 
					T, 
					a,  
					a[pos2], 
					args...>::result result;
};

// duplicate found, don't add to unique set
template <int pos1, size_t pos2, size_t n, typename T, T const (&a)[n],  T... args>
struct gen_unique_set_impl <true, pos1, pos2, n, T, a, args...>{
	typedef typename gen_unique_set_impl<a[pos1-1]==a[pos2-1], 
					pos1-1,
					pos2-1,
					n, 
					T, 
					a,  
					args...>::result result;
};
				

template <size_t  pos2, size_t n, typename T, T const (&a)[n], T... args> 
struct gen_unique_set_impl<false, 0, pos2, n, T, a, args...> {
	typedef UniqueSet<T, a[0], args...> result;
};
template <size_t  pos2, size_t n, typename T, T const (&a)[n], T... args> 
struct gen_unique_set_impl<true, 0, pos2, n, T, a, args...> {
	typedef UniqueSet<T, args...> result;
};

template<size_t n, typename T, T const (&a)[n]>
struct gen_unique_set {
	typedef typename gen_unique_set_impl<a[n-2]==a[n-1],
						n-2,
						n-1, 
						n, 
						wchar_t, 
						a>::result result;
};

constexpr wchar_t myArr[] = { L'à', L'à', L'à', L'à', L'è', L'è', L'è', L'ì', L'ò', L'ù', L'å', L'é', L'í', L'ó', L'ü', L'û', L'ø' };
constexpr char foo[]{"There's a shiver in the dark, its raining in the park the meantime.  South of the river you stop and you hold everything."
			"A band is playing dixie, double four-time. You feel alright when you hear the music playing. You step in side, you don't "
			"see too many faces. Coming in out of the rain you hear the jazz go down. Competition, in other places, but the horns, "
			"they're blowing their sound."};


static const size_t myArrSize(sizeof(myArr)/sizeof(myArr[0]));

typedef typename gen_unique_set<myArrSize,wchar_t,myArr>::result A;

int main()
{
	
	// Check the locale
	cout << "Your locale is: " << locale("").name() << endl; // this is broken? the string is empty.
	cout << "Your preferred locale is: " <<  setlocale(LC_ALL, "") << endl; // this works, "en_US.UTF-8"
	locale::global(locale(setlocale(LC_ALL, ""))); // this works.  LANG env variable needs to be en_US.UTF-8 for this exercise below.

	// you need to imbue wcout with en_US, to convert wchar_t to UTF-8 
	wcout.imbue(locale("en_US.UTF-8") );

	// print the unique static const array of international characters.
	for (auto&&  i : A::data) wcout << i << L'\t';
	cout << endl;

	const string s{u8"กรุงเทพมหานคร อมรรัตนโกสินทร์ มหินทรายุธยา มหาดิลกภพ  นพรัตนราชธานีบูรีรมย์ อุดมราชนิเวศน์มหาสถาน อมรพิมานอวตารสถิต  สักกะทัตติยวิษณุกรรมประสิทธิ์"};
	//cout << s << endl;
	
	// Let's try to convert this for internal use. (meaning, UTF-8 -> wchar_t) 
	mbstate_t mbs{};

	// mbsrtowcs doesn't seem to work, don't know why. codecvt, farther below  does. 
	//char const *p = s.c_str();
	//size_t wchars_written = mbsrtowcs(wc,&p,s.length(),&mbs);
	//if (NULL == p) cout << "Problem with mbsrtowcs : " << p << endl;
	//else cout << "mbsrtowcs success! number of wchars written:" <<  wchars_written << endl;

	wstring wc(s.length(),L'\0');
	wchar_t* p_to; 
	char const * p_from;
	switch (use_facet<codecvt<wchar_t, char, mbstate_t>>(locale()).in(mbs,&s[0],&s[s.size()],p_from,&wc[0],&wc[wc.size()],p_to)) {
	case codecvt_base::noconv:
		cout << "codecvt::in(): No conversion necessary" << endl;
		break;
	case codecvt_base::partial:
		cout << "codecvt::in(): partial conversion: stopped at " << p_to - wc[0] << " numbered element" << endl;
		break;
	case codecvt_base::error:
		cout << "codecvt::in(): invalid character encountered at " << p_to - wc[0] << " numbered element" << endl; 
		break;
	case codecvt_base::ok:
		cout << "codecvt::in(): " << wc.size() << " characters converted" << endl;
		break;
	}
	


	try {
		wcout << L"The converted string in wide: " << wcout.widen('\n') << wc << endl;
		//I don't know why, but we seem to always need clear() after the Thai characters. 
		//Maybe because the final character " ์" is a tonal character, maybe part of a multicharacter.
		wcout.clear(); 


		wcout << L"\n\nThe converted wide characters: " << endl;
		for (auto&& c: wc) wcout << c << L' ';
		wcout.clear();
		wcout << endl << endl;

		// try sorting
		string foo_copy(foo);
		sort(foo_copy.begin(), foo_copy.end()); 	
		foo_copy.erase(unique(foo_copy.begin(), foo_copy.end()), foo_copy.end());
		wcout << L"\n\nThe converted wide characters sorted and unique: " << endl;
		for (auto&& c: foo_copy ) wcout << c << L' ';
		wcout.clear();
		wcout << endl << endl;

		sort(wc.begin(), wc.end());
		wc.erase(unique(wc.begin(), wc.end()), wc.end());
		for (auto&& c: wc) {
			wcout << c << L' ' ;
			wcout.clear(); // don't forget, Thai characters need wcout.clear(). Mystery.
		}
		

		cout << "\n\nThe end.\n" ;
	} catch (exception& e) {
		cout << e.what() << endl;
	}

	return 0;

}
