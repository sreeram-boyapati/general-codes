#include <iostream>
#include <string>
using namespace std;

int main(){
    string n;
    cin>>n;
    int length = n.length();
    int internals = length + 1;
    long long int distinct_pairs = 26*internals;
    distinct_pairs -= length;
    cout<<distinct_pairs;
    return 0;
}
