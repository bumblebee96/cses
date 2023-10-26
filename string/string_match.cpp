#include <iostream>
#include <string>

using namespace std;
typedef unsigned int uint;

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
    string pattern;
    int count = 0;

    cin >> str;
    cin >> pattern;

    for(auto itr = str.begin(); itr != str.end(); ++itr)
    {
        string substr = str.substr(distance(str.begin(), itr), pattern.size());

        if(pattern == substr)
        {
            count++;
        }
    }

    cout << str << "\n";
    cout << pattern << "\n";
    cout << count << "\n";

    return 0;
}

