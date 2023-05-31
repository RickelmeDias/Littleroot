#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[] = {4,3,2,1,5};
    sort(a, a+5);

    for (int i=0; i<5;i ++) cout << a[i] << " ";
    cout << endl;
    

    vector<char> v = { 'J', 'X', 'A', 'C', 'E'};

    // Ordenar em ordem crescente
    sort(v.begin(), v.end());
    for (auto c: v) cout << c << " ";
    cout << endl;

    // Ordenar em ordem decrescente
    sort(v.rbegin(), v.rend());
    for (auto c: v) cout << c << " ";
    cout << endl;

    // Encontra o 3 ou maior que ele se nao tiver.
    vector<int> vi = {1, 3, 15, 19};
    auto it = lower_bound(begin(vi), end(vi), 3);
    cout << *(it) << endl;

    // Excluir o 3 e 15
    vi.erase(vi.begin()+1, vi.begin()+3);
    for (auto i: vi) cout << i << " ";
    cout << endl;
    // Removendo repetições
    vector<int> u = {1, 4, 1, 5, 6};
    sort(begin(u), end(u));

    // Isso não faz ficar unico ainda
    auto itx = unique(begin(u), end(u));
    for (int x: u) cout << x; // 1 4 5 6 6
    cout << endl;
    u.erase(itx, u.end()) ;   
    for (int x: u) cout << x; // 1 4 5 6
    cout << endl;

    return 0;
}