#include <iostream>
#include <algorithm>

#define MAX 21
using namespace std;

int N;
int ph = 100;
int L[MAX];
int J[MAX];
int dp[101];
void solve(){
    for(int i = 0; i < N; i++){
        for(int j = 100; j > L[i]; j--){
            dp[j] = max(dp[j], dp[j-L[i]] + J[i]);
        }
    }
    cout << dp[100];
}
int main(int argc, const char * argv[]) {
    
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> L[i];
    for(int i = 0; i < N; i++)
        cin >> J[i];
    
    solve();
    return 0;
}