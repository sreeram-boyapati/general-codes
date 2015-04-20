#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#define NULL 0
using namespace std;

#ifndef RECT
class RECT{
    public:
        int x1, x2, y1, y2;
        RECT* child1;
        RECT* child2;
        RECT(){}
        RECT(int x1, int y1, int x2, int y2){
            this->x1=x1;
            this->y1=y1;
            this->x2=x2;
            this->y2=y2;
            child1 = NULL;
            child2 = NULL;
        }
        int get_area(){
            int length = abs(x2 - x1);
            int breadth = abs(y2 - y1);
            return length*breadth;
        }
        bool has_children(){
            if(this->child1 == NULL && this->child2 == NULL)
                return false;
            return true;
        }
        void display_cord(){
            cout<<"Lower Left Edge: "<<x1<<" "<<y1<<endl;
            cout<<"Upper Right Edge: "<<x2<<" "<<y2<<endl;
            cout<<"Area: "<<get_area()<<endl;
            cout<<endl;
        }
        ~RECT(){
            delete(child1);
            delete(child2);
        }
        friend bool operator> (RECT& a, RECT& b);
};
#endif


void split_tree(RECT** node, char D, int d){
    int upper_y = (*node)->y2;
    int lower_y = (*node)->y1;
    int left_x = (*node)->x1;
    int right_x = (*node)->x2;
    RECT *child1;
    RECT *child2;
    if(D == 'H'){
        child1 = new RECT(left_x, lower_y, right_x, d);
        child2 = new RECT(left_x, d, right_x, upper_y);
    }
    else if(D == 'V'){
        child1 = new RECT(left_x, lower_y, d, upper_y);
        child2 = new RECT(d, lower_y, right_x, upper_y);
    }
    (*node)->child1 = child1;
    (*node)->child2 = child2;
}

bool is_split(RECT **node, char D, int d){
    int upper_y = (*node)->y2;
    int lower_y = (*node)->y1;
    int left_x = (*node)->x1;
    int right_x = (*node)->x2;
    if(D=='H'){
        if(d > lower_y && d < upper_y)
            return true;
    }
    else if(D=='V'){
        if(d > left_x && d < right_x)
            return true;
    }
    return false;
}


bool operator>(RECT& a, RECT& b){
    return (a.get_area() > b.get_area());
}

int divide_rect(RECT** root, char dir, int dist){
    if((*root) == NULL){
        return 0;
    }
    //check if children exist;
    if(!(*root)->has_children()){
        if(is_split(root, dir, dist)){
            split_tree(root, dir, dist);
        }
    }
    else{
        if(is_split(root, dir, dist)){
            divide_rect(&((*root)->child1), dir, dist);
            divide_rect(&((*root)->child2), dir, dist);
        }
    }
    return 0;
}

int traverse_rect(RECT** root){
    if((*root) == NULL){
        return 0;
    }
    if(!(*root)->has_children()){
        return (*root)->get_area();
    }
    else{
        return max(traverse_rect(&((*root)->child1)),
                traverse_rect(&((*root)->child2)));
    }
} 

RECT *root;
int main(){
    int x, y, n;
    cin>>x>>y>>n;
    vector<int> answers;
    root = new RECT(0, 0, x,  y);
    for(int i=0; i<n; i++){
        char D;
        int dist;
        cin>>D>>dist;
        divide_rect(&root, D, dist);
        answers.push_back(traverse_rect(&root));
    }
    for(unsigned int i=0; i<answers.size(); i++)
        cout<<answers[i]<<endl;
    delete(root);
    return 0;
}
