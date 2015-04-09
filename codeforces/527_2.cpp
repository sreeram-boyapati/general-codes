#include <iostream>
#include <map>
#include <string.h>
using namespace std;

void get_minimum_hamming(string t, string s, int i, int j){
    char temp = t[i];
    t[i] = t[j];
    t[j] = temp;
    cout<<i<<" "<<j;
}

int main(){
    int n;
    string t;
    string s;
    cin>>n>>t>>s;
    int k = 0;
    int counter = 0;
    char a[n], b[n];
    int index[n];
    int hamming_distance = 0;
    map<int, int> chars;
    for(int i=0; i<n; i++){
        if(t[i] != s[i]){
            a[k] = t[i];
            b[k] = s[i];
            index[k] = i;
            k++;
            hamming_distance++;
        }
    }

    // Check if tuple is an anagram.
    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            if(a[i] == b[j] && b[i] == a[j]){
                cout<<hamming_distance - 2<<endl;
                cout<<index[i]+1<<" "<<index[j]+1;
                return 0;
            }
            else if(a[i] == b[j] || b[i] == a[j]){
                if(counter == 0){
                    chars.insert(make_pair(index[i]+1, index[j]+1));
                    counter++;
                }
            }
        }
    }

    for(map<int, int>::iterator it=chars.begin(); it != chars.end(); it++){
        int a = (*it).first;
        int b = (*it).second;
        cout<<hamming_distance-1<<endl;
        cout<<a<<" "<<b<<endl;
        return 0;
    }
    cout<<hamming_distance<<endl;
    cout<<"-1  -1";
    return 0;
}
