#include <iostream>
#include <vector>
using namespace std;

int get_max_path(vector<int> path, int v2, int t, int d){
    int seconds_passed = path.size();
    int seconds_remaining = t - seconds_passed;
    if(seconds_remaining == 0){
        int sum=0;
        for(int i=0; i<t; i++){
            sum+= path[i];
        }
        return sum;
    }
    int last_speed = path[path.size()-1];
    if (last_speed + d < v2){
        path.push_back(last_speed+d);
        return get_max_path(path, v2, t, d);
    }
    else if((last_speed + d - (seconds_remaining -1)*d) <= v2){
        path.push_back(last_speed + d);
        return get_max_path(path, v2, t, d);
    }
    else{
        int increase = v2 + (seconds_remaining - 1)*d - last_speed;
        path.push_back(last_speed + increase);
        return get_max_path(path, v2, t, d);
    }

}

int main(){
    int v1, v2, t, d;
    vector<int> path;
    cin>>v1>>v2>>t>>d;
    path.push_back(v1);
    cout<<get_max_path(path, v2, t, d);
    return 0;
}
