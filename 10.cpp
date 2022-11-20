#include <iostream>
#include <cmath>
#define ll long long
#define ub 2000000

using namespace std;

bool is_prime(ll num) {
    for (ll i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main(int argc, char **argv) {
    ll sum = 0;
    for (ll i = 2; i < ub; ++i) {
        if (is_prime(i)) sum += i;
    }
    cout << "Result: " << sum << endl;
    return 0;
}