//10833 쉬운 계단 수(DP)

#include <iostream>
#include <vector>
#include <algorithm>

#define DIV 1000000000

using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    int dp[101][10]= {};
    int sum = 0;
    
    for(int i = 0; i < 10; i++)
        dp[1][i] = 1;
    for(int i = 2; i <= N; i++){
        for(int j = 0; j < 10; j++){
            if(j == 0)
                dp[i][0] = dp[i-1][1] % DIV;
            else if(j == 9)
                dp[i][9] = dp[i-1][8] % DIV;
            else
                dp[i][j] = (dp[i-1][j+1] + dp[i-1][j-1]) % DIV;
        }
    }
    for(int i = 1; i < 10; i++)
        sum = (sum + dp[N][i]) % DIV;
    cout << sum % DIV << endl;
    return 0;
}
