#include <iterator>
#include <iostream>
#include <string>

using namespace std;

/*
Problem Description
Given a string with potentially repeated characters, 
find the first non repeating character. 
For example, in "bloomberg", 'b' is the first character, 
but it repeats. The next character 'l' is unique, 
so it is the first non repeating character.

Sample inputs - Expected outputs
"bloomberg"             => 'l'
"ababZabab"             => 'Z'
*/

/*
1. char first_unique(string s)
2. char first_unique(const string * const s)
*/

char first_unique(string const& s)
{
    char ret;
    
    for (string::const_iterator it=s.cbegin(); it<s.cend(); ++it) 
        if (find(it+1, s.cend(), *it) == s.cend()) return *it;
    return	*s.begin(); 
}

int main(int argc, char* argv[])
{
    cout << first_unique("bloomberg") << endl;; 
}
