#include <iostream>

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

    cin >> str;

    for(auto itr = str.begin(); itr != str.end(); ++itr)
    {
        string prefix = str.substr(0, distance(str.begin(), itr));

        if(prefix.size() != str.size() && prefix.size() != 0)
        {
            if(equal(str.begin() + (str.size() - prefix.size()), str.end(), prefix.begin()))
            {
                cout << prefix.size() << endl;
            }
        }
    }

    return 0;
}

