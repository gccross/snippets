// LRU Cache from geeksforgeeks
//
// Sample input:
//
//
//	2
//	2
//	2
//	SET 1 2 GET 1
//	2
//	7
//	SET 1 2 SET 2 3 SET 1 5 SET 4 5 SET 6 7 GET 4 GET 1
//



#include <atomic>
#include <map>
#include <unordered_map>
#include <iostream>
#include <utility>


template <typename T>
T* address_of(T& t){
	return static_cast<T*>(reinterpret_cast<const char&>(t));
};


using namespace std;

atomic<unsigned long long> global_order = 0; 
typedef unsigned long long global_order_type;

template<typename K, typename V>
class LRUCache
{
	struct LRUValue
	{
		V value;
		global_order_type  order;
	};

	std::unordered_map<K, LRUValue>  lru_map;
	std::map<global_order_type, K> order_map;

	typedef  typename decltype(lru_map)::iterator lru_map_iterator_type;

	public:
		LRUCache(int size){ lru_map.reserve(size); }

		int get(K key){ 
			lru_map_iterator_type res = lru_map.find(key); 
			if (res != lru_map.end()) {

				// need to make atomic/exception safe
				order_map.erase(res->second.order);
				res->second.order = ++global_order;
				order_map.insert({res->second.order, key});
					
				return res->second.value; 
			}
			else return -1; 
		}

		void set(K key ,V value) { 

			global_order_type new_order_val( ++global_order);
			global_order_type old_order_val(lru_map[key].order);

			if (!lru_map.insert({key,LRUValue{value, new_order_val}}).second) {
				// element already exists 
				
				lru_map[key] = LRUValue{value, new_order_val};
				order_map.erase(old_order_val);
				
			} 

			order_map.insert({new_order_val, key});
			
		}
};


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		LRUCache<int,int> *l  = new LRUCache<int,int>(n);
		int q;
		cin>>q;
		for(int i=0;i<q;i++)
		{
			string a;
			cin>>a;
			if(a=="SET")
			{
				int aa,bb;
				cin>>aa>>bb;
				l->set(aa,bb);
			}else if(a=="GET")
			{
				int aa;
				cin>>aa;
				cout<<l->get(aa)<<" ";
			}
		}
		cout<<endl;
	}
}

/*
For Input:
1
8
82
SET 97 30 GET 43 GET 13 SET 48 56 GET 67 GET 60 SET 74 43 SET 72 39 SET 100 59 GET 85 SET 91 62 GET 72 SET 1 4 GET 1 GET 53 GET 5 SET 59 60 SET 18 95 GET 37 GET 61 GET 15 SET 66 38 GET 22 GET 10 SET 33 1 GET 5 SET 57 59 SET 69 11 SET 29 70 SET 75 47 GET 6 GET 2 SET 68 90 GET 27 GET 39 SET 1 6 GET 58 GET 49 SET 8 18 SET 70 98 GET 29 SET 71 19 SET 81 93 GET 55 SET 44 8 GET 51 SET 89 86 GET 91 GET 35 SET 84 26 SET 43 95 GET 92 SET 21 21 GET 39 GET 93 GET 23 GET 86 GET 95 GET 9 GET 3 SET 23 85 SET 58 26 SET 93 3 GET 97 GET 31 GET 50 SET 57 13 SET 49 55 GET 29 GET 58 GET 77 SET 21 98 SET 6 95 GET 83 GET 24 SET 16 37 SET 54 85 SET 55 25 GET 37 GET 93 GET 59 GET 24

Output of Online Judge is:
-1 -1 -1 -1 -1 39 4 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 70 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 26 -1 -1 -1 -1 -1 -1 -1 

3
59
GET 73 SET 74 38 GET 80 SET 10 62 SET 11 58 SET 67 47 GET 79 GET 42 GET 26 SET 4 70 SET 26 25 SET 85 8 SET 70 32 SET 90 5 GET 66 SET 8 52 GET 63 GET 7 GET 61 SET 55 69 SET 12 46 SET 70 1 SET 27 27 GET 63 SET 32 36 GET 41 GET 50 SET 1 24 GET 33 GET 96 GET 43 SET 63 76 SET 61 80 SET 61 1 GET 98 GET 25 GET 1 SET 32 90 GET 82 GET 80 SET 80 28 SET 95 12 GET 3 GET 15 SET 80 4 GET 64 GET 61 SET 11 55 GET 79 GET 15 GET 54 GET 81 SET 60 55 GET 34 GET 38 SET 45 85 SET 59 74 GET 29 SET 92 90

Its Correct output is:
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 24 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1

*/
