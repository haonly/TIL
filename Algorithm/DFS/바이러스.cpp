//2606 바이러스(DFS)

#include <iostream>
#include <algorithm>
#include <vector>
 
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

int main() {
    cin >> n;
    cin >> con;
    for(int i = 0; i < con; i++){
        cin >> u >> v;
        map[u][v] = map[v][u] = 1;
    }
    dfs(1);
    cout << cnt << endl;
    return 0;
}
