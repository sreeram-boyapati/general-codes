#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
using namespace std;

#ifndef Node
class Node{
    public:
        int x;
        int y;
        Node(int x, int y){
            this->x = x;
            this->y = y;
        }
        Node(){}
        bool operator==(const Node& node){
            if(this->x == node.x && this->y == node.y)
                return true;
            return false;
        }
        bool operator!=(const Node& node){
            if(this->x != node.x || this->y != node.y){
                return true;
            }
            return false;
        }
        bool is_valid(const Node& node){
            bool valid = true;
            if(this->y > (node.y - 1) || this->y < 0)
                valid = false;
            if(this->x > (node.x -1) || this->x < 0)
                valid = false;
            return valid;
        }
        void print(){
            cout<<"Node Print: "<<this->x<<" "<<this->y<<endl;
        }

};
#endif
Node source, dest, limit;
void get_siblings(Node, stack<Node>&);
void build_tree(int, int);
void all_paths(Node, int);

char grid[200][200];
int graph[200][200];
char vis[200][200];
int min_cost = -1;

int main(){
    int T;
    cin>>T;
    for(int i=0; i<T; i++){
        int M, N;
        cin>>M>>N;
        memset(vis, 0, sizeof(vis));
        build_tree(M, N);
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        source = Node(x1, y1);
        dest = Node(x2, y2);
        limit = Node(M, N);
        if(source == dest){
            cout<<0;
        }
        else{
            all_paths(source, 0);
            cout<<min_cost<<endl;
        }
    }
    return 0;
}


void build_tree(int M, int N){
    for(int j=0; j<M; j++){
        for(int k=0; k<N; k++){
            char ch;
            cin>>ch;
            grid[j][k] = ch;
        }
    }
    for(int j=0; j<M; j++){
        for(int k=0; k<N; k++){
            int node;
            cin>>node;
            graph[j][k] = node;
        }
    }
}

void all_paths(Node present, int global_time){
    if(vis[present.x][present.y])
        return;
    if(present == dest){
        // waiting time is zero for dest and source
        if(min_cost == -1 || min_cost > global_time){
            min_cost = global_time;
        }
        return;
    }
    int diff_time = 0;

    if(graph[present.x][present.y] > global_time)
        global_time = graph[present.x][present.y];  
    // can be replaced with a global variable 
    // but does not consume a lot of memory as activation record expires
    // after execution.
    stack<Node> siblings;
    vis[present.x][present.y] = 'V';
    get_siblings(present, siblings);
    
    int cost_min = -1;
    while(!siblings.empty()){
        Node sibling = siblings.top();
        siblings.pop();
        if(min_cost != -1 && min_cost < global_time)
            //Pruning the recursions
            continue;
        all_paths(sibling,  global_time + 1);
    }


    // If it does not reach destination
    if(min_cost == -1){
        min_cost = 0;
    }
    return;
}

void get_siblings(Node node, stack<Node>& siblings){
    int x=node.x, y=node.y;
    Node* sibling = new Node(x+1, y);
    if(sibling->is_valid(limit)){
        siblings.push(Node(x+1, y));
    }
    sibling = new Node(x-1, y);
    if(sibling->is_valid(limit)){
        siblings.push(Node(x-1, y));
    }
    sibling = new Node(x, y-1);
    if(sibling->is_valid(limit)){
        siblings.push(Node(x, y-1));
    }
    sibling = new Node(x, y+1);
    if(sibling->is_valid(limit)){
        siblings.push(Node(x, y+1));
    }
    delete(sibling);
}
