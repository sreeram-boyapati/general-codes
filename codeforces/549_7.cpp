#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;
int n;
int line[200000];

void new_swap(int k, int j){
    int prev_k = line[k];
    int prev_j = line[j];
    int tmp = line[k] - 1;
    int tmp2 = line[j] + 1;
    line[j] = tmp;
    line[k] = tmp2;
    if(line[j] == prev_j && line[k] == prev_k){
        cout<<":("<<endl;
        exit(0);
    }


}

void dvc_merge(int low, int mid, int high){
    int k;
    for(int i=mid; i>=low; i--){
        k=i;
        for(int j=i+1; j<=high; j++){
            if(line[k] > line[j]){
                new_swap(k, j);
                k=j;
            }
            else{
                break;
            }
        }
    }
}

void dvc_sort(int low, int high){

    if(low >= high)
        return;
    int mid = (low + high)/2;
    dvc_sort(low, mid);
    dvc_sort(mid+1, high);
    dvc_merge(low, mid, high);
}

int main(){
    cin>>n;
    memset(line, 0, sizeof line);
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        line[i] = tmp;
    }
    dvc_sort(0, n-1);
    for(int i=0; i<n; i++){
        cout<<line[i]<<" ";
    }
    return 0;
}
