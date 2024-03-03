/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */


#ifndef LIFETYPES_H
#define LIFETYPES_H

#include "CellLife.h"


class CellLife23_3: public CellLife {
  public:
    CellLife23_3(Position& position, const State& state) : CellLife(position, state) {}
    void nextState(const Lattice& reticulo);
    void updateState();
    void display(std::ostream& os);
};


class CellLife51_346: public CellLife {
  public:
    CellLife51_346(Position& position, const State& state) : CellLife(position, state) {}
    void nextState(const Lattice& reticulo);
    void updateState();
    void display(std::ostream& os);
};


#endif