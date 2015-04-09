#include <iostream>
#include <map>
#include <vector>
#include <stdlib.h>
#include <memory.h>
using namespace std;

int main(){
    int n, m, q;
    cin>>n>>m;
    int lookup[m+1][n+1]; 
    bool colors[m+1];
    memset(lookup, 0, sizeof(lookup));
    for(int i=0; i<=m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(!colors[c]){
            colors[c] = true;
        }
        lookup[c][a]  = 1;
        lookup[c][b]  = 1;
    }
    cin>>q;
    int answers[q];
    memset(answers, 0, sizeof(answers));
    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;
        int ans=0;
        for(int j=1; j<=m; j++){
            if(!colors[j]){
                continue;
            }
            int u=0;
            for(int k=1; k<=n; k++){
                if(lookup[j][k] == 1){
                    u++;
                }
                if(u==2){
                    ans++;
                    break;
                }
            }
        }
        answers[i] = ans;
    }
    for(int i=0; i<q; i++)
        cout<<answers[i]<<endl;
    return 0;
}
