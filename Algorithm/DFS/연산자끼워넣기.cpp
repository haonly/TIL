//
//  main.cpp
//  1015_algorithm
//
//  Created by Hayeon Kim on 15/10/2019.
//  Copyright © 2019 Hayeon Kim. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000000000 + 1;

int N;
int num[12], oper[4];
int maxResult = -MAX, minResult = MAX;

void dfs(int plus, int minus, int mult, int div, int cnt, int sum){
    if(cnt == N){
        maxResult = max(maxResult, sum);
        minResult = min(minResult, sum);
    }
    if(plus > 0)
        dfs(plus-1, minus, mult,div,cnt+1, sum+num[cnt]);
    if(minus > 0)
        dfs(plus, minus-1, mult, div, cnt+1, sum-num[cnt]);
    if(mult > 0)
        dfs(plus, minus, mult-1, div, cnt+1, sum*num[cnt]);
    if(div > 0)
        dfs(plus, minus, mult, div-1, cnt+1, sum/num[cnt]);
}

int main(int argc, const char * argv[]) {
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> num[i];
    
    for(int i = 0; i < 4; i++)
        cin >> oper[i];
        
    dfs(oper[0], oper[1], oper[2], oper[3], 1, num[0]);
    
    cout << maxResult << endl;
    cout << minResult << endl;
    return 0;
}
