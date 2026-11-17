
#include <iostream>
#include <memory>
using namespace std;

class Account {
public:
    virtual double rate() const {
        return 3.5;
    }

    virtual void display() const {
        cout << "Normal Account" << endl;
        cout << "Interest Rate: " << rate() << "%" << endl;
    }

    virtual ~Account() {
        cout << "Account destroyed" << endl;
    }
};

class SeniorAccount : public Account {
    double* history;

public:
    SeniorAccount() {
        history = new double[100];
        cout << "Senior Account created" << endl;
    }

    double rate() const override {
        return 4.0;
    }

    void display() const override {
        cout << "Senior Account" << endl;
        cout << "Interest Rate: " << rate() << "%" << endl;
    }

    ~SeniorAccount() override {
        delete[] history;
        cout << "Senior Account destroyed" << endl;
    }
};

int main() {
    Account* accounts[2];

    accounts[0] = new Account();
    accounts[1] = new SeniorAccount();

    cout << "\nAccount Details" << endl;

    for (Account* a : accounts) {
        a->display();
    }

    cout << "\nDeleting Accounts" << endl;

    for (Account* a : accounts) {
        delete a;
    }

    cout << "\nSmart Pointer Example" << endl;

    unique_ptr<Account> p =
        make_unique<SeniorAccount>();

    cout << "Interest Rate: " << p->rate() << "%" << endl;

    return 0;
}
