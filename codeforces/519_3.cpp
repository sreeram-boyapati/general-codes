#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    int teams=0;
    while(n!=0 && m!=0){
        if(n<=1 && m<=1){
            break;
        }
        if(n > m){
            n-=2;
            m-=1;
            teams++;
        }
        else if(m >= n){
            n-=1;
            m-=2;
            teams++;
        }
    }
    cout<<teams;
    return 0;
}
