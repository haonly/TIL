//1149 RGB거리(DP)

#include <iostream>

using namespace std;

int N;
int dp[1001][3];
int MIN(int a, int b){
    return a < b ? a : b;
}
int main(int argc, const char * argv[]) {
    
    cin >> N;
    for(int i = 1 ; i <= N; i++){
        int red, green, blue;
        cin >> red >> green >> blue;
        dp[i][0] = MIN(dp[i-1][1], dp[i-1][2])+red;
        dp[i][1] = MIN(dp[i-1][0], dp[i-1][2]) + green;
        dp[i][2] = MIN(dp[i-1][0], dp[i-1][1]) + blue;
    }
    cout << MIN(dp[N][0], MIN(dp[N][1], dp[N][2])) << endl;
    
    return 0;
}
