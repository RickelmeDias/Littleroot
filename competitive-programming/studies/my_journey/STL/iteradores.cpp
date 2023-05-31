/*
    Os iteradores são pointeiros
    para as estruturas STL

    Apontam para:

    begin: primeiro elemento
    end: elemento na frente do ultimo

    Por isso para pegar o ultimo elemento 
    deve usar *(it_end-1);
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v = {2,5,7,9};
    auto it_end = v.end();
    auto it_begin = v.begin();
    
    cout << *it_end << endl;
    cout << *(it_end-1) << endl;
    
    cout << *it_begin << endl;
    cout << *(it_begin+1) << endl;
    
    return 0;
}