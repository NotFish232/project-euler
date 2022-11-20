#include <iostream>
#include <cmath>
#include <vector>
#define target_num 600851475143
#define ll long long

using namespace std;

vector<int> find_factors(ll num) {
    vector<int> factors;
    ll i = 2;
    while (num != 1) {
        if (num % i == 0) {
            factors.push_back(i);
            num /= i;
        } else {
            ++i;
        }
    }
    return factors;
}

bool is_prime(int num) {
    for(int i = 2; i < sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main(int argc, char **argv) {
    vector<int> factors = find_factors(target_num);
    int max = 0;
    for (const int &factor: factors) {
        if (factor > max && is_prime(factor)) max = factor;
    }
    cout << "Result: " << max << endl;
    return 0;
}