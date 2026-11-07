#include <iostream>
using namespace std;

int& highestMark(int marks[], int size)
{
    int maxIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[maxIndex])
        {
            maxIndex = i;
        }
    }

    return marks[maxIndex];
}

int main()
{
    int marks[5] = {78, 92, 85, 88, 95};

    cout << "Highest Mark: " << highestMark(marks, 5) << endl;

    highestMark(marks, 5) = 100;

    cout << "Updated Mark: " << highestMark(marks, 5) << endl;

    return 0;
}