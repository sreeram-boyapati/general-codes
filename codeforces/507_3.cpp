#include <iostream>
#include <cmath>
#define ROOT 1
using namespace std;
void make_binary_tree(){

}

int main(){
    int h, n;
    cin>>h;
    cin>>n;
    long long int no_nodes = 2*pow(2, h) - 1;
    int tree[no_nodes+1];
    memset(no_nodes, 0, sizeof no_nodes);
    int current_node = ROOT;
    int mode = 1;
    int dest_reached = 0;
    long int no_visited_nodes = 1;
    tree[1] = 1;
    while(!dest_reached){
        if(no_visited_nodes==n){
            dest_reached=true;
            continue;
        }
        if(mode == 1){
            if(!tree[current_node]){
                current_node = 2*current_node;
                no_visited_nodes++;
                tree[current_node]=no_visited_nodes;
            }

        }
        else if(mode == 0){
            current_node = 2*current_node + 1;
        }
        mode = mode^1;;
    }
    return 0;
}
