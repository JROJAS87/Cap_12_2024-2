#ifndef HOURLYWORKER_H
#define HOURLYWORKER_H

#include "Employee.h"
#include <string>
#include <sstream>
#include <iomanip>

class HourlyWorker : public Employee {
public:
    // constructor para inicializar datos del trabajador por hora
    HourlyWorker(const std::string& first, const std::string& last, const std::string& ssn,
                 double hourlyRate, double workedHours)
        : Employee(first, last, ssn), hourlyWage(hourlyRate), hoursWorked(workedHours) {}

    // calculo de salario incluyendo horas extras
    virtual double calculatePay() const override {
        if (hoursWorked <= 40) {
            return hourlyWage * hoursWorked;
        } else {
            return (40 * hourlyWage) + ((hoursWorked - 40) * hourlyWage * 1.5);
        }
    }

    // obtener informacion del trabajador
    virtual std::string getInfo() const override {
        std::ostringstream output;
        output << "Hourly Worker: " << firstName << " " << lastName
               << "\nSSN: " << socialSecurity
               << "\nHourly wage: $" << std::fixed << std::setprecision(2) << hourlyWage
               << "\nHours worked: " << hoursWorked;
        return output.str();
    }

private:
    double hourlyWage;  // tarifa por hora
    double hoursWorked; // horas trabajadas
};

#endif
