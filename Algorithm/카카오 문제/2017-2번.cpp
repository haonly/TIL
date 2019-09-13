//
//  main.cpp
//  0909_algorithm
//
//  Created by Hayeon Kim on 04/09/2019.
//  Copyright © 2019 Hayeon Kim. All rights reserved.
//카카오 2017 2

#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    string input = " ";
    int len;
    int list_index = 0;
    int sum = 0;
    int cnt = 0;
    int list[3];
    
    cin >> input;
    len = input.length();
    
    for(int i =0; i < len; i++){
        if(cnt == 0){
            int tmp_hap = input[i]-48;
            list[list_index] = tmp_hap;
        }
        else if(cnt == 1){
            if(input[i] == '0'){
                list[list_index] *= 10;
                cnt--;
            }
            else if(input[i] == 'D')
                list[list_index] = list[list_index] * list[list_index];
            else if(input[i] == 'T')
                list[list_index] = list[list_index]*list[list_index]*list[list_index];
        }
        else if(cnt == 2){
            if(input[i] == '*'){
                for(int j = list_index-1; j <= list_index; j++){
                    list[j] *= 2;
                }
            }
            else if(input[i] == '#')
                list[list_index] *= -1;
            else i--;
            list_index++;
        }
        cnt++;
        cnt %= 3;
    }
    for(int i = 0; i < 3; i++){
        cout << list[i] << endl;
        sum += list[i];
    }
    cout << sum;
    return 0;
}
