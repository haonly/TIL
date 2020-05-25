// 16360

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int sSize = s.size();
        if (s[sSize - 1] == 'a')
            s += "s";
        else if (s[sSize - 1] == 'i' || s[sSize - 1] == 'y') {
            s[sSize - 1] = 'i';
            s += "os";
        }
        else if (s[sSize - 1] == 'l')
            s += "es";
        else if (s[sSize - 1] == 'n') {
            s[sSize - 1] = 'a';
            s += "nes";
        }
        else if (s[sSize - 1] == 'e' && s[sSize - 2] == 'n') {
            s[sSize - 2] = 'a';
            s[sSize - 1] = 'n';
            s += "es";
        }
        else if (s[sSize - 1] == 'o')
            s += 's';
        else if (s[sSize - 1] == 'r')
            s += "es";
        else if (s[sSize - 1] == 't')
            s += "as";
        else if (s[sSize - 1] == 'u')
            s += "s";
        else if (s[sSize - 1] == 'v')
            s += "es";
        else if (s[sSize - 1] == 'w')
            s += "as";
        else
            s += "us";
        cout << s << '\n';
        
    }
    return 0;
}
