//1890 점프(DP)

#include <iostream>
#define MAX 101
using namespace std;
int N;
int table[MAX][MAX];
long long dp[MAX][MAX];

void travel(){
    dp[1][1] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(table[i][j] > 0 && dp[i][j] > 0){
                int move = table[i][j];
                //move right
                if(j + move <= N)
                    dp[i][j+move] += dp[i][j];
                //move down
                if(i+move <= N)
                    dp[i+move][j] += dp[i][j];
            }
        }
    }
    cout << dp[N][N];
}

int main(int argc, const char * argv[]) {
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> table[i][j];
        }
    }
    
    travel();
    
    return 0;
}
