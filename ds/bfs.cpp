#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
        vector<Node> children;
        int index;
        int data;
        Node(int data){
            this->data = data;
        }
        void add_neighbor(Node neighbor){
            children.push_back(neighbor);
        }
};

//Sample Graph
/*
 * 0 1 1 0
 * 1 0 1 0
 * 1 1 0 1
 * 0 0 1 0
 *
 */

void make_graph(vector<Node>& graph){
    Node node = Node(1);
    node.add_neighbor(Node(2));
    node.add_neighbor(Node(3));
    graph.push_back(node);
    node = Node(2);
    node.add_neighbor(Node(1));
    node.add_neighbor(Node(3));
    graph.push_back(node);
    node = Node(3);
    node.add_neighbor(Node(1));
    node.add_neighbor(Node(2));
    node.add_neighbor(Node(4));
    graph.push_back(node);
    node = Node(4);
    node.add_neighbor(Node(3));
     
    
}

int main(){
    vector<Node> graph;
    make_graph(graph);
    cout<<"Hello World"<<endl;
    return 0;
}
