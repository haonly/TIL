//1012 유기농배추(BFS)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int test;
int m,n,bechu;
int jirung = 0;

int map[55][55];

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

void reset(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            map[i][j] = 0;
        }
    }
}
void input(){
    cin >> n >> m >> bechu;
    for(int i = 0; i< bechu; i++){
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
    }
}


void solve(int x, int y){
    map[x][y] = 0;
    for(int i = 0 ; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < m && map[nx][ny]){
            solve(nx,ny);
        }
    }
}

int main(int argc, const char * argv[]) {
    cin >> test;
    for(int i = 0; i < test; i++){
        reset();
        jirung = 0;
        input();
        for(int j = 0; j <n; j++){
            for(int k = 0; k < m; k++){
                if(map[j][k] == 1){
                    jirung++;
                    solve(j,k);
                }
            }
        }
        cout << jirung << endl;
    }
}

