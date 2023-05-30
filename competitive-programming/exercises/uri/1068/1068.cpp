#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    string lineString;
    
    while(cin >> lineString) {
        stack<char> stk;
        
        for (int i=0; i < lineString.length(); i++) {
            if (lineString[i] == '(')
                stk.push('(');
            if (lineString[i] == ')') {
                if (stk.empty()) {
                    stk.push(')');
                }else{
                    if (stk.top() == '(') {
                        stk.pop();
                    }
                }
            }
        }
        
        if (stk.empty()) {
            cout << "correct" << endl;
        }else{
            cout << "incorrect" << endl;
        }
    }
    
    return 0;
}