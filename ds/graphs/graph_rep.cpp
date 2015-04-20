#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Node{
    public:
        list<Node> nodes;
        int index;
        int data;
        Node(int data){
            this->data = data;
        }
        Node(){
        }
        void add_node(Node n){
            nodes.push_back(n);
        }
        list<Node> get_neighbors(){
            return nodes;
        }
};

/* Sample graph
 * 0 1 0 1
 * 0 1 0 1
 * 0 0 1 0
 * 1 1 0 0
 */

void make_graph(vector<Node>* graph){
    Node n = Node(0);
    n.add_node(Node(2));
    n.add_node(Node(4));
    graph->push_back(n);
    n = Node(1);
    n.add_node(Node(2));
    n.add_node(Node(4));
    graph->push_back(n);
    n = Node(2);
    n.add_node(Node(3));
    graph->push_back(n);
    n = Node(3);
    n.add_node(Node(1));
    n.add_node(Node(2));
    graph->push_back(Node(2));

}

void display_graph(vector<Node> graph){
    for(int i=0; i<graph.size(); i++){
        cout<<"Graph i: "<<graph[i].data<<endl;
        list<Node> nodes = graph[i].get_neighbors();
        list<Node>::iterator it = nodes.begin();
        for(;it!=nodes.end(); ++it){
            cout<<"Nodes: "<<(*it).data<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int V;
    vector<Node> graph;
    make_graph(&graph);
    display_graph(graph);
    return 0;
}
