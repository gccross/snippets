#include <algorithm>
#include <iostream>
#include <iterator>
#include <forward_list>
#include <utility>
#include <vector>

using namespace std;

vector<string> split_string(string);

template <typename It>
int merge(It first, It mid, It last)
{
    int count = 0;
    while (first != mid && mid != last)
    {
        if (*first > *mid)
        {
            count+= distance(first,mid);
            iter_swap(first, mid++);
        }
        ++first;
    }
    return count;
}

template <typename It>
int mergesort(It first, It last)
{
    int count = 0;
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

    cout << endl << mergesort(first, last) << endl;
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

