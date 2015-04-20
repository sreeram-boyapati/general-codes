#include <iostream>
#include <memory.h>
#define MOD 1000000007
using namespace std;
int main(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    int occurences[4];
    memset(occurences, 0, sizeof(occurences));
    int max_sim_chars = 0;
    int num_max_sum_chars = 0;
    long long int answer=1;
    for(int i=0; i<s.size(); i++){
        switch(s[i]){
            case 'A':
                occurences[0]++;
                break;
            case 'C':
                occurences[1]++;
                break;
            case 'G':
                occurences[2]++;
                break;
            case 'T':
                occurences[3]++;
                break;
        }
    }
    for(int i=0; i<4; i++){
        if(occurences[i] > max_sim_chars){
            max_sim_chars = occurences[i];
            num_max_sum_chars = 1;
        }
        else if(max_sim_chars == occurences[i])
            num_max_sum_chars++;
    }
    for(int i=0; i<n; i++){
        answer = answer*num_max_sum_chars % MOD;
    }
    cout<<answer;

}
