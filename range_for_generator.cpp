#include <type_traits> 
#include <iostream>
#include <locale>

namespace george {

template <typename T>
class sequence_generator
{
public: 
	sequence_generator(T _start, T _last, T _step) : start(_start), last(_last), step(_step){}

	class iterator  {
	public:
		iterator(T& v, T _step): elem(v), step(_step) {}
		const T& operator* () const { return elem; }
		//T* operator-> () const { return &elem; } // as some point I got compile error for not providing this with operator*
		iterator& operator++ () { elem+=step; return *this; }

	private: 
		T& elem;
		T step;
	};
	
	iterator begin() {  return iterator(start, step);}
	iterator end() { return iterator(last, step); } 

private: 
	T start, last, step;

};

template <typename It1, typename It2> 
inline bool operator!= (const It1& left, 
		const It2& right) { return *left != *right; }

}

int main(int argc, const char * const argv [] ) 
{
	george::sequence_generator<char16_t> seq(u'ก',u'๙'+1,1); 

	using namespace std;

	wcout.imbue(locale("en_US.UTF-8"));
	wcout.setf(ios::hex, ios::basefield); //ios::hex alone won't work

	size_t line;
	for (auto&& i : seq){
		wstring s(1,i);
		wcout << s << ": "  << i <<  (--line%0x10 ? '\t' : '\n' ) ; //16 columns per line
	}

	return 0;
}
