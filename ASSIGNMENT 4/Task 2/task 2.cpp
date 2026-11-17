
#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
    string phone;

public:
    Person(string n, int i, string p)
        : name(n), id(i), phone(p) {}

    void displayPerson() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Phone: " << phone << endl;
    }
};

class Student : virtual public Person {
protected:
    string programme;
    double cgpa;

public:
    Student(string n, int i, string p, string pr, double c)
        : Person(n, i, p), programme(pr), cgpa(c) {}
};

class Staff : virtual public Person {
protected:
    string department;
    double salary;

public:
    Staff(string n, int i, string p, string d, double s)
        : Person(n, i, p), department(d), salary(s) {}
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int i, string p,
                      string pr, double c,
                      string d, double s)
        : Person(n, i, p),
          Student(n, i, p, pr, c),
          Staff(n, i, p, d, s) {}

    void display() const {
        displayPerson();
        cout << "Programme: " << programme << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

class ResearchScholar : public Student {
    double fellowship;

public:
    ResearchScholar(string n, int i, string p,
                    string pr, double c, double f)
        : Person(n, i, p),
          Student(n, i, p, pr, c),
          fellowship(f) {}

    void display() const {
        displayPerson();
        cout << "Programme: " << programme << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Fellowship: " << fellowship << endl;
    }
};

int main() {
    TeachingAssistant t("Kavya", 101, "9876543210",
                        "CSE", 8.5, "AI", 25000);

    ResearchScholar r("Anu", 102, "9876501234",
                      "ECE", 9.0, 15000);

    cout << "Teaching Assistant Details" << endl;
    t.display();

    cout << "\nResearch Scholar Details" << endl;
    r.display();

    return 0;
}
