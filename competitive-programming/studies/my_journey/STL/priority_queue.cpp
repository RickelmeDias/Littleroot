/*
    priority_queue

    Removendo os dados em ordem lexicográfica maior ou menor (apenas mudar greater para less e terá o evento contrário de saída)

    Entrada: Rickelme, Ana, Julia, Jefferson

    Saída (com greater): Ana, Jefferson, Julia, Rickelme
    Saída (com less): Rickelme, Julia, Jefferson, Ana

    A priority_queue também funcionará para números
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<string, vector<string>, greater<string>> pq;
    pq.push("Rickelme");
    pq.push("Ana");
    pq.push("Julia");
    pq.push("Jefferson");
    
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    
    return 0;
}