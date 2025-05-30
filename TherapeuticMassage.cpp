#include "TherapeuticMassage.h"
#include <iostream>
#include <iomanip>
using namespace std;

TherapeuticMassage::TherapeuticMassage()
    : Service("Personalized therapeutic massage", 0, 0.0), appointmentTime(""), isReturningClient(false) {}

TherapeuticMassage::TherapeuticMassage(const string& time, bool returning, int duration, double basePrice)
    : Service("Personalized therapeutic massage", duration, basePrice),
      appointmentTime(time), isReturningClient(returning) {}

string TherapeuticMassage::getAppointmentTime() const { return appointmentTime; }
bool TherapeuticMassage::getIsReturningClient() const { return isReturningClient; }
void TherapeuticMassage::setAppointmentTime(const string& time) { appointmentTime = time; }
void TherapeuticMassage::setReturningClient(bool returning) { isReturningClient = returning; }

double TherapeuticMassage::calculateFinalPrice() const {
    double finalPrice = basePrice;
    if (duration > 60) {
        finalPrice += 200.0;
    }
    return finalPrice;
}

double TherapeuticMassage::calculateFinalPrice(bool isReturningClientParam) const {
    double finalPrice = basePrice;
    if (duration > 60) {
        finalPrice += 200.0;
    }
    if (isReturningClientParam) {
        finalPrice *= 0.9;
    }
    return finalPrice;
}

void TherapeuticMassage::displaySummary() const {
    cout << "Service: " << serviceName << endl;
    cout << "Duration: " << duration << " minutes" << endl;
    cout << "Base Price: $" << fixed << setprecision(0) << basePrice << endl;
    cout << "Time: " << appointmentTime << endl;
    if (isReturningClient)
        cout << "Client Type: Returning Client" << endl;
    cout << endl;

    bool surchargeApplied = (duration > 60);
    bool discountApplied = isReturningClient;
    if (surchargeApplied)
        cout << "Note: Duration exceeds 60 minutes. Surcharge applied: $200" << endl;
    if (discountApplied)
        cout << "Note: Returning client discount applied: 10%" << endl;

    cout << "Final Price: $" << fixed << setprecision(0)
         << calculateFinalPrice(isReturningClient) << endl;
    cout << "Booking Confirmed" << endl;
}
