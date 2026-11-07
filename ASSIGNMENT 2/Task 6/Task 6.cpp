#include <iostream>
#include <cstdlib>
using namespace std;

class Time
{
private:
    int h, m;

public:
    Time(int hh, int mm)
    {
        h = hh;
        m = mm;
    }

    friend int minutesBetween(const Time &a, const Time &b);
    friend bool earlier(const Time &a, const Time &b);
};

inline int minutesBetween(const Time &a, const Time &b)
{
    int t1 = a.h * 60 + a.m;
    int t2 = b.h * 60 + b.m;

    return abs(t1 - t2);
}

inline bool earlier(const Time &a, const Time &b)
{
    if (a.h < b.h)
        return true;

    if (a.h == b.h && a.m < b.m)
        return true;

    return false;
}

int main()
{
    Time departure(9, 45);
    Time arrival(13, 10);

    cout << minutesBetween(departure, arrival) << " ";
    cout << boolalpha << earlier(arrival, departure) << endl;

    return 0;
}