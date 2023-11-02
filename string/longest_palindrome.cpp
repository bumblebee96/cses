#include <algorithm>
#include <iostream>

using namespace std;
typedef unsigned int uint;

bool isPalindrome(const string& str)
{
    return equal(str.begin(), str.end(), str.rbegin());
}

string findLongestStr(const string& str)
{
    int n = str.size();
    string candidate;
    string ans;

    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j <= n; ++j)
        {
            candidate = str.substr(i, j - i);

            if(isPalindrome(candidate))
            {
                if(ans.size() < candidate.size())
                {
                    ans = candidate;
                }
            }
        }
    }

    return ans;
}

int main()
{
    //configure io
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    //efficint io
    ios::sync_with_stdio(0);
    cin.tie(0);

    //code
    string str;
    string longstr;

    cin >> str;

    longstr = findLongestStr(str);


    cout << longstr << "\n";

    return 0;
}

