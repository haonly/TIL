#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX = 1000;
const int INF = 987654321;

int n, input[MAX];
int result;
int cache[MAX];
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
