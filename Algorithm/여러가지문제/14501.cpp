#include <iostream>
#include <algorithm>

using namespace std;

int t[16], p[16], n, ans;

void sol(int day, int total){
    if(day == n){
        ans = max(ans, total);
        return;
    }
    sol(day + 1, total);
    if(day + t[day] < n)
        sol(day + t[day], total + p[day]);
}

int main(int argc, const char * argv[]) {
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t[i];
        cin >> p[i];
    }
    sol(0, 0);
    cout << ans << endl;
    return 0;
}
