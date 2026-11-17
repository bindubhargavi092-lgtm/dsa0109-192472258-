#include <iostream>
#include <iomanip>
using namespace std;

class Money {
    long long paise;

public:
    Money(long long rupees = 0, int p = 0)
        : paise(rupees * 100 + p) {}

    Money operator+(const Money& m) const {
        Money temp;
        temp.paise = paise + m.paise;
        return temp;
    }

    Money operator-(const Money& m) const {
        Money temp;
        temp.paise = paise - m.paise;
        return temp;
    }

    Money& operator+=(const Money& m) {
        paise += m.paise;
        return *this;
    }

    bool operator==(const Money& m) const {
        return paise == m.paise;
    }

    bool operator<(const Money& m) const {
        return paise < m.paise;
    }

    friend ostream& operator<<(ostream& out, const Money& m) {
        long long value = m.paise;
        if (value < 0) {
            out << "-Rs ";
            value = -value;
        } else {
            out << "Rs ";
        }

        out << value / 100 << "."
            << setw(2) << setfill('0') << value % 100;
        return out;
    }

    friend istream& operator>>(istream& in, Money& m) {
        long long r;
        int p;
        in >> r >> p;
        if (in) m.paise = r * 100 + p;
        return in;
    }
};

int main() {
    Money a(120, 75);
    Money b(79, 25);

    Money c = a + b;

    cout << "Total: " << c << endl;
    cout << boolalpha << "Equal: " << (c == Money(200)) << endl;

    Money d(0, 75);
    Money e(0, 50);

    cout << "Carry: " << d + e << endl;

    Money f(50);
    Money g(100);

    cout << "Subtraction: " << f - g << endl;

    return 0;
}