//9251 LCS(DP)

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char s1[1001], s2[1001];
int dp[1001][1001], i, j;
int main(int argc, const char * argv[]) {
    cin >> s1 >> s2;
    for(i = 1; i <= strlen(s1); i++){
        for(j = 1; j <= strlen(s2); j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[strlen(s1)][strlen(s2)] << endl;
    
    return 0;
}
