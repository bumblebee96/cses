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
    string min;

    cin >> str;
    min = str;

    for(int i = 0; i < str.size(); ++i)
    {
        rotate(str.begin(), str.begin() + 1, str.end());

        if(str < min)
            min = str;
    }

    cout << min << "\n";

    return 0;
}

