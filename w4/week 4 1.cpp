#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Person {
    string name;
    int age;
};

vector<Person> people;

void addPerson(const string& name, int age) {
    people.push_back({name, age});
}

void findPeopleAboveAgeLimit(int ageLimit) {
    cout << "\nPeople above age limit " << ageLimit << ":\n";
    bool found = false;
    for (int i = 0; i < people.size(); ++i) {
        if (people[i].age > ageLimit) {
            cout << people[i].name << " - Age: " << people[i].age << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No person found above age limit " << ageLimit << "." << endl;
    }
}

bool compareByName(Person a, Person b) {
    return a.name < b.name;
}

void displaySortedNames() {
    vector<Person> sortedPeople = people;
    sort(sortedPeople.begin(), sortedPeople.end(), compareByName);

    cout << "\nNames in alphabetical order:\n";
    for (int i = 0; i < sortedPeople.size(); ++i) {
        cout << sortedPeople[i].name << " - Age: " << sortedPeople[i].age << endl;
    }
}

int main() {
    int n;
    cout << "How many people do you want to add? ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        string name;
        int age;

        cout << "Enter name #" << i + 1 << ": ";
        getline(cin, name);

        cout << "Enter age of " << name << ": ";
        cin >> age;

        if (age < 0) {
            cout << "Age cannot be negative. Try again.\n";
            --i;
            cin.ignore();
            continue;
        }

        addPerson(name, age);
        cin.ignore();
    }

    int ageLimit;
    cout << "\nEnter age limit to find people above: ";
    cin >> ageLimit;
    findPeopleAboveAgeLimit(ageLimit);

    displaySortedNames();

    return 0;
}

