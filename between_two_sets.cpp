#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

int getTotalX(vector<int> a, vector<int> b) {
    auto factors_all = [](vector<int> a, int i) {
        for (vector<int>::iterator it = a.begin(); it<a.end(); ++it)
            if (i%(*it)) return false;
        return true;
    };

    auto is_factor = [](int i, vector<int> b) {
        for (vector<int>::iterator it = b.begin(); it < b.end(); ++it)
            if ((*it)%i) return false;
        return true;
    };

    int count{0};
    for (int i = *(a.end()-1); i<=*(b.end()-1); i+=*(a.end()-1)) 
        if (factors_all(a,i) && is_factor(i,b)) ++count;
    return count;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split(rtrim(brr_temp_temp));

    vector<int> brr(m);

    for (int i = 0; i < m; i++) {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    }

    int total = getTotalX(arr, brr);

    fout << total << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

/*

From Hackerrank.com

You will be given two arrays of integers and asked to determine all integers that satisfy the following two conditions:
The elements of the first array are all factors of the integer being considered
The integer being considered is a factor of all elements of the second array
These numbers are referred to as being between the two arrays. You must determine how many such numbers exist.
For example, given the arrays  and , there are two numbers between them:  and .  , ,  and  for the first value. Similarly, ,  and , .
Function Description
Complete the getTotalX function in the editor below. It should return the number of integers that are betwen the sets.
getTotalX has the following parameter(s):
a: an array of integers
b: an array of integers
Input Format
The first line contains two space-separated integers,  and , the number of elements in array  and the number of elements in array . 
The second line contains  distinct space-separated integers describing  where . 
The third line contains  distinct space-separated integers describing  where .
Constraints



Output Format
Print the number of integers that are considered to be between  and .
Sample Input
2 3
2 4
16 32 96
Sample Output
3
Explanation
2 and 4 divide evenly into 4, 8, 12 and 16. 
4, 8 and 16 divide evenly into 16, 32, 96.
4, 8 and 16 are the only three numbers for which each element of a is a factor and each is a factor of all elements of b.

*/
