//
//  main.cpp
//  0820_algorithm
//
//  Created by Hayeon Kim on 20/08/2019.
//  Copyright © 2019 Hayeon Kim. All rights reserved.
//

#include <iostream>
using namespace std;

int fake[9];
int size = 9;

void sort(int *number, int size){
    int i = 0, j = 0, temp = 0;
    for(j = 0; j < size; j++){
        for(i = 0; i < size-1; i++){
            if(number[i] > number[i+1]){
                temp = number[i];
                number[i] = number[i+1];
                number[i+1] = temp;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int hap=0;
    int temp = 0;
    int a = -1,b = -1;
    for(int i = 0; i < size; i++){
        cin >> fake[i];
        hap += fake[i];
    }
    sort(fake, size);
    
    temp = hap;
    
    for(int i = 0; i < size-1; i++){
        for(int j = i+1; j < size; j++){
            if(temp - (fake[j]+fake[i]) == 100){
                a = i;
                b = j;
                break;
            }
        }
    }
    
    for(int i = 0; i < 9; i++){
        if(i == a || i == b){
            continue;
        }
        cout << fake[i] << endl;
    }
    return 0;
}
