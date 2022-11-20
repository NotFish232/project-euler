#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> factor(int num) {
	vector<int> _factors;
	for (int i = 1; i <= sqrt(num); ++i) {
		if (num % i == 0) {
			if (i == num / i) {
				_factors.push_back(i);
			} else {
				_factors.push_back(i);
				_factors.push_back(num / i);
			}
		}
	}
	return _factors;
}

bool is_prime(int num) {
	for (size_t i = 2; i <= sqrt(num); ++i) {
		if (num % i == 0) return false;
	}
	return true
}



int main(int argc, char **argv) {
	while (true) {
		
	}
	return 0;
}
