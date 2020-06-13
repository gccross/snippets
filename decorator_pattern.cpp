#include <iostream>
#include <sstream>
#include <string>


class Shape 
{
public:
	virtual std::string str() const = 0;
};

class Circle : public Shape
{
	float radius;
public: 
	explicit Circle(float radius): radius(radius) {};
	void resize(float factor) { radius *= factor; }
	std::string str() const override
	{
		std::ostringstream oss;
		oss << "circle with radius " << radius ;
		return oss.str();
	}
};

class Square : public Shape
{
	float length;
public:
	explicit Square (float length): length(length) {};
	void resize(float factor) { length *= factor; }
	std::string str() const override
	{
		std::ostringstream oss;
		oss << "square with side length " << length ;
		return oss.str();
	}
};

// dynamic decorators for Colour and Transparency
class ColouredShape :  public Shape
{
	const Shape& shape;
	std::string colour;
public:
	explicit ColouredShape(const Shape& shape, std::string colour) : shape(shape), colour(colour){}
	std::string str() const override
	{
		std::ostringstream oss;
		oss << shape.str() << " and colour " << colour;
		return oss.str();
	}


};

class TransparentShape :  public Shape
{
	const Shape& shape;
	float transparency;
public:
	explicit TransparentShape(const Shape& shape, float transparency) : shape(shape), transparency(transparency){}
	std::string str() const override
	{
		std::ostringstream oss;
		oss << shape.str() << " and transparency " << transparency/255*100.0;
		return oss.str();
	}
};

// static decorators 

template <typename T>
class ColouredShape_static : public T
{
	std::string colour;
public:
	template <typename... Args>
	ColouredShape_static (std::string colour, Args ...args) : colour(colour), T(std::forward<Args>(args)...) {}

	std::string str() const override
	{
		std::ostringstream oss;
		oss << T::str() << " resizeable, with colour " << colour;
		return oss.str();
	}
};

template <typename T>
class TransparencyDecorator : public T
{
	uint8_t transparency;
public:
	template <typename... Args>
	TransparencyDecorator(uint8_t transparency, Args... args): transparency(transparency), T(std::forward<Args>(args)...) {}
	std::string str() const override
	{
		std::ostringstream oss;
		oss << T::str() << " resizeable, with transparency " << static_cast<float>(transparency)/255*100.f ;
		return oss.str();
	}
};

int main(const int argc, const char * const argv[])
{
	TransparentShape t(ColouredShape(Square(3), "green"), 225);
	std::cout << t.str() << "\n"; 

	std::cout << TransparencyDecorator<ColouredShape_static<Circle>>(99,"mauve", 3.5).str() << "\n";

	ColouredShape_static<TransparencyDecorator<Square>> myshape("fushia",35,7) ;
	std::cout << myshape.str() << "\n";
	myshape.resize(1.5);
	std::cout << myshape.str() << "\n";

	return 0;
}
