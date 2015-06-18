#include <iostream>
#include <cmath>
using namespace std;
int convert_to_int(char a){
    return a - '0';
}
int main(){
    int n;
    string a, b;
    cin>>n>>a>>b;
    long int sum=0;
    for(int i=0; i<n ; i++){
        int a1 = convert_to_int(a[i]);
        int b1 = convert_to_int(b[i]);
        if(a1 > b1){
            int t1 = abs(a1 -b1);
            int t2 = abs(a1 - 10 - b1);
            sum += t1 > t2 ? t2 : t1;
        }
        else if(a1 < b1){
            int t1 = abs(b1 - a1);
            int t2 = abs(b1 - 10 - a1);
            sum += t1 > t2 ? t2 : t1; 
        }
    }
    cout<<sum<<endl;
    return 0;
}
