#ifndef PIECEWORKER_H
#define PIECEWORKER_H

#include "Employee.h"
#include <string>
#include <sstream>
#include <iomanip>

class PieceWorker : public Employee {
public:
    // constructor para inicializar al trabajador por pieza
    PieceWorker(const std::string& first, const std::string& last, const std::string& ssn,
                double ratePerPiece, int totalPieces)
        : Employee(first, last, ssn), pieceRate(ratePerPiece), totalPiecesProduced(totalPieces) {}

    // calculo del salario basado en tarifa y cantidad de piezas
    virtual double calculatePay() const override {
        return pieceRate * totalPiecesProduced;
    }

    // informacion detallada del trabajador
    virtual std::string getInfo() const override {
        std::ostringstream output;
        output << "Piece Worker: " << firstName << " " << lastName
               << "\nSSN: " << socialSecurity
               << "\nRate per piece: $" << std::fixed << std::setprecision(2) << pieceRate
               << "\nTotal pieces: " << totalPiecesProduced;
        return output.str();
    }

private:
    double pieceRate;  // tarifa por pieza
    int totalPiecesProduced; // piezas producidas
};

#endif
