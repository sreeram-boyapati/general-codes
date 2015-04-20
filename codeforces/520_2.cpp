#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long long int n, m, diff;
    int ans = 0;
    cin>>n;
    cin>>m;
    if(n < m){
        int temp = n;
        n = m;
        m = temp;
        // n = 100, m = 99
        if(n % 2 != 0){
            n += 1;
            ans += 1;
        }
        int a = 0;
        while( n != m && n > 0){
            if(n % 2 == 0 && n > m){
                n /= 2;
                ans += 1;
            }
            else{
                n += 1;
                ans += 1;
            }
        }

    }
    else{
        diff = abs(m - n);
        ans = diff;
    }
    cout<<ans;
    return 0;
}
