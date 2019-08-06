// trying to create a sequence of squares at compile time, without using constexpr function.
// finish this someday.
#include <cstddef> 

template <size_t N>
struct squares {
	static constexpr size_t result[N] { squares<N-1>::result,N-1 } ;
};

template <>
struct squares<1> {
	static constexpr size_t result[1] { 0 };	
};

template <typename T> struct foo;

foo<squares<4>::result> f;
