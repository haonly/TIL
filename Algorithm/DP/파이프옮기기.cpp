#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX =16;

typedef struct{
    int y, x;
} Dir;

Dir moveDir[3] = {{0,1}, {1,0}, {1,1}};
int n;
int result;
int table[MAX][MAX];

void sol(int y, int x, int pipe){
    if(y == n-1 && x == n-1){
        result++;
        return;
    }
    for(int i = 0; i < 3; i++){
        if((i==0 && pipe == 1) || (i == 1 && pipe == 0)){
            continue;
        }
        int nextY = y + moveDir[i].y;
        int nextX = x + moveDir[i].x;
        if(nextY >= n || nextX >= n || table[nextY][nextX] == 1)
            continue;
        if(i == 2 && (table[y][x+1] == 1 || table[y+1][x] == 1))
            continue;
        sol(nextY, nextX, i);
    }
   
}

int main(int argc, const char * argv[]) {
    cin >>n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cin >> table[i][j];
    }
    sol(0, 1, 0);
    cout << result << endl;
    return 0;
}
