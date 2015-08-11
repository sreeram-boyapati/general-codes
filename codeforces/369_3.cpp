#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

int main(){
    long int n;
    cin>>n;
    vector<int> tree[n], w1[n];
    memset(tree, 0, sizeof tree);
    for(int i=0; i<n-1; i++){
        int a, b, t;
        cin>>a>>b>>t;
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
        w1[a-1].push_back(t);
        w1[b-1].push_back(t);
    }
    int root = 0;
    int nodes = n;
    int depth[n];
    memset(depth, 0 , sizeof depth);
    stack<int> adj;
    adj.push(root);
    int marked[n];
    memset(marked, 0 , sizeof marked);
    while(!adj.empty()){
        int node = adj.top();
        adj.pop();
        for(int i=0; i<tree[node].size(); i++){
            int to = tree[node][i];
            if(node == to)
                continue;
            if(w1[node][i] == 1){
                if(!marked[to]){
                    adj.push(to);
                    depth[to] = depth[node];
                    depth[node] = 0;
                }
            }
            else if(w1[node][i] == 2){
                if(!marked[to]){
                    adj.push(to);
                    depth[to] = depth[node] + 1;
                    depth[node] = 0;
                }
            }
        }
        marked[node]  = 1; 
    }
    vector<int> answers;
    for(int i=0; i<n; i++){
        if(depth[i] != 0){
            answers.push_back(i);
        }
    }
    cout<<answers.size()<<endl;
    for(int i=0; i<answers.size(); i++){
        cout<<answers[i]+1<<" ";
    }
    return 0;
}
