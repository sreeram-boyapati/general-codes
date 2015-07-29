#include <iostream>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    long long int k=9;
    long long int j=1;
    long long int sum = 0;
    while(n>0){
        if(n > k){
            n = n - k;
            sum += k*j;
        }
        else{
            sum += n*j;
            break;
        }
        k = k*10;
        j++;
    }
    cout<<sum<<endl;
    return 0;
}
