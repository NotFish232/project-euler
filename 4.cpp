#include <iostream>
#define ll long long

using namespace std;

bool is_palindrome(string s) {
    if (s.length() <= 1) {
        return true;
    }
    if (s[0] != s[s.length() - 1]) {
        return false;
    }
    return is_palindrome(s.substr(1, s.length() - 2));
}

int main(int argc, char **argv) {
    ll max = 0;
    for (int num_1 = 100; num_1 < 1000; ++num_1) {
        for (int num_2 = 100; num_2 < 1000; ++num_2) {
            int product = num_1 * num_2;
            if (product > max && is_palindrome(to_string(product))) {
                max = product;
            }
        }
    }
    cout << "Result: " << max << endl;
    return 0;
}