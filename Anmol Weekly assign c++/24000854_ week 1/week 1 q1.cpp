/*1.	Write a program that takes a temperature value from the user. It should then allow the user to choose between Celsius (C) and Fahrenheit (F) for conversion. After the user selection, it should then convert the entered temperature to the chosen scale and display the result.
Use appropriate data types for temperature and handle error like non-numeric input. 
Use the following formula for conversion:
F = (C x 9/5) + 32
C = (F - 32) x 5/9 */

#include <iostream>
using namespace std;

int main() {
    double temp,cel,fah;
    char choice;
    
    cout << "Enter temperature= ";
    cin >> temp;
    
    cout << "choose between Celsius (C) and Fahrenheit (F) for conversion ";
    cin >> choice;
    
    if (choice == 'C' || choice == 'c')
    {
	
        cel=(temp - 32)* 5/9 ;
        cout << "Celsius= " << cel << endl;
	}
    else if (choice == 'F' || choice == 'f')
	{
	
        fah=(temp * 9 / 5) + 32;
        cout << "Fahrenheit= " << fah << endl;
		}
    else
	{
	
        cout << "Invalid choice!" << endl;
    }
    return 0;
}


