#include <iostream>
#include <numeric>
#include <vector>

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
    BigNum operator*(const BigNum &obj) {
        BigNum num(digits);
        for (const int &n: obj.digits) {
            num *= n;
        }
        return num;
    }
    void operator*=(int num) {
        *this = *this * num;
    }
    void operator*=(const BigNum &obj) {
        *this = *this * obj;
    }
    friend ostream &operator<<(ostream &os, const BigNum &obj) {
        for (const int &num: obj.digits) {
            cout << num << " ";
        }
        return os;
    }
    int count() {
        return digits.size();
    }
 
};


int main(int argc, char **argv) {
    BigNum num(1);

}