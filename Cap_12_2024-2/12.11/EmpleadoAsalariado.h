#ifndef EMPLEADOASALARIADO_H
#define EMPLEADOASALARIADO_H

#include "Trabajador.h"
#include <string>
#include <iomanip>
#include <sstream>

class EmpleadoAsalariado : public Trabajador {
public:
    EmpleadoAsalariado(const std::string& nombre, const std::string& apellido, const std::string& ssn, int mesNac, int diaNac, int anioNac, double salario)
        : Trabajador(nombre, apellido, ssn, mesNac, diaNac, anioNac), salarioFijo(salario) {}

    virtual double calcularPago() const override {
        return salarioFijo;
    }

    virtual std::string obtenerDetalles() const override {
        std::ostringstream salida;
        salida << "Empleado con salario fijo: " << obtenerNombre() << " " << obtenerApellido()
               << "\nSalario fijo semanal: $" << std::fixed << std::setprecision(2) << salarioFijo;
        return salida.str();
    }

private:
    double salarioFijo;  // Salario semanal
};

#endif
