#include <iostream>
#include <fstream>
#define len 20
#define thing_size 13
#define ll long long

using namespace std;

ll sum(string s) {
    ll thing = 1;
    for (const char &ch: s) {
        thing *= (ch - '0');
    }
    return thing;
}
int main(int argc, char **argv) {
    fstream f;
    string num = "", temp;
    f.open("file.txt");
    for (int i = 0; i < len; ++i) {
        f >> temp;
        num += temp;
    }
    f.close();
    ll max = 0;
    for (int i = 0; i < num.length() - thing_size + 1; ++i) {
        ll _sum = sum(num.substr(i, thing_size));
        if (_sum > max) max = _sum;
    }
    cout << "Result: " << max << endl;
    return 0;
}