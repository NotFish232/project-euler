#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;


bool check(ll num) {
    string str_num =  to_string(num);
    vector<int> target(str_num.begin(), str_num.end());
    sort(target.begin(), target.end());
    for (size_t i = 2; i <= 6; ++i) {
        str_num = to_string(i * num);
        vector<int> test(str_num.begin(), str_num.end());
        sort(test.begin(), test.end());
        if (test != target) return false;
    }
    return true;
}

int main(int argc, char **argv) {
    ll answer;
    for (ll i = 1;; ++i) {
        if (check(i)) {
            answer = i;
            break;
        }
    }
    cout << "Result: " << answer << endl;
    return 0;
}