#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the contacts function below.
 */
vector<int> contacts(vector<vector<string>> queries) {
    /*
     * Write your code here.
     */
    map<string,size_t> dict;
    auto add = [&dict](string const & name) -> void
    {
        for (size_t i=1; i<=name.length(); ++i)
            ++dict[name.substr(0,i)];
    };
    auto find = [&dict](string const & pat) -> int
    {
        return dict[pat];
    };
    vector<int> res;
    for (vector<string> query: queries)
    {
        if (query[0] == "add") add(query[1]);
        else if (query[0] == "find") res.emplace_back(find(query[1]));
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int queries_rows;
    cin >> queries_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<string>> queries(queries_rows);
    for (int queries_row_itr = 0; queries_row_itr < queries_rows; queries_row_itr++) {
        queries[queries_row_itr].resize(2);

        for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
            cin >> queries[queries_row_itr][queries_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = contacts(queries);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

