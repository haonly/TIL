//
//  main.cpp
//  0905_algorithm
//
//  Created by Hayeon Kim on 04/09/2019.
//  Copyright © 2019 Hayeon Kim. All rights reserved.
//dp  1309

#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 100001;
const int MOD = 9901;

int n;
long long lionnum[3][MAX];
int lionnumcal() {
    
    lionnum[0][1] = lionnum[1][1] = lionnum[2][1] = 1;
    for (int i = 2; i <= n; i++) {
        lionnum[0][i] = (lionnum[0][i - 1] + lionnum[1][i - 1] + lionnum[2][i - 1])%MOD;
        lionnum[1][i] = (lionnum[0][i - 1] +  lionnum[2][i - 1])%MOD;
        lionnum[2][i] = (lionnum[0][i - 1] + lionnum[1][i - 1])%MOD;
    }
    return (lionnum[0][n] + lionnum[1][n] + lionnum[2][n])%MOD;
}

int main(void) {
    cin >> n;
    memset(lionnum, 0, sizeof(lionnum));
    cout << lionnumcal();
    return 0;
}
