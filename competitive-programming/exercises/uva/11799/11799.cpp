#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, vel, velMax = 0;
    cin >> t;
    for(int i=1; i <= t; i++)
    {
        cin >> n;
        while(n--) {
            cin >> vel;
            velMax = max(vel, velMax);
        }
        cout << "Case " << i << ": " << velMax << endl;
        velMax=0;
    }
}