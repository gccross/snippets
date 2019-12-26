#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

//recursive - Time Limit Exceeded
string fn(string a, string b) 
{
    int n = a.size(), m=b.size();
    if (m == 0 || m == 0) return "";
    if (a[n-1] == b[n-1]) return string(1,a[n-1]) + fn(a.substr(0,n-1),b.substr(0,m-1));
    string c = fn(a.substr(0,n-1),b);
    string d = fn(a,b.substr(0,m-1));
    return c.size() > d.size() ? c : d;
}

int main() {
    
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        string a,b;
    
        cin >> n >> m;
        cin >> a >> b;
		string res = "";
		for (string::iterator it = a.begin(); it < a.end(); ++it)
		{
			if (res.find(*it) != string::npos) continue;
			size_t c = count(b.begin(), b.end(), *it);
			if (c == count(a.begin(), a.end(), *it))
				res.push_back(*it);
		}
        copy(res.rbegin(),res.rend(), ostream_iterator<char>(cout, "\n"));
        cout << endl;
    }
	//code
	return 0;
}

/*
Given two strings in lowercase, find the longest string whose permutations are subsequence of given two strings. The output longest string must be sorted.

Examples:

Input  :  str1 = "pink", str2 = "kite"
Output : "ik"
The string "ik" is the longest sorted string
whose one permutation "ik" is subsequence of
"pink" and another permutation "ki" is
subsequence of "kite".

Input  : str1 = "working", str2 = "women"
Output : "now"

Input  : str1 = "geeks" , str2 = "cake"
Output : "ek"

Input  : str1 = "aaaa" , str2 = "baba"
Output : "aa"
Input:
First line of the input contains no of test cases  T, then T test cases follow. Each test case consist of 2 space separated integers n and m denoting the size of string str1 and str2 respectively. The next two lines contains the 2 string str1 and str2 .


Output:
For each test case print the output string in sorted order.


Constraints:
1 <= T <= 30
1 <= size(str1),size(str2)<= 100


Example:
Input:
2
6 6
abcdef
edgfhr
3 2
abc
ca

Output:
def
ac

*/
