#ifndef SERVICE_H
#define SERVICE_H

#include <string>
using namespace std;

class Service {
protected:
    string serviceName;
    int duration;
    double basePrice;

public:
    Service();
    Service(const string& name, int duration, double basePrice);

 
    string getService() const;
    int getDuration() const;
    double getBasePrice() const;

    
    void setServiceName(const string& name);
    void setDuration(int duration);
    void setBasePrice(double price);

    
    virtual void displaySummary() const = 0;
    virtual double calculateFinalPrice() const = 0;

    
    virtual double calculateFinalPrice(bool isReturningClient) const;

    virtual ~Service() {}
};

#endif 