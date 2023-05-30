#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;      // Cigarettes
    int k;      // Butts Necessary to make a new Cigarette
    int finalN; // Final Cigarette

    while (cin >> n >> k)
    {
        int restButts = n;                // 4 butts (cigarette smoked)
        int newCigaretts = restButts / k; // 1 cigarrete (new)
        finalN = n + newCigaretts;        // 4 cigarette smoked + 1 new cigarette = 5 cigarette

        while (newCigaretts > 0) // while is possible make new cigarette
        {
            restButts = (restButts % k) + newCigaretts; // 1 + 1 = 2
            newCigaretts = restButts / k;               // 2 / 3 = 0
            finalN += newCigaretts;                     // final += 0
        }

        cout << finalN << endl; // 5
    }
}