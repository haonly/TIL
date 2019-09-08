//
//  main.cpp
//  0908_algorithm
//
//  Created by Hayeon Kim on 04/09/2019.
//  Copyright © 2019 Hayeon Kim. All rights reserved.
//카카오 2017 1

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    
    int n;
    int tmp_map;
    vector<int> arr1, arr2;
    vector<char> map;
    
    cin >> n;
    
    if(n < 1 || n > 16)
        return 0;
    for(int i = 0; i < n; i++){
        int temp = -1;
        cin >> temp;
        arr1.push_back(temp);
    }
    for(int i = 0; i < n; i++){
        int temp = -1;
        cin >> temp;
        arr2.push_back(temp);
    }
    for(int i = 0; i < n; i++){
        int k;
        tmp_map = arr1[i] | arr2[i];
        while(tmp_map != 0){
            k = tmp_map % 2;
            tmp_map /= 2;
            if(k == 1)
                map.push_back('#');
            else
                map.push_back(' ');
        }
        
        reverse(map.begin(), map.end());
        for(int j = 0; j < map.size(); j++)
            cout << map[j];
        cout << endl;
        map.resize(0);
    }
    return 0;
}
