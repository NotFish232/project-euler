#include <iostream>
#include <cmath>
#define ll long long
#define target 500

using namespace std;

int factor_count(ll num) {
    int count = 0;
    for (int i = 1; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            ++count;
            if (i != num / i) ++count;
        }
    }
    return count;
}

int main(int argc, char **argv) {
    int i = 1, fc;
    ll num = 1;
    while ((fc = factor_count(num)) < 500) {
        num += ++i;
    }
    cout << "Result: " << num << endl;
    return 0;
}