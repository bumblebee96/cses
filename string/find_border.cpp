#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef unsigned int uint;

void solve(const string& str);
void solve_using_hashing(const string& str);

void solve(const string& str)
{
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
}

void solve_using_hashing(const string& str)
{
    const int p = 31;
    const int m = 1e9 + 9;
    const int s_size = str.size();
    vector<long long> p_pow(s_size);

    //preprocessing
    //calculate powers of p
    p_pow[0] = 1;
    for(int i = 1; i < s_size; ++i)
    {
        p_pow[i] = (p_pow[i - 1]*p) % m;
    }

    //calculate hash of prefix str
    vector<long long> s_hash(s_size + 1, 0);
    for(int i = 0; i < s_size; ++i)
    {
        s_hash[i + 1] = (s_hash[i] + (str[i] - 'a' + 1)*p_pow[i]) % m;
    }

    //find borders
    long long pre_hash;
    long long suf_hash;
    for(int i = 0; i < s_size - 1; ++i)
    {
        pre_hash = s_hash[i + 1];
        suf_hash = (s_hash[s_size] + m - s_hash[s_size - (i + 1)]) % m;

        if((pre_hash*p_pow[s_size - (i + 1)]) % m == suf_hash)
            cout << i + 1 << endl;

        /*
        cout << "pre_hash: " << (pre_hash*p_pow[s_size - (i + 1)]) % m << endl;
        cout << "suf_hash: " << suf_hash << endl;
        */
    }
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

    cin >> str;

    solve_using_hashing(str);

    return 0;
}

