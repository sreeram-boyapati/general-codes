#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;
int getMod(int n){
    return n%MOD;
}
int main(){
    vector<int> a;
    int k;
    int n;
    cin>>n;
    cin>>k;
    int aux[n];
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }

    for(int j=0; j<k; j++){
        aux[0] = a[0];
        a[0] = aux[0]; 
        for(int i=1; i<n; i++){
            aux[i] = getMod(aux[i-1] + a[i]);
            a[i] = aux[i];
        }
    }
    
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
