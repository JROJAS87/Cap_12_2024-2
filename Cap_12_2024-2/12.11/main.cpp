#include <iostream>
#include <vector>
#include <iomanip>
#include <memory>
#include "Trabajador.h"
#include "EmpleadoAsalariado.h"
#include "Fecha.h"

int main() {
    const int mesActual = 11;  // Cambia el mes para realizar pruebas en otros meses

    // Crear una lista de trabajadores usando punteros inteligentes
    std::vector<std::unique_ptr<Trabajador>> listaTrabajadores;
    listaTrabajadores.push_back(std::make_unique<EmpleadoAsalariado>("Carlos", "Mendoza", "123-45-6789", 11, 5, 1985, 900.00));
    listaTrabajadores.push_back(std::make_unique<EmpleadoAsalariado>("María", "López", "987-65-4321", 6, 15, 1978, 1100.00));
    
    // Recorrer la lista de trabajadores y procesar la nómina de cada uno
    for (const auto& trabajador : listaTrabajadores) {
        double salario = trabajador->calcularPago();  // Calcula el pago del trabajador

        // Verifica si el trabajador tiene cumpleaños este mes
        if (trabajador->obtenerFechaNacimiento().obtenerMes() == mesActual) {
            salario += 100.00;  // Añadir bono de cumpleaños
        }

        // Mostrar detalles del trabajador y su salario final
        std::cout << trabajador->obtenerDetalles() << "\nSalario final: $" << std::fixed << std::setprecision(2) << salario << "\n\n";
    }
    
    return 0;
}
