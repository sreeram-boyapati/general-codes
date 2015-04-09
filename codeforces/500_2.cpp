#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
class Node{
    public:
        int data;
        Node(int d){
            this->data = d;
        }
};
int main(){
    int n;
    cin>>n;
    map<int, int> reps;
    vector<int> nums;
    vector<int> order;
    vector<Node> nodes;
    for(int i=0; i<n; i++){
        int a, b;
        if(find(nums.begin(), nums.end(), a) == nums.end()){
            nums.push_back(a);
            reps[a] = a;
        }
        if(find(nums.begin(), nums.end(), b) == nums.end()){
            nums.push_back(b);
            reps[b]= a;
        }
        else{
            reps[b] = a;
        }
    }
    int root;
    map<int, int> reverse_reps;
    
    map<int, int>::iterator it = reps.begin();
    for(; it != reps.end(); it++){
        int first = (*it).first;
        int second = (*it).second;
        if(first == second){
            root = reps[first];
            reps.erase(it);
        }
        reverse_reps[second] = first;
    }
    order.push_back(root);
    int temp;
    while(order.size() != n){
        order.push_back(reverse_reps[root]);
        root = reverse_reps[root];
    }
    for(int i=0; i<order.size(); i++){
        cout<<order[i]<<" ";
    }
    return 0;
}
