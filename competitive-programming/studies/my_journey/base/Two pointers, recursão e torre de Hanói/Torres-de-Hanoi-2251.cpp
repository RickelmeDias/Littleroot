/*
    Nome: Torres de Hanói
    Nível: Fácil
    Link: https://www.beecrowd.com.br/judge/pt/problems/view/2251
*/

#include <bits/stdc++.h>

#define ____ ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

#define hanoi(n) int(pow(2,(n))-1)

int main() { ____
    int n; int i=1;
    
    while(1) {
        cin >> n;
        if (n==0) break;
        printf("Teste %d\n%d\n\n",i,hanoi(n));    
        i++;
    }

    return 0;
}