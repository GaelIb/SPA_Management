#ifndef THERAPEUTICMASSAGE_H
#define THERAPEUTICMASSAGE_H

#include "Service.h"
#include <string>
using namespace std;

class TherapeuticMassage : public Service {
private:
    string appointmentTime;
    bool isReturningClient;

public:
    TherapeuticMassage();
    TherapeuticMassage(const string& time, bool returning, int duration, double basePrice);

    // Getters & Setters
    string getAppointmentTime() const;
    bool getIsReturningClient() const;
    void setAppointmentTime(const string& time);
    void setReturningClient(bool returning);

    // Métodos override
    string getSummary() const override;
    double calculateFinalPrice() const override;

    // Overload
    double calculateFinalPrice(bool isReturningClient) const override;
};

#endif // THERAPEUTICMASSAGE_H
