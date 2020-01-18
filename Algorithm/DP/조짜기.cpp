//2229 조짜기(DP)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 987654321;

int n, input[1000];
int result;
int cache[1000];
int maxDifference(int idx){
    if(idx == n)
        return 0;
    int & result = cache[idx];
    if(result != -1)
        return result;
    
    result = 0;
    int low = INF, high = -1;
    for(int i = idx; i < n; i++){
        low = min(low, input[i]);
        high = max(high, input[i]);
        
        result = max(result, (high - low)+maxDifference(i+1));
    }
    return result;
}
int main(int argc, const char * argv[]) {
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> input[i];
    
    memset(cache, -1, sizeof(cache));
    cout << maxDifference(0);
    return 0;
}
