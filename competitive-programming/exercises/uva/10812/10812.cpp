#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, s, d;
    cin >> t;
    while (t--)
    {
        cin >> s >> d;

        bool isPossible = (((s + d) % 2 == 0) && (s - d >= 0));

        if (!isPossible)
        {
            cout << "impossible" << endl;
            continue;
        }

        int x = (s + d) / 2;
        int y = (s - d) / 2;

        cout << x << " " << y << endl;
    }
}