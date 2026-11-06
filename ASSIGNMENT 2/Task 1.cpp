#include <iostream>
using namespace std;

void change(int a, int &b, int *c)
{
    a = a + 10;
    b = b + 10;
    *c = *c + 10;
}

int main()
{
    int a = 1, b = 2, c = 3;

    change(a, b, &c);

    cout << a << " " << b << " " << c << endl;

    return 0;
}