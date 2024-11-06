#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "BasePackage.h"

class TwoDayPackage : public BasePackage {
public:
    TwoDayPackage(const std::string& senderName, const std::string& senderAddress, const std::string& senderCity,
                  const std::string& senderState, const std::string& senderZIP,
                  const std::string& recipientName, const std::string& recipientAddress, const std::string& recipientCity,
                  const std::string& recipientState, const std::string& recipientZIP,
                  double weightOz, double costPerOz, double flatFee)
        : BasePackage(senderName, senderAddress, senderCity, senderState, senderZIP,
                      recipientName, recipientAddress, recipientCity, recipientState, recipientZIP, weightOz, costPerOz),
          flatCharge(flatFee) {}

    // Sobrecarga de la función para incluir la tarifa fija en el cálculo
    virtual double computeCost() const override {
        return BasePackage::computeCost() + flatCharge;
    }

private:
    double flatCharge;  // Tarifa fija adicional para envío en dos días
};

#endif
