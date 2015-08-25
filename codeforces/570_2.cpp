#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    if(abs(n-m) > abs(m-1)){
        cout<<m+1<<endl;
    }
    else if(abs(n-m) < abs(m-1)){
        cout<<m-1<<endl;
    }
    else if(abs(n-m) == abs(m-1)){

        cout<<max(1, m-1)<<endl;
    }
    return 0;
}
