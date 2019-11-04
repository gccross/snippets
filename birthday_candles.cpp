#include <iostream>
#include <limits>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<string> split_string(string);

// Complete the birthdayCakeCandles function below.
typedef vector<int>::iterator vit;

vit partition_greatest(vit first, vit last) {
    vit left=first; 
    vit right = last - 1;
    vit select = first;
    while (left < right) {
        if (*left < *right)
            swap(*left, *select++);
        ++left;
    }

    swap(*left, *select);

    return select;
}
// Complete the birthdayCakeCandles function below.
int birthdayCakeCandles(vit first, vit last) {

    vit mid = partition_greatest(first, last);

    if (*mid == *(last - 1)) {
        vit it = last - 1;
        while (*(last - 1) == *it) --it;
        return distance (it+1, last);
    } else if (*mid < *(last - 1)) 
        return birthdayCakeCandles(mid+1, last);
    else
        return birthdayCakeCandles(first, mid);
}

int main()
{
    int ar_count;
    cin >> ar_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(ar_count);

    for (int i = 0; i < ar_count; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = birthdayCakeCandles(ar.begin(), ar.end());

    cout << result << "\n";


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

