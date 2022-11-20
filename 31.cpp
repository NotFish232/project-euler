#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#define target 200;


using namespace std;

static vector<int> counts{1, 2, 5, 10, 20, 50, 100, 200};
static vector<vector<int>> found;
static int _n = 1;

void solve(vector<int> solution = vector<int>()) {
    cout << _n++ <<  "\n";
    int count = accumulate(solution.begin(), solution.end(), 0);
    if (count > 200) {
        return;
    }
    if (count == 200) {
        sort(solution.begin(), solution.end());
        if (find(found.begin(), found.end(), solution) == found.end()) {
            found.push_back(solution);
        }
        return;
    }
    for (const int& n: counts) {
        solution.push_back(n); 
        solve(solution);
        solution.pop_back();
    }

}
int main() {

    solve();
    int result = found.size();
    cout << "Result: " << solve << endl;
    return 0;
}