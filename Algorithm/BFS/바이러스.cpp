//2606 바이러스(BFS)

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
 
#define MAX 101
 
using namespace std;
 
int n;
int con;
int u, v;
int cnt;
int map[MAX][MAX];
int visit[MAX];

void dfs(int node){
    visit[node] = 1;
    for(int i = 1; i <= n; i++){
        if(!visit[i] && map[node][i] == 1){
            cnt++;
            dfs(i);
        }
    }
}

void bfs(int start){
    visit[start] = 1;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(int i = 1; i <= n; i++){
            if(!visit[i] && map[node][i] == 1){
                q.push(i);
                visit[i] = 1;
                cnt++;
            }
        }
    }
}

int main() {
    cin >> n;
    cin >> con;
    for(int i = 0; i < con; i++){
        cin >> u >> v;
        map[u][v] = map[v][u] = 1;
    }
    bfs(1);
    cout << cnt << endl;
    return 0;
}
