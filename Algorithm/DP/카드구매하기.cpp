// 11052 카드구매하기(DP)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p(10001);
int dp[1001];
int main(void){
    
    int n;
    cin >> n;
    // n개 까지의 가격을 입력받는다.
    for(int i=1; i<=n; i++){
        cin >> p[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i] = max(dp[i],dp[i-j]+p[j]);
        }
    }
    cout << dp[n];
    
    return 0;
}
