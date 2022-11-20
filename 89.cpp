#include <iostream>
#include <fstream>
#include <map>
using namespace std;

static map<char, int> rules = {
	{'I', 1},
	{'V', 5},
	{'X', 10},
	{'L', 50},
	{'C', 100},
	{'D', 500},
	{'M', 1000}
};

int roman_to_num(const string &roman) {
	int val = 0;
	for (int i = 0; i < roman.length(); ++i) {
		if (i < roman.length() - 1 && rules[roman[i]] >= rules[roman[i + 1]]) {
			val += rules[roman[i]];
		} else {
			val -= rules[roman[i]];
		}
	}
	return val;
}

string num_to_roman(int num) {
	return "500";
}

int main(int argc, char **argv) {
	fstream f;
	string line, optimal;
	int sum = 0, val;
	f.open("file.txt");
	while (f >> line) {
		val = roman_to_num(line);
		cout << val << endl;
		optimal = num_to_roman(val);
		sum += (optimal.length() - line.length());
	}
	f.close();
	cout << "Result: " << sum << endl;
	return 0;
}
