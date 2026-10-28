
#include <iostream>
#include <iomanip>
using namespace std;

const double MIN_BALANCE = 50.0;
const double PEAK_CHARGE = 10.0;

class SmartCard
{
private:
    double balance;

public:
    SmartCard(double b)
    {
        balance = b;
    }

    bool canTravel(double fare)
    {
        return fare > 0 && balance - fare >= MIN_BALANCE;
    }

    void deduct(double fare)
    {
        if (canTravel(fare))
        {
            balance -= fare;
            cout << "Travel successful\n";
            cout << "Fare: Rs. " << fare << endl;
            cout << "Balance: Rs. " << balance << endl;
        }
        else
        {
            cout << "Travel rejected: insufficient balance\n";
        }
    }

    double getBalance()
    {
        return balance;
    }
};

double getFare(int zone, int hour)
{
    double fare;

    switch (zone)
    {
        case 1: fare = 20; break;
        case 2: fare = 30; break;
        case 3: fare = 40; break;
        default: return -1;
    }

    if ((hour >= 8 && hour < 10) ||
        (hour >= 17 && hour < 20))
    {
        fare += PEAK_CHARGE;
    }

    return fare;
}

int main()
{
    int zone, hour;
    double recharge;
    double fares[] = {20, 30, 40};

    cout << fixed << setprecision(2);

    cout << "METRO FARE SYSTEM\n";
    cout << "Minimum balance: Rs. " << MIN_BALANCE << endl;

    cout << "Enter recharge amount: ";
    cin >> recharge;

    if (cin.fail() || recharge < 0)
    {
        cout << "Invalid recharge amount\n";
        return 0;
    }

    SmartCard card(100 + recharge);

    cout << "\nZone Fare Table\n";
    for (int i = 0; i < 3; i++)
        cout << "Zone " << i + 1
             << ": Rs. " << fares[i] << endl;

    cout << "\nEnter zone (1-3): ";
    cin >> zone;

    cout << "Enter hour (0-23): ";
    cin >> hour;

    if (cin.fail() || hour < 0 || hour > 23)
    {
        cout << "Invalid hour\n";
        return 0;
    }

    double fare = getFare(zone, hour);

    if (fare < 0)
    {
        cout << "Invalid zone\n";
        return 0;
    }

    cout << "\nFinal fare: Rs. " << fare << endl;
    card.deduct(fare);

    return 0;
}
