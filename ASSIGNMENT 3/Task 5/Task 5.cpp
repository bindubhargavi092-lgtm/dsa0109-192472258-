#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Time {
    int seconds;

public:
    Time(int s = 0) : seconds(s) {}

    Time& operator++() {
        ++seconds;
        return *this;
    }

    Time operator++(int) {
        Time old = *this;
        ++seconds;
        return old;
    }

    bool operator==(const Time& t) const {
        return seconds == t.seconds;
    }

    bool operator<(const Time& t) const {
        return seconds < t.seconds;
    }

    void display() const {
        int h = seconds / 3600;
        int m = (seconds % 3600) / 60;
        int s = seconds % 60;

        cout << h << ":" << m << ":" << s << endl;
    }
};

class Playlist {
    vector<string> songs;

public:
    Playlist() {
        songs = {"Song A", "Song B", "Song C"};
    }

    string& operator[](int i) {
        if (i < 0 || i >= (int)songs.size())
            throw out_of_range("Invalid playlist index");

        return songs[i];
    }

    const string& operator[](int i) const {
        if (i < 0 || i >= (int)songs.size())
            throw out_of_range("Invalid playlist index");

        return songs[i];
    }
};

int main() {
    Time t(5);

    Time a = t++;
    Time b = ++t;

    cout << "a = ";
    a.display();

    cout << "b = ";
    b.display();

    cout << "t = ";
    t.display();

    Playlist p;

    cout << "Playlist:" << endl;

    for (int i = 0; i < 3; i++) {
        cout << p[i] << endl;
    }

    try {
        cout << p[-1] << endl;
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    return 0;
}