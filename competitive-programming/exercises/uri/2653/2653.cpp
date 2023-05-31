/*
    Link: https://www.beecrowd.com.br/judge/pt/problems/view/2653
*/

#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    string in;
    set<string> ss;
 
    while(cin >> in)
        ss.insert(in);
    
    cout << ss.size() << endl;
 
    return 0;
}