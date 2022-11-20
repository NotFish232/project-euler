#include <iostream>
#include <cmath>
#define target 1000

using namespace std;

int main(int argc, char **argv) {
    for (int a = 1; a < target; ++a) {
        for (int b = a + 1; b < target; ++b) {
            for (int c = b + 1; c < target; ++c) {
                if (a + b + c == target && pow(a, 2) + pow(b, 2) == pow(c, 2)) {
                    cout << "Result: " << (a * b * c) << endl;
                }
            }
        }
    }
    return 0;
}