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

struct thread_data 
{
	pthread_t thread;
	string name;
	unsigned spoonfuls;
	chrono::seconds sec;
};

pthread_mutex_t spoon;
pthread_cond_t spoon_free;
void* use_spoon(void* data)
{
	thread_data* tdata{static_cast<thread_data*>(data)};
	while (tdata->spoonfuls < 20
		&& 
		0 == pthread_mutex_lock(&spoon) 
		&&
		0 == pthread_cond_wait(&spoon_free,&spoon)) 
	{
		cout << "Apostle " << tdata->name << " thread id " << pthread_self() 
			<< " acquired spoon at count: " << tdata->spoonfuls << endl;
		++tdata->spoonfuls;
		pthread_cond_signal(&spoon_free);
		pthread_mutex_unlock(&spoon);
	}
	return nullptr;
}

int main (int argc, char const * argv[])
{
	vector<string> apostles {"John", "Luke", "Peter", "James", "Judha", "Paul", "Bartholomew", "Matthew", "Philip", "Simon", "Thomas" };
	vector<thread_data> v;
	for (vector<string>::iterator it=apostles.begin(); it<apostles.end(); ++it) 
	{ 
		thread_data td;
		td.name = *it;
		td.spoonfuls = 0;
		td.sec = chrono::seconds(5);
		v.push_back(td);
	}
	
	pthread_mutex_init(&spoon, nullptr);
	pthread_cond_init(&spoon_free, nullptr);
	for (vector<thread_data>::iterator it=v.begin(); it < v.end(); ++it) 
		pthread_create(&it->thread, nullptr, use_spoon, &*it);

	cout << "Press any key to continue... " << endl;
	string input;
	getline(cin,input);
	pthread_cond_signal(&spoon_free);
	chrono::seconds  pause(5);
	hello_and_pause(&pause);
	for (thread_data td: v) 
		pthread_join(td.thread, nullptr);
	
	return 0;

}
