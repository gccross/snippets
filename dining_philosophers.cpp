// Dining Philosophers
// Round table, six philosophers, six chopsticks.  They all share (unsanitary). 
// Each need two chopsticks. 
//
// Deadlock can occur if everyone trys to pickup (mutext lock) the left first.
// Djikstra's solution is to have one person pick up the right first. 
// Or, alternatively, just have everyone pick up the lower-numbered chopstick first. 
// (that merely means the last person trys to pick up the same one the first is already holding)
//
// With mutexs, some might eat more, sooner, since there is no ordering. 
// Introduce condition variables to be sure everyone eats in order.
//
// You actually only need one condition variable for each philosopher, eg. the left chopstick.
// Originally I had put two, but this is redundant (after you reflect upon it).
// 
// Suggest use printf over cout, so output is not interwoven amongst threads.
// (maybe don't have to abandon cout, but printf worked for me.)
//
// std::array static initialization needs {{ }}.  Something about being an aggregate type.

#include <array>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

struct chopstick_t 
{
	pthread_mutex_t mutex;
	pthread_cond_t free;
};

struct apostle_t
{ 
	string name;
	pthread_t thread;
	chopstick_t left;
	chopstick_t right;
};

void* mangiare(void* data)
{
	apostle_t* apostle = static_cast<apostle_t*>(data);
	uint chews { 0 };
	while (chews < 5)
	{
		if (apostle->name == "Judah") 
									 
		{
			pthread_mutex_lock(&apostle->right.mutex);
			pthread_mutex_lock(&apostle->left.mutex);
			//pthread_cond_wait(&apostle->right.free,&apostle->right.mutex ); 
			pthread_cond_wait(&apostle->left.free,&apostle->left.mutex ); 
		} 
		else
		{
			pthread_mutex_lock(&apostle->left.mutex);
			pthread_mutex_lock(&apostle->right.mutex);
			pthread_cond_wait(&apostle->left.free,&apostle->left.mutex );
			//pthread_cond_wait(&apostle->right.free,&apostle->right.mutex );
		}

		++chews;
		printf("%s si manga il suo  %d'i boccone\n", apostle->name.c_str(), chews);

		if (apostle->name == "Judah")
		{
			pthread_cond_signal(&apostle->left.free);
			//pthread_cond_signal(&apostle->right.free);
			pthread_mutex_unlock(&apostle->left.mutex);
			pthread_mutex_unlock(&apostle->right.mutex);
		}
		else
		{
			//pthread_cond_signal(&apostle->right.free);
			pthread_cond_signal(&apostle->left.free);
			pthread_mutex_unlock(&apostle->right.mutex);
			pthread_mutex_unlock(&apostle->left.mutex);
		}
	}
	return nullptr;
}

int main (int argc, char const * argv[])
{

	array<chopstick_t, 12> chopsticks;
	array<pthread_t, 12> threads;
	array<apostle_t, 12> apostles 
	{{
		{ "John", threads[0],  chopsticks[0], chopsticks[1] },
		{ "Andres", threads[1],  chopsticks[1], chopsticks[2] },
		{ "Thaddeus", threads[2],  chopsticks[2], chopsticks[3] },
		{ "James Elder", threads[3],  chopsticks[3], chopsticks[4] },
		{ "Judha", threads[4],  chopsticks[4], chopsticks[5] },
		{ "Paul", threads[5],  chopsticks[5], chopsticks[6] },
		{ "Bartholomew", threads[6],  chopsticks[6], chopsticks[7] },
		{ "Mattew", threads[7],  chopsticks[7], chopsticks[8] },
		{ "Philip", threads[8],  chopsticks[8], chopsticks[9] },
		{ "Simon", threads[9],  chopsticks[9], chopsticks[10] },
		{ "Thomas", threads[10],  chopsticks[10], chopsticks[11] },
		{ "James Younger", threads[11],  chopsticks[11], chopsticks[0] }
	}};

	for (array<chopstick_t, 12>::iterator it = chopsticks.begin(); it < chopsticks.end(); ++it)
	{
		pthread_mutex_init(&it->mutex, nullptr);
		pthread_cond_init(&it->free, nullptr);
	}

	for (array<apostle_t, 12>::iterator it = apostles.begin(); it < apostles.end(); ++it)
	{
		pthread_create(&it->thread, nullptr, mangiare, it);
		pthread_cond_signal(&it->left.free);
		pthread_cond_signal(&it->right.free);
	}
	
	this_thread::sleep_for(chrono::seconds(5));
	cout << "Hello World " __FILE__ << endl;
	
	for (array<apostle_t, 12>::iterator it = apostles.begin(); it < apostles.end(); ++it)
		pthread_join(it->thread, nullptr);
	return 0;

}
