/*
    O multiset<T> é quase mesma
    coisa que o set<T>, porém ele
    permite a inserção de valores
    iguais (duplicados)

    Entrada: Joao, Rick, Joao, Joao, Gabi
    Saída: Gabi, Joao, Joao, Joao, Rick 

    ~ Remove("Joao")

    Saída: Gabi, Rick

    Inserção: log(n)
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    multiset<string> ss;
    ss.insert("Joao");
    ss.insert("Rick");
    ss.insert("Joao");
    ss.insert("Joao");
    ss.insert("Gabi");
    
    auto itsbg = ss.begin();
    while(itsbg != ss.end()) {
        cout << *(itsbg) << endl;    
        itsbg++;
    }

    return 0;
}