#include <bits/stdc++.h>
using namespace std;

void Precompute(string &pat, int z[]) {

    int n = pat.size(), l = 0, r = 0;

    for (int i = 1; i < n; i++) {

        if (i > r)  {

            l = r = i;
            
            while (r < n and pat[r - l] == pat[r]) {

                r++;
            }

            z[i] = r - l; 
            r--;
        } else {

            int k = i - l;
            
            if (z[k] < r - i + 1) {

                z[i] = z[k];
            } else {

                l = i;
                
                while (r < n and pat[r - l] == pat[r]) {

                    r++;
                }

                z[i] = r - l; 
                r--;
            }
        }
    }
}

void Z(string &str, string &pat) {

    int m = str.size(), n = pat.size(), z[n];

    Precompute(pat, z);

    int i = 0, j = 0;

    while(i < m) {

        if(str[i] == pat[j]) {

            i++;
            j++;
        }

        if(j == n) {

            cout << "Pattern found at index " << i - n << endl;
        } else if(i < m and str[i] != pat[j]) {

            
        }
    }
}

int main() {

    string str, pat;
    cin >> str >> pat;

    Z(str, pat);

    return 0;
}