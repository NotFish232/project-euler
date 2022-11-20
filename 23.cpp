#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>
#define ll long long
#define ub 28123

using namespace std;

vector<ll> find_factors(ll num) {
    vector<ll> factors;
    factors.push_back(1);
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            factors.push_back(i);
            if (i != num / i) {
                factors.push_back(num / i);
            }
        }
    }
    return factors;
}


ll find_factors_sum(ll num) {
    vector<ll> factors = find_factors(num);
    return accumulate(factors.begin(), factors.end(), 0LL);
}

bool is_abundant(ll num) {
    return find_factors_sum(num) > num;
}

bool check(ll num) {
    ll num_1, num_2;
    for (int i = 1; i <= num / 2; ++i) {
        num_1 = i;
        num_2 = num - num_1;
        if (is_abundant(num_1) && is_abundant(num_2)) return false;
    }
    return true;
}


int main(int argc, char **argv) {
    ll sum = 0;
    for (int i = 1; i < ub; ++i) {
        if (check(i)) sum += i;
    }
    cout << "Result: " << sum << endl;
    return 0;
}