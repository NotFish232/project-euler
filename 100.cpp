#include <iostream>

#include <vector>
#include <cmath>
#define start 1000000000000
#define ll unsigned long long
#define ull unsigned long long 

using namespace std;

ll solve_num(ll num) {
    // (n)(n-1) / (total)(total - 1) = 1 / 2
    // (n)(n-1) = (total)(total - 1) / 2
    // 
    ll target = (num * (num - 1)) / 2;
    long double n = sqrt(target);                                                                                                                                                                                                               
    ll n1 = floor(n);
    ll n2 = ceil(n);
    return n1 * n2 == target ? n2: 0;
}
int main(int argc, char **argv) {
    ll i = start, result;
    while (!(result = solve_num(i))) {
        ++i;
    }
    cout << "Result: " << result << endl;
    return 0;
}
