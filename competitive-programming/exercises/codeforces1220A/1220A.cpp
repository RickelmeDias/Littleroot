#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    int z = 0, e = 0, r = 0, o = 0, n = 0, zero = 0, one = 0;
    string text;
    string result;
    cin >> t >> text;

    for (int i = 0; i < t; i++)
    {
        if (text[i] == 'z')
            z++;
        if (text[i] == 'e')
            e++;
        if (text[i] == 'r')
            r++;
        if (text[i] == 'o')
            o++;
        if (text[i] == 'n')
            n++;

        if (z >= 1 && e >= 1 && r >= 1 && o >= 1)
        {
            z -= 1;
            e -= 1;
            r -= 1;
            o -= 1;
            zero++;
        }

        if (o >= 1 && n >= 1 && e >= 1)
        {
            o -= 1;
            n -= 1;
            e -= 1;
            one++;
        }
    }

    while (one > 0)
    {
        cout << 1 << " ";
        one--;
    }
    while (zero > 0)
    {
        cout << 0 << " ";
        zero--;
    }
}