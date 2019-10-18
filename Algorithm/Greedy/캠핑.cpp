// 4796 캠핑(그리디)

#include <iostream>
#include <algorithm>

using namespace std;
int main(int argc, const char * argv[]) {
    int P, L, V;
    int i = 0;
    int result;
    while(1){
        cin >> L >> P >> V;
        if(L == 0 && P == 0  && V == 0)
            return 0;
        i++;
        result = (V/P)*L + min(V%P, L);
        cout << "Case " << i << ": " << result << endl;
    }
    return 0;
}
