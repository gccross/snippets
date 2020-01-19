#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;


class Car
{
        string plate;
        string brand;
        unsigned num_passengers;
        virtual unsigned internal_getNumPassengers() const { return 0; }
    public: 
		Car(const string& _p): plate(_p), brand(""), num_passengers(0){};
        Car(const string& _p, const string& _b, unsigned _n): plate(_p), brand(_b), num_passengers(_n) {}
        string getPlate() const { return plate; }
        void setPlate(const string& p) { plate = p; }
        string getBrand() const { return brand; }
        void setBrand(const string& b) { brand = b; }
        unsigned getNumPassengers() const { return internal_getNumPassengers(); }
};

bool operator==(const Car& lhs, const Car& rhs) { return lhs.getPlate() == rhs.getPlate(); }

class SUV: public Car
{
    bool option;
    
    unsigned internal_getNumPassengers() const { return option ? getNumPassengers() + 3 : getNumPassengers(); }
    public:
        SUV(const string& _p, const string& _b, unsigned _n, bool _o): Car(_p,_b,_n), option(_o){}
};

class Sedan: public Car
{
    bool option;
    unsigned internal_getNumPassengers() const { return getNumPassengers(); } 

    public: 
        Sedan(const string& _p, const string& _b, unsigned _n, bool _o): Car(_p,_b,_n), option(_o){}
};

class CarRental
{
        unordered_map<string, Car> cars;

    public:

        CarRental(){};
        CarRental(const unordered_map<string, Car>& _cars) : cars(_cars) {};
        void addCar(const Car& c) { cars.emplace(make_pair(c.getPlate(), c)); }
        void removeCar(const Car& c) { cars.erase(c.getPlate());}
        size_t numCars() { return cars.size(); } 
		Car findCar(const string& plate){ return cars.find(plate)->second; }

};

int main(const int argc, char const * const argv[])
{
	
	SUV suv1 { "abc", "Lincoln", 10, true };
	SUV suv2 { "bcd", "Yukon", 8, false };
	Sedan sed1 { "cde", "Camry", 5, true };
	Sedan sed2 { "def", "Continental", 6, false };

	CarRental cr;
	cr.addCar(suv1);

    return 0;
}
