#include<iostream>
using namespace std;

class Cinema {
private:
    char a[5][5];  

public:
    Cinema() {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                a[i][j] = '0';
            }
        }
    }

    void seat() {
        cout << "Seat arrangement:" << endl;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    
    void input() {
        int row, col;
        seat();  

        cout << "Enter row and column (1-5): ";
        cin >> row >> col;

        if(row < 1 || row > 5 || col < 1 || col > 5) {
            cout << "Invalid input." << endl;
            return;
        }

        if(a[row-1][col-1] == 'x') {
            cout << "Seat already booked!" << endl;
        } else {
            a[row-1][col-1] = 'x';
            cout << "Seat booked successfully!" << endl;
        }

        seat();  
    }
};

int main() {
    Cinema c;
    c.input();  
    return 0;
}

