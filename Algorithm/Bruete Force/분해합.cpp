//
//  main.cpp
//  0820_algorithm2
//
//  Created by Hayeon Kim on 20/08/2019.
//  Copyright © 2019 Hayeon Kim. All rights reserved.
//

#include <iostream>
using namespace std;

#define MAX 1000000

int main(int argc, const char * argv[]) {
    int N;
    int temp;
    cin >> N;
    
    
    for(int i = 1; i <= MAX; i++){
        temp = i;
        int sum = i;
        while(temp){
            sum += temp % 10;
            temp /= 10;
        }
        if(sum == N){
            cout << i;
            return 0;
        }
    }
    cout << 0;
    return 0;
}
