//
//  main.cpp
//  1126_algorithm
//
//  Created by Hayeon Kim on 2019/11/26.
//  Copyright © 2019 Hayeon Kim. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
struct POSI{
    int y, x;
};
int map[51][51];
int tmpMap[51][51];
int R, C, T;
int dy[4] ={0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int topAir[4][2] = {{0, +1}, {-1, 0}, {0, -1}, {+1, 0}};
int botAir[4][2] = {{0, +1}, {+1, 0}, {0, -1}, {-1, 0}};

void spread(int y, int x){
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= R || nx < 0 || nx >= C)
            continue;
        if(map[ny][nx] < 0)
            continue;
        tmpMap[y][x] -= map[y][x]/5;
        tmpMap[ny][nx] += map[y][x]/5;
    }
}
void clearTop(int startY, int startX){
    queue<int> tmp;
    POSI cur, next;
    cur.y = startY;
    cur.x = startX+1;
    int i = 0;
    
    tmp.push(0);
    while(!(cur.y == startY && cur.x == startX)){
        next.y = cur.y + topAir[i][0];
        next.x = cur.x + topAir[i][1];
        if(next.x >= C || next.y < 0 || next.x < 0 || next.y > startY){
            i++;
            continue;
        }
        tmp.push(map[cur.y][cur.x]);
        cur = next;
    }
    cur.y = startY;
    cur.x = startX+1;
    i = 0;
    while(!(cur.y == startY && cur.x == startX)){
        next.y = cur.y + topAir[i][0];
        next.x = cur.x + topAir[i][1];
        if(next.x >= C || next.y < 0 || next.x < 0||next.y > startY){
            i++;
            continue;
        }
        map[cur.y][cur.x] = tmp.front();
        tmp.pop();
        cur = next;
    }
}

void clearBottom(int startY, int startX){
    queue<int> tmp;
    POSI cur, next;
    cur.y = startY;
    cur.x = startX+1;
    int i = 0;
    tmp.push(0);
    
    while(!(cur.y == startY && cur.x == startX)){
        next.y = cur.y + botAir[i][0];
        next.x = cur.x + botAir[i][1];
        if(next.x >= C || next.y >= R || next.x < 0|| next.y < startY){
            i++;
            continue;
        }
        tmp.push(map[cur.y][cur.x]);
        cur = next;
    }
    cur.y = startY;
    cur.x = startX+1;
    i = 0;
    while(!(cur.y == startY && cur.x == startX)){
        next.y = cur.y+botAir[i][0];
        next.x = cur.x + botAir[i][1];
        if(next.x >= C || next.y>=R || next.x < 0 || next.y < startY){
            i++;
            continue;
        }
        map[cur.y][cur.x] = tmp.front();
        tmp.pop();
        cur = next;
    }
}

int main(int argc, const char * argv[]) {

    cin >> R >> C >> T;
    bool check = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> map[i][j];
            if(map[i][j] == -1){
                if(check == 0) check = 1;
                else map[i][j] = -2;
            }
        }
    }
    while(T--){
        for(int y = 0; y < R; y++){
            for(int x = 0; x < C; x++){
                if(map[y][x] > 0) // 먼지가 존재한다면
                    spread(y,x);
            }
        }
        for(int y = 0; y < R; y++){
            for(int x = 0; x < C; x++){
                map[y][x] += tmpMap[y][x];
            }
        }
        memset(tmpMap, 0, sizeof(tmpMap));
        
        for(int y = 0; y < R; y++){
            for(int x = 0; x < C; x++){
                if(map[y][x] == -1) clearTop(y,x);
                if(map[y][x] == -2) clearBottom(y, x);
            }
        }
    }
    int answer = 0;
    for(int y = 0; y < R; y++){
        for(int x = 0; x < C; x++){
            if(map[y][x] > 0) answer += map[y][x];
        }
    }
    cout << answer;
    return 0;
}