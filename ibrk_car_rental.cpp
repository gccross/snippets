#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


class Car
{
	string plate;
	string brand;
	virtual unsigned internal_getNumPassengers() const = 0;
protected:
	unsigned num_passengers;
public: 
	Car(const string& _p): plate(_p), brand(""), num_passengers(0){};
	Car(const string& _p, const string& _b, unsigned _n): plate(_p), brand(_b), num_passengers(_n) {}
	virtual ~Car() = default;
	const string& getPlate() const { return plate; }
	void setPlate(const string& p) { plate = p; }
	const string& getBrand() const { return brand; }
	void setBrand(const string& b) { brand = b; }
	unsigned getNumPassengers() const { return internal_getNumPassengers(); }
};

bool operator==(const Car& lhs, const Car& rhs) { return lhs.getPlate() == rhs.getPlate(); }

class SUV: public Car
{
	bool option;
	unsigned internal_getNumPassengers() const { return option ? num_passengers + 3 : num_passengers; }
public:
	SUV(const string& _p, const string& _b, unsigned _n, bool _o): Car(_p,_b,_n), option(_o){}
};

class Sedan: public Car
{
	bool option;
	unsigned internal_getNumPassengers() const { return num_passengers; } 

public: 
	Sedan(const string& _p, const string& _b, unsigned _n, bool _o): Car(_p,_b,_n), option(_o){}
};

class CarRental
{
	unordered_map<string, unique_ptr<Car>> cars;

public:

	CarRental() = default;
	void addCar(unique_ptr<Car> c) { cars[c->getPlate()] = move(c); }
	void removeCar(const unique_ptr<Car> c) { cars.erase(c->getPlate());}
	size_t numCars() { return cars.size(); } 
	const Car& findCar(const string& plate){ return *(cars.find(plate)->second); }

};

int main(const int argc, char const * const argv[])
{
	
	unique_ptr<SUV> suv1 = make_unique<SUV>( "abc", "Lincoln", 10, true );
	unique_ptr<SUV> suv2 = make_unique<SUV>( "bcd", "Yukon", 8, false );
	unique_ptr<Sedan> sed1 = make_unique<Sedan>( "cde", "Camry", 5, true );
	unique_ptr<Sedan> sed2 = make_unique<Sedan>( "def", "Continental", 6, false );

	CarRental cr;
	cr.addCar(move(suv1));
	const Car& c = cr.findCar("abc");
	cout << "Brand: " << c.getBrand() << " Passengers: " << c.getNumPassengers() << endl;

    return 0;
}
