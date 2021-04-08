#include <bits/stdc++.h>
using namespace std;

// Always take a prime number greater than number of unique characters
// involving in hashing.
const int prime = 31;
const int mod = 1000000007;

// If s = "abcde", then this function will generate hash in the following form.
// hash = (a * p^5) + (b * p^4) + (c * p^3) + (d * p^2) + (e * p^1).
int FindHash(string s) {

    int n = s.size(), hash = 0;

    for(int i = 0; i < n; i++) {

        hash = ((hash + (s[i] - 'a' + 1)) * prime) % mod;
    }

    return hash;
}

// We can also use hashing in different way.
// hash = (a * p^1) + (b * p^2) + (c * p^3) + (d * p^4) + (e * p^5).
int FindHash2(string s) {

    int n = s.size(), hash = 0;

    int powerOfPrime = prime;

    for(int i = 0; i < n; i++) {

        hash = (hash + (s[i] - 'a' + 1) * powerOfPrime) % mod;

        powerOfPrime = powerOfPrime * prime % mod;
    }

    return hash;
}

// We can use both ways of hashing to solve some palindrome based
// problems.


void RabinKarp(string &str, string &pat) {

    int m = str.size(), n = pat.size();

    if(m < n) {

        return;
    }

    int patHash = FindHash(pat);
    int currentHash = FindHash(str.substr(0, n));

    int p = 1;

    for(int i = 1; i <= n; i++) {

        p = (p * prime) % mod;
    }

    for(int i = n - 1; i < m; i++) {

        if(currentHash == patHash) {

            cout << "Pattern found at index " << i - n + 1 << endl;
        }

        if(i == m - 1) {

            break;
        }

        int end = ((str[i - n + 1] - 'a' + 1) * p) % mod;
        int current = (str[i + 1] - 'a' + 1);

        currentHash = ((currentHash + current - end) * prime) % mod;
    }
}

int main() {

    string str, pat;
    cin >> str >> pat;

    RabinKarp(str, pat);

    return 0;
}