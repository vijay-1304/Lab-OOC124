#include <iostream>
using namespace std;

class Time {
public:
    int hour, minutes;

    Time(int h = 0, int m = 0) : hour(h), minutes(m) {}

    Time add(const Time &c) {
        int totalMinutes = minutes + c.minutes;
        int totalHours = hour + c.hour;

        totalHours += totalMinutes / 60;
        totalMinutes = totalMinutes % 60;

        return Time(totalHours, totalMinutes);
    }

    Time sub(const Time &c) {
        int total1 = hour * 60 + minutes;
        int total2 = c.hour * 60 + c.minutes;

        int difference = total1 - total2;

        int h = difference / 60;
        int m = difference % 60;

        return Time(h, m);
    }

    void display() const {
        cout << hour << " hours and "
             << minutes << " minutes" << endl;
    }
};

int main() {

    Time c1(1, 50);
    Time c2(2, 20);

    Time sum = c1.add(c2);
    Time diff = c1.sub(c2);

    cout << "1st time is: ";
    c1.display();

    cout << "2nd time is: ";
    c2.display();

    cout << "Addition: ";
    sum.display();

    cout << "Subtraction: ";
    diff.display();

    return 0;
}