#include <bits/stdc++.h>

using namespace std;

int main()
{
    tuple<int, int, string, double> tp(1,2, "teste", 4.321);

    // Print "teste"
    cout << get<2>(tp) << endl;

    return 0;
}