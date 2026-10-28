
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int journeys[] = {20000, 500000, 3000000};
    double fare = 20.50;

    cout << fixed << setprecision(2);
    cout << "FARE TOTAL COMPARISON\n\n";

    cout << left << setw(15) << "Journeys"
         << setw(20) << "Double Total"
         << setw(20) << "Paise Total"
         << "Difference\n";

    for (int i = 0; i < 3; i++)
    {
        long long paiseTotal =
            (long long)journeys[i] * 2050;

        double doubleTotal = journeys[i] * fare;

        double paiseInRupees = paiseTotal / 100.0;

        cout << left << setw(15) << journeys[i]
             << setw(20) << doubleTotal
             << setw(20) << paiseInRupees
             << doubleTotal - paiseInRupees << endl;
    }

    cout << "\nINT OVERFLOW TEST\n";

    int intTotal = 0;
    long long longTotal = 0;

    for (int i = 0; i < 3000000; i++)
    {
        intTotal += 2050;
        longTotal += 2050;
    }

    cout << "Expected paise total: "
         << 3000000LL * 2050 << endl;
    cout << "Long long total: " << longTotal << endl;
    cout << "Int total: " << intTotal << endl;

    return 0;
}
