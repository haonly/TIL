//
//  main.cpp
//  0830_algorithm
//
//  Created by Hayeon Kim on 26/08/2019.
//  Copyright © 2019 Hayeon Kim. All rights reserved.
//dp

#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

int fibonacci(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(dp[n] != -1) return dp[n];
    dp[n] = fibonacci(n-2) + fibonacci(n-1);
    return dp[n];
}

int main(){
    int N;
    cin >> N;
    dp.resize(N+1, -1);
    cout << fibonacci(N) << endl;
}
