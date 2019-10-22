// 1449 수리공항승(그리디)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(int argc, const char * argv[]) {
    int N, L;
    int cnt = 1;
    vector<int> water;
    cin >> N >> L;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        water.push_back(tmp);
    }
    sort(water.begin(), water.end());
    
    int tmp = water[0];
    for(int i = 1; i < N; i++){
        if(water[i] - tmp+1>L){
            cnt++;
            tmp = water[i];
        }
    }
    cout << cnt << endl;
    return 0;
}
