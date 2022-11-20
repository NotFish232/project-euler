#include <iostream>
#include <fstream>
#include <stdio.h>
#define ll long long
#define file_len 100
#define accuracy 16

using namespace std;

int main(int argc, char **argv) {
    ll sum = 0;
    string temp;
    fstream f;
    f.open("file.txt");
    for (int i = 0; i < file_len; ++i) {
        f >> temp;
        sum += strtoll(temp.substr(0,accuracy).c_str(), NULL, 10);
    }
    f.close();
    cout << "Result: " << to_string(sum).substr(0, 10) << endl;
    return 0;
}