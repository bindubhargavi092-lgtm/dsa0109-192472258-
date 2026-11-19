
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

class Bill {
public:
    virtual double total() const = 0;
    virtual ~Bill() = default;
};

class OutPatient : public Bill {
public:
    double total() const override {
        return 500 + 1200;
    }
};

class InPatient : public Bill {
public:
    double total() const override {
        return 3 * 2500 + 40000;
    }
};

struct SimpleBill {
    int type;
};

double switchTotal(const SimpleBill& b) {
    switch (b.type) {
        case 1: return 1700;
        case 2: return 47500;
        default: return 0;
    }
}

int main() {
    vector<OutPatient> op(5);
    vector<InPatient> ip(5);

    vector<Bill*> bills;

    for (int i = 0; i < 5; i++) {
        bills.push_back(&op[i]);
        bills.push_back(&ip[i]);
    }

    vector<SimpleBill> simple;

    for (int i = 0; i < 10; i++) {
        simple.push_back({i % 2 == 0 ? 1 : 2});
    }

    double virtualSum = 0;
    double switchSum = 0;

    for (Bill* b : bills)
        virtualSum += b->total();

    for (auto b : simple)
        switchSum += switchTotal(b);

    cout << "Virtual Total: " << virtualSum << endl;
    cout << "Switch Total: " << switchSum << endl;

    const int N = 1000000;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < N; i++)
        for (Bill* b : bills)
            virtualSum += b->total();

    auto stop = high_resolution_clock::now();

    cout << "Virtual Time: "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds" << endl;

    start = high_resolution_clock::now();

    for (int i = 0; i < N; i++)
        for (auto b : simple)
            switchSum += switchTotal(b);

    stop = high_resolution_clock::now();

    cout << "Switch Time: "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds" << endl;

    return 0;
}
