#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// the function implements simple search for substrings
auto simpleSearch(string str, string seekedStr)
{
    // the vector which stores starting substrings indexes
    vector<int> results;
    // variables which are the sizes of strings
    int n = str.size(), m = seekedStr.size();

    // loop is going on to n-m in order to no exit from border
    for(int i=0; i<=n-m; i++){
        for(int j=0, k=0; j<m; j++){
            // is the substring equal to seeked string?
            if(str[i+j] == seekedStr[j])
                k++;
            // if substring equals to seeked string then we add starting index to vector
            if(k == m)
                results.push_back(i);
        }
    }

    return results;
}

void show(int i)
{
    cout << i << " ";
}

int main()
{
    string str = "Hello my friends my";
    string seekedStr = "my";
    auto results = simpleSearch(str, seekedStr);

    for_each(results.begin(), results.end(), show);

    return 0;
}
