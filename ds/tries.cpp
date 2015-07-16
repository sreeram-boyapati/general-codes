#include <iostream>
#include <algorithm>

#ifndef TRIE_ESSENTIALS
#define MAX 1000
#define CHARSET 26
#define ROOT 0
#endif

using namespace std;

/* efficient implementation but not needed :P */
class Trie{
    public:
        char key;
        int value;
        Trie *children[26];
        Trie(char key, int value){
            this->key = key;
            this->value = value;
        }
        Trie(char key){
            this->value = 0;
            this->key = key;
        }
        bool is_end(){
            if(value == -1){
                return true;
            }
            return false;
        }
};

/* array based implementation */
int f[MAX][CHARSET];
int sz_trie = 0;

void init(){
}

void insert(string s){
    for(int i=0; i<s.length(); i++){
        int node = ROOT;
        int ch = s[i] - 'a';
        if(f[node][ch] == -1){
            f[node][ch] = sz_trie++;
        }
        node = f[node][ch];
    }
}

int dfs_find(int node){
    int num_words = 1;
    for(int i=0; i<CHARSET; i++){
        if(f[node][i] != -1){
            num_words += dfs_find(f[node][i]);
        }
    }
    return num_words;
}

int find_words(string s){
    int node = ROOT;
    int num_words = 0;
    for(int i=0; i<s.length(); i++){
        int ch = s[i] - 'a';
        if(f[node][ch] == -1){
            //prefix does not exist
            return num_words;
        }
        node = f[node][ch];
    }
    // Now list of all nodes from 'node' are the whole words.
    int root_node = node;
    for(int i=0; i<CHARSET; i++){
        if(f[root_node][i] != -1){
            num_words += dfs_find(f[root_node][i]);
        }
    }
}

int main(){

    int n, m, T;
    cin>>n;
    //Insert few strings
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        insert(s);
    }
    cin>>m;
    for(int i=0; i<m; i++){
        string s;
        cin>>s;
        // Given prefix, find num of whole words.
        int num_words = find_words(s);
    }
    return 0;
}
