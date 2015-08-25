<<<<<<< HEAD
#include<iostream>
=======
#include <iostream>
>>>>>>> add few problems
#include <map>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
<<<<<<< HEAD
    int max_value=-1;
    map<int, int> count_num;
    map<int, int> distance;
    map<int, int> lru;
    map<int, int> left;
    map<int, int> right;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(count_num.find(a[i]) != count_num.end()){
            count_num[a[i]] += 1;
            int prev_pos = lru[a[i]];
            distance[a[i]] += i - prev_pos;
            lru[a[i]] = i;
            right[a[i]] = i+1;
        }
        else{
            count_num[a[i]] = 1;
            lru[a[i]] = i;
            distance[a[i]] = 0;
            left[a[i]] = i+1;
            right[a[i]] = i+1;
        }
        if(max_value < count_num[a[i]]){
            max_value = count_num[a[i]];
        }
    }
    long int min_distance=-1;
    int min_left;
    int min_right;
    map<int, int>::iterator it = count_num.begin();
    for(;it!=count_num.end(); it++){
        if(it->second == max_value){
            if(min_distance == -1 || distance[it->first] < min_distance){
                min_left = left[it->first];
                min_right = right[it->first];
                min_distance =distance[it->first];
            }
        }
    }
    cout<<min_left<<" "<<min_right<<endl;
    return 0;
}
