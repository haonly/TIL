#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    string si;
    int tmp;
    string rest;
    string cho;
    string apm;

    si = s.substr(0, 2);
    rest = s.substr(2, 6);
    apm = s.substr(8, s.length());
    if(apm == "PM"){
        tmp = atoi(si.c_str());
        if(tmp < 12){
            tmp += 12;
            si = to_string(tmp);
            if(si == "24")
                si = "00";
        }
        if(tmp == 12){
            si = to_string(tmp);
        }
    }
    if(si == "12" && apm == "AM"){
        si = "00";
    }
    si += rest;

    return si;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s); 

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
