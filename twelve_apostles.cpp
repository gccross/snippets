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
	struct thread_data
	{
		vector<apostle> &v;
		const size_t index;
	};
	thread_data td;
	pthread_t thread;
	const string & name;
	unsigned mouthfuls;
	chrono::seconds sec;
	chopstick &left, &right;

	pthread_t& get_thread() { return thread; } 

	apostle(const string &s, chopstick &l, chopstick &r, vector<apostle>& v, const size_t index): 
		name(move(s)), left(l), right(r), mouthfuls(0), td({v,index})
	{
		pthread_create(&thread, nullptr, feed, static_cast<void*>( &td));
	};

};



void* feed(void* data)
{
	const apostle::thread_data & td = *static_cast<apostle::thread_data*>(data);
	apostle &a = td.v[td.index];  // <-- dangerous, &a could be changed if vector resizes
	while (a.mouthfuls < 20)
	{
		pthread_mutex_lock(&a.left.mutex);
		pthread_cond_wait(&a.left.cond,&a.left.mutex);
		pthread_mutex_lock(&a.right.mutex);
		pthread_cond_wait(&a.right.cond,&a.right.mutex);
		cout << "Apostle " << a.name << " thread id " << pthread_self() 
			<< " acquired spoon at count: " << a.mouthfuls << endl;
		++a.mouthfuls;
		pthread_cond_signal(&a.left.cond);
		pthread_cond_signal(&a.right.cond);
		pthread_mutex_unlock(&a.right.mutex);
		pthread_mutex_unlock(&a.left.mutex);
	}
	return nullptr;
}

int main (int argc, char const * argv[])
{
	array<string, 12> names {"John", "Luke", "Peter", "James", "Judha", "Paul", "Bartholomew", "Matthew", "Philip", "Simon", "Thomas", "Juddhas" };
	//array<string, 2> names {"John","Luke"};
	array<chopstick,names.size()> sticks;
	vector<apostle> apostles;

	for (int i=0; i+1<names.size(); ++i)
		apostles.emplace_back( names[i],sticks[i],sticks[i+1], apostles, i );  // <-- danger!! elements could be relocated elsewhere causing segfault in feed() function

	apostles.emplace_back(names[names.size()-1], sticks[0],sticks[names.size()-1], apostles, names.size()-1);
	for (chopstick& stick: sticks) pthread_cond_signal(&stick.cond);
	for (apostle&  a: apostles) pthread_join(a.get_thread(), nullptr);
	
	return 0;

}
