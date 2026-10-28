#include <iostream>
using namespace std;

class SmartCard
{
private:
    int balance;
    int minimumBalance;

public:
    SmartCard(int b, int m)
    {
        balance = b;
        minimumBalance = m;
    }

    bool canTravel(int fare)
    {
        return fare > 0 && balance - fare >= minimumBalance;
    }

    void deduct(int fare)
    {
        if (canTravel(fare))
        {
            balance -= fare;
            cout << "Travel successful" << endl;
            cout << "Remaining balance: " << balance << endl;
        }
        else
        {
            cout << "Travel not allowed" << endl;
            cout << "Balance: " << balance << endl;
        }
    }
};

int main()
{
    SmartCard card(100, 10);
    int fare;

    cout << "Enter fare: ";
    cin >> fare;

    card.deduct(fare);

    return 0;
}