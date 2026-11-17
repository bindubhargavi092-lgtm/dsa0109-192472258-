
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Cart {
    string items[10];
    double prices[10];
    int n = 0;
    double discount = 0;

public:
    // Add item and return current object
    Cart& add(string item, double price) {
        if (n < 10) {
            items[n] = item;
            prices[n] = price;
            n++;
        }
        return *this;
    }

    // Set discount
    Cart& setDiscount(double discount) {
        this->discount = discount;
        return *this;
    }

    double total() const {
        double t = 0;

        for (int i = 0; i < n; i++) {
            t += prices[i];
        }

        return t * (100 - discount) / 100;
    }

    void display() const {
        cout << "Cart Items:" << endl;

        for (int i = 0; i < n; i++) {
            cout << items[i] << " - Rs " << prices[i] << endl;
        }

        cout << "Total: Rs " << total() << endl;
    }
};

int main() {
    // 1. Direct object
    Cart c;
    c.add("Rice", 60);

    // 2. Pointer using ->
    Cart* p = &c;
    p->add("Dal", 120);

    // 3. Reference
    Cart& ref = c;
    ref.add("Oil", 180);

    // 4. Dynamic object
    Cart* dynamicCart = new Cart();

    dynamicCart->add("Milk", 50)
               .add("Bread", 40)
               .setDiscount(10);

    cout << fixed << setprecision(2);

    cout << "First Cart" << endl;
    c.display();

    cout << "\nDynamic Cart" << endl;
    dynamicCart->display();

    // Array of pointers to Cart
    Cart cart1, cart2, cart3;

    cart1.add("Book", 100);
    cart2.add("Shoes", 500);
    cart3.add("Bag", 300);

    Cart* carts[3] = {&cart1, &cart2, &cart3};

    int highest = 0;

    for (int i = 1; i < 3; i++) {
        if (carts[i]->total() > carts[highest]->total()) {
            highest = i;
        }
    }

    cout << "\nHighest Cart Total: Rs "
         << carts[highest]->total() << endl;

    delete dynamicCart;

    return 0;
}
