/*
    O set<T> é um conjunto
    onde não é possível colocar
    valores repetidos e retorna
    em ordem de prioridade (begin-end)

    Entrada: Joao, Rick, Joao, Joao, Gabi
    Saída: Gabi, Joao, Rick 

    ~ Remove("Joao")

    Saída: Gabi, Rick

    Inserção: log(n)
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Com unordered_map remove o lower e upper bound e melhora a inserção (sem ordenação mais rapido)
    /*unordered_*/set<string> ss;
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

    // Remover valor
    ss.erase("Joao");

    for (auto sbg : ss) {
        cout << sbg << endl;
    }
    
    // Retorna 0, nao existe "Oi"
    cout << ss.count("Oi") << endl;
    // Retonar 1, existe "Gabi" (é case sensitive)
    cout << ss.count("Gabi") << endl;


    // Find retorna a busca pelo elemento e retorna iteradorador apontando para o elemento encontrado
    // Se o iterador for igual ao end(), significa que não encontrou.
    auto it = ss.find("Joao");
    if (it == ss.end()) cout << "Não existe";
    else cout << "Existe";
    
    /* 
     set s = {1,2,3,4,5,6,7}
        Primeiro elemento maior que...
     it = s.upper_bound(5); // --> 6
        Primeiro elemento maior or igual que..
     it = s.lower_bound(4); // --> 4
    */
    
    return 0;
}