#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
int main(){
    int n, k, p, x, y;
    cin>>n>>k>>p>>x>>y;
    int a[n], sum=0;
    for(int i=0; i<k; i++){
        int tmp;
        cin>>tmp;
        sum+=tmp;
        a[i] = tmp;
    }
    int median = (n+1)/2;
    int difference = ceil((x - sum)/(n-k));
    int sum_diff = x - sum;
    if(median < k && a[median] < y){
        cout<<-1;
        return 0;
    }
    if(difference == 0 || p < y){
        cout<<-1;
        return 0;
    }
    int max_value = min(difference , p);
    for(int i=k; i<n; i++){
        if(i == median){
            a[i] = max(max_value, y);
            sum_diff -= a[i];
        }
        else{
            a[i] = min(p, sum_diff/(n-i));
        }
        cout<<a[i]<<" ";
    }
    return 0;
}
