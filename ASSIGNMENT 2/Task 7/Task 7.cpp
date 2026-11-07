#include <iostream>
using namespace std;

class TransactionHistory
{
private:
    int transactions[10];
    int count;
    int next;

public:
    TransactionHistory()
    {
        count = 0;
        next = 0;
    }

    void addTransaction(int amount)
    {
        transactions[next] = amount;

        next = (next + 1) % 10;

        if (count < 10)
            count++;
    }

    void display()
    {
        cout << "Last 10 Transactions:" << endl;

        int start = (count == 10) ? next : 0;

        for (int i = 0; i < count; i++)
        {
            cout << transactions[(start + i) % 10] << endl;
        }
    }
};

int main()
{
    TransactionHistory t;

    for (int i = 1; i <= 12; i++)
    {
        t.addTransaction(i * 100);
    }

    t.display();

    return 0;
}