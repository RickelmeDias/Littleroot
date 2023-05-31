/*
    O map<T, T> é um conjunto
    de chave e valor.

    Se voce adicionar dois valores
    para a mesma chave ele irá sobrescever
    o primeiro valor.

    Apesar de ser possivel acessar
    o valor por colchetes, é importante
    tentar evitar, pois se você tentar 
    acessar um valor que não existe, exemplo

    mss["cachorro"]

    ele irá retornar uma string vazia, mas
    irá armazenar na memoria isso, fazendo com
    que o size() do seu map seja maior que o esperado.

*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Com unordered_map remove o lower e upper bound e melhora a inserção (sem ordenação mais rapido)
    /*unordered_*/map<string, string> mss;
    mss["joao"] = "menino";
    mss["maria"] = "menina";
    mss["pedro"] = "menino";

    auto it = mss.find("maria");

    // Se ele encontrar pode mostrar
    if (it != mss.end())
        cout << (*it).first << " " << (*it).second << " " << endl;    // Chave (first) | Valor (second)
    
    /* 
    Ele também tem essa busca, mas ele testa 
    pela chave (>, >=).
     
        Primeiro elemento maior que...
     it = s.upper_bound(5); // --> 6
        Primeiro elemento maior or igual que..
     it = s.lower_bound(4); // --> 4
    */
    
    return 0;
}