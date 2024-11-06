#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

// clase base employee
class Employee {
public:
    // inicializar datos basicos del empleado
    Employee(const std::string& first, const std::string& last, const std::string& ssn)
        : firstName(first), lastName(last), socialSecurity(ssn) {}

    virtual ~Employee() = default;

    // funciones virtuales puras para obtener ingresos y detalles
    virtual double calculatePay() const = 0;
    virtual std::string getInfo() const = 0;

protected:
    std::string firstName;
    std::string lastName;
    std::string socialSecurity;
};

#endif
