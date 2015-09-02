#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

map<int, vector<int> > num_map;
vector<int> series;
int n, k;
int max_num=0;
int seqs = 0;
bool exists[200001];

void find_series(int index, int num, int count){
    int next_num = num*k;
    if(count == 3){
        seqs++;
    }
    while(next_num <= max_num){
        if(exists[next_num]){
            vector<int> indexes = num_map[next_num];
            for(int i=0; i<indexes.size(); i++){
                if(indexes[i] > index)
                    find_series(indexes[i], next_num, count+1);
            }
            break;
        }
        else{
            next_num *= k;
        }
    }
}

int main(){
    cin>>n>>k;
    memset(exists, false, sizeof exists);
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        if(!exists[tmp]){
            vector<int> indexes;
            indexes.push_back(i);
            num_map[tmp] = indexes;
            exists[tmp] = true;
        }
        else{
            vector<int> indexes = num_map[tmp];
            indexes.push_back(i);
            num_map[tmp] = indexes;
        }
        if(tmp>max_num)
            max_num = tmp;
        series.push_back(tmp);
    }
    for(int i=0; i<series.size(); i++){
        int num = series[i];
        find_series(i, num, 1);
    }
    cout<<seqs<<endl;
    return 0;
}
