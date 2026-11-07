#include <iostream>
using namespace std;

double charge(double weight, bool express = false, bool insured = false)
{
    double total = weight * 20;

    if (express)
        total += 50;

    if (insured)
        total += 30;

    return total;
}

int charge(int grams)
{
    return grams / 1000 * 20;
}

int main()
{
    cout << charge(2.0) << endl;
    cout << charge(2.0, true) << endl;
    cout << charge(2.0, true, true) << endl;
    cout << charge(2.0f) << endl;
    cout << charge(500) << endl;

    return 0;
}