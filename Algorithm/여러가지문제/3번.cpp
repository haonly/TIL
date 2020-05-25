#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    string test;
    vector<char> first;
    vector<char> sec;
    for(int i = 0; i < T; i++){
        cin >> test;
      for(int j = 0; j < test.length(); j++){
            if(j % 2 == 0)
                first.push_back(test[j]);
            else
                sec.push_back(test[j]);
        }
        for(int k = 0; k < first.size(); k++)
            cout << first[k];
        cout << " ";
        for(int k = 0; k < sec.size(); k++)
            cout << sec[k];
        cout << '\n';
        first.clear();
        sec.clear();
   
    }

    return 0;
}
