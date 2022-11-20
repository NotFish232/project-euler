#include <iostream>
#include <vector>
#include <numeric>
#define count 1000
#define ll long long

using namespace std;


int main(int argc, char **argv) {
    vector<int> num;
    num.push_back(1);
    for (int i = 0; i < count; ++i) {
        if (num[num.size() - 1] >= 5) {
            num.push_back(0);
        }
        int carry = 0;
        for (int &n: num) {
            n *= 2;
            n += carry;
            if (n >= 10) {
                carry = 1;
                n %= 10;
            } else {
                carry = 0;
            }
        }
    }
    ll sum = accumulate(num.begin(), num.end(), 0);
    cout << "Result: " << sum << endl;
    return 0;
}