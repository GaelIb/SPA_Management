#include <iostream>
#include <string>
#include "TherapeuticMassage.h"
using namespace std;

int main() {
    string time;
    int duration;
    double price;
    char clientTypeChar;
    bool isReturningClient;

    cout << "=== SPA Service Booking ===" << endl;
    cout << "Enter duration (in minutes): ";
    cin >> duration;
    cout << "Enter base price: $";
    cin >> price;
    cin.ignore();
    cout << "Enter appointment time (e.g., 3:00 PM): ";
    getline(cin, time);
    cout << "Is the client returning? (y/n): ";
    cin >> clientTypeChar;
    isReturningClient = (clientTypeChar == 'y' || clientTypeChar == 'Y');


    Service* booking = new TherapeuticMassage(time, isReturningClient, duration, price);
    cout << "\n========================================\n";
    booking->displaySummary();
    cout << "========================================\n";

    delete booking;
    return 0;
}
