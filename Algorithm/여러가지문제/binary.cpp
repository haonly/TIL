#include <bits/stdc++.h>

using namespace std;


int my_max(int a, int b){
    return a > b ? a: b;
}
int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<int> binary;
    int max = 0;
    int count = 0;
    int i = 0;
    while(n != 1){
        binary.push_back(n % 2);
        n = n/2;
    }
    binary.push_back(1);
    for(int i = binary.size()-1; i>=0;i--){
        if(binary[i] != 1){
            max = my_max(count, max);
            count = 0;
        }
        if(binary[i] == 1)
            count++;  
    }
    max = my_max(count, max);
    cout << max << endl;

    return 0;
}
