#include<bits/stdc++.h>

using namespace std;

class Website {
  public:
    int relevance;
    string url;
};

int main()
{
    int t;
    Website website;
    queue<Website> qwebsites;
    
    int maxRelevance;
    
    cin >> t;
    
    for(int i=1; i <= t; i++)
    {
        maxRelevance = 0;
        
        for (int j=0; j<10; j++) {
            cin >> website.url >> website.relevance;
            maxRelevance = max(maxRelevance, website.relevance);
            qwebsites.push(website);
        }
        
        cout << "Case #" << i << ":" << endl;

        for (int i=0; i<10; i++) {
            if (qwebsites.front().relevance == maxRelevance)
                cout << qwebsites.front().url << endl;
            qwebsites.pop();
        }
    }

}