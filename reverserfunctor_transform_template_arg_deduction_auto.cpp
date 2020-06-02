#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

class 	MyObjectBuilder
{
public:
	std::vector<std::string>& makeObject() const
	{
		return *std::make_unique<std::vector<std::string>>(25,"brindles");
	}

};

template <typename T>
class ReverserFunctor
{
public:
	T& operator()(T& t)
	{
		std::reverse(t.begin(),t.end());
		return t;
	}
};
template </*typename BuiltType,*/ typename Builder>
void makeAndProcessObject (const Builder& builder)
{
    //BuiltType val = builder.makeObject();
    auto val = builder.makeObject();
    std::transform(val.begin(), val.end(), std::ostream_iterator<std::string>(std::cout, "\n"), ReverserFunctor<std::string>());
};

int main(const int argc, const char* argv[])
{
	MyObjectBuilder b;
	makeAndProcessObject(b);

	return 0;
}

