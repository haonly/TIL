//2667 단지번호붙이기(DFS)

#include <iostream>
#include <algorithm>
#include <vector>
 
#define MAX 26
 
using namespace std;
 
char map[MAX][MAX] = { 0, };
int visit[MAX][MAX] = { 0, };
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int N, cnt = 0;
 
void dfs(int i, int j) {
    visit[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int x = i + dir[k][0];
        int y = j + dir[k][1];
        if (0 <= x && x < N && 0 <= y && y < N) {
            if (map[x][y] == '1' && !visit[x][y]) {
                cnt++;
                dfs(x, y);
            }
        }
    }
}
 
int main() {
    int sectionNum = 0;
    vector<int> arrSize;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == '1' && !visit[i][j]) {
                sectionNum++;
                cnt = 1;
                dfs(i, j);
                arrSize.push_back(cnt);
            }
        }
    }
    sort(arrSize.begin(), arrSize.end());
 
    cout << sectionNum << endl;
 
    for (int i = 0; i < arrSize.size(); i++) {
        cout << arrSize[i] << endl;
    }
}
