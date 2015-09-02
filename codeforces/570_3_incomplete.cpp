#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int calculate_f(string str){
    stack<char> chars;
    int ops = 0;
    for(int i=0; i<str.length(); i++){
        chars.push(str[i]);
    }
    while(!chars.empty()){
        char top = chars.top();
        if(top == '.'){
            chars.pop();
            if(chars.empty())
                return ops;
            char pen_top = chars.top();
            chars.pop();
            if(pen_top == '.'){
                ops++;
                chars.push('.');
            }
        }
        else
            chars.pop();
    }
    return ops;
}

int main(){
    int n, m;
    string str;
    vector<int> strings;
    cin>>n>>m>>str;
    for(int i=0; i<m; i++){
        int a;
        char b;
        cin>>a>>b;
        str[a-1] = b;
        strings.push_back(calculate_f(str));
    }
    for(int i=0; i<strings.size(); i++)
        cout<<strings[i]<<endl;
    return 0;
}
