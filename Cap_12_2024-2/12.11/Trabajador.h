#ifndef TRABAJADOR_H
#define TRABAJADOR_H

#include <string>
#include "Fecha.h"

class Trabajador {
public:
    Trabajador(const std::string& nombre, const std::string& apellido, const std::string& ssn, int mesNac, int diaNac, int anioNac)
        : nombre(nombre), apellido(apellido), numeroSeguroSocial(ssn), fechaNacimiento(diaNac, mesNac, anioNac) {}

    virtual ~Trabajador() = default;

    std::string obtenerNombre() const { return nombre; }
    std::string obtenerApellido() const { return apellido; }
    Fecha obtenerFechaNacimiento() const { return fechaNacimiento; }

    // Función virtual pura que deben implementar las clases derivadas
    virtual double calcularPago() const = 0;
    virtual std::string obtenerDetalles() const = 0;

private:
    std::string nombre;
    std::string apellido;
    std::string numeroSeguroSocial;
    Fecha fechaNacimiento;  // Fecha de nacimiento del trabajador
};

#endif
