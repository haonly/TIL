#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MMAX 50
#define NMAX 1000

int N, M;
char dna[NMAX][MMAX];
vector<char> s;
vector<int> acgt(4);
char acgt_[4] = {'A', 'C', 'G', 'T'};

void clear_func(){
    for(int i = 0; i < 4; i++)
        acgt[i] = 0;
}

int main(int argc, const char * argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> dna[i][j];
        }
    }
    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(dna[j][i] == 'A')
                acgt[0]++;
            else if(dna[j][i] == 'C')
                acgt[1]++;
            else if(dna[j][i] == 'G')
                acgt[2]++;
            else if(dna[j][i] == 'T')
                acgt[3]++;
        }
        int maxIdx = max_element(acgt.begin(), acgt.end()) - acgt.begin();
        s.push_back(acgt_[maxIdx]);
        clear_func();
    }
    for(int i = 0; i < s.size(); i++)
        cout << s[i];
    cout << "" << endl;
    
    int cnt = 0;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(dna[j][i] != s[i])
                cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
