// 2217 로프(그리디)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100000

bool desc(int a, int b){
    return a > b;
}
int main(int argc, const char * argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    int ropes[MAX];
    int DP[10000];
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> ropes[i];
    }
    sort(ropes, ropes+N, desc);

    for(int i = 0; i < N; i++){
        DP[i+1] = ropes[i] * (i+1);
    }
    sort(DP, DP+N+1, desc);
    cout << DP[0] << endl;
    return 0;
}