#include <iostream>
#include <vector>
#include <list>

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
    Node node = Node(0);
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

void dfs(vector<Node>& Graph, int index ,vector<Node>& topolist){

}

int main(){
    vector<Node> Graph;
    make_graph(graph);
    vector<Node> topo_list;
    dfs(Graph, 0, topolist);
    
    return 0;
}
