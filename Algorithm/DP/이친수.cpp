#include <iostream>

using namespace std;

const int DIV = 10007;

int main() {

    int N;
    long long dp[91] = {0};
    cin >> N;
    dp[1] = 1;
    dp[2] = 1;
    
    for(int i = 3; i <= N; i++){
        dp[i] = (dp[i-1] + dp[i-2]);
    }
    cout << dp[N] << endl;
}
