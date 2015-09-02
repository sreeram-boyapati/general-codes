#include <iostream>
#include <cstring>
#include <map>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    int recognition[n];
    memset(recognition, 0, sizeof recognition);
    int soldiers[n][n];
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        soldiers[a][b] = 1;
        recognition[a]++;
    }
    return 0;

}
