#include <iostream>
#include <cstring>
using namespace std;

long long int gcd(long long int a, long long int b){
    if(a<b)
        return gcd(b, a);
    if(b==0)
        return a;
    return gcd(b, a%b);
}

bool only_divisible_by_2_and_3(long int num){
    while(num > 1)
        if(num%2 == 0)
            num /= 2;
        else if(num%3 == 0)
            num /= 3;
        else
            return false;
    return true;
}

int main(){
    int n;
    cin>>n;
    long int a[n];
    memset(a, 0, sizeof a);
    bool jackpot = true;
    for(int i=0; i<n; i++){
        long int temp;
        cin>>temp;
        a[i] = temp;
    }
    int mega_gcd = gcd(a[0], a[1]);
    for(int i=2; i<n; i++){
        mega_gcd = gcd(mega_gcd, a[i]);
    }

    for(int i=0; i<n; i++){
        int divisor = a[i]/mega_gcd;
        if(!only_divisible_by_2_and_3(divisor)){
            jackpot = false;
            break;
        }
    }

    if(jackpot)
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}
