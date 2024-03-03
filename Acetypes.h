/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */



#ifndef ACETYPES_H
#define ACETYPES_H

#include "CellAce.h"


class CellACE110: public CellACE {
  public:
    CellACE110(Position& position, const State& state) : CellACE(position, state) {}
    void nextState(const Lattice& reticulo);
    void updateState();
    void display(std::ostream& os);
};


class CellACE30: public CellACE {
  public:
    CellACE30(Position& position, const State& state) : CellACE(position, state) {}
    void nextState(const Lattice& reticulo);
    void updateState();
    void display(std::ostream& os);
};


#endif