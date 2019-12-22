#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <forward_list>
#include <utility>
#include <vector>

using namespace std;

vector<string> split_string(string);

template <typename It>
size_t merge(It first, It mid, It last)
{
    size_t count = 0;
    while (first != mid && mid != last)
    {
        if (*first > *mid)
        {
			It left = first;
            while (left != mid) {
            	count+= distance(left,mid);
				iter_swap(left++, mid);
			}
			++mid;
        }
        else ++first;
    }
    return count;
}

namespace rama_hoetzlein
{
template <typename It>
size_t mergesort(It first, It last)
{
	size_t n = distance(first, last);
	size_t count = 0;

	for (size_t incr = 1; incr < n; incr *= 2)
		for (size_t left = 0; left + incr < n; left += incr*2)
		{
			size_t right = left + incr;
			size_t right_end = right + incr;
			if (right_end > n) right_end = n;

			It it_l = first, it_mid = first, it_r = first;
			advance(it_l, left);
			advance(it_mid, right);
			advance(it_r, right_end);
			count += merge(it_l, it_mid, it_r);
		}
	return count;	
}
}

namespace george_bfs
{
template <typename It>
size_t mergesort(It first, It last)
{
	size_t n = distance(first,last);
	if (n < 4)
	{
		It mid = first;
		++mid;
		return merge(first, mid, last);
	}
	
	deque<pair<It, It>> dq;
	for (int incr = n/2; incr > 1; incr/=2)
	{
		It left = first;
		size_t len = 0;

		while (len < n)
		{
			It right = left;
			advance(right, incr);
			dq.push_front(make_pair(left, right));
			left = right;
			len += incr;
			if (n - len < 2*incr)
			{
				dq.push_front(make_pair(left, last));
				len = n;
			}
		}
	}

	// sort the leaves
	size_t inv_count = 0;
	typename deque<pair<It, It>>::iterator it = dq.begin(); 
	do
	{
		It mid = it->first;
		++mid;
		inv_count += merge(it->first, mid, it->second);
		++it;
	} while (it->second != last);

	
	// merge the rest
	while (!dq.empty())
	{
		pair<It, It> right = dq.front(); dq.pop_front();
		pair<It, It> left = dq.front(); dq.pop_front();
		
		inv_count += merge(left.first, left.second, right.second);
	}
	return inv_count;
}
} 


template <typename It>
size_t mergesort(It first, It last)
{
    size_t count = 0;
    if (first == last) return 0;
	It mid = first;
	++mid;	
    if (mid == last) return 0;

    advance(mid, distance(first,last)/2 - 1);
    count += mergesort(first, mid);
    count += mergesort(mid, last);

    count += merge(first, mid, last);
    return count;
}

// Complete the minimumBribes function below.
template <typename It>
void minimumBribes(It first, It last) {

    cout << endl << rama_hoetzlein::mergesort(first, last) << endl;
    copy(first, last, ostream_iterator<int>(cout, " "));
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        forward_list<int> q(n);
		forward_list<int>::iterator it = q.begin();

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            //q[i] = q_item;
            *it++ = q_item;
        }

        minimumBribes(q.begin(), q.end());
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

