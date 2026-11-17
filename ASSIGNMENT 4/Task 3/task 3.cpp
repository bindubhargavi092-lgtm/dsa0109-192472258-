
#include <iostream>
#include <string>
using namespace std;

class Address {
    string city;
    int pin;

public:
    Address(string c, int p) : city(c), pin(p) {
        cout << "Address created" << endl;
    }

    string str() const {
        return city + "-" + to_string(pin);
    }

    ~Address() {
        cout << "Address destroyed" << endl;
    }
};

class Course {
    string courseName;

public:
    Course(string c) : courseName(c) {
        cout << "Course created" << endl;
    }

    ~Course() {
        cout << "Course destroyed" << endl;
    }
};

class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {
        cout << "Person created" << endl;
    }

    virtual ~Person() {
        cout << "Person destroyed" << endl;
    }
};

class Student : virtual public Person {
    long long regNo;
    Address home;
    Course course;

public:
    Student(string n, int a, long long r,
            string city, int pin, string c)
        : Person(n, a), regNo(r),
          home(city, pin), course(c) {
        cout << "Student created" << endl;
    }

    void display() const {
        cout << regNo << " " << name << " ("
             << age << ") " << home.str() << endl;
    }

    ~Student() override {
        cout << "Student destroyed" << endl;
    }
};

class Staff : virtual public Person {
protected:
    double salary;

public:
    Staff(string n, int a, double s)
        : Person(n, a), salary(s) {
        cout << "Staff created" << endl;
    }

    ~Staff() override {
        cout << "Staff destroyed" << endl;
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int a, long long r,
                      string city, int pin, string c,
                      double s)
        : Person(n, a),
          Student(n, a, r, city, pin, c),
          Staff(n, a, s) {
        cout << "Teaching Assistant created" << endl;
    }

    ~TeachingAssistant() override {
        cout << "Teaching Assistant destroyed" << endl;
    }
};

int main() {
    cout << "Student Object" << endl;

    {
        Student s("Kavya", 19, 192311001,
                  "Salem", 636001, "C++");

        s.display();
    }

    cout << "\nStaff Object" << endl;

    {
        Staff s("Ravi", 40, 40000);
    }

    cout << "\nTeaching Assistant Object" << endl;

    {
        TeachingAssistant t("Anu", 22, 192311002,
                            "Chennai", 600001,
                            "Python", 25000);
    }

    return 0;
}
