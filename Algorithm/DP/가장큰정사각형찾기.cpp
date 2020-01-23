#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001][1001];
int solution(vector<vector<int>> board)
{
    int answer = 0;
    int rowSize = (int)board.size();
    int colSize = (int)board[0].size();
    
    for(int i = 0; i < rowSize; i++){
        for(int j = 0; j < colSize; j++){
            if(i == 0 || j == 0){
                dp[i][j] = board[i][j];
                answer = answer < dp[i][j] ? dp[i][j] : answer;
                continue;
            }
            if(board[i][j]){
                int tmp = min(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = min(tmp, dp[i-1][j-1]) + 1;
                answer = answer < dp[i][j] ? dp[i][j] : answer;
            }
        }
    }

    answer *= answer;
    return answer;
}