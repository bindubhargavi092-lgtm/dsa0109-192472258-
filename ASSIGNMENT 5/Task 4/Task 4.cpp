
#include <iostream>
#include <string>
using namespace std;

class Bill {
public:
    virtual double total() const = 0;
    virtual string type() const = 0;
    virtual ~Bill() {}
};

class OutPatient : public Bill {
public:
    double total() const override {
        return 1700;
    }

    string type() const override {
        return "Outpatient";
    }
};

class InPatient : public Bill {
public:
    double total() const override {
        return 47500;
    }

    string type() const override {
        return "Inpatient";
    }
};

// New bill type
class DayCareBill : public Bill {
public:
    double total() const override {
        return 15000;
    }

    string type() const override {
        return "Day Care";
    }
};

class Payer {
public:
    virtual double amountCovered(const Bill& b) const = 0;
    virtual ~Payer() {}
};

// New payer
class CorporatePayer : public Payer {
public:
    double amountCovered(const Bill& b) const override {
        return b.total() * 0.80;
    }
};

int main() {
    OutPatient op;
    InPatient ip;
    DayCareBill dc;

    CorporatePayer corporate;

    Bill* bills[] = {&op, &ip, &dc};

    for (Bill* b : bills) {
        cout << b->type() << " Bill: "
             << b->total() << endl;

        cout << "Corporate Covered: "
             << corporate.amountCovered(*b)
             << endl;
    }

    return 0;
}
