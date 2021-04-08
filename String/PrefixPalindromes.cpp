#include<bits/stdc++.h>
using namespace std;

vector<int> Z(string str)
{
    int m = str.size();

    string s = str + '$';

    reverse(str.begin(), str.end());

    s += str;

    int n = s.size(), l = 0, r = 0;

    vector<int> z(n, 1);

    for (int i = 1; i < n; i++)
    {
        if (i > r)
        {
            l = r = i;

            while (r < n && s[r - l] == s[r])
            {
                r++;
            }

            z[i] = r - l;
            r--;
        }
        else
        {
            int k = i - l;

            if (z[k] < r - i + 1)
            {
                z[i] = z[k];
            }
            else
            {
                l = i;

                while (r < n and s[r - l] == s[r])
                {
                    r++;
                }

                z[i] = r - l;
                r--;
            }
        }
    }

    for (int i = m + 1; i < n; i++)
    {
        z[i - m - 1] = z[i];
    }

    z.resize(m);

    reverse(z.begin(), z.end());

    return z;
}

int main()
{
    string str = "abacaba";

    vector<int> v = Z(str);

    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}