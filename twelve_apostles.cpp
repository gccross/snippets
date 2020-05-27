#include <array>
#include <chrono>
#include <iostream>
#include <pthread.h>
#include <string>
#include <thread>
#include <vector>

using namespace std;

void* hello_and_pause(void* data)
{ 
	cout <<  "Hello world from thread: " << pthread_self() << endl; 
	this_thread::sleep_for(*(chrono::seconds*)data); 
	return nullptr; 
}

struct chopstick
{
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	chopstick()
	{
		pthread_mutex_init(&mutex,nullptr);
		pthread_cond_init(&cond,nullptr);
	}
	~chopstick() 
	{
		pthread_cond_destroy(&cond);
		pthread_mutex_destroy(&mutex);
	}

};

void* feed(void* data);
class apostle 
{
public: 
	pthread_t thread;
	string name;
	unsigned mouthfuls;
	chrono::seconds sec;
	chopstick *left, *right;

	pthread_t& get_thread() { return thread; } 

	apostle() = default;
	apostle(const string& a_name, chopstick* a_left, chopstick* a_right): name(a_name), left(a_left), right(a_right){}
	apostle& operator=(apostle a)
	{
		thread = a.thread;
		name = a.name;
		mouthfuls = a.mouthfuls;
		sec = a.sec;
		left = a.left;
		right = a.right;
		pthread_create(&thread, nullptr, feed, this);
		return *this;
	}

};

void* feed(void* data)
{
	apostle & a = *static_cast<apostle*>(data);
	while (a.mouthfuls < 20)
	{
		pthread_mutex_lock(&a.left->mutex);
		pthread_cond_wait(&a.left->cond,&a.left->mutex);
		pthread_mutex_lock(&a.right->mutex);
		pthread_cond_wait(&a.right->cond,&a.right->mutex);
		cout << "Apostle " << a.name << " thread id " << pthread_self() 
			<< " acquired spoon at count: " << a.mouthfuls << endl;
		++a.mouthfuls;
		pthread_mutex_unlock(&a.right->mutex);
		pthread_cond_signal(&a.right->cond);
		pthread_mutex_unlock(&a.left->mutex);
		pthread_cond_signal(&a.left->cond);
	}
	return nullptr;
}

int main (int argc, char const * argv[])
{
	array<string, 12> names {"John", "Luke", "Peter", "James", "Judha", "Paul", "Bartholomew", "Matthew", "Philip", "Simon", "Thomas", "Juddhas" };
	array<chopstick,names.size()> sticks;
	vector<apostle> apostles;
	apostles.reserve(names.size());
	apostles.resize(names.size());

	for (int i=0; i+1<names.size(); ++i)
		apostles[i]=apostle(names[i],&sticks[i],&sticks[i+1]);

	apostles[names.size()-1] = apostle(names[names.size()-1], &sticks[0],&sticks[names.size()-1]);

	while(true)
	{
		for (chopstick& stick: sticks)   pthread_cond_signal(&stick.cond); 
		pthread_yield_np();
	}

	for (apostle&  a: apostles) pthread_join(a.get_thread(), nullptr);
	
	return 0;

}
