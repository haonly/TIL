//10833 쉬운 계단 수(DP)

#include <iostream>
#include <vector>
#include <algorithm>

#define DIV 1000000000

using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    vector<vector<int>> d(N, vector<int>(10, 0));
    d[0] = {0, 1, 1 ,1 ,1 ,1 ,1 ,1 ,1 ,1};
    
    for(int i =1; i<N; i++){
        for(int digit = 0; digit<10; digit++){
            if(digit == 0){
                d[i][digit] = d[i-1][1];
            }
            else if(digit == 9){
                d[i][digit] = d[i-1][8];
            }
            else{
                d[i][digit] = (d[i-1][digit-1] + d[i-1][digit+1]) % DIV;
            }
        }
    }
    int sum = 0;
    for(int x : d[N-1]){
        sum = (sum+x) % DIV;
    }
    
    cout << sum << endl;
    return 0;
}
