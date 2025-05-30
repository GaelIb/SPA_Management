#include "TherapeuticMassage.h"
#include <sstream>
#include <iomanip>
using namespace std;

// Constructores
TherapeuticMassage::TherapeuticMassage()
    : Service("Personalized therapeutic massage", 0, 0.0), appointmentTime(""), isReturningClient(false) {}

TherapeuticMassage::TherapeuticMassage(const string& time, bool returning, int duration, double basePrice)
    : Service("Personalized therapeutic massage", duration, basePrice),
      appointmentTime(time), isReturningClient(returning) {}

// Getters & Setters
string TherapeuticMassage::getAppointmentTime() const { return appointmentTime; }
bool TherapeuticMassage::getIsReturningClient() const { return isReturningClient; }
void TherapeuticMassage::setAppointmentTime(const string& time) { appointmentTime = time; }
void TherapeuticMassage::setReturningClient(bool returning) { isReturningClient = returning; }

// Método override (sin parámetros)
double TherapeuticMassage::calculateFinalPrice() const {
    double finalPrice = basePrice;
    if (duration > 60) {
        finalPrice += 200.0;
    }
    return finalPrice;
}

// Overload/override: con parámetro de cliente recurrente
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

// Ahora este método SOLO arma el string, NO imprime
string TherapeuticMassage::getSummary() const {
    stringstream ss;
    ss << "Service: " << serviceName << endl;
    ss << "Duration: " << duration << " minutes" << endl;
    ss << "Base Price: $" << fixed << setprecision(0) << basePrice << endl;
    ss << "Time: " << appointmentTime << endl;
    if (isReturningClient)
        ss << "Client Type: Returning Client" << endl;
    ss << endl;

    if (duration > 60)
        ss << "Note: Duration exceeds 60 minutes. Surcharge applied: $200" << endl;
    if (isReturningClient)
        ss << "Note: Returning client discount applied: 10%" << endl;

    ss << "Final Price: $" << fixed << setprecision(0)
       << calculateFinalPrice(isReturningClient) << endl;
    ss << "Booking Confirmed" << endl;

    return ss.str();
}
