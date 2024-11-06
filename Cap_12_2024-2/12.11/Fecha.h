#ifndef FECHA_H
#define FECHA_H

class Fecha {
public:
    Fecha(int dia, int mes, int anio) 
        : dia(dia), mes(mes), anio(anio) {}

    int obtenerMes() const { return mes; }

private:
    int dia;
    int mes;
    int anio;
};

#endif
