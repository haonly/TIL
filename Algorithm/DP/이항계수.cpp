//11051 이항계수2(DP)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1001
#define MOD 10007

int N, K;
int ans = 0;
int cache[MAX][MAX];

int sol(){
    for(int i = 1; i <= N; i++){
        cache[i][1] = i;
        cache[i][i] = cache[i][0] = 1;
    }
    for(int i = 3; i <= N; i++)
        for(int j = 2; j < i; j++)
            cache[i][j] = (cache[i-1][j-1] + cache[i-1][j]) % MOD;
    return cache[N][K] % MOD;
}

int main(int argc, const char * argv[]) {
    
   
    cin >> N >> K;
    
    ans = sol();
    cout << ans << endl;
    
    return 0;
}