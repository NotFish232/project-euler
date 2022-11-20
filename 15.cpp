#include <iostream>
#define dim 20
#define ll long long

using namespace std;


ll solve() {
    ll paths = 1;
    for (int i = 0; i < dim; i++) {
        paths *= (2 * dim) - i;
        paths /= i + 1;
    }
    return paths;
}

int main(int argc, char **argv) {
    cout << "Result: " << solve() << endl;
    return 0;
}