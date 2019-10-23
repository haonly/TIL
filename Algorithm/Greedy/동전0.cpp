// 11047 동전 0(그리디)

#include <iostream>
#include <algorithm>

using namespace std;
int main(int argc, const char * argv[]) {
    int N,K;
    cin >> N >> K;
    int a[N];
    int tmp = K;
    int cnt = 0;
    for(int i = 0; i < N; i++)
        cin >> a[i];
    
    for(int i = N-1; i >= 0; i--){
        if(tmp / a[i] > 0){
            cnt += tmp/a[i];
            tmp = tmp%a[i];
        }
        if(tmp % a[i] == 0)
            break;
    }
    cout << cnt << endl;
    return 0;
}
