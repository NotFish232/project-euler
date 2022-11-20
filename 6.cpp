#include <iostream>
#include <cmath>
#define n 100

using namespace std;

int main(int argc, char **argv) {
    int sum_of_squares = (n * (n + 1) * (2 * n + 1))  / 6;
    int square_of_sums = (pow(n, 2) * pow(n + 1, 2)) / 4;
    int difference = abs(sum_of_squares - square_of_sums);
    cout << "Result: " << difference << endl;
    return 0;
 
}