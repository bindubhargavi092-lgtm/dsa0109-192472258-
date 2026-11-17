#include <iostream>
#include <cmath>
using namespace std;

class Complex {
    double real, imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Constructor with real part
    Complex(double r) : real(r), imag(0) {}

    // Constructor with real and imaginary parts
    Complex(double r, double i) : real(r), imag(i) {}

    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(const Complex& c) const {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(const Complex& c) const {
        return Complex(
            real * c.real - imag * c.imag,
            real * c.imag + imag * c.real
        );
    }

    Complex operator/(const Complex& c) const {
        double denominator = c.real * c.real + c.imag * c.imag;

        if (denominator == 0) {
            throw runtime_error("Division by zero impedance");
        }

        return Complex(
            (real * c.real + imag * c.imag) / denominator,
            (imag * c.real - real * c.imag) / denominator
        );
    }

    bool operator==(const Complex& c) const {
        return real == c.real && imag == c.imag;
    }

    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;

        if (c.imag >= 0)
            out << " + " << c.imag << "j";
        else
            out << " - " << -c.imag << "j";

        return out;
    }
};

int main() {
    try {
        Complex resistor(10, 0);
        Complex inductor(0, 5);
        Complex capacitor(0, -2);

        Complex series = resistor + inductor + capacitor;

        cout << "Series Impedance: " << series << endl;
        cout << "Magnitude: " << series.magnitude() << endl;

        Complex z1(10, 5);
        Complex z2(20, -5);

        Complex parallel = (z1 * z2) / (z1 + z2);

        cout << "Parallel Impedance: " << parallel << endl;
        cout << "Magnitude: " << parallel.magnitude() << endl;

        Complex zero(0, 0);
        Complex result = resistor / zero;

        cout << result << endl;
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}