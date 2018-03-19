#include <iostream> // cout
#include <string>
#include <vector>
#include <algorithm>

auto sunday(const std::string& message, const std::string& pattern)
// a function implements a sunday algorithm
{
    size_t size_pattern = pattern.size();
    size_t size_message = message.size();
    // a table of result
    std::vector<int> result;
    // an offset table
    unsigned char* offsetTable = new unsigned char[256];
    // initialize the table of result
    for(size_t i=0; i<256; i++)
        offsetTable[i] = size_pattern + 1;

    for(size_t i=0; i<size_pattern; i++)
        offsetTable[static_cast<unsigned char>(pattern[i])] = size_pattern - i;

    // search the matches
    for(size_t i = 0; i <= size_message - size_pattern; i+=offsetTable[static_cast<unsigned char>(message[i + size_pattern])]){
        
        size_t j;
        for(j = 0; j < size_pattern && message[i+j] == pattern[j]; ++j);

        // if we found the match 
        if(j == size_pattern)
            // insert a start index of this match int the result
            result.push_back(i);
    }

    // free up memory
    delete[] offsetTable;

    return result;

}

void show(int i)
{
    std::cout << i << std::endl;
}

int main()
{
    std::string text = "abcabbdcabcababcdaca";
    std::string pattern = "aba";
    // the result vector which stores indexes of starts of a pattern in the text
    auto result = sunday(text, pattern);

    // show
    std::for_each(result.begin(), result.end(), show);

    return 0;
}

