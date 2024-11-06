#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "BasePackage.h"

class OvernightPackage : public BasePackage {
public:
    OvernightPackage(const std::string& senderName, const std::string& senderAddress, const std::string& senderCity,
                     const std::string& senderState, const std::string& senderZIP,
                     const std::string& recipientName, const std::string& recipientAddress, const std::string& recipientCity,
                     const std::string& recipientState, const std::string& recipientZIP,
                     double weightOz, double costPerOz, double extraCostPerOz)
        : BasePackage(senderName, senderAddress, senderCity, senderState, senderZIP,
                      recipientName, recipientAddress, recipientCity, recipientState, recipientZIP, weightOz, costPerOz),
          additionalCostPerOunce(extraCostPerOz) {}

    // Sobrecarga de la función para incluir el costo adicional por onza
    virtual double computeCost() const override {
        return weight * (costPerOunce + additionalCostPerOunce);
    }

private:
    double additionalCostPerOunce;  // Costo adicional para el servicio nocturno
};

#endif
