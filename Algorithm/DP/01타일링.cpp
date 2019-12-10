#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   int n;
   cin >> n;
   int* num = new int[n+1];
   num[0] = 0;
   num[1] = 1;//1
   num[2] = 2;//00,11

   for (int i = 3; i <= n; i++) {
      num[i] = (num[i - 1] + num[i - 2])%15746;
   }
   cout << num[n];
}