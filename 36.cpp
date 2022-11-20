#include <iostream>
#define ub 1000000

using namespace std;

string to_binary(int num) {
	string result = "";
	while (num != 0) {
		result += to_string(num % 2);
		num /= 2;
	}
	string reversed(result.rbegin(), result.rend());
	return reversed;
}

bool is_palindrome(string num) {
	string reversed(num.rbegin(), num.rend());
	return num == reversed;
}

int main(int argc, char **argv) {
	int sum = 0;
	for (int i = 1; i < ub; ++i) {
		if (is_palindrome(to_string(i)) && is_palindrome(to_binary(i))) {
			sum += i;
		}
	}
	cout << "Result: " << sum << endl;
	return 0;
}
