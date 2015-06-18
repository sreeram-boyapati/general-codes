#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

map<long long int, long long int> factorials; 
long long int fact(int num){
    long long int mul=1;
    while(num > 0){
        mul = mul*num;
        num--;
    }
    return mul;
}

int get_num_divisors(long long int num){
    int sum = 0;
    long long int temp = num;
    while(temp > 1){
        for(int i=2; i<=temp; i++){
            if(temp%i == 0){
                cout<<temp<<endl;
                sum++;
                temp  = temp/i;                
                i--;
            }
        }
    
    }
    return sum;
}

void solve(){
    int a, b, diff;
    cin>>a>>b;
    long long int mul=1;
    for(int i=b+1; i<=a; i++){
        mul = mul*i;
    }
    cout<<get_num_divisors(mul)<<endl;
}

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        solve();
    }
    return 0;
}
