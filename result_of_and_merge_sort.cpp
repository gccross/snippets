// This is a little demonstration of isolating the return value of a function type
// eg. a simplified result_of
// It also shows how to emit that type from the compiler 

// I also wrote a merge sort, for practise.  

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>


template <typename T> struct retval { typedef T  type; };

template <typename T1>
struct retval<T1 (*)()>
{
	using type = T1;
};

template <typename T> struct EmitType {};

#ifdef SHOW_TYPES
EmitType<typename retval<float (&)()>::type>::ugh Et; // won't match specialization
EmitType<typename retval<float (*)()>::type>::ugh Et; // matches specialization
#endif


namespace george {

	template <typename It> 
		
	void merge (It first, It last, It pivot) // <--- John feedback: remove this pivot it isn't necessary!
	{
		It it1 = first;
		for (It it2 = pivot; it2 != last; ++it2) {

			// advance to spot it belongs
			while (*it2 > *it1) ++it1;

			// insert
			typename It::value_type temp = *it1;  // John feedback: std::move()
			*it1 = *it2;
			for (It it = it1+1; it<it2+1; ++it ) swap(temp, *it);
		}
	
	}

	template <typename It> 
	void sort(It first, It last)
	{
		// John feedback: handle empty range

		// terminal case just one element 
		if (first+1 == last) return;

		// terminal case, just two elements
		if (first+2 == last) {   
			if (*first > *(first+1))
				 swap(*first, *(first+1));
			 return; 
		}

		// otherwise, divide and conquer
	
		// first find the middle
		It i=first, i2=first;
		for (; i2<last; ++i, i2+=2 ); 

		//std::cout << *i << std::endl; // just checking if it is in the middle


		// sort each range 
		sort (first, i);
		sort (i, last);

		// merge them
		merge (first, last, i);
		
		
	}

}


int main(int argc, const char* const argv[]) 
{
	using namespace std; 
	ifstream ifs;
	if (argc > 1) {
		ifs.open(argv[1]);
		cin.rdbuf(ifs.rdbuf());
	}

	vector<string> v;
	copy(istream_iterator<string>(cin), istream_iterator<string>(), back_insert_iterator<vector<string>>(v));
	copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));	

	cout << endl;

	george::sort(v.begin(), v.end());
	copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));	
	
	return 0;
}
