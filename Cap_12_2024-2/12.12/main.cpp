#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>
#include "BasePackage.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

int main() {
    // Crear un vector de punteros a objetos de tipo BasePackage
    std::vector<std::unique_ptr<BasePackage>> packageList;

    // Agregar objetos de TwoDayPackage y OvernightPackage al vector
    packageList.push_back(std::make_unique<TwoDayPackage>("Carlos Jimenez", "123 Main St", "New York", "NY", "10001",
                                                          "Ana Diaz", "456 Oak St", "Los Angeles", "CA", "90001",
                                                          8.0, 2.5, 4.0));
    packageList.push_back(std::make_unique<OvernightPackage>("Laura Gomez", "789 Maple St", "Chicago", "IL", "60616",
                                                             "John Smith", "101 Pine St", "Houston", "TX", "77002",
                                                             5.0, 3.0, 1.2));

    double totalCost = 0.0;

    // Procesar cada paquete polimórficamente
    for (const auto& pkg : packageList) {
        // Mostrar la información del remitente y destinatario
        std::cout << "Sender:\n" << pkg->getSenderInfo() << "\n";
        std::cout << "Recipient:\n" << pkg->getRecipientInfo() << "\n";

        // Calcular y mostrar el costo del paquete actual
        double cost = pkg->computeCost();
        std::cout << "Shipping Cost: $" << std::fixed << std::setprecision(2) << cost << "\n\n";

        // Acumular el costo total de envío
        totalCost += cost;
    }

    // Mostrar el costo total de envío de todos los paquetes
    std::cout << "Total Shipping Cost for all packages: $" << std::fixed << std::setprecision(2) << totalCost << std::endl;

    return 0;
}
