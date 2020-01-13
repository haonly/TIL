//12865 평범한 배낭(DP)

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int N, K;
int items[101][2];
int d[100001];

void knapsack(){
    for(int i = 1; i <= N; i++){
        for(int j = K; j >= 1; j--){
            if(items[i][0] <= j){
                d[j] = max(d[j], d[j-items[i][0]] + items[i][1]);
            }
        }
    }
}

int main(int argc, const char * argv[]) {

    cin >> N >> K;
    
    for(int i = 1; i <= N; i++)
        cin >> items[i][0] >> items[i][1];
    knapsack();
    
    cout << d[K];
    
    return 0;
}
