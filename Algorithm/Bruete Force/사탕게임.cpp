//
//  main.cpp
//  0820_algorithm3
//
//  Created by Hayeon Kim on 20/08/2019.
//  Copyright © 2019 Hayeon Kim. All rights reserved.
//3085

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX 50

int N;
char table[MAX][MAX];

int check(){
    
    int count = 1;
    for(int i = 1; i <= N; i++){
        int temp = 1;
        for(int j = 2; j <= N; j++){
            if(table[i][j-1] == table[i][j])
                temp++;
            else{
                count = max(count, temp);
                temp = 1;
            }
        }
        count = max(count, temp);
    }
    
    for(int i = 1; i <= N; i++){
        int temp = 1;
        for(int j = 0; j <= N-1; j++){
            if(table[j+1][i] == table[j][i])
                temp++;
            else{
                count = max(count, temp);
                temp = 1;
            }
        }
        count = max(count, temp);
    }
    
    return count;
}

int main(int argc, const char * argv[]) {
    cin >> N;
    int result = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> table[i][j];
        }
    }
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N-1; j++){

            swap(table[i][j], table[i][j+1]);
            result = max(result, check());
            swap(table[i][j], table[i][j+1]);
            
       
            swap(table[j][i], table[j+1][i]);
            result = max(result, check());
            swap(table[j][i], table[j+1][i]);
            
        }
    }
    cout << result;
    return 0;
    
}
