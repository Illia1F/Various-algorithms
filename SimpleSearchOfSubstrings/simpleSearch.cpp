#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// the function implements simple search for substrings
auto simpleSearch(const string& message, const string& pattern)
{
    // the vector which stores starting substrings indexes
    vector<int> results;
    // variables which are the sizes of strings
    int n = message.size(), m = pattern.size();

    // loop is going on to n-m in order to no exit from border
    for(int i=0; i<=n-m; i++){
        for(int j=0, k=0; j<m; j++){
            if(message[i+j] != pattern[j]) break;
            else k++;
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
    string soughtStr = "my";
    auto results = simpleSearch(str, soughtStr);

    for_each(results.begin(), results.end(), show);

    return 0;
}
