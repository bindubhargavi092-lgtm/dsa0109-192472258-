
#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

int main()
{
    bool paymentStatus = true;
    char zoneName = 'A';
    int zoneNumber = 1;
    unsigned int journeyCount = 5000;
    long long farePaise = 2550;
    long long balancePaise = 100000;
    double journeyTime = 25.5;
    float distance = 12.5f;
    auto surchargePaise = 500LL;

    cout << "DATA TYPE SIZES\n";
    cout << "bool: " << sizeof(bool) << " bytes\n";
    cout << "char: " << sizeof(char) << " bytes\n";
    cout << "int: " << sizeof(int) << " bytes\n";
    cout << "unsigned int: " << sizeof(unsigned int) << " bytes\n";
    cout << "long long: " << sizeof(long long) << " bytes\n";
    cout << "float: " << sizeof(float) << " bytes\n";
    cout << "double: " << sizeof(double) << " bytes\n";
    cout << "auto variable type (long long): "
         << sizeof(surchargePaise) << " bytes\n";

    cout << "\nFARE DETAILS\n";
    cout << "Zone: " << zoneName << endl;
    cout << "Zone number: " << zoneNumber << endl;
    cout << "Journey count: " << journeyCount << endl;
    cout << "Fare: " << farePaise << " paise" << endl;
    cout << "Balance: " << balancePaise << " paise" << endl;
    cout << "Journey time: " << journeyTime << " minutes" << endl;
    cout << "Distance: " << distance << " km" << endl;
    cout << "Payment status: " << boolalpha << paymentStatus << endl;

    long long totalPaise = farePaise + surchargePaise;
    cout << "Total fare: " << totalPaise << " paise" << endl;

    cout << "\nINTEGER RANGE\n";
    cout << "INT_MAX: " << INT_MAX << endl;
    cout << "LLONG_MAX: " << LLONG_MAX << endl;
    cout << "UINT_MAX: " << UINT_MAX << endl;

    cout << "\nTYPE COMPATIBILITY\n";
    int a = 10;
    double b = 2.5;
    bool c = true;
    double result = a + b + c;
    cout << "10 + 2.5 + true = " << result << endl;

    cout << "\nPRECISION COMPARISON\n";
    double rupees = 0.1 + 0.2;
    cout << setprecision(17);
    cout << "0.1 + 0.2 using double = " << rupees << endl;

    long long paise1 = 10;
    long long paise2 = 20;
    cout << "10 paise + 20 paise = "
         << paise1 + paise2 << " paise" << endl;

    return 0;
}
