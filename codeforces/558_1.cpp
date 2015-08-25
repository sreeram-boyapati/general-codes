#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
bool pos_cmp(int a, int b){
    return a < b ? true: false;
}
bool neg_cmp(int a, int b){
    return a > b ? true: false;
}

int main(){
    int n;
    int neg_plane = 0;
    int pos_plane = 0;
    vector<int> neg;
    vector<int> pos;
    cin>>n;
    map<int, int> plane;
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        if(a < 0){
            neg_plane += b;
            neg.push_back(a);
        }
        else{
            pos_plane += b;
            pos.push_back(a);
        }
        plane[a] = b;
    }
    sort(pos.begin(), pos.end(), pos_cmp);
    sort(neg.begin(), neg.end(), neg_cmp);
    int min_size = min(pos.size(), neg.size());
    int pos_range = min_size < pos.size() ? min_size + 1 : min_size;
    int neg_range = min_size < neg.size() ? min_size + 1 : min_size;
    long long int sum = 0;
    for(int i=0; i<pos_range; i++){
        sum += plane[pos[i]];
    }
    for(int i=0; i<neg_range; i++){
        sum += plane[neg[i]];
    }
    cout<<sum<<endl;

    return 0;
}
