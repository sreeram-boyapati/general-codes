#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int main(){
    int i, j;
    char *string;
    int dp[2][2];
    memset(dp, -1, sizeof(dp));
    string = (char *)malloc(100005);
    scanf("%s", string);
    for(i=0; i<strlen(string) - 1; i++){
        char sub_string[3];
        sub_string[0] = string[i];
        sub_string[1] = string[i+1];
        sub_string[2] = '\0';
        if(strcmp(sub_string, "AB") == 0){
            if(dp[0][0] == -1){
                dp[0][0] = i;
            }
            dp[0][1] = i;
        }
        if(strcmp(sub_string, "BA") == 0){
            if(dp[1][0] == -1){
                dp[1][0] = i;
            }
            dp[1][1] = i;
        }
    }
    if(dp[0][0] == -1 || dp[1][0] == -1){
        printf("NO");
    }
    else if(dp[0][0]+1 < dp[1][1] || dp[1][0]+1 < dp[0][1]){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}
