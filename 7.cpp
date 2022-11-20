#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int num) {
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main(int argc, char **argv) {
    int i = 1, count = 0;
    while(count < 10001) {
        ++i;
        if (is_prime(i)) ++count;
    }
    cout << "Result: " << i << endl;
    return 0;
}