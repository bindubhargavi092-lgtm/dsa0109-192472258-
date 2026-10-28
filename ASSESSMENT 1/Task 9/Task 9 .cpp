
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

struct Test
{
    string zone, hour;
    double balance, recharge, expectedFare;
};

double getFare(string zone, int hour)
{
    double fare;

    if (zone == "1")
        fare = 20;
    else if (zone == "2")
        fare = 30;
    else if (zone == "3")
        fare = 40;
    else
        return -1;

    if ((hour >= 8 && hour < 10) ||
        (hour >= 17 && hour < 20))
        fare += 10;

    return fare;
}

int main()
{
    Test tests[] = {
        {"1", "7", 100, 0, 20},
        {"2", "8", 100, 0, 40},
        {"3", "10", 100, 0, 40},
        {"1", "17", 100, 0, 30},
        {"2", "20", 100, 0, 30},
        {"1", "9", 70, 0, 30},
        {"5", "12", 100, 0, -1},
        {"1", "12", 100, -50, -2},
        {"1", "abc", 100, 0, -3}
    };

    int n = sizeof(tests) / sizeof(tests[0]);
    double total = 0;

    cout << fixed << setprecision(2);
    cout << "FARE LOGIC TEST REPORT\n\n";
    cout << left << setw(8) << "Zone"
         << setw(8) << "Hour"
         << setw(15) << "Expected"
         << setw(15) << "Actual"
         << "Result\n";

    for (int i = 0; i < n; i++)
    {
        double actual;
        int hour;
        stringstream ss(tests[i].hour);

        if (!(ss >> hour) || !(ss >> ws).eof()
            || hour < 0 || hour > 23)
            actual = -3;
        else if (tests[i].recharge < 0)
            actual = -2;
        else
        {
            actual = getFare(tests[i].zone, hour);

            if (actual >= 0 &&
                tests[i].balance - actual < 50)
                actual = -4;
        }

        bool pass = (actual == tests[i].expectedFare);

        cout << left << setw(8) << tests[i].zone
             << setw(8) << tests[i].hour
             << setw(15) << tests[i].expectedFare
             << setw(15) << actual
             << (pass ? "PASS" : "FAIL") << endl;
    }

    cout << "\nFIVE JOURNEYS:\n";

    string zones[] = {"1", "2", "3", "1", "2"};
    int hours[] = {7, 8, 10, 17, 20};

    for (int i = 0; i < 5; i++)
    {
        double fare = getFare(zones[i], hours[i]);
        total += fare;
        cout << "Journey " << i + 1
             << ": Rs. " << fare << endl;
    }

    cout << "Total fare: Rs. " << total << endl;

    return 0;
}
