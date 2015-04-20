#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#ifndef None
#define None 0
#endif
using namespace std;

class Node{
    public:
        int data;
        vector<Node> children;
        Node(int d){
            data=d;
        }
        void add_children(Node neighbor){
            children.push_back(neighbor);
        }
        friend bool operator==(const Node &n1, const Node &n2);
};


bool operator==(const Node &n1, const Node &n2){
    return n1.data == n2.data;
}
/*
 * 0 1 1 0
 * 1 0 1 0
 * 1 1 0 0
 * 1 1 1 0
 */

void make_graph(vector<Node>& graph){
    Node node = Node(1);
    node.add_children(Node(2));
    node.add_children(Node(3));
    graph.push_back(node);
    node = Node(2);
    node.add_children(Node(1));
    node.add_children(Node(3));
    graph.push_back(node);
    node = Node(3);
    node.add_children(Node(1));
    node.add_children(Node(2));
    graph.push_back(node);
    node = Node(4);
    node.add_children(Node(1));
    node.add_children(Node(2));
    node.add_children(Node(3));
    graph.push_back(node);
}

int bfs(vector<Node>& graph, int index){
    vector<Node>::iterator it = find(graph.begin(), graph.end(), index); 
    Node source_node =  it != graph.end() ? (*it) : None;
    if(source_node == None){
        return 0;
    }
    queue<Node> nodes;
    nodes.push(source_node);
    bool blacks[graph.size()];
    while(!nodes.empty()){
        Node ref_node = nodes.front();
        cout<<ref_node.data<<endl;
        blacks[ref_node.data] = true;
        nodes.pop();
        vector<Node>::iterator g_it = find(graph.begin(), graph.end(), ref_node);
        vector<Node> children = (*g_it).children;
        vector<Node>::iterator it = children.begin();
        while(it != children.end()){
            if(blacks[(*it).data]==false){
                nodes.push((Node)(*it));
            }
            it++;
        }
    }
}

void display_graph(vector<Node>& graph){
    vector<Node>::iterator it = graph.begin();
    while(it != graph.end()){
        Node node =  (*it);
        vector<Node> node_neighbors = node.children;
        for(int i=0; i<node_neighbors.size(); i++){
            Node child = node_neighbors[i];
            cout<<"Node:"<<child.data<<" ";
        }
        cout<<endl;
        it++;
    }
}
int main(){
    int n;
    cin>>n;
    vector<Node> Graph;
    make_graph(Graph);
    //bfs and choose source of your choice.
    bfs(Graph, n);
}
