#include <iostream>

using namespace std;

const int DIV = 10007;

//https://www.acmicpc.net/problem/11726
int main() {
  int n=0;
  int dp[1001]={0,};

  scanf("%d", &n);

  dp[0]=1;
  dp[1]=1;

  for(int i=2;i<=n; i++){
    dp[i] = (dp[i-1] + dp[i-2]) % DIV;
  }

  printf("%d", dp[n]);

}