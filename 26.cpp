#include <iostream>
#include <vector> 
#include <algorithm>
#define ub 1000

using namespace std;

struct Val {
    int d;
    int count;
};

int count(int n) {
    vector<int> seq;
    int num = 1;
    while (true) {
        if (find(seq.begin(), seq.end(), num / n) != seq.end()) {
            break;
        }
        if (num % n == 0) return 0;
        seq.push_back(num /  n);
        num %= n;
        num *= 10;
    
    }
    cout << "Seq for " << n << ": " << endl;
    for (const int &_n: seq) cout << _n << " ";
    cout << endl;
    return seq.size();
}
int main(int argc, char **argv) {
    Val max{0, 0};
    for (int i = 2; i < ub; ++i) {
        int cnt = count(i);
        if (cnt > max.count) {
            max.d = i;
            max.count = cnt;
        }
    }  
    cout << max.d << endl;
    return 0; 
}