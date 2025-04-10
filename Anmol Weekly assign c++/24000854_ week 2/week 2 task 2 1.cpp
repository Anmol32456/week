#include<iostream>
using namespace std;

class Circle 
{
private:
    float rad, rad1, cal, cal1;

public:
    Circle() 
	{
        rad = rad1 = 0;
    }

    void input() {
        cout << "Enter the radius of 1st circle: ";
        cin >> rad;
        cout << "Enter the radius of 2nd circle: ";
        cin >> rad1;
    }

    void calc() {
        cal = 3.14 * rad * rad;
        cal1 = 3.14 * rad1 * rad1;
    }

    void area() {
        if (cal > cal1) 
		{
            cout << "The largest circle area = " << cal << endl;
        } else 
		{
            cout << "The largest circle area = " << cal1 << endl;
        }
    }
};

int main() {
    Circle c;
    c.input();
    c.calc();
    c.area();
    return 0;
}

