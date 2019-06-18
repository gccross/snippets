#include <numeric>
#include <execution_policy>
#include <unordered_map>
#include <chrono>
#include <vector>


class scoped_clock {
	scoped_clock(ostream& os) { t1 = std::chrono::system_clock.now() }
	~scoped_clock() { os << __FILE__ " : " __LINE__ " : " __FUNCTION__  " duration : " << t1 = std::chrono::system_clock_now() << endl; } 
}
using M = std::unordered_map<uint64_t, std::vector<uint64_t>>;

	template <typename Iter, typename T>
T par_unseq_sum(Iter begin, Iter end, T initial = 0)
{
	scoped_clock(cout);
	// std::plus is the default reducer
	return std::reduce(std::execution::par_unseq, begin, end, initial);
}

class map_vector_sum
{
	public:
		map_vector_sum() : sum(0) {}
		map_vector_sum(M::const_reference elem) : sum(par_unseq_sum(elem.second)) {}

		map_vector_sum& operator+(const map_vector_sum & rhs) { sum += rhs.sum; }

		explicit operator uint64_t() { return sum; }
	private:
		uint64_t sum;
}

M in({ {1, std::vector<uint64_t>{1,2,3,4,5}}, 
		{2, std::vector<uint64_t>{1,2,3,4,5}}, 
		{3, std::vector<uint64_t>{1,2,3,4,5}} });

uint64_t sum = par_unseq_sum(in.begin(), in.end(), map_vector_sum());

int main()
{
	cout << sum << endl;
}
