/*
This source file should be utf-8 encoding to see the Thai characters. 
Compile using g++ or clang++,

	g++ -std=c++17  

Output of the program on a terminal that handles utf-8, should look like this:

ก: e01	ข: e02	ฃ: e03	ค: e04	ฅ: e05	ฆ: e06	ง: e07	จ: e08	ฉ: e09	ช: e0a	ซ: e0b	ฌ: e0c	ญ: e0d	ฎ: e0e	ฏ: e0f	ฐ: e10
ฑ: e11	ฒ: e12	ณ: e13	ด: e14	ต: e15	ถ: e16	ท: e17	ธ: e18	น: e19	บ: e1a	ป: e1b	ผ: e1c	ฝ: e1d	พ: e1e	ฟ: e1f	ภ: e20
ม: e21	ย: e22	ร: e23	ฤ: e24	ล: e25	ฦ: e26	ว: e27	ศ: e28	ษ: e29	ส: e2a	ห: e2b	ฬ: e2c	อ: e2d	ฮ: e2e	ฯ: e2f	ะ: e30
ั: e31	า: e32	ำ: e33	ิ: e34	ี: e35	ึ: e36	ื: e37	ุ: e38	ู: e39	ฺ: e3a	฻: e3b	฼: e3c	฽: e3d	฾: e3e	฿: e3f	เ: e40
แ: e41	โ: e42	ใ: e43	ไ: e44	ๅ: e45	ๆ: e46	็: e47	่: e48	้: e49	๊: e4a	๋: e4b	์: e4c	ํ: e4d	๎: e4e	๏: e4f	๐: e50
๑: e51	๒: e52	๓: e53	๔: e54	๕: e55	๖: e56	๗: e57	๘: e58	๙: e59	

*/

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
