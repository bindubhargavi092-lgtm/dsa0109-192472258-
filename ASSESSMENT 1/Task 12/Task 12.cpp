
#include <iostream>
#include <iomanip>
using namespace std;

const int ZONES = 4;
const double PEAK_CHARGE = 10.0;
const double WEEKEND_DISCOUNT = 0.10;

double fares[ZONES] = {20, 30, 40, 60};

class MonthlyPass
{
private:
    int zone1, zone2;

public:
    MonthlyPass(int z1, int z2)
    {
        zone1 = z1;
        zone2 = z2;
    }

    bool allowsTravel(int zone)
    {
        return zone == zone1 || zone == zone2;
    }
};

class SmartCard
{
private:
    double balance;

public:
    SmartCard(double b)
    {
        balance = b;
    }

    void travel(int zone, int hour, bool weekend,
                MonthlyPass *pass)
    {
        if (zone < 1 || zone > ZONES ||
            hour < 0 || hour > 23)
        {
            cout << "Invalid zone or hour\n";
            return;
        }

        if (pass != nullptr && pass->allowsTravel(zone))
        {
            cout << "Monthly pass used. Fare: Rs. 0.00\n";
            return;
        }

        double fare = fares[zone - 1];

        if (weekend)
        {
            fare = fare * (1 - WEEKEND_DISCOUNT);
        }
        else if ((hour >= 8 && hour < 10) ||
                 (hour >= 17 && hour < 20))
        {
            fare += PEAK_CHARGE;
        }

        if (balance - fare >= 50)
        {
            balance -= fare;
            cout << "Travel successful\n";
            cout << "Fare: Rs. " << fare << endl;
            cout << "Remaining balance: Rs. "
                 << balance << endl;
        }
        else
        {
            cout << "Insufficient balance\n";
        }
    }
};

int main()
{
    cout << fixed << setprecision(2);

    SmartCard card(500);
    MonthlyPass pass(1, 4);

    cout << "METRO FARE SYSTEM\n\n";

    cout << "Test 1: Zone 4, weekday peak\n";
    card.travel(4, 8, false, nullptr);

    cout << "\nTest 2: Zone 2, weekend\n";
    card.travel(2, 12, true, nullptr);

    cout << "\nTest 3: Zone 1 with monthly pass\n";
    card.travel(1, 9, false, &pass);

    cout << "\nTest 4: Zone 3, weekday off-peak\n";
    card.travel(3, 12, false, nullptr);

    return 0;
}
