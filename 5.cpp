#include <iostream>

using namespace std;

bool is_divisible(int num) {
    for (int i = 1; i <= 20; ++i) {
        if (num % i != 0) return false;
    }
    return true;
}

int main(int argc, char **argv) {
    int i = 1;
    while (!is_divisible(i)) {
        ++i;
    }
    cout << "Result: " << i << endl;
}