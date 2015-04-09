#include <iostream>
#include <math.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    int ans[n];
    for(int i=0; i<n; i++){
        int a, b, c;
        cin>>a>>b>>c;
        int num1, num2;
        if(a >= b){
            num1 = a;
            num2 = b;
        }
        else{
            num1=b;
            num2=a;
        }
        if(c >= num1){
            num2 = num1;
            num1 = c;
        }
        else{
            if(num2 <= c){
                num2=c;
            }
        }
        int num3 = 2*num2+1;
        if(num1 <= num2){
            ans[i] = num2 + num1;
        }
        else{
            ans[i] = 2*num2 + 1;
        }
    }

    for(int i=0; i<n; i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
