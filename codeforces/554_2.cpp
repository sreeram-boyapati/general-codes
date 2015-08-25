#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<string, int>  distinct_rows;
    string max_string;
    int max_count = 0;
    for(int i=0; i<n; i++){
        string tmp;
        cin>>tmp;
        if(distinct_rows.find(tmp) == distinct_rows.end()){
            distinct_rows[tmp] = 1;

        } else{
            distinct_rows[tmp] += 1;
        }
        int count = distinct_rows[tmp];
        if(count > max_count){
            max_string = tmp;
            max_count = count;
        }
    }
    cout<<max_count<<endl;
    return 0;
}
