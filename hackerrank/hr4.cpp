#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

bool cmp(int a, int b){
    return a > b ? false : true;
}

int main(){
    int N;
    cin>>N;
    int salaries[N];
    int maximum = 0;
    vector<int> distinct;
    memset(salaries, 0, sizeof salaries);
    for(int i=0; i<N; i++){
        int temp;
        cin>>temp;
        if(temp > maximum)
            maximum = temp;
        if(salaries[temp] == 0)
            distinct.push_back(temp);
        salaries[temp]++;
    }
    sort(distinct.begin(), distinct.end(), cmp);
    int Q;
    cin>>Q;
    for(int i=0; i<Q; i++){
        int temp;
        cin>>temp;
        int sum=0;
        for(int j=0; j<distinct.size(); j++){
            if(distinct[j] >= temp)
                break;
            sum += distinct[j];
        }
        cout<<sum<<endl;
    }
    return 0;
}
