#include <iostream> // cout
#include <string>
#include <vector>
#include <map>
#include <algorithm>

auto sundaya(const std::string& message, const std::string& pattern)
{
    // a vector which stores the results
    std::vector<int> result;
    // a map, which plays the role as the help table
    std::map<char, int> helpTab;
    // we insert characters with its indexes from a pattern in the help table
    for(int i=pattern.size()-1; i>=0; --i)
        helpTab.insert(std::make_pair(pattern[i], i));

    // variable stores sizes of strings into which loops is going
    size_t into_pattern = pattern.size();
    size_t into_message = message.size() - into_pattern + 1;
    for(size_t i = 0; i < into_message; ++i){
        for(size_t j = 0; j<into_pattern; ++j){
            // check whether fit an element or not
            if(message[i+j] == pattern[j]){
                // check whether we have gone the whole pattern or not
                if(j == into_pattern - 1)
                // insert a result to the result vector
                    result.push_back(i);
            }
            else
            {
                // if we are about to exit from a scope
                if(i+into_pattern == message.size()) break;

                // find a next element and check if it is in the pattern
                auto t = helpTab.find(message.at(i+into_pattern));

                if(t != helpTab.end())
                    // if a next element is in the pattern
                    i += into_pattern - t->second - 1;
                // and an opposite option
                else i += into_pattern;

                break;
            }
        }
    }
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
    auto result = sundaya(text, pattern);

    // show
    std::for_each(result.begin(), result.end(), show);

    return 0;
}

