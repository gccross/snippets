#include <iomanip>
#include <locale>
#include <sstream>
#include <iostream>

using namespace std;
int main ()
{
   /* brute force
    short hour = (s[0]-'0')*10 + (s[1]-'0');
    if ('A'==s[8] && 0==s.compare(0,2,"12")) //12AM set to 0
        hour = 0;
    else if ('P'==s[8] && 0!=s.compare(0,2,"12")) //12PM leave as 12
        hour += 12;
    
    string ret; 
    if (10 > hour) ret+='0';
    ret += to_string(hour) + s.substr(2,6);
    */
 
	istringstream iss("12:49:22AM");
	ostringstream oss;
	tm t;
	iss >> get_time(&t, "%I:%M:%S%p");
	oss.imbue(locale("POSIX"));
	oss << put_time(&t, "%H:%M:%S") << '\n';
	cout <<  oss.str();

}
