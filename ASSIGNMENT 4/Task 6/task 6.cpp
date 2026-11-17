
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Abstract base class
class Vehicle {
protected:
    string regNo;
    double dailyRate;
    bool rented;

public:
    Vehicle(string r, double rate)
        : regNo(r), dailyRate(rate), rented(false) {}

    virtual double charge(int days) const = 0;

    virtual void display() const = 0;

    void rent() {
        if (!rented) {
            rented = true;
            cout << regNo << " rented successfully" << endl;
        } else {
            cout << regNo << " is already rented" << endl;
        }
    }

    void returnVehicle(int daysLate) {
        if (rented) {
            double lateCharge = daysLate * 200;
            cout << regNo << " returned successfully" << endl;
            cout << "Late Charge: Rs " << lateCharge << endl;
            rented = false;
        } else {
            cout << regNo << " was not rented" << endl;
        }
    }

    virtual ~Vehicle() {}
};

// Bicycle class
class Bicycle : public Vehicle {
public:
    Bicycle(string r, double rate)
        : Vehicle(r, rate) {}

    double charge(int days) const override {
        return dailyRate * days;
    }

    void display() const override {
        cout << "Bicycle: " << regNo
             << " | Daily Rate: Rs " << dailyRate << endl;
    }
};

// Motor vehicle base class
class MotorVehicle : public Vehicle {
protected:
    double fuelLevel;
    string serviceDate;

public:
    MotorVehicle(string r, double rate,
                 double fuel, string date)
        : Vehicle(r, rate),
          fuelLevel(fuel), serviceDate(date) {}
};

// Two-wheeler class
class TwoWheeler : public MotorVehicle {
public:
    TwoWheeler(string r, double rate,
               double fuel, string date)
        : MotorVehicle(r, rate, fuel, date) {}

    double charge(int days) const override {
        return dailyRate * days + fuelLevel * 2;
    }

    void display() const override {
        cout << "Two-Wheeler: " << regNo
             << " | Fuel: " << fuelLevel << endl;
    }
};

// Car class
class Car : public MotorVehicle {
protected:
    int seats;

public:
    Car(string r, double rate, double fuel,
        string date, int s)
        : MotorVehicle(r, rate, fuel, date),
          seats(s) {}

    double charge(int days) const override {
        return dailyRate * days + fuelLevel * 3;
    }

    void display() const override {
        cout << "Car: " << regNo
             << " | Seats: " << seats << endl;
    }
};

// Electric car class
class ElectricCar : public Car {
    double batteryCapacity;
    double unitsUsed;

public:
    ElectricCar(string r, double rate,
                string date, int seats,
                double capacity, double units)
        : Car(r, rate, 0, date, seats),
          batteryCapacity(capacity), unitsUsed(units) {}

    double charge(int days) const override {
        return dailyRate * days + unitsUsed * 8;
    }

    void display() const override {
        cout << "Electric Car: " << regNo
             << " | Battery: " << batteryCapacity
             << " kWh" << endl;
    }
};

// New vehicle type added without changing existing classes
class ElectricBus : public MotorVehicle {
    double unitsUsed;

public:
    ElectricBus(string r, double rate,
                string date, double capacity,
                double units)
        : MotorVehicle(r, rate, capacity, date),
          unitsUsed(units) {}

    double charge(int days) const override {
        return dailyRate * days + unitsUsed * 10;
    }

    void display() const override {
        cout << "Electric Bus: " << regNo << endl;
    }
};

int main() {
    cout << fixed << setprecision(2);

    Vehicle* fleet[5];

    fleet[0] = new Bicycle("BIKE101", 100);
    fleet[1] = new TwoWheeler("TN01AB1234", 300, 5, "2026-12-01");
    fleet[2] = new Car("TN02CD5678", 1500, 10, "2026-12-10", 5);
    fleet[3] = new ElectricCar("TN03EF9012", 2000,
                              "2026-12-15", 5, 60, 20);
    fleet[4] = new ElectricBus("TN04GH3456", 3000,
                              "2026-12-20", 200, 50);

    cout << "VEHICLE FLEET" << endl;

    for (int i = 0; i < 5; i++) {
        fleet[i]->display();
    }

    cout << "\nRENTING VEHICLES" << endl;

    for (int i = 0; i < 5; i++) {
        fleet[i]->rent();
    }

    cout << "\nRENTAL CHARGES FOR 2 DAYS" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "Charge: Rs "
             << fleet[i]->charge(2) << endl;
    }

    cout << "\nRETURNING VEHICLES" << endl;

    for (int i = 0; i < 5; i++) {
        fleet[i]->returnVehicle(2);
    }

    for (int i = 0; i < 5; i++) {
        delete fleet[i];
    }

    return 0;
}
