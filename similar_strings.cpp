#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> split_string(string);

template <typename It>
vector<unsigned short> pattern(It first, It last)
{
    size_t len = distance(first, last);
    vector<unsigned short> res(len, 0);
    if (0 == len) return res;

    unordered_map<typename It::value_type, size_t> uos;
    size_t i = 0;
    uos.emplace(make_pair(*first, i));
    res[i] = i;
    while (++i < len)
    {
        ++first;
        if (uos.count(*first)) res[i] = uos[*first]; 
        else 
        {
            res[i] = i;
            uos[*first] = i;
        }

    }
    return res;
}
/*
 * Complete the similarStrings function below.
 */
vector<int> similarStrings(int n, const string& s, vector<vector<int>> queries) {

    vector<int> res;
    for (vector<vector<int>>::const_iterator cit = queries.begin(); 
        cit!=queries.end();
        ++cit)
    {
        int l = (*cit)[0], r = (*cit)[1];
        l-=1; 
        int count = 1;
        //cout << "left: " << l << " right: " << r << endl;
        vector<unsigned short> pattern_to_match = pattern(s.cbegin()+l, s.cbegin()+r);

        for (int i=0, j=r - l; s.cbegin()+i+j <= s.end(); ++i)
        {
            if (i == l) continue; // already counted above
            if (pattern(s.begin() + i,s.begin() +i+j) == pattern_to_match) ++count;
        }
        res.push_back(count);
    }
    return res;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string nq_temp;
    getline(cin, nq_temp);

    vector<string> nq = split_string(nq_temp);

    int n = stoi(nq[0]);

    int q = stoi(nq[1]);
    string string_in;
    cin >> string_in;
    vector<vector<int>> queries(q);
    for (int queries_row_itr = 0; queries_row_itr < q; queries_row_itr++) {
        queries[queries_row_itr].resize(2);

        for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
            cin >> queries[queries_row_itr][queries_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = similarStrings(n, string_in, queries);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        cout << result[result_itr];

        if (result_itr != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";


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

/*
Jimmy loves playing with strings. He thinks string  is similar to string  if the following conditions are satisfied:
Both strings have the same length (i.e.,  and ).
For each valid pair of indices, , in the strings,  and  or  and .
For example, string  and  are similar as for ,  and  and for all other  pairs  as well as .
He has a string, , of size  and gives you  queries to answer where each query is in the form of a pair of integers . For each substring , find the number of substrings  where substring  is similar to substring  and print this number on a new line.
Note: Substring  is the contiguous sequence of characters from index  to index . For example, if  abcdefgh, then  cdef.
Input Format
The first line contains two space-separated integers describing the respective values of  and .
The second line contains string .
Each line  of the  subsequent lines contains two space-separated integers describing the respective values of  and  for query .
Constraints



Output Format
For each query, print the number of similar substrings on a new line.
Sample Input
8 4
giggabaj
1 1
1 2
1 3
2 4
Sample Output
8
6
2
1
Explanation
We perform the following sequence of queries:
Strings with length  are all similar, so our answer is .
gi, ig, ga, ab, ba, and aj are similar, so our answer is .
gig and aba are similar, so our answer is .
igg has no similar string, so our answer is .
*/
