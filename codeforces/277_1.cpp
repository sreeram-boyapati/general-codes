#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> reps;

bool find_rep(int n){
    return reps[n];
}
map<int, int> ranks;
map<int, int> emp;
int main(){
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        reps[i] = i;
        ranks[i] = 1;
    }
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        vector<int> list;
        for(int j=0; j<temp; j++){
            int tmp2;
            cin>>tmp2;
            list.push_back(tmp2);
        }
        int rep = list[0];
        for(int j=1; j<list.size(); j++){
            if(ranks[find_rep(list[j])] > ranks[rep]){
                reps[rep] = list[j];
                ranks[rep] = 0;
                emp[i] = list[j];
            }
            else{
                reps[list[j]] = rep;
                ranks[list[j]] = 0;
                emp[i] = rep;
            }
        } 
    }
    vector<int> different_groups;
    map<int, int>::iterator it = ranks.begin();
    for(; it!=ranks.end(); it++){
        if((*it).second != 0){
            different_groups.append((*it).second);

        }
    }
    
    return 0;
} 
