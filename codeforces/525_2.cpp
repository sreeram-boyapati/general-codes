#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
    return (a<b);
}
struct swap_index{
    int l;
    int u;
};
typedef struct swap_index swi;
string swap_strings(string s, swi lsw){
    for(int i=lsw.l; i<lsw.u; i++){
        int lower_index=i-1;
        int upper_index = s.size()-i;
        if( i != s.size() - i + 1){
            char temp = s[lower_index];
            s[lower_index] = s[upper_index];
            s[upper_index] = temp;
        }
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
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end(), cmp);
    for(int i=0; i<a.size(); i++){
        if(i != a.size()-1){
            if(a[i] == a[i+1]){
                a[i]=-1;
                a[i+1]=-1;
            }
        }
    }
    vector<int> b;
    for(int i=0; i<a.size(); i++){
        if(a[i] != -1){
            b.push_back(a[i]);
        }
    }
    for(int i=0; i<b.size(); i++){
        if(i!=b.size()-1){
            struct swap_index lsw;
            lsw.l = b[i];
            lsw.u = b[i+1];
            s = swap_strings(s, lsw);
            i++;
        }
        else{
            int index = b[i] - 1;
            int u_index = s.size() - index;
            reverse(s.begin()+index, s.begin()+u_index);
        }
    }
    cout<<s;
    return 0;
}
