#include <iostream>
#include <vector>
#include <map>
#include <stack>
#define MAP_IT map<int, int>::iterator
#define PAIR_IT pair<int, int>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<int, int> num_map;
    stack<pair<int, int> > dups;
    vector<int> series;
    for(int i=1; i<=n; i++){
        num_map[i] = 0;
    }
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        if(num_map.find(tmp) == num_map.end())
            dups.push(make_pair(i, tmp));
        else if(num_map[tmp] == 0)
            num_map[tmp] = 1;
        else
            dups.push(make_pair(i, tmp));
        series.push_back(tmp);
    }

    MAP_IT map_it = num_map.begin();
    for(; map_it!=num_map.end(); map_it++){
        if((*map_it).second != 0)
            continue;

        PAIR_IT it = dups.top();
        dups.pop();
        int position = it.first;
        int num = (*map_it).first;
        series[position] = num;
        (*map_it).second = 1;
    }

    for(int i=0; i<series.size(); i++){
        cout<<series[i]<<" ";
    }
}
