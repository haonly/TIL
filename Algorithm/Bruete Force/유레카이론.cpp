//
//  main.cpp
//  0826_algorithm
//
//  Created by Hayeon Kim on 26/08/2019.
//  Copyright © 2019 Hayeon Kim. All rights reserved.
//

#include <iostream>
using namespace std;
int N;
int test;
int hapsu[1001];

void set(){
    for(int i = 1; i <= 45; i++){
        hapsu[i] = i * (i+1)/2;
    }
}

int check(int num){
    int result = 0;
    
    for(int i = 1; i <= num; i++){
        for(int j = 1; j <= num; j++){
            for(int k = 1; k <= num; k++){
                if(hapsu[i] + hapsu[j] + hapsu[k] == num){
                    result = 1;
                    return result;
                }
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    set();
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> test;
        cout << check(test) << endl;
    }
    
    return 0;
}
