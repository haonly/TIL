#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX 200+1

using namespace std;

int N, Max;
int arr[MAX];
int dp[MAX];

int main(int argc, const char * argv[]) {
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> arr[i];
    
    for(int i = 1; i <= N; i++){
        dp[i] = 1;
        for(int j = 1; j <= i; j++){
            if(arr[j] < arr[i] && dp[i] < dp[j]+1)
                dp[i] = dp[j]+1;
        }
        if(Max < dp[i])
            Max = dp[i];
    }
    cout << N - Max << endl;
    
    return 0;
}