#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int get_spec(char i){
    if(i == '0')
        return 0;
    if(i == '1')
        return 1;
    if(i == '2')
        return 2;
}

void fill_colors(vector<char>& colors, char color){
    // Acceptable colors to color children.
    if(color != 'g')
        colors.push_back('g');
    if(color != 'b')
        colors.push_back('b');
    if(color != 'r')
        colors.push_back('r');
}

void build_tree(vector<int>& tree, string n){
    /*
     * Construct the tree from array.
     */
    int leaf_nodes = 0;
    // counting root
    int no_nodes = 1;
    queue<int> node_stack;
    tree.push_back(1);
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
            tree.push_back(2*node);
        }
        else if(specification == 2){
            node_stack.push(2*node);
            node_stack.push(2*node + 1);
            tree.push_back(2*node);
            tree.push_back(2*node + 1);
        }
    }
}

int solve_tree(int index, string s, vector<int>& tree, char color){
    char spec = s[index];
    vector<char> colors;
    fill_colors(colors, color);
    if(spec == '0'){
        return color == 'g' ? 0 : 1;
    }
    if(spec == '1'){
        return min(solve_tree(index + 1, s, tree, colors[0]),
                    solve_tree(index + 1, s, tree, colors[1]));
    }
    if(spec == '2'){
        return min(
    }    
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        vector<int> tree;
        build_tree(tree, s);
        int max_greens = min(solve_tree(0, s, tree, 'g'),
                solve_tree(0, s, tree, 'r'), solve_tree(0, s, tree, 'b'));
    }
    return 0;
}
