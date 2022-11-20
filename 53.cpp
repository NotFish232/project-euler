#include <iostream>
#include <cmath>
#define ub 100
#define lb 1
#define target 1000000
#define ll unsigned long long
using namespace std;

ll factorial(int n, int start = 1) {
	ll val = 1;
	for (int i = start; i <= n; ++i) {
		val *= i;
	}
	return val;
}

int main(int argc, char **argv) {
	int count = 0;
	for (size_t n = lb; n <= ub; ++n) {
		for (size_t r = 1; r <= n; ++r) {
			ll numerator, denominator;
			if (n - r > r) {
				numerator = factorial(n, n - r + 1);
				denominator = factorial(r);
			} else {
				numerator = factorial(n, r + 1);
				denominator = factorial(n - r);
			}
			ll result = numerator / denominator;
			cout << result << endl;
			if (result > target) ++count;
		}
	}
	cout << "Result: " << count << endl;
	return 0;
}
