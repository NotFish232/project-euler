#include <iostream>
#define four_million 4000000
#define ll long long

int fib(int n) {
    return n <= 2 ? 1 : fib(n - 2) + fib(n - 1);
}

int main(int argc, char **argv) {
    int i = 1;
    ll result, sum = 0;
    while((result = fib(i++)) <= four_million) {
        if (result % 2 == 0) sum += result;
    }
    std::cout << "Result: " << sum << std::endl;
    return 0;
}