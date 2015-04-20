#include <iostream>
#include <vector>
#include <map>

using namespace std;
map<int, bool> lookup;
bool is_interesting(int);

bool is_interesting(int num){
    // Is interesting if it has odd divisors.
    int no_divisors=0;
    int i=2;
    if(lookup.find(num) != lookup.end()){
        cout<<"Lookup Found"<<endl;
        return lookup[num];
    }
    while(num > 1 && i < num){
        if(num % i == 0){
            num = num / i;
            bool i_int = is_interesting(i);
            bool num_int = is_interesting(num);
            if(!i_int && num_int){ 
                lookup[num] = true;
                return true;
            }
            else if (!i_int && num_int){
                lookup[num] = true;
                return true;
            }
            else{
                lookup[num] = false;
                return false;
            }
            break;
        }
        else{
            i++;
        }
    }
    if(no_divisors == 0){
        //its prime.
        lookup[num] = false;
        return false;
    }
    else{
        lookup[num] = true;
        return false;
    }
}

int find_interesting_problems(int L, int R){
    int no_of_interesting=0;
    for(int num=L; num<=R; num++){
        if(is_interesting(num)){
            no_of_interesting++;
        }
    }
    return no_of_interesting;
}

int main(){
    int test_cases;
    int l, r;
    vector<int> answers;
    cin>>test_cases;
    lookup[1] = true;
    lookup[2] = false;
    lookup[3] = false;
    for(int i=0; i<test_cases; i++){
        cin>>l>>r;
        answers.push_back(find_interesting_problems(l, r));
    }
    for(int counter=0; counter<answers.size(); counter++){
        cout<<answers[counter]<<endl;
    }
    return 0;
}
