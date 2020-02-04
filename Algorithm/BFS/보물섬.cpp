//2589 보물섬(BFS)

#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 51

using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};


int n, m;
int ret, max_num;
char table[MAX][MAX];
int visited[MAX][MAX];
string s;
queue<pair<int, int>> q;

void bfs(int y, int x){
    fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
    visited[y][x] = 1;
    q.push({y, x});
    max_num = 0;
    while(q.size()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || table[ny][nx] == 'W' || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
            if(max_num <= visited[ny][nx]){
                max_num = visited[ny][nx];
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(int j = 0; j < m; j++){
            table[i][j] = s[j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(table[i][j] == 'L'){
                bfs(i, j);
                ret = max(ret, max_num);
            }
        }
    }
    cout << ret -1 << endl;
    
    return 0;
}
