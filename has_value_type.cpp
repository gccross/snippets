#include <iostream>
#include <type_traits>
#include <vector>

// has_value_type
template <typename, typename = std::void_t<>>
struct  has_value_type: std::false_type {};

template <typename T>
struct has_value_type<T, std::void_t<typename T::value_type>>: std::true_type {};

int main() 
{ 
	std::cout << "bool: " << std::boolalpha << has_value_type<bool>::value << std::endl;
	std::cout << "vector_has: " << std::boolalpha << has_value_type<std::vector<int>>::value << std::endl;

	std::cout << "true_type: " << std::boolalpha << std::true_type::value << std::endl;
	std::cout << "false_type: " << std::boolalpha << std::false_type::value << std::endl;
	return 0;
}
