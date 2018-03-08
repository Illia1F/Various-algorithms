#include <iostream>
#include <string>
#include <vector>
using namespace std;

auto KMP(const string& S, const string& pattern)
{
	vector<int> pf (pattern.length());

	pf[0] = 0;
	for (int k = 0, i = 1; i < pattern.length(); ++i)
	{
		while (k > 0 && pattern[i] != pattern[k])
			k = pf[k-1];

		if (pattern[i] == pattern[k])
			k++;

		pf[i] = k;
	}

	for (int k = 0, i = 0; i < S.length(); ++i)
	{
		while (k > 0 && pattern[k] != S[i])
			k = pf[k-1];

		if (pattern[k] == S[i])
			k++;

		if (k == pattern.length())
			return (i - pattern.length() + 1);
	}

	return string::npos;
}

int main()
{
    string s = "hello my friends!";
    string Sstr = "my";
    auto od = KMP(s, Sstr);

    for(auto i = od; i<Sstr.size() + od; i++)
        cout << s[i];

    cout << endl;

    return 0;
}
