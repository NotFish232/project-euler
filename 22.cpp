#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define ll long long


using namespace std;

ll name_to_num(string s) {
    ll sum = 0;
    for (const char &ch: s) {
        sum += (ch - 'A' + 1);
    }
    return sum;
}
int main(int argc, char **argv) {
    fstream f;
    string name;
    vector<string> names;
    f.open("file.txt");
    while (f >> name) {
        names.push_back(name);
    }
    f.close();

    sort(names.begin(), names.end());

    ll sum = 0;
    for (int i = 0; i < names.size(); ++i) {
        sum += (i + 1) * name_to_num(names[i]);
    }

    cout << "Result: " << sum << endl;
    return 0;
}