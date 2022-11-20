#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class BigNum {
private:
    vector<int> digits;
public:
    BigNum(int num) {
        digits.push_back(num);
    }
    BigNum(vector<int> _digits): digits(_digits) {};
    ~BigNum() = default;
    BigNum operator*(int n) {

        int carry = 0;
        vector<int> _digits(digits);
        for (int &num : _digits) {
            num *= n;
            num += carry;
            if (num >= 10) {
                carry = num / 10;
                num %= 10;
            } else {
                carry = 0;
            }
        }
        if (carry != 0) {
            string str = to_string(carry);
            for (int i = str.length() - 1; i >= 0; --i) {
                _digits.push_back(str[i] - '0');
            }
        }
        return BigNum(_digits);
    }
    void operator*=(int num) {
        *this = *this * num;
    }
    friend ostream &operator<<(ostream &os, const BigNum &obj) {
        for (const int &num: obj.digits) {
            cout << num << " ";
        }
        return os;
    }
    int sum() {
        return accumulate(digits.begin(), digits.end(), 0);
    }
};

int main(int argc, char **argv) {
    BigNum num(1);
    for (int i = 2; i <= 100; ++i) {
        num *= i;
    }
    cout << "Result: " << num.sum() << endl;
    return 0;
}