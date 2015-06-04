#include <iostream>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

int get_spec(char i){
    if(i == '0')
        return 0;
    if(i == '1')
        return 1;
    if(i == '2')
        return 2;
}


void solve_tree(){
    int leaf_nodes = 0;
    // counting root
    int no_nodes = 1;
    string n;
    cin>>n;
    queue<int> node_stack;
    // 1 stands for root.
    node_stack.push(1);
    for(int i=0; i<n.length(); i++){
        if(node_stack.empty())
            break;
        int node = node_stack.front();
        int specification = get_spec(n[i]);
        node_stack.pop();
        if(specification == 0){
            leaf_nodes++;
        }
        else if(specification == 1){
            node_stack.push(2*node);
            no_nodes++;
        }
        else if(specification == 2){
            node_stack.push(2*node);
            node_stack.push(2*node + 1);
            no_nodes += 2;
        }
    }
    cout<<floor(no_nodes/2)<<" "<<floor(leaf_nodes/2)<<endl;
}


int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        solve_tree();
    }
    return 0;
}
