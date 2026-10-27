
#include <iostream>
using namespace std;

// Constants defined in one place
constexpr double ZONE_A_FARE = 10.0;
constexpr double ZONE_B_FARE = 20.0;
constexpr double ZONE_C_FARE = 30.0;
constexpr double SURCHARGE = 5.0;
constexpr int MAX_TICKETS = 10;

// Zones using enum class
enum class Zone
{
    A = 1,
    B = 2,
    C = 3
};

int main()
{
    int zoneNumber, tickets;
    double fare = 0.0, total;

    cout << "1. Zone A\n2. Zone B\n3. Zone C\n";
    cout << "Enter zone number: ";
    cin >> zoneNumber;

    cout << "Enter number of tickets: ";
    cin >> tickets;

    if (tickets <= 0 || tickets > MAX_TICKETS)
    {
        cout << "Invalid number of tickets";
        return 0;
    }

    Zone selectedZone = static_cast<Zone>(zoneNumber);

    switch (selectedZone)
    {
        case Zone::A:
            fare = ZONE_A_FARE;
            break;

        case Zone::B:
            fare = ZONE_B_FARE;
            break;

        case Zone::C:
            fare = ZONE_C_FARE;
            break;

        default:
            cout << "Invalid zone";
            return 0;
    }

    total = (fare * tickets) + SURCHARGE;

    cout << "Fare per ticket: " << fare << endl;
    cout << "Surcharge: " << SURCHARGE << endl;
    cout << "Total fare: " << total << endl;

    return 0;
}
