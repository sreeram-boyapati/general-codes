#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int A[100][100];
    memset(A, 0, sizeof A);
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        x1 = x1-1;
        x2 = x2-1;
        y1 = y1-1;
        y2 = y2-1;
        for(int i=x1; i<=x2; i++){
            for(int j=y1; j<=y2; j++){
                A[i][j] += 1;
            }
        }
    }
    long long int sum = 0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            sum += A[i][j];
        }
    }
    cout<<sum<<endl;
    return 0;
}
