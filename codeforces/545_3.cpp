#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    vector<int> x;
    vector<int> h;
    cin>>n;
    for(int i=0; i<n; i++){
        int tmp1, tmp2;
        cin>>tmp1>>tmp2;
        x.push_back(tmp1);
        h.push_back(tmp2);
    }
    int answer;
    answer = n < 2 ? n : 2;
    for(int i=1; i<n-1; i++){
        if(x[i]-x[i-1]>h[i]){
            answer++;
        }
        else if(x[i+1]-x[i]>h[i]){
            answer++;
            x[i] += h[i];
        }
    }
    cout<<answer<<endl;

    return 0;
}
