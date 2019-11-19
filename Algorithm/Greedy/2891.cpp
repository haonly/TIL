//
//  main.cpp
//  1119_algorithm
//
//  Created by Hayeon Kim on 2019/11/19.
//  Copyright © 2019 Hayeon Kim. All rights reserved.
//2891 카약과 강풍(그리디)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N, S, R;
    
    cin >> N >> S >> R;
    
    vector<int> team(N+1, 1);
    vector<int> broken(S);
    vector<int> spare(R);
    
    for(int i = 0; i < S; i++){
        cin >> broken[i];
        team[broken[i]]--;
    }
    for(int i = 0; i < R; i++){
        cin  >> spare[i];
        team[spare[i]]++;
    }
    
    for(int i = 1; i <= N; i++){
        if(team[i] == 0){
            if(i == 0 && team[i+1] == 2){
                team[i+1]--;
                team[i]++;
            }
            else if(i == N && team[i-1] == 2){
                team[i-1]--;
                team[i]++;
            }
            else{
                if(team[i-1] == 2){
                    team[i-1]--;
                    team[i]++;
                }
                else if(team[i+1] == 2){
                    team[i+1]--;
                    team[i]++;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++)
        if(team[i] == 0)
            ans++;
    
    cout << ans << endl;
    return 0;
}
