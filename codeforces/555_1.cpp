#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    int no_groups = k;
    int ops = 0;
    for(int i=0; i<k; i++){
        int m;
        cin>>m;
        int a[m];
        bool one_dismantled=false;
        bool dismantle = true;
        int diff = m;
        for(int j=0; j<m; j++){
            cin>>a[j];
            if(a[j] == 1){
                dismantle=false;
            }
            if(j==0)
                continue;
            if(!dismantle){
                if(a[j] - a[j-1] > 1 || one_dismantled){
                    no_groups += 1;
                    ops += 1;
                    one_dismantled = true;
                }

            }
        }
        if(dismantle){
            no_groups += m - 1;
            ops += m - 1;
        }
    }
    cout<<ops+no_groups-1<<endl;
    return 0;
}
