#include <iostream>
#include <string>
#include <cmath>
#define PRIME 5381
using namespace std;

unsigned long hash(string a){
    unsigned long hash = 5381;
    int c;
    for(int i=0; i<a.length(); i++){
        hash = ((hash << 5) + hash) + a[i];
    }
    return hash;
}

bool is_equivalent(string a, string b){
    unsigned long hash_a = hash(a);
    unsigned long hash_b = hash(b);
    if(hash_a == hash_b)
        return true;
    else if(a.length() > 1 && b.length() > 1){
        string a1 = a.substr(0, a.length()/2);
        string a2 = a.substr(a.length()/2);

        string b1 = b.substr(0, b.length()/2);
        string b2 = b.substr(b.length()/2);

        bool part_1 = is_equivalent(a1, b2);
        bool part_2 = is_equivalent(a2, b1);
        return part_1 && part_2;
    }
    else{
        return false;
    }
}

int main(){
    string a, b;
    cin>>a>>b;
    if(is_equivalent(a, b)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}
