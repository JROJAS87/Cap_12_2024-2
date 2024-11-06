#ifndef BASEPACKAGE_H
#define BASEPACKAGE_H

#include <string>

class BasePackage {
public:
    // Constructor con todos los detalles requeridos para inicializar el paquete
    BasePackage(const std::string& senderName, const std::string& senderAddress, const std::string& senderCity,
                const std::string& senderState, const std::string& senderZIP,
                const std::string& recipientName, const std::string& recipientAddress, const std::string& recipientCity,
                const std::string& recipientState, const std::string& recipientZIP,
                double weightOz, double costPerOz)
        : senderName(senderName), senderAddress(senderAddress), senderCity(senderCity),
          senderState(senderState), senderZIP(senderZIP),
          recipientName(recipientName), recipientAddress(recipientAddress), recipientCity(recipientCity),
          recipientState(recipientState), recipientZIP(recipientZIP) {
        
        // Validación para peso y costo por onza
        if (weightOz > 0.0) {
            weight = weightOz;
        } else {
            throw std::invalid_argument("Weight must be positive.");
        }

        if (costPerOz > 0.0) {
            costPerOunce = costPerOz;
        } else {
            throw std::invalid_argument("Cost per ounce must be positive.");
        }
    }

    virtual ~BasePackage() = default;

    // Método virtual para calcular el costo base
    virtual double computeCost() const {
        return weight * costPerOunce;
    }

    // Métodos para obtener información del remitente y destinatario
    std::string getSenderInfo() const {
        return senderName + "\n" + senderAddress + "\n" + senderCity + ", " + senderState + " " + senderZIP;
    }

    std::string getRecipientInfo() const {
        return recipientName + "\n" + recipientAddress + "\n" + recipientCity + ", " + recipientState + " " + recipientZIP;
    }

protected:
    double weight;  // Peso del paquete en onzas
    double costPerOunce;  // Costo de envío por onza

private:
    // Información del remitente
    std::string senderName;
    std::string senderAddress;
    std::string senderCity;
    std::string senderState;
    std::string senderZIP;

    // Información del destinatario
    std::string recipientName;
    std::string recipientAddress;
    std::string recipientCity;
    std::string recipientState;
    std::string recipientZIP;
};

#endif
