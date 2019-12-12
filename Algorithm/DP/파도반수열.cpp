//9561 파도반수열(dp)

#include <iostream>

using namespace std;

long long dp[101];
int N;
int test;
int main(int argc, const char * argv[]) {
    cin >> N;
    
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    
    for(int i = 0; i <N; i++){
        cin >> test;
        for(int j = 6; j <= test; j++)
            dp[j] = dp[j-1] + dp[j-5];
        cout << dp[test] << endl;
    }
    return 0;
}
