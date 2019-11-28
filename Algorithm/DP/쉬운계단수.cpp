#include <iostream>
#include <vector>
#include <algorithm>

#define DIV 1000000000

using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    int dp[101][10]= {}; //100자리까지 있고 마지막 자리는 0~9
    long long sum = 0;
    
    //1의 자리수는 1~9까지로 하나씩 있음
    for(int i = 0; i < 10; i++)
        dp[1][i] = 1;
    
    for(int i = 2; i <= N; i++){
        for(int j = 0; j < 10; j++){
            if(j == 0)
                dp[i][0] = dp[i-1][1];
            else if(j == 9)
                dp[i][9] = dp[i-1][8];
            else
                dp[i][j] = (dp[i-1][j+1] + dp[i-1][j-1]) % DIV;
        }
    }
    for(int i = 1; i < 10; i++)
        sum = (sum + dp[N][i]);
    cout << sum % DIV << endl;
    return 0;
}
