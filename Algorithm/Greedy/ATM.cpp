// 11399 ATM(Greedy)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(int a, int b){
    return a> b;
}

int main(int argc, const char * argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    
    int q[N];
    vector<int> hap;
    int sum = 0;
    for(int i =0 ; i < N; i++){
        cin >> q[i];
    }
    sort(q, q+N);
    
    hap.push_back(q[0]);
    for(int i =1 ; i < N; i++){
        hap.push_back(hap[i-1] + q[i]);
    }
    for(int i = 0; i < hap.size(); i++)
        sum += hap[i];
    
    cout << sum;
    return 0;
}
