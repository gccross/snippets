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



#include <map>
#include <unordered_map>
#include <iostream>
#include <utility>


template <typename T>
T* address_of(T& t){
	return static_cast<T*>(reinterpret_cast<const char&>(t));
};


using namespace std;

static unsigned long long  global_order = 0; 
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
				order_map[res->second.order] = key;
					
				return res->second.value; 
			}
			else return -1; 
		}

		void set(K key ,V value) { 
			if (lru_map.max_size() == lru_map.size()) {
				K lrukey = order_map.begin()->second;		
				global_order_type orderkey = lru_map[lrukey].order;
			
				// need to make atomic/exception safe
				lru_map.erase(lrukey);		
				order_map.erase(order_map.begin());

			}

			global_order_type new_order_val = ++global_order;
			lru_map_iterator_type res = lru_map.find(key); 
			if (res != lru_map.end()) {

				// need to make atomic/exception safe
				order_map.erase(res->second.order);
				res->second.order = new_order_val;
				order_map[res->second.order] = key;
			}
			lru_map[key] = LRUValue{value,new_order_val}; // can template params be deduced? 
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

/*This is a function problem.You only need to complete the function given below*/
/*The structure of the class is as follows 
  class LRUCache
  {
  public:
  LRUCache(int );
  int get(int );
  void set(int , int );
  };*/
