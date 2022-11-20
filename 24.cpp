#include <iostream>
#include <vector>
#define target 1000000

using namespace std;

static int count = 1;

void recursion(string num) {
    if (num.length() == 10) {
        if (count == target) {
            cout << "Result: " << num << endl;
            exit(0);
        }
        ++count;
        return;
    }
    for (char i = '0'; i <= '9'; ++i) {
        if (num.find(i) == string::npos)
            recursion(num + i);
    }
}

int main(int argc, char **argv) {
    recursion("");
    return 0;
}