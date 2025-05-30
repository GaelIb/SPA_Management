#include "Service.h"

// Constructores
Service::Service() : serviceName(""), duration(0), basePrice(0.0) {}

Service::Service(const string& name, int duration, double basePrice)
    : serviceName(name), duration(duration), basePrice(basePrice) {}

// Getters
string Service::getService() const { return serviceName; }
int Service::getDuration() const { return duration; }
double Service::getBasePrice() const { return basePrice; }

// Setters
void Service::setServiceName(const string& name) { serviceName = name; }
void Service::setDuration(int duration) { this->duration = duration; }
void Service::setBasePrice(double price) { basePrice = price; }

// Overload
double Service::calculateFinalPrice(bool isReturningClient) const {
    return basePrice;
}
