#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int ans = 987654321;
int map[50][50];
vector<pair<int, int>> house, chicken;
bool visited[13];

int distance(pair<int, int> a, pair<int, int> b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void sol(int idx, int select){
    if(select == M){
        int temp = 0;
        for(int i = 0; i < house.size(); i++){
            int dist = 987654321;
            for(int j = 0; j < chicken.size(); j++){
                if(visited[j])
                    dist = min(dist,distance(house[i], chicken[j]));
            }
            temp += dist;
        }
        ans = min(ans, temp);
        return;
    }
    
    if(idx == chicken.size())
        return;
    
    visited[idx] = true;
    sol(idx+1, select+1);
    
    visited[idx] = false;
    sol(idx+1, select);
}

int main(int argc, const char * argv[]) {
    
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] == 2)
                chicken.push_back(make_pair(i, j));
            if(map[i][j] == 1)
                house.push_back(make_pair(i, j));
        }
    }
    
    sol(0, 0);
    cout << ans << endl;
    
    return 0;
}
