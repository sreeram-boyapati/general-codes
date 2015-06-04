#include <iostream>
#include <queue>

using namespace std;

int n;
int no_max = 0;
int player_max = 0;
queue<int> a;
queue<int> b;

void read_input(){ 
    int no_a;
    cin>>no_a;
    for(int i=0; i<no_a; i++){
        int temp;
        cin>>temp;
        if(no_max < temp){
            no_max = temp;
            player_max = 1;
        }
        a.push(temp);
    }
    
    int no_b;
    cin>>no_b;
    for(int i=0; i<no_b; i++){
        int temp;
        cin>>temp;
        if(no_max < temp){
            no_max = temp;
            player_max = 2;
        }
        b.push(temp);
    }
}

void solve(){
    int iterations = 0;
    while(!a.empty() && !b.empty()){
        int val_a = a.front();
        int val_b = b.front();
        a.pop();
        b.pop();
        if(val_a > val_b){
            a.push(val_b);
            a.push(val_a);
        }
        else if(val_b > val_a){
            b.push(val_a);
            b.push(val_b);
        }
        iterations++;
    }
    cout<<iterations<<" "<<player_max;
}

int main(){
    cin>>n;
    read_input();
    solve();
    return 0;
}
