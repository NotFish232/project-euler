#include <iostream>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
    int total;
    friend ostream &operator<<(ostream &os, const struct Date &date) {
        os << date.day << ", " << date.month << ", " << date.year;
        return os;
    }
};

int main(int argc, char **argv) {
    Date date{1, 1, 1901, 2};
    int count = 0;
    while (!(date.year == 2000 && date.month == 12 && date.day == 31)) {
        if (date.day == 1 && date.total % 7 == 0) {
            ++count;
        }
        ++date.day;
        bool is_leap_year = date.year % 4 == 0 && (!date.year % 100 == 0 || date.year % 400 == 0);
        if (date.month == 2 && ((is_leap_year && date.day > 29) || (!is_leap_year && date.day > 28))) { /* february */
            ++date.month;
            date.day = 1;
        }
        else if ((date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) && date.day > 30) {
            ++date.month;
            date.day = 1;
        } else if (date.day > 31) {
            ++date.month;
            date.day = 1;
        }
        if (date.month > 12) {
            ++date.year;
            date.month = 1;
        }
        ++date.total;
    }
    cout << "Result: " << count << endl;
    return 0;

}