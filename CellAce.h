/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Computabilidad y Algoritmia 2023-2024
  *
  * @author Rubén Díaz Marrero 
  * @date 22/09/2023
  */


#ifndef CELLACE_H
#define CELLACE_H

#include <iostream>

#include "Cell.h"


class CellACE: public Cell {
  public:
  CellACE(const Position&, const State&);
  void nextState(const Lattice&);
  void updateState();
  void display(std::ostream&);
};






#endif // CELLACE_H