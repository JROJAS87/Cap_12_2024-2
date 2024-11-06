#include <iostream>
#include <vector>
#include <memory>
#include "Employee.h"
#include "PieceWorker.h"
#include "HourlyWorker.h"

// funcion principal para el sistema de pago
int main() {
    // vector de punteros de empleados
    std::vector<std::unique_ptr<Employee>> staff;

    // agregar trabajadores al vector de empleados
    staff.push_back(std::make_unique<PieceWorker>("Luis", "Gonzalez", "555-55-5555", 10.0, 250));
    staff.push_back(std::make_unique<HourlyWorker>("Carla", "Lopez", "444-44-4444", 18.0, 42));

    // mostrar detalles y salario de cada empleado
    for (const auto& emp : staff) {
        std::cout << emp->getInfo() << "\n"
                  << "Pay: $" << emp->calculatePay() << "\n\n";
    }

    return 0;
}
