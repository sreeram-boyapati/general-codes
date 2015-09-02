#include <iostream>
#include <vector>
using namespace std;

int find_top_candidate(vector<int>& candidates){
    int MAX = 0;
    for(int i=1; i<candidates.size(); i++)
        if(candidates[MAX] <= candidates[i])
            MAX = i;

    return MAX;
}

int main(){
    int n;
    cin>>n;
    int candies=0;
    vector<int> candidates;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        candidates.push_back(temp);
    }
    while(1){
        int top = find_top_candidate(candidates);
        if(top == 0)
            break;
        candidates[top]--;
        candidates[0]++;
        candies++;
    }
    cout<<candies<<endl;
    return 0;
}
