#include <bits/stdc++.h>

using namespace std;

int main()
{   
    vector<int> v = {4, 1, 2, 3, 8};
    int foi_permutado;
    do {
        foi_permutado = prev_permutation(begin(v), end(v)); 
        for (int x:v) cout<<x<<" ";
        cout << endl;
    } while (foi_permutado != 0);
    
    // Resultado final do next_permutation(begin(v), end(v));       => {1, 2, 3, 4, 8}
    // Resultado final do prev_permutation(begin(v), end(v));       => {8, 4, 3, 2, 1}

    return 0;
}