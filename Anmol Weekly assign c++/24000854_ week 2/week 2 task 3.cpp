#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class BookManager {
private:
    const int COUNT = 10;
    const int TITLE = 150;

    char titles[10][150];
    char filename[100];

public:
    void getFilename() {
        cout << "Enter the binary file name to save book titles: ";
        cin.getline(filename, 100);
    }

    void inputTitles() {
        cout << "Enter " << COUNT << " book titles:"<<endl;
        for (int i = 0; i < COUNT; ++i) {
            cout << "Title " << i + 1 << ": ";
            cin.getline(titles[i], TITLE);
        }
    }

    void saveToFile() {
        ofstream outFile(filename, ios::binary);
        if (!outFile) {
            cerr << "? Error opening file for writing.\n";
            return;
        }

        for (int i = 0; i < COUNT; ++i) {
            outFile.write(titles[i], TITLE);
        }

        outFile.close();
        cout << " Book titles saved successfully."<<endl;
    }

    void searchTitle() {
        ifstream inFile(filename, ios::binary);
        if (!inFile) {
            cerr << "? Error opening file for reading."<<endl;
            return;
        }

        char search[150];
        char current[150];
        bool found = false;

        cout << "Enter a title to search: "<<endl;
        cin.getline(search, TITLE);

        while (inFile.read(current, TITLE)) {
            if (strncmp(current, search, TITLE) == 0) {
                found = true;
                break;
            }
        }

        inFile.close();

        if (found)
            cout << "? The title is contained in the file."<<endl;
        else
            cout << "? The title is NOT contained in the file."<<endl;
    }
};

int main() {
    BookManager manager;

    manager.getFilename();
    manager.inputTitles();
    manager.saveToFile();
    manager.searchTitle();

    return 0;
}
