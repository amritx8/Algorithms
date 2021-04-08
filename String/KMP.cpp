#include <bits/stdc++.h>
using namespace std;

void Precompute(string &pat, int lps[]) {

    int n = pat.size();

    // Prefix should not be string itself.
    // In genaral, for each index i(0-based indexing) lps[i] < i + 1.
    lps[0] = 0;

    int i = 1, len = 0;

    while(i < n) {

        if(pat[i] == pat[len]) {

            lps[i] = len + 1;

            len++;
            i++;
        } else if(len > 0) {

            len = lps[len - 1];
        } else {

            lps[i] = 0;
            i++;
        }
    }
}

void KMP(string &str, string &pat) {

    int m = str.size(), n = pat.size(), lps[n];

    Precompute(pat, lps);

    int i = 0, j = 0;

    while(i < m) {

        if(str[i] == pat[j]) {

            i++;
            j++;
        }

        if(j == n) {

            cout << "Pattern found at index " << i - n << endl;

            j = lps[j - 1];
        } else if(i < m and str[i] != pat[j]) {

            if(j > 0) {

                j = lps[j - 1];
            } else {

                i++;
            }
        }
    }
}

int main() {

    string str, pat;
    cin >> str >> pat;

    KMP(str, pat);

    return 0;
}