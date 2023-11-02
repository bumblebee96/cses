#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef unsigned int uint;

int solve(const string& str, const string& pattern);
int rabin_karp(const string& haystack, const string& needle);

int rabin_karp(const string& haystack, const string& needle)
{
    const int p = 31;
    const int m = 1e9 + 9;
    const int h_size = haystack.size();
    const int n_size = needle.size();
    vector<long long> p_pow(h_size);

    //preprocessing
    //calculate powers of p
    p_pow[0] = 1;
    for(int i = 1; i < h_size; ++i)
    {
        p_pow[i] = (p_pow[i - 1]*p) % m;
    }

    //calculate hash of prefix of haystack
    vector<long long> h_hash(h_size + 1, 0);
    for(int i = 0; i < h_size; ++i)
    {
        h_hash[i + 1] = (h_hash[i] + (haystack[i] - 'a' + 1)*p_pow[i]) % m;
    }

    //calculate hash of needle
    long long n_hash = 0;
    for(int i = 0; i < n_size; ++i)
    {
        n_hash = (n_hash + (needle[i] - 'a' + 1)*p_pow[i]) % m;
    }

    //count occurances
    int count = 0;
    for(int i = 0; i + n_size - 1 < h_size; ++i)
    {
        long long substr_hash = (h_hash[i + n_size] + m - h_hash[i]) % m;

        if(substr_hash == ((n_hash*p_pow[i]) % m))
        {
            count++;
        }
    }

    return count;
}

int solve(const string& str, const string& pattern)
{
    int count = 0;

    for(auto itr = str.begin(); itr != str.end(); ++itr)
    {
        string substr = str.substr(distance(str.begin(), itr), pattern.size());

        if(pattern == substr)
        {
            count++;
        }
    }

    return count;
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
    string pattern;
    int count = 0;

    cin >> str;
    cin >> pattern;

    count = rabin_karp(str, pattern);

    cout << str << "\n";
    cout << pattern << "\n";
    cout << count << "\n";

    return 0;
}

