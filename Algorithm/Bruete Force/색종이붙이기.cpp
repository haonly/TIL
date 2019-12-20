//17136 색종이붙이기(BF)

#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int arr[10][10];
int cnt, result;
int paper[6] = {0, 5, 5, 5, 5, 5};

void func(int y, int x){
    if(x == 10){
        func(y+1, 0);
        return;
    }
    if(y == 10){
        result = min(result, cnt);
        return;
    }
    if(arr[y][x] == 0){
        func(y, x+1);
        return;
    }
    
    for(int len = 5; len >= 1; len--){
        if(paper[len] == 0 || y + len > 10 || x + len > 10)
            continue;
        bool flag = true;
        for(int j = 0; j < len; j++){
            for(int k = 0; k < len; k++){
                if(arr[y+j][x+k] == 0){
                    flag = false;
                    break;
                }
            }
            if(flag == false)
                break;
        }
        if(flag == false)
            continue;
        for(int j = 0; j < len; j++){
            for(int k = 0; k < len; k++){
                arr[y+j][x+k] = 0;
            }
        }
        paper[len]--;
        cnt++;
        func(y, x+len);
        
        for(int j = 0; j < len; j++){
            for(int k = 0; k < len; k++){
                arr[y+j][x+k] = 1;
            }
        }
        paper[len]++;
        cnt--;
    }
}

int main() {

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> arr[i][j];
        }
    }
    result = INF;
    func(0, 0);
    if(result == INF)
        cout << -1 << endl;
    else
        cout << result << endl;
    return 0;
}
