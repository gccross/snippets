#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;

//recursive
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
