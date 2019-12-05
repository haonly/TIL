//1495 기타리스트(DP)

#include <iostream>
#include <vector>
#include <cstring>

#define MAX_SONG 101
#define MAX_VOL 1001

using namespace std;

int main(int argc, const char * argv[]) {
    int N, S, M;
    int play[MAX_SONG];
    int dp[MAX_SONG][MAX_VOL];
    
    cin >> N >> S >> M;
    
    
    for(int i = 0; i < N; i++)
        cin >> play[i];
    
    memset(&dp, 0, sizeof(dp));
    dp[0][S] = 1;
    
    for(int i = 1; i <= N; i++){
        for(int v = 0; v <= M; v++){
            if(dp[i-1][v] == 1){
                int tmpAdd = v+play[i-1];
                int tmpSub = v-play[i-1];
                
                if(tmpAdd <= M)
                    dp[i][tmpAdd] = 1;
                if(tmpSub >= 0)
                    dp[i][tmpSub] = 1;
            }
        }
    }
    int ans = -1;
    for(int i = 0; i <= M; i++){
        if(dp[N][i] == 1)
            ans = max(ans, i);
    }
    cout << ans;
    
    return 0;
}
