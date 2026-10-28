
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main()
{
    int journeys;
    double fare, balance = 500.00;
    
    cout << "Enter number of journeys: ";

    while (!(cin >> journeys) || journeys <= 0)
    {
        cout << "Invalid input! Enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\nEnter fare per journey: ";

    while (!(cin >> fare) || fare <= 0)
    {
        cout << "Invalid fare! Enter a positive amount: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    double total = journeys * fare;
    balance -= total;

    cout << "\n";
    cout << setfill('=') << setw(40) << "" << endl;
    cout << setfill(' ') << setw(27) << "JOURNEY REPORT" << endl;
    cout << setfill('=') << setw(40) << "" << endl;

    cout << fixed << setprecision(2);
    cout << left << setw(25) << "Number of journeys"
         << right << journeys << endl;
    cout << left << setw(25) << "Fare per journey"
         << "Rs. " << fare << endl;
    cout << left << setw(25) << "Total fare"
         << "Rs. " << total << endl;
    cout << left << setw(25) << "Remaining balance"
         << "Rs. " << balance << endl;

    cout << setfill('=') << setw(40) << "" << endl;

    return 0;
}
