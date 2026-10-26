#include <iostream>
using namespace std;

class FareTable {
public:
    static int getFare(int zone) {
        if (zone == 1) return 1000;
        if (zone == 2) return 2000;
        if (zone == 3) return 3000;
        return 0;
    }
};

class SmartCard {
    long long balance;

public:
    SmartCard(long long amount) : balance(amount) {}

    bool canTravel(long long fare) {
        return balance - fare >= 5000;
    }

    bool deduct(long long fare) {
        if (!canTravel(fare)) return false;
        balance -= fare;
        return true;
    }

    long long getBalance() {
        return balance;
    }
};

class Journey {
public:
    int zone;
    bool peak;

    Journey(int z, bool p) : zone(z), peak(p) {}

    long long calculateFare() {
        long long fare = FareTable::getFare(zone);
        if (peak) fare += fare * 20 / 100;
        return fare;
    }
};

int main() {
    SmartCard card(10000);
    Journey trip(1, false);

    long long fare = trip.calculateFare();

    if (card.deduct(fare))
        cout << "Journey allowed\n";
    else
        cout << "Journey denied\n";

    cout << "Balance in paise: " << card.getBalance() << '\n';
    return 0;
}