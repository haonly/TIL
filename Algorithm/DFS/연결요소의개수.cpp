//11724 연결요소의개수(DFS)

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
 
#define MAX 1001
 
using namespace std;
 
int N, M;
int u, v;
int cnt;
vector<int> map[MAX];
int visit[MAX];

void dfs(int node){
    visit[node] = 1;
    for(int i = 0; i < map[node].size(); i++){
        int next = map[node][i];
        if(!visit[next])
            dfs(next);
    }
}


int main() {
    cin >> N;
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        map[u].push_back(v);
        map[v].push_back(u);
    }
    for(int i = 1; i <= N; i++){
        if(!visit[i]){
            dfs(i);
            cnt++;
        }
    }
    
    cout << cnt << endl;
    return 0;
}
