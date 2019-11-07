

using namespace std;

vector<string> split_string(string);

/*
 * From Hacker Rank.   Complete the similarStrings function below.
 */
vector<int> similarStrings(int n, string S, vector<vector<int>> queries) {


    typedef string::iterator vit;
    auto cmp = [](vit first_l, vit last_l, vit first_r, vit last_r){
         if (distance(first_l,last_l) != distance(first_r,last_r))
            return false;
    
        for (vit it_l = first_l, it_r=first_r ; it_l != last_l; ++it_l, ++it_r)
        {
            vit it_l2 = find(it_l+1, last_l, *it_l);
            if (it_l2 != last_l) {
                // TODO: memoize duplicates
                if (*it_r != *(it_r + distance(it_l, it_l2)))
                    return false;
            }
            if (it_l2 == last_l && find(it_r+1, last_r, *it_r) != last_r) 
                return false;

        }
        cout << "True: " << string(first_l, last_l) << " : " << string(first_r, last_r) << endl;
        return true;
    };


    auto build_memoize_table = [](vit first, vit last) {
        auto factorial = [](int N) { 
            int res = 0, i=N;
            while (i--) res += N-i;
            return res;
        };

        vector<bool> dp(factorial(distance(first, last) - 1));
        fill(dp.begin(), dp.end(), false);
        int k=0;
        for (vit i = first; i < last - 1; ++i) 
            for (vit j = i + 1; j< last; ++j, ++k) {
                if (*i == *j) dp[k] = true;
            }
        return dp;
    };

    vector<int> res_vec;
    for (vector<vector<int>>::iterator it=queries.begin(); it<queries.end(); ++it) {
        int left = (*it)[0]-1, right = (*it)[1]; // conv 1..n to C++ iterator paradigm
        int sub_len = right - left;
 
        vector<bool> dp = build_memoize_table(S.begin()+left, S.begin() + left + sub_len);
        int res = 0;
        for (vit h=S.begin(); h + sub_len - 1 < S.end() ; ++h){
            vector<bool> dp2 = build_memoize_table(h, h+sub_len);
            if (dp == dp2) ++res;
        }
        res_vec.emplace_back(res);          
    }
    return res_vec;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nq_temp;
    getline(cin, nq_temp);

    vector<string> nq = split_string(nq_temp);

    int n = stoi(nq[0]);

    int q = stoi(nq[1]);
    string S;
    cin >> S; 
    vector<vector<int>> queries(q);
    for (int queries_row_itr = 0; queries_row_itr < q; queries_row_itr++) {
        queries[queries_row_itr].resize(2);

        for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
            cin >> queries[queries_row_itr][queries_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = similarStrings(n, S, queries);

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

