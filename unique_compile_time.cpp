#include <type_traits>
#include <iostream>
using namespace std;
template< typename T, T... args>
struct UniqueSet
{
        static const T data[sizeof ...(args)] ;
};

template <typename T, T... args>
const T UniqueSet<T,args...>::data[sizeof ...(args)] = { args... };

template <size_t  pos, size_t n, typename T, T const (&a)[n], T... args>
struct gen_unique_set {
        typedef typename gen_unique_set<pos-1, n, T, a,  args..., a[pos]>::result result;
};

template <size_t n, typename T, T const (&a)[n], T... args>
struct gen_unique_set <0, n, T,  a, args...> {
        typedef UniqueSet<T, a[0], args...> result;
};

constexpr wchar_t myArr[] =  { L'Â§',L'Ã¨', L'Ã©', L'Ã²', L'Ã²', L'Ã²', L'Ã¹', L'ï¬~A', L'Ã~F', L'Ã~F' };

static const size_t myArrSize(sizeof(myArr)/sizeof(myArr[0]));
typedef typename gen_unique_set<myArrSize-1, myArrSize, wchar_t, myArr>::result A;

int main()
{
	cout << "Your locale is: " << locale("").name() << endl;
	
	// you need to imbue wcout with en_US, since fileencoding is en_US.UTF-8, and these wide characters are not UTF-8
	wcout.imbue(locale("en_US.UTF-8") );
	
	for (auto&&  i : A::data) wcout << i << L'\t';
	cout << endl;

	return 0;

}


