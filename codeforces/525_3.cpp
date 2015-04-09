#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
bool cmp(int a, int b){
    return (a>b);
}
int main(){
    int n;
    vector<long long int> nums;
    cin>>n;
    for(int i=0; i<n; i++){
        long long int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    sort(nums.begin(), nums.end(), cmp);
    vector<long long int> sides;
    for(int i=0; i<nums.size()-1; i++){
        if(nums[i] == nums[i+1]){
            sides.push_back(nums[i]);
            nums[i]=-1;
            nums[i+1]=-1;
            i++;
        }
        else if(nums[i]-nums[i+1] == 1){
            sides.push_back(nums[i+1]);
            nums[i] = -1;
            nums[i+1] = -1;
            i++;
        }
    }
    if(sides.size()<2){
        cout<<0<<endl;
    }
    else{
        long long int ans = 0;
        for(int i=0; i<sides.size()-1; i=i+2){
            ans += sides[i]*sides[i+1];
        }
        cout<<ans<<endl;
    }
    return 0;
}
