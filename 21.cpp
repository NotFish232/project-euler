#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#define ll long long
#define ub 10000

using namespace std;


vector<int> find_factors(ll num) {
    vector<int> factors;
    factors.push_back(1);
    for (int i = 2; i * i < num; ++i) {
        if (num % i == 0) {
            factors.push_back(i);
            factors.push_back(num / i);
        }
    }
    return factors;
}
ll sum_of_factors(ll num) {
    vector<int> factors = find_factors(num);
    return accumulate(factors.begin(), factors.end(), 0LL);
}

int main(int argc, char **argv) {
    ll sum = 0;
    for (int i = 1; i < ub; ++i) {
        int num_1 = sum_of_factors(i);
        int num_2 = sum_of_factors(num_1);


        if (num_2 == i && i < num_1)
        {
            sum += i + num_1;

        }
    }
    cout << "Result: " << sum << endl;
    return 0;
}