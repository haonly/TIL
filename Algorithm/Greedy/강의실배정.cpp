// 11000 강의실배정(그리디)

#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
 
using namespace std;
typedef pair<int, int> intpair;

int main() {
    int N;
    cin >> N;
    intpair * v = new intpair[N+1];
    
    for(int i = 0; i < N; i++)
        cin >> v[i].first >> v[i].second;
    sort(v, v+N+1);
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(v[0].second);
    int start, end;
    for(int i = 1; i <= N; i++){
        start = v[i].first;
        end = v[i].second;
        if(pq.top() > start)
            pq.push(end);
        else{
            pq.pop();
            pq.push(end);
        }
    }
    cout << pq.size() << endl;
    return 0;
}