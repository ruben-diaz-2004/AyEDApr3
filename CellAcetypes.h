/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */


#ifndef CELLACETYPES_H
#define CELLACETYPES_H

#include <iostream>

#include "Cell.h"
#include "CellACE.h"


class CellACE110: public CellACE {
    public:
    CellACE110(const Position&, const State&) : CellACE(position_, state_) {}
    void nextState(const Lattice&);
    void display(std::ostream&);
};



class CellACE30: public CellACE {
  public:
  CellACE30(const Position&, const State&) : CellACE(position_, state_) {}
  void nextState(const Lattice&);
  void display(std::ostream&);
};

#endif // CELLACETYPES_H