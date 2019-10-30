// 2212 센서(그리디)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100001

bool desc(int a, int b){
    return a > b;
}

int main(int argc, const char * argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, K;
    int sensors[MAX];
    int dist[MAX-1];
    int ans = 0;
    
    cin >> N;
    cin >> K;
    
    for(int i = 0; i < N; i++){
        cin >> sensors[i];
    }
    
    sort(sensors, sensors+N);
    for(int i = 0; i < N-1; i++)
        dist[i] = sensors[i+1] - sensors[i];
    
    sort(dist, dist+N-1, desc);
    
    for(int i = 0; i < N-1; i++){
        if(i < K-1) continue;
        ans += dist[i];
    }
    cout << ans;
    
    return 0;
}
