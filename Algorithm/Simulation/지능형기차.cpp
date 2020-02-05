//2455 지능형기차(Simulation)

#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 4

int main(int argc, const char * argv[]) {
    
    int in, out;
    int total = 0;
    int max_people = 0;
    
    for(int i = 0; i < 4; i++){
        cin >> out >> in;
        total -= out;
        total += in;
        max_people = max(max_people, total);
    }
    cout << max_people;
    return 0;
}
