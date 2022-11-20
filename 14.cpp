#include <iostream>
#define ll long long
#define ub 1000000

using namespace std;

ll count_seq(ll n) {
    if (n == 1) {
        return 0;
    }
    return 1 + count_seq(n & 1 ? 3 * n + 1 : n / 2);
}

int main(int argc, char **argv) {
    int max = 0, val = 0;
    for (int i = 1; i < ub; ++i) {
        int cnt = count_seq(i);
        if (cnt > max) {
            max = cnt;
            val = i;
        }
    }
    cout << "Result: " << val << endl;
    return 0;
}