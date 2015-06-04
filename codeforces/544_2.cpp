#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n, k;
    cin>>n>>k;
    if(k > (ceil(n*n/2) + floor((n*n)/2)){
        cout<<"NO"<<endl;
        return 0;
    }
    int x = 1;
    cout<<"YES"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(k!=0 && x^1){
                cout<<"L";
                k--;
            }
            else{
                cout<<"S";
            }
            x = x^1;
        }
        if(n%2==0){
            x = x^1;
        }
        cout<<endl;
    }

    return 0;
}
