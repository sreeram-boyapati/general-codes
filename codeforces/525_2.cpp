#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
    return (a>b);
}

string swap_string(string s, int index){
    string left_part = s.substr(0, index);
    string right_part = s.substr(s.size()-index, s.size());
    for(int i=0; i<index; i++){
        s[i] = right_part[i];
    }
    for(int i=s.size()-1; i>s.size() - index; i--){
        s[i] = left_part[i];
    }
    return s;
}

int main(){
    string s;
    int m;
    cin>>s;
    cin>>m;
    vector<int> a;
    for(int i=0; i<m; i++){
        int tmp;
        cin>>tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end(), cmp);
    vector<int>::iterator it = a.begin();
    cout<<"asdasd";
    while(it != a.end() && !a.empty()){
        if ((it+1) != a.end()){
            if(*it == *(it+1)){
                *it = -1;
                *(it+1) = -1;
                it = it + 2;
            }
            else{
                it++;
            }
        }
        else{
            it++;
        }

    }
    vector<int> b;
    for(int i=0; i<a.size(); i++){
        if(a[i] == -1){
            continue;
        }
        else{
            b.push_back(a[i]);
        }
    }

    for(int i=0; i<b.size();){
        if(i+1 != b.size()){
            int difference = b[i+1] -b[i];
            int swap_index = difference;
            s = swap_string(s, swap_index);
            i = i+2;
        }
        else if(i+1 == b.size()){
            reverse(s.begin()+b[i], s.end()- b[i]+1);
            i++;
        }
    }
    cout<<s;
    return 0;
}
